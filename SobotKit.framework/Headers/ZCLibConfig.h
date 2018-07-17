//
//  ZCLibConfig.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLibLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibInitInfo.h"

/**
 *  配置信息
 */
@interface ZCLibConfig : NSObject

/**
 *  用户id
 */
@property (nonatomic , strong) NSString *uid;

@property (nonatomic , strong) NSString *equipmentId;

// 记录企业编号
//@property (nonatomic , strong) NSString *sysNumber;


/**
 *  appKey
 */
@property (nonatomic , strong) NSString *appKey;


/**
 *  客服不在线标题
 */
@property (nonatomic , strong) NSString *adminNonelineTitle;

/**
 *  机器人头像logo
 */
@property (nonatomic , strong) NSString *robotLogo;

/**
 *  用户超时下线
 */
@property (nonatomic , strong) NSString *userOutWord;

/**
 *  客服欢迎语
 */
@property (nonatomic , strong) NSString *adminHelloWord;

/**
 *  用户无应答提示时间
 */
@property (nonatomic , assign) int      userTipTime;

/**
 *  用户无应答提示文案
 */
@property (nonatomic , strong) NSString *userTipWord;

/**
 *  机器人欢迎语
 */
@property (nonatomic , strong) NSString *robotHelloWord;

/**
 *  客服无应答提示文案
 */
@property (nonatomic , strong) NSString *adminTipWord;

/**
 *  企业名称
 */
@property (nonatomic , strong) NSString *companyName;
@property (nonatomic , strong) NSString *companyLogo;

/**
 *  接入方式,1只有机器人,2.仅人工 3.智能客服-机器人优先 4智能客服-人工客服优先',
 */
@property (nonatomic , assign) int      type;

/**
 *  会话id
 */
@property (nonatomic , strong) NSString *cid;

/**
 *  公司付费状态 0试用 1免费 2永久 10都付费 11机器人付费 12人工客服付费
 */
@property (nonatomic , assign) int      companyStatus;

/**
 *  机器人昵称
 */
@property (nonatomic , strong) NSString *robotName;

/**
 *  是否是黑名单 0否 1是
 */
@property (nonatomic , assign) BOOL     isblack;

/**
 *  用户超时下线时间
 */
@property (nonatomic , assign) int      userOutTime;

/**
 *  机器人未知措辞
 */
@property (nonatomic , strong) NSString *robotUnknownWord;

/**
 *  标示
 */
@property (nonatomic , strong) NSString *token;

/**
 *  颜色代码
 */
@property (nonatomic , strong) NSString *color;

/**
 *  1 开启语音 2 关闭语音功能 3只选择机器人客服
 */
@property (nonatomic , assign) int      onORoff;

/**
 *  客服无应答提示时间
 */
@property (nonatomic , assign) int      adminTipTime;


/**
 *  是否人工服务
 */
@property (nonatomic , assign) BOOL     isArtificial;

/**
 *  评论人工，以逗号隔开
 */
@property (nonatomic , strong) NSString *manualCommentTitle;

/**
 *  评论机器人
 */
@property (nonatomic , strong) NSString *robotCommentTitle;


/**
 * 机器人引导转人工 勾选为1，默认为0 固定位置，比如1,1,1,1=直接回答勾选，理解回答勾选，引导回答勾选，未知回答勾选
 */
@property (nonatomic , strong) NSString *manualType;


/**
 * 顶踩开关 0关闭 1开启
 */
@property (nonatomic , assign) BOOL     realuateFlag;

/**
 *realuateFlag 顶踩开关 0关闭 1开启
 留言相关 1显示 0不显示
 telShowFlag 电话是否显示
 telFlag 电话是否必填
 enclosureShowFlag 附件是否显示
 enclosureFlag 附件是否必填  0 可选 1 必填
 emailFlag 邮箱是否必填
 emailShowFlag 邮箱是否显示
 ticketStartWay 工单发起方式 1邮箱，2手机
 */
@property (nonatomic , assign) BOOL     telShowFlag;
@property (nonatomic , assign) BOOL     telFlag;
@property (nonatomic , assign) BOOL     enclosureShowFlag;
@property (nonatomic , assign) BOOL     enclosureFlag;
@property (nonatomic , assign) BOOL     emailFlag;
@property (nonatomic , assign) BOOL     emailShowFlag;
@property (nonatomic , assign) int      ticketStartWay;

/**
 *  是否显示技能组
 */
@property (nonatomic , assign) BOOL     groupflag;


/**
 *  用户当前状态：
 *  -2.排队中
 *  -1.机器人
 *  0.离线
 *  1.在线
 */
@property (nonatomic , assign) int      ustatus;


/**
 *  发送正在输入的频率
 */
@property (nonatomic , assign) int      inputTime;



/**
 是否显示机器人引导语,1-开启，0-关闭
 */
@property (nonatomic , assign) int      guideFlag;


/**
 *  初始化参数
 *  自己设置，服务器端未返回
 */
@property (nonatomic , strong) ZCLibInitInfo *zcinitInfo;


/**
 *  临时属性，用于显示发送人头像
 */
@property (nonatomic , strong) NSString *senderFace;

/**
 *  临时属性，用于存储发送人名称
 */
@property (nonatomic , strong) NSString *senderName;

/**
 *  用于留言工单
 */
@property (nonatomic,strong) NSString *companyID;

/**
 *  留言引导文案
 */
@property (nonatomic,strong) NSString *msgTxt;

/**
 *  留言内容模板
 */
@property (nonatomic,strong) NSString *msgTmp;

/**
 *  留言开关   0关闭 ，1开启
 */
@property (nonatomic,assign) NSUInteger msgFlag;

/**
 *  用户的头像
 */
@property (nonatomic, strong) NSString *face;

/**
 *  用户的昵称
 */
@property (nonatomic, strong) NSString *uname;


/**
 * 机器人编号
 */
@property (nonatomic, assign) int      robotFlag;


/*
 *  通告是否置顶
 */
@property (nonatomic,assign) int   announceTopFlag;

/**
 *   通告是否打开
 */
@property (nonatomic,assign) int  announceMsgFlag;


/**
 *  通告的标题
 */
@property (nonatomic,strong) NSString * announceMsg;

/**
 *   通告的链接
 */
@property (nonatomic,strong) NSString *announceClickUrl;

/**
 *  通道点击之后是否关闭
 */
@property (nonatomic,assign) int   announceClickFlag;

/**
 *  用户超时提示开关
 */
@property (nonatomic,assign) BOOL   customOutTimeFlag;


/**
 *  客服超时提示开关
 */
@property (nonatomic,assign) BOOL   serviceOutTimeFlag;

/**
 *   切换机器人开关 1-开启，0-关闭
 */
@property (nonatomic,assign) int  robotSwitchFlag;

/**
 *
 *  是否开启快捷入口
 *
 **/
@property (nonatomic,assign) int quickEntryFlag;


/**
 *
 *  -1待激活，0免费版，1试用版，2专业版，3企业版  4旗舰版
 *
 **/
@property (nonatomic,assign) int accountStatus;

/**
 *  对象封装
 *
 *  @param dict 获取数据解析后的数据
 *
 *  @return ZCLibConfig
 */
-(id)initWithMyDict:(NSDictionary *)dict;

@end
