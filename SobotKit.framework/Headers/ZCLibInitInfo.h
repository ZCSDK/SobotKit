//
//  ZCLibInitInfo.h
//  SobotLib
//
//  Created by zhangxy on 15/11/27.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  初始化配置用户信息
 *  企业唯一编号 用户唯一标识 用户昵称 用户电话 用户邮箱
 */
@interface ZCLibInitInfo : NSObject

/**
 *  企业唯一编号
 *  not null
 */
//@property (nonatomic,strong) NSString   *enterpriseId;


/**
 *
 *  appid   app唯一标识  （代替原sysNumber）
 *
 */
@property (nonatomic,strong) NSString   *appKey;


/**
 *   指定客服ID
 *
 *   默认不设置
 */
@property (nonatomic,strong)  NSString  * receptionistId;


/**
 *  定指客服 转接类型
 *
 *  0 可转入其他客服  1 必须转入指定客服（注意：如果当前指定的客服不在线，选择之后不能在转接到其他客服）
 */
@property (nonatomic,assign) int  tranReceptionistFlag;


/**
 *  用户唯一标识（对接用户可靠身份，不建议为null）
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *userId;


/**
 *
 *  对接机器人ID  （可以转接到对应的机器人）
 *
 */
@property (nonatomic,strong) NSString  *robotFlag;


/**
 *  用户昵称
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *nickName;

/**
 *  用户电话
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *phone;

/**
 *  用户邮箱
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *email;


/**
 *  自定义用户资料
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSDictionary *customInfo;

 /**
 *  当前转接的技能组 
 *  null
 *  自动连接上一个客服时用户服务端验证
 */
@property (nonatomic,strong) NSString     *groupId;

/**
 *  用户的姓名 将自动备注到客户资料
 */
@property (nonatomic,strong) NSString     *userName;

/**
 *  用户的QQ号 将自动备注到客户资料
 */
@property (nonatomic,strong) NSString     *qqNumber;

/**
 *  用户微信账号 将自动备注到客户资料
 */
@property (nonatomic,strong) NSString     *weChat;

/**
 *  用户的微博账号 将自动备注到客户资料
 */
@property (nonatomic,strong) NSString     *weiBo;

/**
 *  用户的性别 将自动备注到客户资料
 *  0.男，1.女
 */
@property (nonatomic,strong) NSString     *userSex;

/**
 *  用户的生日 将自动备注到客户资料
 *  yyyy-MM-dd
 */
@property (nonatomic,strong) NSString     *userBirthday;

/**
 *  用户备注
 */
@property (nonatomic,strong) NSString     *userRemark;

/**
 *  用户自定义头像 将自动备注到客户资料
 */
@property (nonatomic,strong) NSString     *avatarUrl;


/**
 *  接入来源页面标题
 *  null
 */
@property(nonatomic,strong) NSString     *sourceTitle;

/**
 *  接入的来源URL
 *  null
 */
@property (nonatomic,strong) NSString    *sourceURL;

/**
 *  默认 0 ，跟随系统设置
 *  自定义接入模式
 *  1只有机器人,2.仅人工 3.智能客服-机器人优先 4智能客服-人工客服优先'
 */
@property (nonatomic,assign) int         serviceMode;

/**
 *
 *  聊天页顶部标题 的自定义方式 0.默认  1.企业名称  2.自定义字段
 *
 */
@property (nonatomic,strong) NSString  *titleType;

/**
 *
 *  聊天页顶部标题 自定义字段  （如果传入，优先使用该字段）
 *
 */
@property (nonatomic,strong) NSString  *customTitle;


/**
 历史记录时间范围，单位分钟(例:100-表示从现在起前100分钟的会话)
 */
@property (nonatomic,assign) int  scopeTime;

@end
