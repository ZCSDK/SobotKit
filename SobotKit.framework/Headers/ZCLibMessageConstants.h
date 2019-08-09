//
//  ZCLibMessageConstants.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import "ZCLibMessage.h"

#define ZCNotification_NetworkChange @"NetworkChanged"
#import "ZCLibStatusDefine.h"


typedef void(^onZCConnectBlock)();

typedef void(^onZCReceiveMessageBlock)(ZCLibMessage *message,int num,id obj);

/**消息体类型*/
typedef NS_ENUM(NSInteger,ZCMessageType) {
    ZCMessageTypeText  = 0, //文本
    ZCMessageTypePhoto = 1, //图片
    ZCMessageTypeSound = 2, // 声音
    ZCMessageTypeRich  = 3, // 富文本
    ZCMessageTypeFile  = 12, // 文件
    ZCMessageTypeVideo = 23, // 视频
    ZCMessageTypeLocation  = 22, // 文件
    ZCMessagetypeStartSound = 4,//正在录音
    ZCMessagetypeCancelSound = 5,//取消正在闪烁的语音cell
//    ZCMessagetypeCard   = 101,//商品卡片消息
    ZCMessageTypeCard = 24,//商品卡片消息
};

/**下推消息类型*/
typedef NS_ENUM(NSInteger,ZCReceivedMessageType) {
    ZCReceivedMessageUnKonw         = -1,// 未知类型
    ZCReceiVedMessageNotice         = -2,// 通告不置顶
    ZCReceivedMessageNews           = 202,// 新消息
    ZCReceivedMessageOnline         = 200,// 接入人工成功
    ZCReceivedMessageWaiting        = 201,// 排队
    ZCReceivedMessageTansfer        = 210,// 转接
    ZCReceivedMessageOfflineByAdmin = 2041,// 管理员下线
    ZCReceivedMessageOfflineByClose = 2042,// 管理员移除用户
    ZCReceivedMessageOfflineBeBlack = 2043,// 被拉入黑名单，不重新接入
    ZCReceivedMessageOfflineToLong  = 2044,// 长时间未说话
    ZCReceivedMessageToNewWindow    = 2046,// 打开新窗口
    ZCReceivedMessageConfirm        = 301,// 消息确认
    ZCReceivedMessageEvaluation     = 209,// 客服主动推送评价
    ZCReceivedMessageRevertMsg      = 211,// 消息撤回
    ZCReceivedMessageLockType_1      = 2131,// 会话锁定
    ZCReceivedMessageLockType_2      = 2132,// 会话解锁
};


@protocol ZCMessageDelegate <NSObject>

/**
 *  消息接收
 *
 *  @param message 下发消息
 *  @param num     未读消息，暂时未使用
 *  @param obj     预留对象
 */
-(void)onReceivedMessage:(ZCLibMessage *) message unReaded:(int) num object:(id)obj showType:(ZCReceivedMessageType) type;

/**
 *  连接状态变化
 *
 *  @param status 智齿连接业务状态码
 */
-(void)onConnectStatusChanged:(ZCConnectStatusCode) status;

@end
