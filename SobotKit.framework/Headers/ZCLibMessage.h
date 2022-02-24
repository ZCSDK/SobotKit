//
//  ZCLibMessage.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  ZCTipMessageType 提示消息内容
 */
typedef NS_ENUM(NSInteger,ZCTipMessageType) {
    /** 普通消息*/
    ZCTipMessageDefault                          = 0,
    /** 转人工成功 */
    ZCTipMessageOnline                           = 1,
    /** 转人工排队 */
    ZCTipMessageWaiting                          = 2,
    /** 暂无客服在线 */
    ZCTipMessageUserNoAdmin                      = 3,
    /** 暂时无法评价 */
    ZCTipMessageTemporarilyUnableToEvaluate      = 4,
    /** 已完成评价 */
    ZCTipMessageEvaluationCompleted              = 5,
    /** 咨询后才可评价 */
    ZCTipMessageAfterConsultingEvaluation        = 6,
    /** 已下为新消息 */
    ZCTipMessageNewMessage                       = 7,
    /** 空消息 */
    ZCTipMessageNullMessage                      = 8,
    /** 机器人欢迎语 */
    ZCTipMessageRobotHelloWord                   = 9,
    /** 用户超时提示语 */
    ZCTipMessageUserTipWord                      = 10,
    /** 客服超时提示语 */
    ZCTipMessageAdminTipWord                     = 11,
    /** 拉黑，暂时无法转人工 */
    ZCTipMessageIsBlock                          = 12,
    /** 用户超时下线 */
    ZCTipMessageUserOutWord                      = 13,
    /** 发送和接收的消息内容 文件路径 */
    ZCTipMessageText                             = 14,
    /** 人工欢迎语 */
    ZCTipMessageAdminHelloWord                   = 15,
    /** 本次会话结束 */
    ZCTipMessageOverWord                         = 16,
    /** 您打开了新窗口，本次会话结束 */
    ZCTipMessageOpenNewWindow                    = 17,
    /** 评价 */ 
    ZCTipMessageEvaluation                       = 18,
    
    /** 排队达到阀值*/
    ZCTipMessageWatingFull                       = 19,
    /** 消息撤回*/
    ZCTipMessageRevertMsg                        = 20,
    
    /** 安全提示 */
    ZCTipMessageSafety                           = 21,
    
    /*** 您的留言状态有更新  ***/
    ZCTipMessageUpdateLeave                      = 22,
    
    /***** 情绪转人工和重复提问转人工 提示文案   ****/
    ZCTipMessageRobotTurnMsg                     = 23,
    
    /****** 留言转离线消息 ******/
    ZCTipMessageOrderLeave                        = 24,
    
    /****** 您的留言已提交成功 *****/
    ZCTipMessageLeaveSuccess                      = 25,
    /****** 通告消息 *****/
    ZCTipMessageNotice                            = 26,
    /****** 诈骗词告警消息 *****/
    ZCTipMessageChatWarning                       = 29,
    /**机器人点踩 触发转人工*/
    ZCTipMessageUnresolvedProblemTurn             = 30,
    /****** 发送留言转离线消息后，结束会话 *****/
    ZCTipMessageChatCloseByLeaveMsg               = 99,
    
    
    /**
         * 用户咨询页授权
         */
    ZCTipMessageChat_AUTH_SAFETY = 43,

        /**
         * 用户同意敏感词授权
         */
    ZCTipMessageChat_AUTH_AGREE = 44,

        /**
         * 用户拒绝敏感词授权
         */
    ZCTipMessageChat_AUTH_REFUSE = 45,
   
};




#import "ZCLibRich.h"

/**
 *  配置消息记录
 */
@interface ZCLibMessage : NSObject


/**
 *  会话时间
 */
@property (nonatomic , strong) NSString *date;

/**
 * 消息id
 */
@property (nonatomic , strong) NSString *msgId;
@property (nonatomic , strong) NSString *revokeMsgId;


/**
 *  内容[未使用]
 */
@property (nonatomic , strong) NSString *contentTemp;

/**
 *  会话id
 */
@property (nonatomic , strong) NSString *cid;

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
 *  会话类型0，不知道怎么用
 */
@property (nonatomic , strong) NSString *action;

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


/// 发送人是否包含敏感词,0不启动，1启动，2拒绝
@property (nonatomic , assign) int includeSensitive;

/// 如果触发敏感信息，是否展示所有信息，默认收起
@property (nonatomic , assign) BOOL showAllMessage;
// 敏感词提示语
@property (nonatomic , strong) NSString *sentisiveExplain;

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
 0，不处理，1新添加(可赞、可踩)，2已赞，3已踩，4 超时下线之后不能在评价 置灰并给提示“会话结束，无法反馈”
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



// ////////////////////////////////////关键字转人工数据使用
/**
 *
 *     命中的关键字id
 *
 **/
@property (nonatomic,copy) NSString * keywordId;

/**
 *
 *           keyword:命中的关键字
 *
 **/
@property (nonatomic,copy) NSString * keyword;


/**
 *
 *   transferFlag:1-指定技能组接入，2-选择技能组列表，3-直接转入;
 *
 **/
@property (nonatomic,assign) int  transferFlag;


/**
 *
 *  queueFlag  排队方式标记  只在关键字转人工的时候传给服务端，其他情况传空
 *  1:展示排队或者客服不在线提示，为0不展示(如果转人工失败显示机器人回复，如果成功，不显示机器人回复)
 *
 **/
@property (nonatomic,assign)  int queueFlag;

// 1-客服在线可以转入，0-客服忙碌或不在线，不能转入
@property (nonatomic,assign) int  onlineFlag;

// 转人工提示语
@property (nonatomic,strong) NSString  *transferTips;

/**
 *
 *   groupId:指定技能组id
 *
 **/
@property (nonatomic,copy) NSString * groupId;


/**
 *
 *    tipsMessage:机器人转技能组提示语
 *
 **/
@property (nonatomic,copy) NSString * tipsMessage;

/**
 *
 *    groupList:选择技能组列表，模型：[{groupId：技能组id，groupName:技能组名称}，……]
 *
 **/
@property (nonatomic,strong) NSMutableArray * groupList;

/**
 *
 *   用户发消息 判定是否是被超时下线，如果超时下线不在执行关键字转人工
 *
 **/
@property (nonatomic,assign) BOOL userOffline;


/**
 *
 *   revokeFlag  0    1 撤回 “显示 客服xxx 撤回了一条消息”
 *
 **/
@property (nonatomic,assign) BOOL revokeFlag;


/**
 *
 *  transferType  转人工类型，0-不转，1-重复提问转人工，2-情绪负向转人工  3、关键词转人工、4、多次命中转人工(显示转人工按钮，不主动转人工)，5:机器人自动转人工(新版拆分为6-9,activeTransfer此时为1) 6直接转人工，7理解转人工，8引导转人工，9未知转人工 10，点踩转人工
 **/
@property (nonatomic,assign)  int transferType;



/// 客户原始提问 用于接下来针对词条点赞点踩用，点踩/赞时需要记录用户的原始问题用于统计展示
@property (nonatomic,strong  ) NSString         *originQuestion;


/**
 *
 *  记录通告是否展开
 *
 **/
@property (nonatomic,assign) BOOL isOpenNotice;


/**
 *
 *  消息体中包含leaveMsgFlag=1，表示该消息为离线留言消息，需要在左侧有小图标
 *
 **/
@property (nonatomic,assign) int leaveMsgFlag;


@property (nonatomic,strong) NSMutableDictionary * miniPageDic;// 订单消息、卡片消息的数据（仅历史记录数据中获取）

/**
 *  是否是机器人引导语
 */
@property (nonatomic , assign) BOOL isRobotGuide;

/**
 *  初始化
 *
 *  @param dict 数据解析后的数据字典类型
 *  @param isHistory
 *  @return ZCLibMessage
 */
-(id) initWithMyDict:(NSDictionary *)dict IsHistory:(BOOL)isHistory;



-(NSString *)getTipMsg:(ZCTipMessageType)action content:(NSString*)message isOpenLeave:(NSUInteger) isOpen;


-(void)getNewMessageModel:(ZCLibMessage *)model isShowGroup:(BOOL)isShow;


// 临时使用，查询数据时赋值
@property (nonatomic,strong) NSMutableAttributedString * displayMsgAttr;
@property (nonatomic,strong) NSMutableAttributedString * displaySugestionattr;

/**
 获取显示的组合内容

 @return
 */
// 保证使用时不创建NSMutableAttributedString属性
-(NSString *) getModelDisplayText;
-(NSString *) getModelDisplayText:(BOOL) createAttr;

// 保证使用时不创建NSMutableAttributedString属性
-(NSString *) getModelDisplaySugestionText;
-(NSString *) getModelDisplaySugestionText:(BOOL) createAttr;

-(NSString *)getLastMessage;
- (NSString *)getHtmlAttrStringWithText:(NSString *)text;
@end
