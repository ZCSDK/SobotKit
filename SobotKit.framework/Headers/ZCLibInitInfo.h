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
 *  接口域名,
 * 默认SaaS平台域名为:https://api.sobot.com
 * 如果您是腾讯云服务，请设置为：https://ten.sobot.com
 * 如果您是本地化部署，请使用你们自己的部署的服务域名
 */
@property(nonatomic,strong) NSString *apiHost;


/**
 *
 *  appid   app唯一标识  （代替原sysNumber）
 *
 */
@property (nonatomic,strong) NSString   *appKey;


/**
 *
 *  customerCode   商户对接id （仅电商版适用，如果没有appkey，请提供此编码）
 *
 */
@property (nonatomic,strong) NSString   *customerCode;


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
 跨公司转接人工(仅电商版本可用)
 */
// 1 是开启，默认0不开启
@property (nonatomic,assign)  int   flowType;
// 转接到的公司ID
@property (nonatomic,strong)  NSString  * flowCompanyId;
// 转接到的公司技能组
@property (nonatomic,strong)  NSString  * flowGroupId;



/**
 *  用户唯一标识（对接用户可靠身份，不能写死，不建议为null，如果为空会以设备区别）
 *  null
 *  将自动备注到客户资料，
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
 *  转人工 指定技能组 溢出
 * [{"actionType":"to_group","optionId":"3","deciId":"162bb6bb038d4a9ea018241a30694064","spillId":"7"},
 {"actionType":"to_group","optionId":"4","deciId":"a457f4dfe92842f8a11d1616c1c58dc1"}]
 
 actionType:执行动作类型：to_group:转接指定技能组
 optionId:是否溢出  指定技能组时：3：溢出，4：不溢出。
 deciId:指定的技能组。
 spillId:溢出条件  指定客服组时：4:技能组无客服在线,5:技能组所有客服忙碌,6:技能组不上班,7:智能判断
 *
 */
@property (nonatomic,strong) NSArray *customGroupType;


/**
 *  转人工自定义字段
 *
 *
 **/
@property (nonatomic,strong) NSDictionary * summaryParams;

/**
 * 固定KEY的自定义字段
 * null
 * 所有的KEY均在工作台设置后生效（设置->自定义字段->用户信息字段）
 */
@property (nonatomic,strong) NSDictionary *customerFields;


/**
 *
 *  多轮会话 自定义字段
 *  默认 null
 **/
@property (nonatomic,strong) NSDictionary *multiParams ;


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
 *  通告的icon 的URL
 */
@property (nonatomic,strong) NSString   * notifitionIconUrl;


/**
 *  通告的 URL地址
 */
//@property (nonatomic,strong) NSString   * notifitionaddressUrl;



//@property (nonatomic,assign) BOOL   isWaitFull;

/**
 平台通道参数，初始化成功后会自动赋值
 */
@property (nonatomic,strong) NSString   * platformUserId;

/**
 *
 * 私钥
 *
 **/
@property (nonatomic,copy) NSString * platformKey;

/**
 *
 *   是否允许请求热点引导问题接口
 */
@property (nonatomic,assign) BOOL isEnableHotGuide;


/**
 *
 *    热点引导问题的扩展字段
 **/
@property (nonatomic,strong) NSDictionary * hotguideDict;



/**
 *
 *   机器人问答是否支持分词联想
 */
@property (nonatomic,assign) BOOL isEnableAutoTips;

/**
 *
 *  自定发送商品订单信息类型
 *  0 不发 1 给机器人发送 2 给人工发送  3 机器人和人工都发送
 **/
@property (nonatomic,assign) int goodMsgType;

/**
 *
 *   自动发送商品订单信息内容
 *   例如：“商品订单编号1403388282”
 **/
@property (nonatomic,copy) NSString * goodMsg;


/**
 *
 *  指定客户优先
 *  同PC端 设置-在线客服分配-排队优先设置-指定客户优先   开启传1 默认不设置
 *  开启后 指定客户发起咨询时，如果出现排队，系统将优先接入。
 **/
@property (nonatomic,assign) int queueFirst;

-(id)initByJsonDict:(NSDictionary *) dict;

@end
