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
#import "ZCUICore.h"
#import "ZCLibClient.h"
#import "ZCPlatformTools.h"
#import "ZCUIWebController.h"
#import "ZCLocalStore.h"
#import "ZCServiceCentreVC.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZCSobotApi : NSObject

/** 初始化
 @param appkey 智齿appkey(如果是电商版本，请填写自己公司的APPKEY)
 @param  默认SaaS平台域名为:https://api.sobot.com
 @param resultBlock 初始化结果回调
 */
+(void)initSobotSDK:(NSString *) appkey result:(void (^)(id object))resultBlock;


/** 初始化
 @param appkey 智齿appkey(如果是电商版本，请填写自己公司的APPKEY)
 @param apiHost
 * 默认SaaS平台域名为:https://api.sobot.com
 * 如果您是腾讯云服务，请设置为：https://www.soboten.com
 * 如果您是本地化部署，请使用你们自己的部署的服务域名
 @param resultBlock 初始化结果回调
 */
+(void)initSobotSDK:(NSString *) appkey host:(NSString *) apiHost result:(void (^)(id object))resultBlock;



/// 启动聊天页面，简单处理
/// @param info 自定义UI属性
/// @param byController  启动的页面
/// @param pageClick 页面当前状态
+ (void)openZCChat:(ZCKitInfo *) info
            with:(UIViewController *) byController
       pageBlock:(void (^)(id object,ZCPageBlockType type))pageClick;

/// 启动聊天页面
/// @param info 自定义UI属性
/// @param byController  启动的页面
/// @param delegate   点击留言拦截操作,如果不为空切实现了代理方法，留言将不再跳转
/// @param pageClick 页面当前状态
/// @param messagelinkBlock 链接点击事件，也可使用setMessageLinkClick统一处理
+ (void)openZCChat:(ZCKitInfo *) info
            with:(UIViewController *) byController
          target:(id<ZCChatControllerDelegate>) delegate
       pageBlock:(void (^)(id object,ZCPageBlockType type))pageClick
messageLinkClick:(BOOL (^)(NSString *link)) messagelinkBlock;




/// 点击链接拦截 帮助中心、留言、聊天、留言记录
/// @param messagelinkBlock 获取到链接，如果返回 YES 则拦截
+(void)setMessageLinkClick:(BOOL (^)(NSString *link))messagelinkBlock;


/// 点击返回功能事件监听，使用setFunctionClickListener替换
/// @param backBlock id当前viewcontroller，type：帮助中心、留言、聊天、会话列表
+(void)setZCViewControllerBackClick:(void (^)(id currentVC,ZCPageCloseType type))backBlock;

/// 包含（留言返回、客服服务中心返回、电商消息中心返回、聊天返回、点击电话按钮）
/// 点击返回功能事件监听, 替换setZCViewControllerBackClick方法，和其他平台统一函数名
/// @param backBlock 点击事件回调
+(void)setFunctionClickListener:(void (^)(id currentVC,ZCPageCloseType type))backBlock;



// 打开客户中心页面
+ (void)openZCServiceCenter:(ZCKitInfo *) info
                         with:(UIViewController *) byController
                  onItemClick:(void (^)(ZCUIBaseController *object))itemClickBlock;


// 打开消息中心页面
+ (void)openZCChatListView:(ZCKitInfo *)info with:(UIViewController *)byController onItemClick:(void (^)(ZCUIChatListController *object,ZCPlatformInfo *info))itemClickBlock;

/**
直接打开留言页面

@param showRecored  是否选中留言记录，0不选择，默认功能，1仅显示留言记录，2默认选中留言记录,可切换到留言
@param byController 当前执行跳转的VC           not null
@param CloseBlock 留言点击返回时间 code = 0 ,正常关闭， ，其他情况发送错误 如获取不到模版
*/
+ (void)openLeave:(int )showRecored kitinfo:(ZCKitInfo *)kitInfo with:(UIViewController *)byController onItemClick:(void (^)(NSString *msg,int code))CloseBlock;

// 打开留言记录详情页面
+(void)openRecordDetail:(NSString *)ticketId viewController:(UIViewController *) byController;

// 获取当前企业id
+(NSString *)getCommanyId;

// 发送位置
+ (void)sendLocation:(NSDictionary *)locations resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 发送文字消息
+ (void)sendTextToUser:(NSString *)textMsg resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

/// 发送消息给人工
/// @param textMsg  消息内如，如果是视频、图片、音频、文件时，请传本地图片路径
/// @param msgType  0, //文本   1, //图片  4, // 文件   3, // 视频
/// @param ResultBlock 发送结果 code == 0表示已发送
+ (void)sendMessageToUser:(NSString *)textMsg type:(NSInteger ) msgType resultBlock:(nonnull void (^)(NSString *, int code))ResultBlock;


// 发送订单卡片
+ (void)sendOrderGoodsInfo:(ZCOrderGoodsModel *)orderGoodsInfo resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 发送商品卡片
+ (void)sendProductInfo:(ZCProductInfo *)productInfo resultBlock:(void (^)(NSString *msg,int code))ResultBlock;

// 给机器人发送消息
+ (void)sendTextToRobot:(NSString *)textMsg;


///同步用户信息，如果没有建立会话，会默认建立一个新会话（同openZCChat）
/// @param ResultBlock
///  msg 操作结果说明，code=0成功，code==1失败
+ (void)synchronizationInitInfoToSDK:(void (^)(NSString *msg,int code))ResultBlock;

// 转人工自定义
+ (void)connectCustomerService:(ZCLibMessage *)message KitInfo:(ZCKitInfo*)uiInfo ZCTurnType:(NSInteger)turnType;


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



/// 根据手机时区，自动适配
/// @param autoMatchTimeZone  默认NO，不自动切换
+(void)setAutoMatchTimeZone:(BOOL) autoMatchTimeZone;

/**
*   获取对应商户客服是否正在和用户聊天
*   appkey：商户id   uid： ZCPlatformInfo 类中的uid
**/
+(BOOL)getPlatformIsArtificialWithAppkey:(NSString *)appkey Uid:(NSString*)uid;

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
+ (NSString *)readLogFileDateString:(NSString *) dateString;


/// 关闭通道，清理内存，退出智齿客户 移除推送
/// @param isClosePush YES 关闭push；NO 离线用户，但是可以收到push推送
+ (void)outCurrentUserZCLibInfo:(BOOL) isClosePush;



// 获取最后一条消息
+ (NSString *)readLastMessage;


/// 查询用户最后一条聊天记录
/// @param resultBlock 会返回2次，第一次为本地缓存，第二次同步接口结果，必须保证有cid的前提才能获取到
///  info：最后一条消息内容，message：内部使用消息体(不用)，code =0 本地，=1接口结果，其它为异常
+(void ) getLastMessageInfo:(void (^)(ZCPlatformInfo *info,ZCLibMessage *message, int code))resultBlock;

// 检查当前消息通道是否建立，没有就重新建立
+ (void)checkIMConnected;

// 关闭当前消息通道，使其不再接受消息
+ (void)closeIMConnection;

// 清空用户下的所有未读消息(本地清空)
+ (void)clearUnReadNumber:(NSString *) partnerid;

// 获取未读消息数
+ (int)getUnReadMessage;

// 获取最后一条消息
+(NSString *)getLastMessage;


/// 从服务端同步语言文件
/// @param lan  要同步的语言，如果本地bundle中已存在不会下载，en_lproj,zh-Hans_lproj
/// @param isReWrite  如果已经下载过了是否重复下载
+(void)synchronizeLanguage:(NSString *) language write:(BOOL) isReWrite result:(void (^)(NSString *message,int code))ResultBlock;;


/// 获取当前语言文件名称
+(NSString *)getCurLanguagePreHeader;

// 测试多语言是否有效，key 参见zh-Hans_lproj中获取
+(NSString *)checkZCSTLocalString:(NSString *)key;


/// md5字符串
/// @param sign 要转换的字符串
+(NSString *)zcMd5Sign:(NSString *) sign;

// 获取当前时间戳(毫秒)
+(NSString *)zcGetCurrentTimes;

// 关闭智齿页面
+(void)closeSobotPage;

@end

NS_ASSUME_NONNULL_END
