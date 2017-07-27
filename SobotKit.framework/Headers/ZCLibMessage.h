//
//  ZCLibMessage.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibRich.h"



/**
 *  ZCTipCellMessageType 提示消息内容
 */
typedef NS_ENUM(NSInteger,ZCTipCellMessageType) {
    /** 转人工成功 */
    ZCTipCellMessageOnline                           = 1,
    /** 转人工排队 */
    ZCTipCellMessageWaiting                          = 2,
    /** 暂无客服在线 */
    ZCTipCellMessageUserNoAdmin                      = 3,
    /** 暂时无法评价 */
    ZCTipCellMessageTemporarilyUnableToEvaluate      = 4,
    /** 已完成评价 */
    ZCTipCellMessageEvaluationCompleted              = 5,
    /** 咨询后才可评价 */
    ZCTipCellMessageAfterConsultingEvaluation        = 6,
    /** 已下为新消息 */
    ZCTipCellMessageNewMessage                       = 7,
    /** 空消息 */
    ZCTipCellMessageNullMessage                      = 8,
    /** 机器人欢迎语 */
    ZCTipCellMessageRobotHelloWord                   = 9,
    /** 用户超时提示语 */
    ZCTipCellMessageUserTipWord                      = 10,
    /** 客服超时提示语 */
    ZCTipCellMessageAdminTipWord                     = 11,
    /** 拉黑，暂时无法转人工 */
    ZCTipCellMessageIsBlock                          = 12,
    /** 用户超时下线 */
    ZCTipCellMessageUserOutWord                      = 13,
    /** 发送和接收的消息内容 文件路径 */
    ZCTipCellMessageText                             = 14,
    /** 人工欢迎语 */
    ZCTipCellMessageAdminHelloWord                   = 15,
    /** 本次会话结束 */
    ZCTipCellMessageOverWord                         = 16,
    /** 您打开了新窗口，本次会话结束 */
    ZCTipCellMessageOpenNewWindow                    = 17,
    /** 评价 */ 
    ZCTipCellMessageEvaluation                       = 18,
    
    /** 排队达到阀值*/
    ZCTipCellMessageWatingFull                       = 19,
};



/**
 *  配置消息记录
 */
@interface ZCLibMessage : NSObject


/**
 *  会话时间
 */
@property (nonatomic , strong) NSString *date;

/**
 *  内容[未使用]
 */
@property (nonatomic , strong) NSString *contentTemp;

/**
 *  会话id
 */
@property (nonatomic , strong) NSString *cid;

/**
 *  会话类型0，用户，1机器人 2客服
 */
@property (nonatomic , strong) NSString *action;

/**
 *  用户id
 */
@property (nonatomic , strong) NSString *sender;

/**
 *  用户名称
 */
@property (nonatomic , strong) NSString *senderName;

/**
 *  发送,0，自己，1机器人，2客服
 */
@property (nonatomic , assign) int      senderType;

/**
 *  头像
 */
@property (nonatomic , strong) NSString *senderFace;

/**
 *  发送时间戳 -long
 */
@property (nonatomic , strong) NSString *t;

/**
 *  发送时间
 */
@property (nonatomic , strong) NSString *ts;

/**
 *  客服ID
 */
@property (nonatomic , strong) NSString *receiver;

/**
 *  客服名称
 */
@property (nonatomic , strong) NSString *receiverName;

/**
 *  下线类型
 */
@property (nonatomic , strong) NSString *offlineType;

/**
 *  客服头像
 */
@property (nonatomic , strong) NSString *receiverFace;

/**
 *  是否已读
 */
@property (nonatomic , assign) BOOL isRead;

/**
 *  上传进度
 */
@property (nonatomic , assign) float progress;

/**
 *  发送状态，1 开始发送，2发送失败，0，发送完成
 */
@property (nonatomic , assign) int  sendStatus;

/**
 *  是否播放
 */
@property (nonatomic , assign) BOOL isPlaying;

/**
 *  是否是历史消息
 */
@property (nonatomic , assign) BOOL isHistory;

/**
 *  ZCLibRic创建的对象
 */
@property (nonatomic , strong) ZCLibRich *richModel;

/**
 *  提醒,上下线等
 */
@property (nonatomic , strong) NSString *sysTips;

/**
 *  提示类型
 */
@property (nonatomic , assign) int tipStyle;


/**
 机器人评价
 0，不处理，1新添加(可赞、可踩)，2已赞，3已踩，
 */
@property (nonatomic , assign) int commentType;


/**
 机器人显示转人工按钮
 YES 显示，NO不显示
 */
@property (nonatomic , assign) BOOL showTurnUser;


/**
 *  0 没有评价 1已解决  2未解决
 *
 */
@property (nonatomic , assign) int  satisfactionCommtType;

/**
 *
 *  评价后的星级
 */
@property (nonatomic , assign) float  ratingCount;

/**
 *  评价是否开启 已解决 未解决   1开启 0关闭
 */
@property (nonatomic , strong) NSString* isQuestionFlag;

/**
 *  初始化
 *
 *  @param dict 数据解析后的数据字典类型
 *
 *  @return ZCLibMessage
 */
-(id) initWithMyDict:(NSDictionary *)dict;



-(NSString *)getTipMsg:(int)action content:(NSString*)message isOpenLeave:(NSUInteger) isOpen;
@end
