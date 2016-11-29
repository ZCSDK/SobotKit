//
//  ZCLibClient.h
//  SobotKit
//
//  Created by zhangxy on 2016/10/19.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ZCKitInfo.h"

@interface ZCLibClient : NSObject

// 同ZCKitInfo中的配置有同等效力，不会覆盖
@property (nonatomic,strong) id<ZCReceivedMessageDelegate> delegate;
// block方式配置
@property (nonatomic,strong) ReceivedMessageBlock          receivedBlock;


+(ZCLibClient *) getZCLibClient;



/**
 初始化智齿客服，会建立长连接通道，监听服务端消息（建议启动应用时调用，没有发起过咨询不会浪费资源,至少转一次人工才有效果）
 */
-(void)initZCIMCaht;



/**
 关闭通道，清理内存，退出智齿客户
 说明：调用此方法后将不能接收到离线消息，除非再次进入智齿SDK重新激活
 */
+(void) closeAndoutZCServer;


@end
