//
//  ZCChatController.h
//  SobotKit
//
//  Created by zhangxy on 2018/1/29.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZCKitInfo.h"
#import "ZCUIBaseController.h"
#import "ZCChatView.h"

@protocol ZCChatControllerDelegate <NSObject>

@optional

/**
 点击留言跳转到用户自己留言页面，SDK将不在处理留言
 @param tipMsg 提示语
 */
-(void)openLeaveMsgClick:(NSString*)tipMsg;

@end

@interface ZCChatController : ZCUIBaseController

@property (nonatomic,assign) BOOL isPush;// 是否是push 进来的
@property (nonatomic,strong) ZCTitleView *titleView;



/**
 *  初始化
 *
 *  @param info
 *
 *  @return ZCUIChatController
 */
-(id)initWithInitInfo:(ZCKitInfo *)info;


// 留言代理
@property (nonatomic,assign) id<ZCChatControllerDelegate> chatdelegate;

@end
