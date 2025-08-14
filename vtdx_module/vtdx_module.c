#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>

#include <linux/kvm_host.h>

#include "vtdx.h"

static int __init vtdx_init(void) {
    printk(KERN_INFO "VTDX Module Initialized.\n");
}

static void __exit vtdx_exit(void) {
    printk(KERN_INFO "VTDX Module Exit.\n");
}

static long vtdcall(int opcode) {
    switch (opcode) {
        case TDH_VP_ENTER_LEAF:
            printk(KERN_INFO "Handling TDH_VP_ENTER_LEAF\n");
            break;
        case TDH_MNG_ADDCX_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_ADDCX_LEAF\n");
            break;
        case TDH_MEM_PAGE_ADD_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_PAGE_ADD_LEAF\n");
            break;
        case TDH_MEM_SEPT_ADD_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_SEPT_ADD_LEAF\n");
            break;
        case TDH_VP_ADDCX_LEAF:
            printk(KERN_INFO "Handling TDH_VP_ADDCX_LEAF\n");
            break;
        case TDH_MEM_PAGE_RELOCATE:
            printk(KERN_INFO "Handling TDH_MEM_PAGE_RELOCATE\n");
            break;
        case TDH_MEM_PAGE_AUG_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_PAGE_AUG_LEAF\n");
            break;
        case TDH_MEM_RANGE_BLOCK_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_RANGE_BLOCK_LEAF\n");
            break;
        case TDH_MNG_KEY_CONFIG_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_KEY_CONFIG_LEAF\n");
            break;
        case TDH_MNG_CREATE_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_CREATE_LEAF\n");
            break;
        case TDH_VP_CREATE_LEAF:
            printk(KERN_INFO "Handling TDH_VP_CREATE_LEAF\n");
            break;
        case TDH_MNG_RD_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_RD_LEAF\n");
            break;
        case TDH_MEM_RD_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_RD_LEAF\n");
            break;
        case TDH_MNG_WR_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_WR_LEAF\n");
            break;
        case TDH_MEM_WR_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_WR_LEAF\n");
            break;
        case TDH_MEM_PAGE_DEMOTE_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_PAGE_DEMOTE_LEAF\n");
            break;
        case TDH_MR_EXTEND_LEAF:
            printk(KERN_INFO "Handling TDH_MR_EXTEND_LEAF\n");
            break;
        case TDH_MR_FINALIZE_LEAF:
            printk(KERN_INFO "Handling TDH_MR_FINALIZE_LEAF\n");
            break;
        case TDH_VP_FLUSH_LEAF:
            printk(KERN_INFO "Handling TDH_VP_FLUSH_LEAF\n");
            break;
        case TDH_MNG_VPFLUSHDONE_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_VPFLUSHDONE_LEAF\n");
            break;
        case TDH_MNG_KEY_FREEID_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_KEY_FREEID_LEAF\n");
            break;
        case TDH_MNG_INIT_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_INIT_LEAF\n");
            break;
        case TDH_VP_INIT_LEAF:
            printk(KERN_INFO "Handling TDH_VP_INIT_LEAF\n");
            break;
        case TDH_MEM_PAGE_PROMOTE_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_PAGE_PROMOTE_LEAF\n");
            break;
        case TDH_PHYMEM_PAGE_RDMD_LEAF:
            printk(KERN_INFO "Handling TDH_PHYMEM_PAGE_RDMD_LEAF\n");
            break;
        case TDH_MEM_SEPT_RD_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_SEPT_RD_LEAF\n");
            break;
        case TDH_VP_RD_LEAF:
            printk(KERN_INFO "Handling TDH_VP_RD_LEAF\n");
            break;
        case TDH_MNG_KEY_RECLAIMID_LEAF:
            printk(KERN_INFO "Handling TDH_MNG_KEY_RECLAIMID_LEAF\n");
            break;
        case TDH_PHYMEM_PAGE_RECLAIM_LEAF:
            printk(KERN_INFO "Handling TDH_PHYMEM_PAGE_RECLAIM_LEAF\n");
            break;
        case TDH_MEM_PAGE_REMOVE_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_PAGE_REMOVE_LEAF\n");
            break;
        case TDH_MEM_SEPT_REMOVE_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_SEPT_REMOVE_LEAF\n");
            break;
        case TDH_SYS_KEY_CONFIG_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_KEY_CONFIG_LEAF\n");
            break;
        case TDH_SYS_INFO_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_INFO_LEAF\n");
            break;
        case TDH_SYS_INIT_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_INIT_LEAF\n");
            break;
        case TDH_SYS_RD_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_RD_LEAF\n");
            break;
        case TDH_SYS_LP_INIT_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_LP_INIT_LEAF\n");
            break;
        case TDH_SYS_TDMR_INIT_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_TDMR_INIT_LEAF\n");
            break;
        case TDH_SYS_RDALL_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_RDALL_LEAF\n");
            break;
        case TDH_MEM_TRACK_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_TRACK_LEAF\n");
            break;
        case TDH_MEM_RANGE_UNBLOCK_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_RANGE_UNBLOCK_LEAF\n");
            break;
        case TDH_PHYMEM_CACHE_WB_LEAF:
            printk(KERN_INFO "Handling TDH_PHYMEM_CACHE_WB_LEAF\n");
            break;
        case TDH_PHYMEM_PAGE_WBINVD_LEAF:
            printk(KERN_INFO "Handling TDH_PHYMEM_PAGE_WBINVD_LEAF\n");
            break;
        case TDH_MEM_SEPT_WR_LEAF:
            printk(KERN_INFO "Handling TDH_MEM_SEPT_WR_LEAF\n");
            break;
        case TDH_VP_WR_LEAF:
            printk(KERN_INFO "Handling TDH_VP_WR_LEAF\n");
            break;
        case TDH_SYS_LP_SHUTDOWN_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_LP_SHUTDOWN_LEAF\n");
            break;
        case TDH_SYS_CONFIG_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_CONFIG_LEAF\n");
            break;
        case TDH_SERVTD_BIND_LEAF:
            printk(KERN_INFO "Handling TDH_SERVTD_BIND_LEAF\n");
            break;
        case TDH_SERVTD_PREBIND_LEAF:
            printk(KERN_INFO "Handling TDH_SERVTD_PREBIND_LEAF\n");
            break;
        case TDH_SYS_SHUTDOWN_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_SHUTDOWN_LEAF\n");
            break;
        case TDH_SYS_UPDATE_LEAF:
            printk(KERN_INFO "Handling TDH_SYS_UPDATE_LEAF\n");
            break;
        case TDH_EXPORT_ABORT_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_ABORT_LEAF\n");
            break;
        case TDH_EXPORT_BLOCKW_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_BLOCKW_LEAF\n");
            break;
        case TDH_EXPORT_RESTORE_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_RESTORE_LEAF\n");
            break;
        case TDH_EXPORT_MEM_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_MEM_LEAF\n");
            break;
        case TDH_EXPORT_PAUSE_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_PAUSE_LEAF\n");
            break;
        case TDH_EXPORT_TRACK_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_TRACK_LEAF\n");
            break;
        case TDH_EXPORT_STATE_IMMUTABLE_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_STATE_IMMUTABLE_LEAF\n");
            break;
        case TDH_EXPORT_STATE_TD_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_STATE_TD_LEAF\n");
            break;
        case TDH_EXPORT_STATE_VP_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_STATE_VP_LEAF\n");
            break;
        case TDH_EXPORT_UNBLOCKW_LEAF:
            printk(KERN_INFO "Handling TDH_EXPORT_UNBLOCKW_LEAF\n");
            break;
        case TDH_IMPORT_ABORT_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_ABORT_LEAF\n");
            break;
        case TDH_IMPORT_END_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_END_LEAF\n");
            break;
        case TDH_IMPORT_COMMIT_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_COMMIT_LEAF\n");
            break;
        case TDH_IMPORT_MEM_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_MEM_LEAF\n");
            break;
        case TDH_IMPORT_TRACK_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_TRACK_LEAF\n");
            break;
        case TDH_IMPORT_STATE_IMMUTABLE_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_STATE_IMMUTABLE_LEAF\n");
            break;
        case TDH_IMPORT_STATE_TD_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_STATE_TD_LEAF\n");
            break;
        case TDH_IMPORT_STATE_VP_LEAF:
            printk(KERN_INFO "Handling TDH_IMPORT_STATE_VP_LEAF\n");
            break;
        case TDH_MIG_STREAM_CREATE_LEAF:
            printk(KERN_INFO "Handling TDH_MIG_STREAM_CREATE_LEAF\n");
            break;
        case default:
            printk(KERN_ERR "Unknown opcode: %d\n", opcode);
            return -EINVAL;
    }
    return 0;
}

EXTERN_SYMBOL(vtdcall);



module_init(vtdx_init);
module_exit(vtdx_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("lua1012");
MODULE_DESCRIPTION("A virtual TDX module.");
