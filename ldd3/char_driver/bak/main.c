/*
 * main.c -- the bare scull char module
 */

#include <linux/config.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>		/* printk() */
#include <linux/slab.h>			/* kmalloc() */
#include <linux/fs.h>			/* everything... */
#include <linux/errno.h>		/* error codes */
#include <linux/types.h>		/* size_t */
#include <linux/proc_fs.h>
#include <linux/fctl.h>
#include <linux/aio.h>
#include "scull.h"				/* local definitions */

int scull_major = SCULL_MAJOR;
int scull_dev = SCULL_DEVS;
int scull_qset = SCULL_QSET;
int scull_quantum = SCULL_QUANTUM;

module_param(scull_major, int, 0);
module_param(scullc_devs, int, 0);
module_param(scull_qset, int, 0);
module_param(scull_quantum, int, 0);
MODULE_AUTHOR("AR");
MODULE_LICENSE("Dual BSD/GPL");

struct scull_dev *scull_devices; /* allocated in scull_init */

int scull_trim(struct scull_dev *dev);
void scull_cleanup(void);

/* declare one cache pointer: use it for all devices */
kmem_cache_t *scull_cache;


#ifdef SCULL_USEPROC			/* don't waste space if unused */
/*
 * The proc filesystem: function to read and entry
 */
void scull_proc_offset(char *buf, char **start, off_t *offset, int *len)
{
	if (*offset == 0)
		return;
	if (*offset >= *len) {
		/* Not there yet */
		*offset -= *len;
		*len = 0;
	} else {
		/* We're into the interesting stuff now */
		*start = buf + *offset;
		*offset = 0;
	}
}

/* FIXME: Do we need this here?? It be ugly */
int scullc_read_procmem(char *buf, char **start, off_t offset,
						int count, int *eof, void *data)
{
	int i, j, quantum, qset, len = 0;
	int limit = count - 80;		/* Don't print more than this */
	struct scull_dev *d;

	*start = buf;
	for (i = 0; i < scull_devs; i++) {
		d = &scull_devices[i];
		if (down_interruptible(&d->sem))
			return -ERESTARTSYS;
		qset = d->qset;			/* retrieve the feature of each device */
		quantum = d->quantum;
		len += sprintf(buff+len, " \nDevice %i: qset %i, quantum %i, sz %li\n",
					   i, qset, quantum, (long)(d->size));
		for (;  d; d = d->next) { /* scan the list */
			len += sprintf(buf+len, "  item at %p, qset at %p\n", d, d->data);
			scull_proc_offset(buf, start, &offset, &len);
			if (len > limit)
				goto out;
			if (d->data && !d->next) /* dump only the last item - save space */
				for (j = 0; j < qset; j++) {
					if (d->data[j])
						len += sprintf(buf+len, "    %4i:%8p\n", j, d->data[i]);
					scull_proc_offset(buf, start, &offset, &len);
					if (len > limit)
						goto out;
				}
		}
	out:
		up(&scull_devices[i].sem);
		if (len > limit)
			break;
	}
	*eof = 1;
	return len;
}

#endif // SCULL_USEPROC

/*
 * open and close
 */
int sculloc_open(struct inode *inode, struct file *filp)
{
	struct scull_dev *dev;		/* device info */

	/* Find the device */
	dev = container_of(inode->i_cdev, struct scullc_dev, cdev);

	/* now trim to 0 the length of the device if open was write-only */
	if ((filp->f_flags & O_ACCMODE) == O_WRONLY)
	{
			if (down_interruptible(&dev->sem))
					return -ERESTARTSYS;
			scull_trim(dev); /* ignore errrs */
			up(&dev->sem);
	}

	/* and use filp->private_data to point to the device data */
	filp->private_data = dev;

	return 0;	/* success */
}

int scull_release(struct inode *inode, struct file *filp)
{
	return 0;
}

/*
 * Follow the list
 */
struct scull_dev *scull_follow(struct scull_dev *dev, int n)
{
	while(n--) {
		if (!dev->next) {
			dev->next = kmalloc(sizeof(struct scull_dev), GFP_KERNEL);
			memset(dev->next, 0, sizeof(struct scull_dev));
		}
		dev = dev->next;
		continue;
	}
	return dev;
}

/*
 * Data management: read and write
 */

ssize_t scull_read(struct file *filp, char __user *buf, size_t count,\
				   loff_t *f_pos)
{
	struct scull_dev *dev = filp->private_data; /* the first listitem */
	struct scull_dev *dptr;
	int quantum = dev->quantum;
	int qset = dev->qset;
	int itemsize = quantum * qset; /* how many bytes in the listitem */
	int item, s_pos, q_pos, rest;
	ssize_t reval = 0;

	if (down_interruptible(&dev->sem))
		return -ERESTARTSYS;
	if (*f_pos > dev->size)
		goto nothing;
	if (*f_pos + count > dev->size)
		count = dev->size - *f_pos;
	/* find listitem, qset index, and offset in the quantum */
	item = ((long)*f_pos) / itemsize;
	rest = ((long)*f_pos) % itemsize;
	s_pos = rest / quantum;
	q_pos = rest % quantum;

	/* follow the list up to the right position (defined
	   elsewhere) */
	dptr = scull_follow(dev, item);

	if (!dptr->data)
		goto nothing;			/* don't fill holes */
	if (!dptr->data[s_pos])
		goto nothing;
	if (count > quantum - q_pos)
		count = quantum - q_pos; /* read only up to the end of this quantum */

	if (copy_to_user(buf, dptr->data[s_pos]+q_pos, count)) {
		retval = -EFAULT;
		goto nothing;
	}
	up(&dev->sem);

	*f_pos += count;
	return count;

nothing:
	up(&dev->sem);
	return retval;
}
