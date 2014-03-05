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
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x68aca4ad, __VMLINUX_SYMBOL_STR(down) },
	{ 0x71e3cecb, __VMLINUX_SYMBOL_STR(up) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "82F9D11855F65315A200D2D");
