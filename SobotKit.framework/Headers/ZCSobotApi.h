//
//  ZCSobotApi.h
//  SobotKit
//
//  Created by xuhan on 2020/1/17.
//  Copyright © 2020 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "ZCSobot.h"
#import "ZCLibCusMenu.h"
#import "ZCKitInfo.h"
#import "ZCLibInitInfo.h"
#import "ZCPlatformInfo.h"
#import "ZCUIBaseController.h"
#import "ZCLibClient.h"
#import "ZCChatController.h"
#import "ZCUIChatListController.h"
#import "ZCChatView.h"
#import "ZCRecordListModel.h"

#import "ZCLibClient.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZCSobotApi : NSObject



//  打开会话页面
+ (void)openZCChat:(ZCKitInfo *) info
            with:(UIViewController *) byController
          target:(id<ZCChatControllerDelegate>) delegate
       pageBlock:(void (^)(id object,ZCPageBlockType type))pageClick
messageLinkClick:(BOOL (^)(NSString *link)) messagelinkBlock;




/// 点击链接拦截 帮助中心、留言、聊天、留言记录
/// @param messagelinkBlock 获取到链接，如果返回 YES 则拦截
+(void)setMessageLinkClick:(BOOL (^)(NSString *link))messagelinkBlock;


// 打开客户中心页面
+ (void)openZCServiceCenter:(ZCKitInfo *) info
                         with:(UIViewController *) byController
                  onItemClick:(void (^)(ZCUIBaseController *object))itemClickBlock;


// 打开消息中心页面
+ (void)openZCChatListView:(ZCKitInfo *)info with:(UIViewController *)byController onItemClick:(void (^)(ZCUIChatListController *object,ZCPlatformInfo *info))itemClickBlock;


// 打开留言页面
+ (void)openLeave:(int )showRecored kitinfo:(ZCKitInfo *)kitInfo with:(UIViewController *)byController onItemClick:(void (^)(NSString *msg,int code))CloseBlock;

// 打开留言记录详情页面
+(void)openRecordDetail:(NSString *)ticketId viewController:(UIViewController *) byController;

// 获取当前企业id
+(NSString *)getCommanyId;

// 发送位置
+ (void)sendLocation:(NSDictionary *)locations resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 发送文字消息
+ (void)sendTextToUser:(NSString *)textMsg resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 发送订单卡片
+ (void)sendOrderGoodsInfo:(ZCOrderGoodsModel *)orderGoodsInfo resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 发送商品卡片
+ (void)sendProductInfo:(ZCProductInfo *)productInfo resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 给机器人发送消息 ?
+ (void)sendTextToRobot:(NSString *)textMsg;

// 同步用户信息
+ (void)synchronizationInitInfoToSDK:(void (^)(NSString *msg,int code))ResultBlock;

// 转人工自定义
+ (void)connectCustomerService:(NSString *)groupId  Obj:(id)obj KitInfo:(ZCKitInfo*)uiInfo ZCTurnType:(NSInteger)turnType Keyword:(NSString*)keyword KeywordId:(NSString*)keywordId;


/// 获取最新回复
/// @param partnerid  用户id
/// @param ResultBlock code=1返回成功，
/// dict :data:items:[{(ticketId(工单id),ticketTitle(工单标题),replyContent(回复内容),replyTime(回复时间),customerId(客户id),serviceNick(客服昵称）}] 
+ (void)getLastLeaveReplyMessage:(NSString *) partnerid resultBlock:(void (^)(NSDictionary *dict,NSMutableArray *arr,int code))ResultBlock;



/// 发送本地推送
/// @param message  消息内容
/// @param userInfo 参数
+(void)postLocalNotification:(NSString *)message dict:(NSDictionary *) userInfo;

// 获取 SDK 版本号
+ (NSString *)getVersion;

// 获取渠道信息
+ (NSString *)getChannel;

// 显示日志信息 默认不显示
+ (void)setShowDebug:(BOOL)isShowDebug;

//
+ (NSString *)getSystem;

// 获取当前app的版本号
+ (NSString *)getAppVersion;

// 获取手机型号
+ (NSString *)getIPhoneType;

// 获取当前集成的app名称
+ (NSString *)getAppName;

// 获取用户的 UUID
+ (NSString *)getUserUUID;

// 添加异常统计
+ (void)setZCLibUncaughtExceptionHandler;

// 读取日志文件内容 保存最近的7天
+ (void)readLogFileDateString:(NSString *) dateString;


/// 关闭通道，清理内存，退出智齿客户 移除推送
/// @param isClosePush YES 关闭push；NO 离线用户，但是可以收到push推送
+ (void)outCurrentUserZCLibInfo:(BOOL) isClosePush;


/// 初始化，如果要修改域名，请在调用方法之前设置
/// @param appkey appkey
/// @param resultBlock
+ (void)initSobotSDK:(NSString *) appkey result:(void (^)(id object))resultBlock;

// 获取最后一条消息
+ (NSString *)readLastMessage;

// 检查当前消息通道是否建立，没有就重新建立
+ (void)checkIMConnected;

// 关闭当前消息通道，使其不再接受消息
+ (void)closeIMConnection;

// 清空用户下的所有未读消息(本地清空)
+ (void)clearUnReadNumber;

// 获取未读消息数
+ (int)getUnReadMessage;


@end

NS_ASSUME_NONNULL_END
