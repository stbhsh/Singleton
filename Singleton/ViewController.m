//
//  ViewController.m
//  Singleton
//
//  Created by cwwmac01 on 16/5/19.
//  Copyright © 2016年 朗泰恒盛. All rights reserved.
//

#import "ViewController.h"
#import "MySingleton.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    MySingleton * singleton = [MySingleton shareInstance];
    
    MySingleton * singleton1 = [[MySingleton alloc] init];
    
    MySingleton * singleton2 = [singleton mutableCopy];
    
    MySingleton * singleton3 = [singleton1 copy];
    
    NSLog(@"%@",singleton);
    NSLog(@"%@",singleton1);
    NSLog(@"%@",singleton2);
    NSLog(@"%@",singleton3);

}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
