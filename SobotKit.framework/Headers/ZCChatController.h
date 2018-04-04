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


@protocol ZCChatControllerDelegate <NSObject>

@optional

// 跳转留言
-(void)openLeaveMsgClick:(NSString*)tipMsg;// 点击留言跳转到用户自己留言页面，SDK 不在处理留言
@end

@interface ZCChatController : UIViewController

@property(nonatomic,strong) ZCKitInfo *info;

@property(nonatomic,assign) BOOL isNoPush;// 是否是push
/**
 *  初始化
 *
 *  @param info
 *
 *  @return ZCUIChatController
 */
-(id)initWithInitInfo:(ZCKitInfo *)info;

@property (nonatomic,assign) id<ZCChatControllerDelegate> chatdelegate;

/**
 *  点击返回后的回调（注意：实现此方法后，sdk不自动实现返回事件）
 *
 *  @param backBlock
 */
-(void)setPageBlock:(void (^)(ZCChatController *object,ZCPageBlockType type))pageClick messageLinkClick:(void (^)(NSString *link)) linkBlock;

@end
