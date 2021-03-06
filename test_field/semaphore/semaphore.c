#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/sched.h>
#include <linux/semaphore.h>

#define N 15

static unsigned count = 0, num = 0;
struct semaphore sem_2;
//DECLARE_SEMAPHORE(sem_1);
struct semaphore sem_1;

int thread_func1(void *context)
{
	char *tmp = (char *)context;

	while (num < N) {
		down(&sem_1);
		printk("<2>" "%s\tcount:%d\n", tmp, count++);
		num++;
		up(&sem_2);
	}

	return 0;
}

int thread_func2(void *context)
{
	char *tmp = (char *)context;
	while (num < N) {
		down(&sem_2);
		printk("<2>" "%s\tcount:%d\n", tmp, count--);
		num++;
		up(&sem_1);
	}

	return 0;
}

static __init int semaphore_init(void)
{
	char *ch1 = "This is FIRST thread!";
	char *ch2 = "This is SECOND thread!";
	sema_init(&sem_2, 0);
	sema_init(&sem_1, 0);

	EXPORT_SYMBOL_GPL(kernel_thread); 

	kernel_thread(thread_func1, ch1, CLONE_KERNEL);
	kernel_thread(thread_func2, ch2, CLONE_KERNEL);

	//kthread_run(thread_func1, ch1, CLONE_KERNEL);
	//kthread_run(thread_func2, ch2, CLONE_KERNEL);
}

static void semaphore_exit(void)
{
	return;
}

MODULE_AUTHOR("zzz");
MODULE_LICENSE("Dual BSD/GPL");

module_init(semaphore_init);
module_exit(semaphore_exit);
