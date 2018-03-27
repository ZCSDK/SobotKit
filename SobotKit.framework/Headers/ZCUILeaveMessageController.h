//
//  ZCUILeaveMessageController.h
//  SobotKit
//
//  Created by lizhihui on 16/1/21.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <SobotKit/SobotKit.h>
#import "ZCOrderModel.h"

/**
 *  ZCUILeaveMessageController 留言VC
 */
@interface ZCUILeaveMessageController : ZCUIBaseController

@property (nonatomic,strong) ZCOrderModel * model;

@property (nonatomic,assign) BOOL             isExitSDK;
@property (nonatomic,assign) BOOL             isNavOpen;

@property (nonatomic,strong) UIViewController *backVC;

@property (nonatomic,assign) NSInteger        exitType;

/**  是否显示排队人数已满*/
@property (nonatomic,assign) BOOL             isShowToat;

@property (nonatomic,strong) NSString         *tipMsg;
// 直接退出SDK 并关闭技能组弹框
-(void)setCloseBlock:(void (^)())closeBlock;
@end
