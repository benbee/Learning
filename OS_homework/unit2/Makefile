obj-m := print_pid.o
CURREN_PATH:=$(shell pwd)
LINUX_KERNEL:=$(shell uname -r)
LINUX_KERNEL_PATH:=/usr/src/linux-headers-$(LINUX_KERNEL)

all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURREN_PATH) modules

clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURREN_PATH) clean
