#include <linux/init.h>
#include <linux/module.h>

int __init hello_init(void)
{
	printk(KERN_ALERT "HELLO KERNEL\n");
	return 0;
}

/* int parintMSG(int n) */
/* { */
/* 	int i; */
/* 	for (i = 0; i < n; i++) { */
/* 		printk(KERN_ALERT "I am balala balala"); */
/* 		return 0; */
/* 	} */
/* } */

void __exit hello_exit(void)
{
	printk(KERN_ALERT "byebye, HK\n");
	return;
}
//EXPORT_SYMBOL(printMSG);
module_init(hello_init);
module_exit(hello_exit);










