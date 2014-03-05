	obj-m:=hello_mod.o

KERNELDIR:=/lib/modules/$(shell uname -r)/build
PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

install:
	$(shell sudo insmod ./hello_mod.ko)
