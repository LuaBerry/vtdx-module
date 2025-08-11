#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void) {
    printk(KERN_INFO "Hello, kernel module!\n");
    return misc_register(&vtdx_dev);
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, kernel module!\n");
    misc_deregister(&vtdx_dev);
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Lua");
MODULE_DESCRIPTION("A simple Linux kernel module.");
