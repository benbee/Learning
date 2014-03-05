// main.c -- the bare scullc char module


#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/kernel.h>       /* printk() */
#include <linux/slab.h>         /* kmalloc() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/aio.h>
#include <asm/uaccess.h>
#include "scullc.h"             /* local definitions */

int scullc_major = SCULLC_MAJOR;
int scullc_dev = SCULLC_DEV;
int scullc_qset = SCULLC_QSET;
int scullc_quantum = SCULLC_QUANTUM;

module_param(scullc_major, int, 0);
module_param(scullc_devs, int, 0);
module_param(scullc_qset, int, 0);
module_param(scullc_quantum, int, 0);
MODULE_AUTHOR("zzz");
MODULE_LICENSE("Dual BSD/GPL");
