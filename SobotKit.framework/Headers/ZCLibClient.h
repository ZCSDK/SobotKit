//
//  ZCLibClient.h
//  SobotKit
//
//  Created by zhangxy on 2016/10/19.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibInitInfo.h"


////////////////////////////////////////////////////////////////
// 自定义回调）
////////////////////////////////////////////////////////////////


/**
 *
 *  消息回调
 *
 */
@protocol ZCReceivedMessageDelegate <NSObject>

//未读消息数获取
-(void)onReceivedMessage:(id) message unRead:(int) nleft;

@end

/**
 *  未读消息数，block方式获取
 *
 *  @param message 当前消息
 *  @param nleft   未读消息数
 */
typedef void(^ReceivedMessageBlock)(id message,int nleft);






/**
 初始化配置类
 */
@interface ZCLibClient : NSObject

/**
 推送的token
 每次启动应用都需要重新设置
 */
@property (nonatomic,strong) NSData     *token;



#pragma mark ---  原 appKey  userId  2.1.0之前的版本使用，之后的版本使用 ZCLibInitInfo中的参数
/**
 appkey，应用的唯一标识
 */
//@property (nonatomic,strong) NSString   *appKey;


/**
 推送的用户Id
 与ZCLibInitInfo.h中的字段统一，取消推送的关键参数
 */
//@property (nonatomic,strong) NSString   *userId;


@property (nonatomic,strong) ZCLibInitInfo *libInitInfo;

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


/**
 *  记录当前是否可以显示转人工按钮（记录机器人未知回复的次数已达到，在一次有效的会话中）
 *
 */
@property (nonatomic,assign) BOOL isShowTurnBtn;


////////////////////////////////////////////////////////////////////////


// 同ZCKitInfo中的配置有同等效力，不会覆盖
@property (nonatomic,strong) id<ZCReceivedMessageDelegate> delegate;
// block方式配置
@property (nonatomic,strong) ReceivedMessageBlock          receivedBlock;


+(ZCLibClient *) getZCLibClient;


/**
 添加异常统计
 */
+(void)setZCLibUncaughtExceptionHandler;

/**
 获取未读消息数

 @return 未读消息数(进入智齿聊天页面会清空)
 */
-(int) getUnReadMessage;


/**
 初始化智齿客服，会建立长连接通道，监听服务端消息
 检查如果断开就重新连接
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
 关闭通道，清理内存，退出智齿客户
 说明：调用此方法后将不能接收到离线消息，除非再次进入智齿SDK重新激活,
 isClosePush:YES ,是关闭push；NO离线用户，但是可以收到push推送
 */
+(void) closeAndoutZCServer:(BOOL) isClosePush;




@end
