#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static char *test_name = "just a test by habwtl";
static int num = 2000;

static int test_init(void)
{
	printk(KERN_INFO "What's happenning: %s\n", test_name);
	printk(KERN_INFO "Number: %d", num);
	return 0;
}

static void test_exit(void)
{
	printk(KERN_ALERT "param test module exited\n");
}

module_init(test_init);
module_exit(test_exit);
module_param(num, int, S_IRUGO);
module_param(test_name, charp, S_IRUGO);

MODULE_AUTHOR("habtwl, habwtl@gmail.com");
MODULE_DESCRIPTION("A param test module");
MODULE_VERSION("v0.1");
