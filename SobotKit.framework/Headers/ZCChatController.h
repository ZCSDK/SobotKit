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

@interface ZCChatController : UIViewController

@property (nonatomic,assign) BOOL isPush;// 是否是push 进来的

@property (nonatomic,strong) ZCChatView * chatView;

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
