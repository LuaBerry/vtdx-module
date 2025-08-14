#ifndef __VTDX_H__
#define __VTDX_H__

#define VTDX_GET_API_VERSION _IOR ('v', 0, int)
#define VTDX_CREATE_TD _IO ('v', 1)
#define VTDX_CHECK_EXTENSION _IO ('v', 2)
#define VTDX_GETVCPU_MMAP_SIZE _IO ('v', 3)
#define VTDX_GET_MSR_INDEX_LIST _IO ('v', 4)
#define VTDX_GET_SUPPORTED_CPUID _IO ('v', 5)
#define VTDX_GET_EMULATED_CPUID _IO ('v', 6)
#define VTDX_X86_GET_MCE_CAP_SUPPORTED _IO ('v', 7)
#define VTDX_GET_MSR_FEATURE_INDEX_LIST _IO ('v', 8)
#define VTDX_GET_MSRS _IO ('v', 9)
#define VTDX_GET_DEVICE_ATTR _IO ('v', 10)
#define VTDX_HAS_DEVICE_ATTR _IO ('v', 11)



struct vTD {
    struct kvm *vm;
    struct kvm_vcpu *vcpu;
};

static struct vTD* create_vTD(void);

#endif /* __VTDX_H__ */