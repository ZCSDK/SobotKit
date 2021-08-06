//
//  ZCServiceCentreVC.h
//  SobotKit
//
//  Created by lizhihui on 2019/3/27.
//  Copyright © 2019 zhichi. All rights reserved.
//

#import <SobotKit/SobotKit.h>

#import "ZCSobotApi.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZCServiceCentreVC : ZCUIBaseController

@property (nonatomic,assign) BOOL isPush;// 是否是push 进来的

// 留言代理
@property (nonatomic,assign) id<ZCChatControllerDelegate> chatdelegate;

@property(nonatomic,strong) void (^OpenZCSDKTypeBlock)(ZCUIBaseController *object);


@property(nonatomic,strong) ZCKitInfo *kitInfo;

/**
 *  初始化
 *
 *  @param info
 *
 *  @return ZCServiceCentreVC
 */
-(id)initWithInitInfo:(ZCKitInfo *)info;

@end

NS_ASSUME_NONNULL_END
