#include <linux/sched.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init lkp_init(void)
{
	printk("<1>Hello, world! from the kernel space...\n");
	return 0;
}

static int print_pid(void)
{
	struct task_struct *task, *p;
	struct list_head *pos;
	int count = 0;
	printk("hello print pid begin: \n");
	task = &init_task;
	list_for_each(pos, &task->tasks) {
		p = list_entry(pos, struct task_struct, tasks);
		count++;
		printk("%d--->%s\n", p->pid, p->comm);
	}
	printk("The number of process is: %d\n", count);
	return 0;
}

static void __exit lkp_cleanup(void)
{
	printk("<1>Goodbye, World! leaving kernel space...\n");
	print_pid();
}

module_init(lkp_init);
module_exit(lkp_cleanup);
MODULE_LICENSE("GPL");
