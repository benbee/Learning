#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xafb4eeef, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x15692c87, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x29ce1880, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xcc02930f, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xf5bdeb4f, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0xfc9d2c7d, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x8fa6a20e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd8e484f0, __VMLINUX_SYMBOL_STR(register_chrdev_region) },
	{ 0x71de9b3f, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x71e3cecb, __VMLINUX_SYMBOL_STR(up) },
	{ 0x77e2f33, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x9f6b4c62, __VMLINUX_SYMBOL_STR(down_interruptible) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "FDB2845502753860DA5EB6B");
