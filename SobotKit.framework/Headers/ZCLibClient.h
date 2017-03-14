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
/**
 推送的token
 每次启动应用都需要重新设置
 */
@property (nonatomic,strong) NSData     *token;

/**
 appkey，应用的唯一标识
 */
@property (nonatomic,strong) NSString   *appKey;


/**
 推送的用户Id
 与ZCLibInitInfo.h中的字段统一，取消推送的关键参数
 */
@property (nonatomic,strong) NSString   *userId;



/**
 测试模式，
 根据此设置调用的推送证书，默认NO
 NO ,调用生产环境
 YES，测试环境
 */
@property (nonatomic,assign) BOOL isDebugMode;


/**
 自动提醒消息
 说明：如果开启自动提醒消息，当没有在智齿聊天页面的时候，都会主动把消息作为本地通知展示
 */
@property (nonatomic,assign) BOOL autoNotification;


////////////////////////////////////////////////////////////////////////


// 同ZCKitInfo中的配置有同等效力，不会覆盖
@property (nonatomic,strong) id<ZCReceivedMessageDelegate> delegate;
// block方式配置
@property (nonatomic,strong) ReceivedMessageBlock          receivedBlock;


+(ZCLibClient *) getZCLibClient;


/**
 获取未读消息数

 @return 未读消息数(进入智齿聊天页面会清空)
 */
-(int) getUnReadMessage;


/**
 初始化智齿客服，会建立长连接通道，监听服务端消息
 （建议启动应用时调用，没有发起过咨询不会浪费资源,至少转一次人工才有效果）
 */
-(void)initZCIMCaht;



/**
 移除消息推送
 退出账号时，切记移除消息推送
 uid，根据传入的userId生成的唯一标识，token，当前推送的token，error退出错误
 error为nil说明成功(如果token和uid都是空不会调用)
 */
-(void)removePush:(void (^)(NSString *uid, NSData *token,NSError *error))resultBlock;


/**
 关闭通道，清理内存，退出智齿客服
 说明：调用此方法后将不能接收到离线消息，除非再次进入智齿SDK重新激活
 */
+(void) closeAndoutZCServer;



@end
