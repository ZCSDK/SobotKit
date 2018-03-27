//
//  ZCChatController.h
//  SobotKit
//
//  Created by zhangxy on 2018/1/29.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZCKitInfo.h"



@protocol ZCChatControllerDelegate <NSObject>

@optional

// 跳转留言
-(void)openLeaveMsgClick:(NSString*)tipMsg;// 点击留言跳转到用户自己留言页面，SDK 不在处理留言
@end

@interface ZCChatController : UIViewController

@property(nonatomic,strong) ZCKitInfo *info;

/**
 *  初始化
 *
 *  @param info
 *
 *  @return ZCUIChatController
 */
-(id)initWithInitInfo:(ZCKitInfo *)info;

@property (nonatomic,assign) id<ZCChatControllerDelegate> chatdelegate;



@end
