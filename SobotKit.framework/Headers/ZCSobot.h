//
//  ZCSobot.h
//  SobotKit
//
//  Created by zhangxy on 15/11/12.
//  Copyright © 2015年 zhichi. All rights reserved.
//  0221a

#import <Foundation/Foundation.h>
#import "ZCLibCusMenu.h"
#import "ZCKitInfo.h"
#import "ZCLibInitInfo.h"
#import "ZCPlatformInfo.h"
#import "ZCUIBaseController.h"
#import "ZCLibClient.h"
#import "ZCChatController.h"
#import "ZCUIChatListController.h"
#import "ZCChatView.h"
#import "ZCUIWebController.h"


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
    messageLinkClick:(BOOL (^)(NSString *link)) messagelinkBlock;



/**
 *
 *  启动 客户帮助中心
 *
 *  @param info         初始化参数，详情见ZCLibInitInfo not null
 *  @param byController 当前执行跳转的VC           not null
 *  @param delegate     ZCUIChatDelagete        聊天页面的代理，如果实现这个代理用户可以实现留言跳转到自定义页面
 *  @param pageClick    点击返回，UI修改, object为ZCChatController（使用系统导航栏场景） 或者 ZCChatView（使用SDK自定义导航栏场景） 
 *  @param linkBlock    点击消息链接回调，可以为null(注意：如果传递实现后内部将直接返回url，不在做跳转处理)
 *
 */
+(void)openZCServiceCentreVC:(ZCKitInfo *) info
                with:(UIViewController *) byController
                 onItemClick:(void (^)(ZCUIBaseController *object))itemClickBlock;


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



/// 点击链接拦截 帮助中心、留言、聊天、留言记录
/// @param messagelinkBlock 获取到链接，如果返回 YES 则拦截
+(void)getMessageLinkClick:(BOOL (^)(NSString *link))messagelinkBlock;

/**
 发送位置信息，此方法，只能是收到sobot://sendlocation时调用
 @param locations 位置信息
@{
 @"lng":经度,
 @"lat":纬度,
 @"localName":名称,
 @"localLabel":地址,
 @"file":当前位置截图};
 
 示例：
 {
 file = "/var/mobile/Containers/Data/Application/fff84824-4894-4CA1-A071-C0030A75xxxx/Documents/sobot/image1001544587922.jpg";
 lat = "40.001693";
 lng = "116.353276";
 localLabel = "学清路38号金码大厦A座23层金码大酒店";
 localName = "云景四季餐厅";
 }
 */
+(void)sendLocation:(NSDictionary *) locations;



/**
 发送商品信息给客服（仅转人工成功以后可以成功，机器人发送无法成功）

 @param pinfo
 */
+(void)sendProductInfo:(ZCProductInfo *)pinfo;


/**
 *  发送订单信息 消息给 人工客服
 * 只能人工客服的时候才可以发送成功
 *
 *
 */
+(void)sendOrderGoodsInfo:(ZCOrderGoodsModel *)orderGoodsInfo;


// 已废弃，请使用sendTextToUser:方法替换
//+(void)sendeOrderMsg:(NSString *) msg;

/**
 发送字符串给人工
 */
+(void)sendTextToUser:(NSString *) textMsg;



/**
 自定义转人工调用
 @param message 包含机器人触发转人工相关信息
 @param uiInfo 配置商品信息和自动发送参数
 @param turnType 转人工事件类型（按钮触发，关键字触发等）
 */
+(void)customConnectUserService:(ZCLibMessage *) message kitInfo:(ZCKitInfo*)uiInfo type:(int) trunType;

/**
 *
 *   获取对应商户客服是否正在和用户聊天
 *   appkey：商户id   uid： ZCPlatformInfo 类中的uid 
 **/
+(BOOL)getPlatformIsArtificialWithAppkey:(NSString *)appkey Uid:(NSString*)uid;



/**
 初始化SDK，初始化之前，必须给ZCLibClient中的initInfo赋值
  code = 0 ,正常，其他情况发送错误
 */
+(void)backgroundInitSDK:(void (^)(NSString *msg,int code))ResultBlock;

/**
 直接打开留言页面

 @param showRecored  是否选中留言记录，0不选择，默认功能，1仅显示留言记录，2默认选中留言记录,可切换到留言
 @param byController 当前执行跳转的VC           not null
 @param CloseBlock 留言点击返回时间 code = 0 ,正常关闭， ，其他情况发送错误
 */
+(void)openLeanve:(int ) showRecored kitinfo:(ZCKitInfo *)kitInfo with:(UIViewController *)byController onItemClick:(void (^)(NSString *msg,int code))CloseBlock;



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
