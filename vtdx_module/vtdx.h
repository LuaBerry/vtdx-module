#ifndef __VTDX_H__
#define __VTDX_H__

#define VTDX_CREATE_TD _IO ('v', 0)
#define VTDX_DESTROY_TD _IO ('v', 1)
#define VTDX_RUN_TD _IO ('v', 2)

struct vTD {
    struct kvm *vm;
    struct kvm_vcpu *vcpu;
};

static struct vTD* create_vTD(void);
static void run_vm(void);
static void destroy_vm(void);

#endif /* __VTDX_H__ */