//
//  ZCUIChatListController.h
//  SobotKit
//
//  Created by zhangxy on 2017/9/5.
//  Copyright © 2017年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZCUIBaseController.h"
#import "ZCPlatformInfo.h"
#import "ZCKitInfo.h"

@interface ZCUIChatListController : ZCUIBaseController

@property(nonatomic,strong) ZCKitInfo *kitInfo;


@property(nonatomic,strong) void (^OnItemClickBlock)(ZCUIChatListController *vc,ZCPlatformInfo *object);

@end
