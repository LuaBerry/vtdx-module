#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0xd408da62, "misc_deregister" },
	{ 0xbd03ed67, "random_kmalloc_seed" },
	{ 0xa62b1cc9, "kmalloc_caches" },
	{ 0xd1f07d8f, "__kmalloc_cache_noprof" },
	{ 0x10e30605, "kvm_get_kvm" },
	{ 0x97c20d46, "xa_load" },
	{ 0xcb8b6ec6, "kfree" },
	{ 0x10e30605, "kvm_put_kvm" },
	{ 0xd272d446, "__fentry__" },
	{ 0xe8213e80, "_printk" },
	{ 0x88fafe6b, "misc_register" },
	{ 0xab006604, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0xd272d446,
	0xd408da62,
	0xbd03ed67,
	0xa62b1cc9,
	0xd1f07d8f,
	0x10e30605,
	0x97c20d46,
	0xcb8b6ec6,
	0x10e30605,
	0xd272d446,
	0xe8213e80,
	0x88fafe6b,
	0xab006604,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"__x86_return_thunk\0"
	"misc_deregister\0"
	"random_kmalloc_seed\0"
	"kmalloc_caches\0"
	"__kmalloc_cache_noprof\0"
	"kvm_get_kvm\0"
	"xa_load\0"
	"kfree\0"
	"kvm_put_kvm\0"
	"__fentry__\0"
	"_printk\0"
	"misc_register\0"
	"module_layout\0"
;

MODULE_INFO(depends, "kvm");


MODULE_INFO(srcversion, "DAADC4AE3540BD1FA594BB7");
