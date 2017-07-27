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
 *  企业唯一编号 用户唯一标识 用户昵称 用户电话 用户邮箱...
 */
@interface ZCLibInitInfo : NSObject



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
@property (nonatomic,strong) NSString  *robotId;


/**
 *  用户昵称
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *nickName;


/**
 *  用户的真实姓名
 *  null
 *  将自动备注到客户资料
 */
@property(nonatomic,strong) NSString   *realName;

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
 * 固定KEY的自定义字段
 * null
 * 所有的KEY均在工作台设置后生效（设置->自定义字段->用户信息字段）
 */
@property (nonatomic,strong) NSDictionary *customerFields;


/**
 *  用户的qq号码
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *qqNumber;

/**
 *  用户的性别 0男 1女
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *userSex;

/**
 *  用户的微博账号
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *weiBo;

/**
 *  用户的微博账号
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *weChat;

/**
 *  用户的生日
 *  例：20170323，*注意* 如果不是这个格式，初始化接口会给过滤掉
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *userBirthday;

/**
 * 备注
 * null
 * 将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *userRemark;

/**
 *  技能组编号
 *  null
 *  根据传递的值转接到对应的技能组,不传不起作用
 */
@property (nonatomic,strong) NSString   *skillSetId;

/**
 *  技能组名称(同一个技能组，不同名称是需要)
 *  null
 */
@property (nonatomic,strong) NSString   *skillSetName;


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




/**
 *  自定义客服欢迎语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customAdminHelloWord;


/**
 *  自定义机器人欢迎语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customRobotHelloWord;


/**
 *  自定义用户超时提示语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customUserTipWord;


/**
 *  自定义客服不在线的说辞,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customAdminNonelineTitle;


/**
 *  自定义客服超时提示语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customAdminTipWord;


/**
 *  自定义用户超时下线提示语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customUserOutWord;


// *****   通告  ******  除了通告的图标地址，其他取接口

/**
 *   是否显示通告栏
 */
//@property (nonatomic,assign) BOOL     isShowNotifitionTopView;
//
///**
// *  点击跳转后是否显示通告栏
// */
//@property (nonatomic,assign) BOOL     isDismissNotifitionTopView;
//
///**
// *   通告标题
// */
//@property (nonatomic,strong) NSString   * notifitionTitle;

/**
 *  通告的icon 的URL
 */
@property (nonatomic,strong) NSString   * notifitionIconUrl;


/**
 *  通告的 URL地址
 */
//@property (nonatomic,strong) NSString   * notifitionaddressUrl;



//@property (nonatomic,assign) BOOL   isWaitFull;

@end
