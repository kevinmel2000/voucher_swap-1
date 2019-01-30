//
//  ViewController.m
//  voucher_swap
//
//  Created by Brandon Azad on 12/7/18.
//  Copyright © 2018 Brandon Azad. All rights reserved.
//

#import "ViewController.h"
#import "kernel_memory.h"

@interface ViewController ()
@property (weak, nonatomic) IBOutlet UILabel *tfp0_label;

@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
    _tfp0_label.text = [NSString stringWithFormat:@"tfp0: %u", kernel_task_port];
}


@end
