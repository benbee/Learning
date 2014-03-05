local_irq_disable(); /* 屏蔽中断 */
....
critical section   /* 临界区 */
....
local_irq_enable(); /* 开中断 */

/*-----------------------------*/

static atomic_t xxx_available = ATOMIC_INIT(1); /* 定义原子变量 */

static int xxx_open(struct inode *inode, struct file *filp)
{
	...
	if (!atomic_dec_and_test(&xxx_available)) {
		atomic_inc(&xxx_available);
		return - EBUSY;	/* 已经打开 */
	}
	...
	return 0; /* 成功 */
}

static int xxx_release(struct inode *inode, struct file *filep)
{
	atomic_inc(&xx_available);
	return 0;
}

/*-----------------------------*/

/* define one spinlock */
spinlock_t lock;
spin_lock_init(&lock);

spin_lock(&lock);	/* 获取自旋锁，保护临界区 */
...		/* 临界区 */
spin_unlock(&lock);	/* 解锁 */

/*-----------------------------*/

int xxx_count = 0; 				/* 定义文件打开次数计数 */

static int xxx_open(struct inode *inode, struct file *filp)
{
	...
	spinlock(&xxx_lock);
	if (xxx_count) {			/* already open */
		spin_unlock(&xxx_lock);
		return -EBUSY;
	}
	xxx_count++;				/* increase count */
	spin_unlock(&xxx_lock);
	...
	return 0;					/* success */
}

static int xxx_release(struct inode *inode , struct file *filp)
{
	...
	spinlock(&xxx_lock);
	xxx_count--;				/* decrease count */
	spin_unlock(&xxx_lock);

	return 0;
}

/*-----------------------------*/

rwlock_t lock;					/* define rwlock */
rwlock_init(&lock);				/* init rwlock */

/* get lock when need to read */
read_lock(&lock);
...								/* critical section */
read_unlock(&lock);

/* get lock when need to write */
write_lock_irqsave(&lock, flags);
... 							/* critical section */
write_unlock_irqsave(&lock, flags);

/*-----------------------------*/

/* define mutex */
DELCARE_MUTEX(mount_sem);
down(&mount_sem);				/* get mutes, protect critical section */
...
/* critical section */
...
up(&mount_sem);

/* exp */
static DECLARE_MUTEX(xxx_lock);

static int xxx_open(struct inode *inode, struct file *filp)
{
	...
	if (down_trylock(&xxx_lock)) { /* get lock; if get lock return 0 */
		return - EBUSY;			   /* device busy */
	}
	...
	return 0; 					/* success */
}

static int xxx_release(struct inode *inode, struct file *filp)
{
	up(&xxx_lock);				/* release lock */
	return 0;
}
