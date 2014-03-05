/* globalmem: a simple linux char device driver */

#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/io.h>
//#include <asm/system.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

#define GLOBALMEM_SIZE 0x100	/* globalmem max size 4K */
#define MEM_CLEAR 0x1			/* clear globalmem */
#define GLOBALMEM_MAJOR 521

static int globalmem_major = GLOBALMEM_MAJOR;

/* globalmem struct */
struct globalmem_dev {
	struct cdev cdev;
	unsigned char mem[GLOBALMEM_SIZE];
};

struct globalmem_dev *globalmem_devp; /* device struct pointer */

/* file open operation */
int globalmem_open(struct inode *inode, struct file *filep)
{
	filep->private_data = globalmem_devp;
	return 0;
}

/* release file operation */
int globalmem_release(struct inode *inode, struct file *filep)
{
	return 0;
}

/* ioctl function */
static int globalmem_ioctl(struct inode *inode, struct file *filep,
						   unsigned int cmd, unsigned long arg)
{
	struct globalmem_dev *dev = filep->private_data;
	
	switch (cmd) {
	case MEM_CLEAR:
		memset(dev->mem, 0, GLOBALMEM_SIZE);
		printk(KERN_INFO "GLOBALMEM is set to zero...\n");
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

/* read function */
static ssize_t globalmem_read(struct file *filep, char __user *buf,
							  size_t size, loff_t *ppos)
{
	unsigned long p = *ppos;
	unsigned long int count = size;
	int ret = 0;				/* return value? */
	struct globalmem_dev *dev = filep->private_data; /* get device
													  struct pointer*/
	/* make sure to get the vaild value */
	if (p >= GLOBALMEM_SIZE)
		return 0;
	if(count > GLOBALMEM_SIZE)
		count = GLOBALMEM_SIZE - p;

	/* kernel space -> user space */
	if (copy_to_user(buf, (void *)(dev->mem + p), count)) {
		ret = -EINVAL;
	} else {
		*ppos += count;
		ret = count;

		printk(KERN_INFO "READ %u bytes from %lu...\n", count, p);
	}

	return ret;
}

/* write function */
static ssize_t globalmem_write(struct file *filep, const char __user *buf,
							   size_t size, loff_t *ppos)
{
	unsigned long p = *ppos;
	unsigned int count = size;
	int ret = 0;
	struct globalmem_dev *dev = filep->private_data;

	if (p >= GLOBALMEM_SIZE)
		return 0;
	if (count > GLOBALMEM_SIZE)
		count = GLOBALMEM_SIZE - p;

	if (copy_from_user(dev->mem + p, buf, count)) {
		ret = -EFAULT;
	} else {
		*ppos += count;
		ret = count;
		printk(KERN_INFO "WRITTEN %u byte(s) from %lu", count, p);
	}

	return ret;
}

/* seek function */
static loff_t globalmem_llseek(struct file *filep, loff_t offset, int orig)
{
	loff_t ret = 0;
	switch (orig) {
	case 0:						/* the start position of file */
		if (offset < 0) {
			ret = -EINVAL;
			break;
		}
		if ((unsigned int)offset > GLOBALMEM_SIZE) {
			ret = -EINVAL;
			break;
		}
		filep->f_pos = (unsigned int)offset;
		ret = filep->f_pos;
		break;
	case 1:						/* current positon */
		if (offset < 0) {
			ret = -EINVAL;
			break;
		}
		if ((unsigned int)offset > GLOBALMEM_SIZE) {
			ret = -EINVAL;
			break;
		}
		filep->f_pos += (unsigned int)offset;
		ret = filep->f_pos;
		break;
	default:
		ret = -EINVAL;
		break;
	}

	return ret;
}

/* file_operation structure */
static const struct file_operations globalmem_fops = {
	.owner = THIS_MODULE,
	.llseek = globalmem_llseek,
	.read = globalmem_read,
	.write = globalmem_write,
	//.ioctl = globalmem_ioctl,
	.open = globalmem_open,
	.release = globalmem_release,
};

/* init and register cdev */
static void globalmem_setup_cdev(struct globalmem_dev *dev, int index)
{
	int err, devno = MKDEV(globalmem_major, index);

	cdev_init(&dev->cdev, &globalmem_fops);
	dev->cdev.owner = THIS_MODULE;
	err = cdev_add(&dev->cdev, devno, 1);
	if (err)
		printk(KERN_NOTICE "Error %d adding globalmem %d", err, index);
}

/* module init */
int globalmem_init(void)
{
	int result;
	dev_t devno = MKDEV(globalmem_major, 0);

	/* alloc device no */
	if (globalmem_major)
		result = register_chrdev_region(devno, 1, "globalmem");
	else {						/* alloc device no dynamiclly */
		result = alloc_chrdev_region(&devno, 0, 1, "globalmem");
		globalmem_major = MAJOR(devno);
	}
	if (result < 0)
		return result;

	/* alloc structure memory */
	globalmem_devp = kmalloc(sizeof(struct globalmem_dev), GFP_KERNEL);
	if (!globalmem_devp) {		/* alloc fault */
		result = -ENOMEM;
		goto fail_malloc;
	}

	memset(globalmem_devp, 0, sizeof(struct globalmem_dev));

	globalmem_setup_cdev(globalmem_devp, 0);
	return 0;

fail_malloc:
	unregister_chrdev_region(devno, 1);
	return result;
}

/* unload driver module */
void globalmem_exit(void)
{
	cdev_del(&globalmem_devp->cdev); /* unregister cdev */
	kfree(globalmem_devp);			 /* release structure memory */
	unregister_chrdev_region(MKDEV(globalmem_major, 0), 1);
	/* release device number */
}

MODULE_AUTHOR("zzz");
MODULE_LICENSE("Dual BSD/GPL");

module_param(globalmem_major, int, S_IRUGO);

module_init(globalmem_init);
module_exit(globalmem_exit);
