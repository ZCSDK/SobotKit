//
//  ZCPlatformTools.h
//  SobotKit
//
//  Created by zhangxy on 2017/9/4.
//  Copyright © 2017年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibMessage.h"
#import "ZCPlatformInfo.h"
#import "ZCLibClient.h"
//
#define LOCAL_AppkeyPrefix @"ZCPrefixLocal"
#define LOCAL_AppkeyTEMPPrefix @"PFKEYTEMP_"



@interface ZCPlatformTools : NSObject

+ (instancetype)sharedInstance;



/// 离线消息开关，1:开; 0:关,
/// 临时存储使用
@property (nonatomic,assign) BOOL isOfflineMsgConnect;

/// 离线消息的客服ID，当id不为空是，说明当前客户发送了离线消息，需要直接转人工
/// 临时存储使用
@property (nonatomic,strong) NSString *offlineMsgAdminId;

/**
 获取平台咨询过的商户列表

 本地获取，主线程执行即可
 @return 商户列表
 */
-(NSMutableArray *) getPlatformList:(NSString *) partnerid;


/**
 删除商家信息,本地永久删除
 
 @param appkey 商户APPKEY
 @param userId 用户标识
 */
-(void)deletePlatformByAppKey:(NSString *) appkey user:(NSString *) partnerid;



-(ZCPlatformInfo *)getPlatformInfo:(NSString *) appkey partnerid:(NSString *) partnerid;
-(void)savePlatformInfo:(ZCPlatformInfo *)platformInfo;
-(void)savePlatformInfo:(ZCPlatformInfo *)platformInfo cache:(BOOL) isCache;


//////////////////////////////////////////
-(ZCPlatformInfo *)getPlatformInfo;
-(ZCLibMessage *)getWaitintMessage;


/**
 获取当前商户消息列表

 @param appkey 具体商户APPKEY
 @return 最新消息列表
 */
-(NSMutableArray *)getMessageForAppkey:(NSString *) appkey partnerid:(NSString *)partnerid;






/**
 退出登录时调用
 */
-(void)cleanCacheData;


/**
 初始化失败时清理

 @param appkey
 @param userId
 */
-(void)cleanCacheDataByAppkey:(NSString *) appkey partnerid:(NSString *) partnerid;
+(void)cleanLocalParamterByPrefix:(NSString *) prefix;


/**
 判断当前初始化条件是否改变
 
 @return YES 需要从新初始化，NO不需要重新初始化
 */
+(BOOL) checkInitParameterChanged;


// 检查是否拥有留言功能
+(BOOL) checkLeaveMessageModule;


-(void)changeConnectedStatus:(ZCServerConnectStatus) status message:(id) message object:(NSDictionary *) obj;

@end
