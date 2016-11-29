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
@property (nonatomic,strong) NSString   *enterpriseId;


/**
 *  用户唯一标识（对接用户可靠身份，不建议为null）
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *userId;


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

@end
