#ifndef __VTDX_H__
#define __VTDX_H__

#define VTDX_CREATE_TD _IO ('v', 0)
#define VTDX_DESTROY_TD _IO ('v', 1)
#define VTDX_RUN_TD _IO ('v', 2)

static long create_vm(void);
static void run_vm(void);
static void destroy_vm(void);

#endif /* __VTDX_H__ */