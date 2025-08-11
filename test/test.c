#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "../vtdx_module/vtdx.h"

int main() {
    int fd = open("/dev/vtdx", O_RDWR);
    if (fd < 0) {
        perror("Failed to open /dev/vtdx");
        return -1;
    }

    ioctl(fd, VTDX_CREATE_TD, 0);
    ioctl(fd, VTDX_RUN_TD, 0);
    ioctl(fd, VTDX_DESTROY_TD, 0);
    close(fd);
    
    return 0;
}