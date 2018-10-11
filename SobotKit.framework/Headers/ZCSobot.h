//
//  ZCSobot.h
//  SobotKit
//
//  Created by zhangxy on 15/11/12.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibCusMenu.h"
#import "ZCKitInfo.h"
#import "ZCLibInitInfo.h"
#import "ZCPlatformInfo.h"
#import "ZCUIBaseController.h"
#import "ZCLibClient.h"
#import "ZCChatController.h"
#import "ZCUIChatListController.h"
#import "ZCTopView.h"
#import "ZCChatView.h"

/**
 *  智齿SDK入口
 *  启动智齿客服 获取系统版本号 获取渠道名称
 */
@interface ZCSobot : NSObject




/**
 *
 *  启动智齿客服
 *
 *  @param info         初始化参数，详情见ZCLibInitInfo not null
 *  @param byController 当前执行跳转的VC           not null
 *  @param delegate     ZCUIChatDelagete        聊天页面的代理，如果实现这个代理用户可以实现留言跳转到自定义页面
 *  @param pageClick    点击返回，UI修改, object为ZCChatController（使用系统导航栏场景） 或者 ZCChatView（使用SDK自定义导航栏场景） 2.6.6 此处回调参数修改
 *  @param linkBlock    点击消息链接回调，可以为null(注意：如果传递实现后内部将直接返回url，不在做跳转处理)
 *
 */
+(void)startZCChatVC:(ZCKitInfo *) info
                with:(UIViewController *) byController
              target:(id<ZCChatControllerDelegate>) delegate
           pageBlock:(void (^)(id object,ZCPageBlockType type))pageClick
    messageLinkClick:(void (^)(NSString *link)) messagelinkBlock;




/**
 开启消息中心

 @param info 跳转时的样式
 @param byController 当前执行跳转的VC           not null
 @param itemClickBlock 自定义跳转,可以为null(注意：如果传递实现后内补不在做跳转处理)
    事例代码：
 [ZCSobot startZCChatListView:uiInfo with:self onItemClick:nil];
 或
 [ZCSobot startZCChatListView:uiInfo with:self onItemClick:^(ZCUIChatListController *object, ZCPlatformInfo *info) {
 [ZCSobot startZCChatVC:uiInfo with:object target:nil pageBlock:^(ZCChatController *object, ZCPageBlockType type) {
 
 } messageLinkClick:nil]; // 可以自己实现跳转
 }];
 */
+(void)startZCChatListView:(ZCKitInfo *)info with:(UIViewController *)byController onItemClick:(void (^)(ZCUIChatListController *object,ZCPlatformInfo *info))itemClickBlock;

/**
 *  获取SDK版本号
 *
 *  @return 版本号
 */
+(NSString *)getVersion;

/**
 *  获取渠道名称
 *
 *  @return 渠道
 */
+(NSString *)getChannel;

/**
 *  显示日志信息
 *
 *  @param isShowDebug 默认不显示
 */
+(void) setShowDebug:(BOOL) isShowDebug;

+(NSString *)getsystorm;

/**
 *
 *   获取当前app的版本号
 *
 **/
+(NSString *)getAppVersion;

/**
 *
 *  获取手机型号
 *
 **/
+(NSString *)getiphoneType;

/**
 *
 * 获取当前集成的app名称
 *
 **/
+(NSString *)getAppName;
@end
