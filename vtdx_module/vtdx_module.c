#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/ioctl.h>

#include "vtdx.h"

static long vtd_ioctl(struct file *flip,
        unsigned int ioctl, unsigned long arg) {
    switch (ioctl) {
        case VTDX_CREATE_TD: // Example command
            create_vm();
            printk(KERN_INFO "Create TD.\n");
            return 0;
        case VTDX_DESTROY_TD:
            destroy_vm();
            printk(KERN_INFO "Destroy TD.\n");
            return 0;
        case VTDX_RUN_TD:
            run_vm();
            printk(KERN_INFO "Run TD.\n");
            return 0;
        default:
            return -EINVAL; // Invalid argument
    }
}

static struct file_operations vtd_chardev_ops = {
    .owner = THIS_MODULE,
    .unlocked_ioctl = vtd_ioctl
};

static struct miscdevice vtdx_dev = {
    .minor = MISC_DYNAMIC_MINOR, // Dynamic minor number
    .name = "vtdx", // Device name
    .fops = &vtd_chardev_ops, // File operations
    .mode = 0666, // Permissions
};

static int __init vtdx_init(void) {
    printk(KERN_INFO "VTDX Module Initialized.\n");
    return misc_register(&vtdx_dev);
}

static void __exit vtdx_exit(void) {
    printk(KERN_INFO "VTDX Module Exit.\n");
    misc_deregister(&vtdx_dev);
}

static long create_vm(void) {
    // Arbitrary logic to create a VM
    /*
    long kvm_fd = open("/dev/kvm", O_RDWR);
    if (kvm_fd < 0) {
        printk(KERN_ERR "Failed to open /dev/kvm\n");
        return -1;
    }
    long vm_fd = ioctl(kvm_fd, KVM_CREATE_VM, 0);
    if (vm_fd < 0) {
        printk(KERN_ERR "Failed to create VM\n");
        return -1;
    }
    return vm_fd;
    */
    return 0; // Placeholder
}

static void run_vm(void) {
    // Placeholder for VM running logic
}

static void destroy_vm(void) {
    // Placeholder for VM destruction logic
}



module_init(vtdx_init);
module_exit(vtdx_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lua1012");
MODULE_DESCRIPTION("A virtual TDX module.");
