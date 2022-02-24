//
//  ZCLibClient.h
//  SobotKit
//
//  Created by zhangxy on 2016/10/19.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibInitInfo.h"
//#import "ZCKitInfo.h"
#import "ZCLibMessage.h"



////////////////////////////////////////////////////////////////
// 自定义回调）
////////////////////////////////////////////////////////////////


// 当前用户会话状态
typedef NS_ENUM(NSInteger,ZCServerConnectStatus) {
    ZCServerConnectOffline    = 0, // 当前会话已经结束
    ZCServerConnectRobot      = 1, // 机器人
    ZCServerConnectArtificial = 2, // 人工接入成功
    ZCServerConnectWaiting    = 3  // 仅人工的排队
};


/**
 *
 *  消息回调
 *
 */
@protocol ZCReceivedMessageDelegate <NSObject>

//未读消息数获取
-(void)onReceivedMessage:(id) message unRead:(int) nleft obj:(id) object;



/// <#Description#>
/// @param status status description
-(void)currentConnectStatus:(id) message status:(ZCServerConnectStatus) status obj:(id) object;

@end

/**
 *  未读消息数，block方式获取
 *
 *  @param message 当前消息
 *  @param nleft   未读消息数
 */
typedef void(^ReceivedMessageBlock)(id message,int nleft,NSDictionary *object);


typedef void(^ZCServerConnectBlock)(id message,ZCServerConnectStatus status,NSDictionary *object);




typedef void(^TurnServiceBlock)(ZCLibMessage *model, NSInteger turnType);



/**
 初始化配置类
 */
@interface ZCLibClient : NSObject

/**
 推送的token
 每次启动应用都需要重新设置
 */
@property (nonatomic,strong) NSData     *token;



/// 可直接设置字符串，NSdata可不设置
@property (nonatomic,strong) NSString     *deviceToken;

/**
 平台标识，仅电商版本需要
 */
@property (nonatomic,strong) NSString     *platformUnionCode;


/// 初始化功能配置属性
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

/**
 退出道后台，自动关闭长连接，默认NO
 说明：如果设置YES，退出后台立即关闭通道，不影响应用后台挂起时长
 */
@property (nonatomic,assign) BOOL autoCloseConnect;


////////////////////////////////////////////////////////////////////////


// 同ZCKitInfo中的配置有同等效力，不会覆盖
@property (nonatomic,strong) id<ZCReceivedMessageDelegate> delegate;
// block方式配置
@property (nonatomic,strong) ReceivedMessageBlock          receivedBlock;

@property (nonatomic,strong) ZCServerConnectBlock          serverConnectBlock;

/**
 *
 *
 * 自定义转人工回调事件
 * 拦截SDK 转人工事件 用于跳转到自己的app页面动态处理转人工 配置技能组id 商品信息等参数
 *
 *
 ***/
@property (nonatomic,strong)  TurnServiceBlock    turnServiceBlock;

+(ZCLibClient *) getZCLibClient;



/**
 初始化智齿客服 2.7.2开始使用
 
 @param appkey 智齿appkey(如果是电商版本，请填写自己公司的APPKEY)
 @param apiHost,不设置为默认域名
 * 默认SaaS平台域名为:https://api.sobot.com
 * 如果您是腾讯云服务，请设置为：https://www.soboten.com
 * 如果您是本地化部署，请使用你们自己的部署的服务域名
 @param resultBlock 初始化结果回调
 */
-(void)initSobotSDK:(NSString *) appkey host:(NSString *) apiHost result:(void (^)(id object))resultBlock;

/**
 *
 *  初始化智齿客服 (2.7.1之前使用)
    @param apiHost 不设置为默认域名
    * 默认SaaS平台域名为:https://api.sobot.com
    * 如果您是腾讯云服务，请设置为：https://www.soboten.com
    * 如果您是本地化部署，请使用你们自己的部署的服务域名
 *
 **/
-(void)initSobotSDK:(NSString *) appkey host:(NSString *)apiHost;

/**
 检查初始化状态，（成功/失败）
 @return
 */
-(BOOL) getInitState;

-(NSString *)getCurApiHost;


/**
 关闭通道，清理内存，退出智齿客户 移除推送
 说明：调用此方法后将不能接收到离线消息，除非再次进入智齿SDK重新激活,
 isClosePush:YES ,是关闭push；NO离线用户，但是可以收到push推送
 */
+(void) closeAndoutZCServer:(BOOL) isClosePush;


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
 清空用户下的所有未读消息(本地清空)

 @param userId 接入的用户ID
 */
-(void) clearUnReadNumber:(NSString *) partnerid;


/**
 获取最后一条消息
 
 @return
 */
-(NSString  *) getLastMessage;


/**
* @deprecated This method is deprecated starting in version 2.6.3
 * @note Please use @code [checkIMConnected]
 初始化智齿客服，会建立长连接通道，监听服务端消息
 检查如果断开就重新连接
 （建议启动应用时调用，没有发起过咨询不会浪费资源,至少转一次人工才有效果）
    isAgInit 是否再次重新构建通道
 */
-(void)initZCIMCaht:(BOOL)isAgInit;


/**
 @note 检查当前消息通道是否建立，没有就重新建立
 如果调用 closeIMConnection 后，可调用此方法重新建立链接
 */
-(void)checkIMConnected;


/**
 @note 关闭当前消息通道，使其不再接受消息
 */
-(void)closeIMConnection;


/**
 移除IM所有监听，可能会影响应用在后台存活时长，如果调用此方法后需要checkIMObserverWithCreate重新激活
 网络监听 ZCNotification_NetworkChange
 UIApplicationDidBecomeActiveNotification
 UIApplicationDidEnterBackgroundNotification
 */
-(void)removeIMAllObserver;


/**
 检查当前监听是否被移除，如果移除就重新注册
 */
-(void)checkIMObserverWithRegister;


/**
 *  读取日志文件内容 保存最近的7天 v2.7.9
 *
 *  @param dateString 具体哪一天的日志，格式yyyyMMdd
 *
 *  @return 文件内容
 */
+(NSString *) readLogFileDateString:(NSString *) dateString;





/// <#Description#>
-(NSString *)getPlatform_userid;



// 电商版本
+(BOOL) isPlatformUnion;

// 当前版本
+(NSString *)sobotGetSDKVersion;

// 当前渠道
+(NSString *)sobotGetAppChannel;

@end
