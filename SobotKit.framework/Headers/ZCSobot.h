//
//  ZCSobot.h
//  SobotKit
//
//  Created by zhangxy on 15/11/12.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCKitInfo.h"
#import "ZCLibInitInfo.h"
#import "ZCUIChatController.h"
#import "ZCLibClient.h"

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
 *  @param pageClick    点击返回，UI修改,object为当前
 *  @param linkBlock    点击消息链接回调，可以为null(注意：如果传递实现后内部将直接返回url，不在做跳转处理)
 */
+(void)startZCChatView:(ZCKitInfo *) info
                  with:(UIViewController *) byController
             pageBlock:(void (^)(ZCUIChatController *object,ZCPageBlockType type))pageClick
      messageLinkClick:(void (^)(NSString *link)) messagelinkBlock;

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


@end
