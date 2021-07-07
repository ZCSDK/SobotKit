//
//  ZCLibMessageConstants.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import "ZCLibMessage.h"

#define ZCNotification_NetworkChange @"NetworkChanged"
#import  "ZCLibStatusDefine.h"


typedef void(^onZCConnectBlock)();

typedef void(^onZCReceiveMessageBlock)(ZCLibMessage *message,int num,id obj);


/**下推消息类型*/
typedef NS_ENUM(NSInteger,ZCReceivedMessageType) {
    ZCReceivedMessageUnKonw         = -1,// 未知类型
    ZCReceiVedMessageNotice         = -2,// 通告不置顶
    ZCReceiVedMessageDefault        = 0, // 普通消息
    ZCReceivedMessageNews           = 202,// 新消息
    ZCReceivedMessageOnline         = 200,// 接入人工成功
    ZCReceivedMessageWaiting        = 201,// 排队
    ZCReceivedMessageTansfer        = 210,// 转接
    ZCReceivedMessageChatLock       = 213,// 会话锁定
    ZCReceivedMessageChatWarning    = 215,// 诈骗词告警
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
    ZCReceivedMessageTransferTips     = 301,// 转接提示语
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
