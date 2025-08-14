#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>

#include <linux/kvm_host.h>

#include "vtdx.h"

static long vtd_ioctl(struct file *flip,
        unsigned int ioctl, unsigned long arg) {
    switch (ioctl) {
        case VTDX_GET_API_VERSION:
            printk(KERN_INFO "Get API version.\n");
        case VTDX_CREATE_TD: // Example command
            create_vTD();
            printk(KERN_INFO "Create TD.\n");
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

static struct vTD* create_vTD(void) {
    struct vTD *vtd;
    int ret;

    vtd = kmalloc(sizeof(struct vTD), GFP_KERNEL);
    if (!vtd) {
        printk(KERN_ERR "Failed to allocate memory for vTD\n");
        return -ENOMEM;
    }
    kvm_get_kvm(vtd->vm);
    if (IS_ERR(vtd->vm)) {
        printk(KERN_ERR "Failed to create VM\n");
        kfree(vtd);
        return PTR_ERR(vtd->vm);
    }
    kvm_get_vcpu(vtd->vm, 0);
    if (IS_ERR(vtd->vcpu)) {
        printk(KERN_ERR "Failed to create VCPU\n");
        kvm_put_kvm(vtd->vm);
        kfree(vtd);
        return PTR_ERR(vtd->vcpu);
    }
    printk(KERN_INFO "Virtual TD created successfully.\n");
    return vtd;
}



module_init(vtdx_init);
module_exit(vtdx_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lua1012");
MODULE_DESCRIPTION("A virtual TDX module.");
