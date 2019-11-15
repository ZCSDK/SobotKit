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
 *  自2.8.0以后所有渠道统一命名参数(所有参数小写,多个字母直接下划线连接)，原因参数名称还可以使用；
 *  【后期将废弃掉旧的参数，如果新接入请使用小写参数】
 */
@interface ZCLibInitInfo : NSObject

/**
 *  接口域名,
 * 默认SaaS平台域名为:https://api.sobot.com
 * 如果您是腾讯云服务，请设置为：https://ten.sobot.com
 * 如果您是本地化部署，请使用你们自己的部署的服务域名
 */
@property(nonatomic,strong) NSString *apiHost;

// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *api_host;


/**
 *
 *  appid   app唯一标识  （代替原sysNumber）
 *
 */
@property (nonatomic,strong) NSString   *appKey;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *app_key;

/**
 *
 *  customerCode   商户对接id （仅电商版适用，如果没有appkey，请提供此编码）
 *
 */
@property (nonatomic,strong) NSString   *customerCode;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *customer_code;

/**
 *   指定客服ID
 *
 *   默认不设置
 */
@property (nonatomic,strong)  NSString  * receptionistId;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *choose_adminid;


/**
 *  定指客服 转接类型
 *
 *  0 可转入其他客服
    1 必须转入指定客服
   （注意：如果当前指定的客服不在线，选择之后不能在转接到其他客服）
 */
@property (nonatomic,assign) int  tranReceptionistFlag;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) int tran_flag;


/**
 跨公司转接人工(仅电商版本可用)
 */
// 1 是开启，默认0不开启
@property (nonatomic,assign)  int   flowType;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) int flow_type;

// 转接到的公司ID
@property (nonatomic,strong)  NSString  * flowCompanyId;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *flow_companyid;

// 转接到的公司技能组
@property (nonatomic,strong)  NSString  * flowGroupId;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *flow_groupid;



/**
*  用户唯一标识（对接用户可靠身份，不能写死，相同的值会获取同一份历史数据，不建议为null，如果为空会以设备区别）
*  null
*  将自动备注到客户资料
* （所有渠道统一参数名称，替换原有的userId）
*/
@property(nonatomic,strong) NSString *partnerid NS_AVAILABLE_IOS(2_8_0);
/**
 *  用户唯一标识（对接用户可靠身份，不能写死，不建议为null，如果为空会以设备区别）
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *userId NS_DEPRECATED_IOS(1_0,2_8_0,"建议使用 partnerid");


/**
 *
 *  对接机器人ID  （可以转接到对应的机器人）
 *
 */
@property (nonatomic,strong) NSString  *robotId;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *robotid;

/**
 *  用户昵称
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *nickName;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_nick;

/**
 *  用户的真实姓名
 *  null
 *  将自动备注到客户资料
 */
@property(nonatomic,strong) NSString   *realName;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_name;
/**
 *  用户电话
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *phone;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_tels;
/**
 *  用户邮箱
 *  null
 *  将自动备注到客户资料
 */
@property (nonatomic,strong) NSString   *email;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_emails;

/**
 *
 *  指定客户是否为vip，0:普通 1:vip
 *  同PC端 设置-在线客服分配-排队优先设置-VIP客户排队优先   开启传1 默认不设置
 *  开启后 指定客户发起咨询时，如果出现排队，系统将优先接入。
 **/
@property (nonatomic,copy) NSString *isVip;


/**
 *
 *  指定客户的vip等级，传入等级
 *  同PC端 设置-自定义字段-客户字段
 **/
@property (nonatomic,copy) NSString *vipLevel;

/**
 *  自定义用户资料
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSDictionary *customInfo;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSDictionary *params;


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
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSArray *transferaction;

/**
 *  转人工自定义字段
 *
 *
 **/
@property (nonatomic,strong) NSDictionary * summaryParams;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSDictionary *summary_params;
/**
 * 固定KEY的自定义字段
 * null
 * 所有的KEY均在工作台设置后生效（设置->自定义字段->用户信息字段）
 */
@property (nonatomic,strong) NSDictionary *customerFields;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSDictionary *customer_fields;

/**
 *
 *  多轮会话 自定义字段
 *  默认 null
 **/
@property (nonatomic,strong) NSDictionary *multiParams ;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSDictionary *multi_params;

/**
 *  用户的qq号码
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *qqNumber;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *qq;
/**
 *  用户的性别 0男 1女
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *userSex;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_sex;

/**
 *  用户的微博账号
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *weiBo;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *weibo;
/**
 *  用户的微信账号
 *  null
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *weChat;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *weixin;
/**
 *  用户的生日
 *  例：20170323，*注意* 如果不是这个格式，初始化接口会给过滤掉
 *  将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *userBirthday;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *birthday;
/**
 * 备注
 * null
 * 将自动显示到客服工作台客户资料
 */
@property (nonatomic,strong) NSString *userRemark;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *remark;

/**
 *  技能组编号
 *  null
 *  根据传递的值转接到对应的技能组,不传不起作用
 */
@property (nonatomic,strong) NSString   *skillSetId;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *groupid;

/**
 *  技能组名称(同一个技能组，不同名称是需要)
 *  null
 */
@property (nonatomic,strong) NSString   *skillSetName;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *group_name;

/**
 *  用户自定义头像 将自动备注到客户资料
 */
@property (nonatomic,strong) NSString     *avatarUrl;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *face;

/**
 *  接入来源页面标题
 *  null
 */
@property(nonatomic,strong) NSString     *sourceTitle;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *visit_title;

/**
 *  接入的来源URL
 *  null
 */
@property (nonatomic,strong) NSString    *sourceURL;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *visit_urL;

/**
 *  默认 0 ，跟随系统设置
 *  自定义接入模式
 *  1只有机器人,2.仅人工 3.智能客服-机器人优先 4智能客服-人工客服优先'
 */
@property (nonatomic,assign) int         serviceMode;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) int service_mode;

/**
 *
 *  聊天页顶部标题 的自定义方式 0.默认  1.企业名称  2.自定义字段
 *
 */
@property (nonatomic,strong) NSString  *titleType;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *title_type;
/**
 *
 *  聊天页顶部标题 自定义字段  （如果传入，优先使用该字段）
 *
 */
@property (nonatomic,strong) NSString  *customTitle;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *custom_title;
// 自定义图像路径
@property(nonatomic,strong) NSString *custom_title_url;

/**
 历史记录时间范围，单位分钟(例:100-表示从现在起前100分钟的会话)
 */
@property (nonatomic,assign) int  scopeTime;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) int scope_time;



/**
 *  自定义客服欢迎语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customAdminHelloWord;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *admin_hello_word;

/**
 *  自定义机器人欢迎语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customRobotHelloWord;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *robot_hello_word;

/**
 *  自定义用户超时提示语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customUserTipWord;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_tip_word;

/**
 *  自定义客服不在线的说辞,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customAdminNonelineTitle;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *admin_offline_title;

/**
 *  自定义客服超时提示语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customAdminTipWord;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *admin_tip_word;

/**
 *  自定义用户超时下线提示语,默认为空 （如果传入，优先使用该字段）
 */
@property (nonatomic,strong) NSString * customUserOutWord;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *user_out_word;

// *****   通告  ******  除了通告的图标地址，其他取接口


/**
 *  通告的icon 的URL
 */
@property (nonatomic,strong) NSString   * notifitionIconUrl;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *notifition_icon_url;

/**
 *  通告的 URL地址
 */
//@property (nonatomic,strong) NSString   * notifitionaddressUrl;



//@property (nonatomic,assign) BOOL   isWaitFull;

/**
 平台通道参数，初始化成功后会自动赋值
 */
@property (nonatomic,strong) NSString   * platformUserId;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *platform_userid;
/**
 *
 * 私钥
 *
 **/
@property (nonatomic,copy) NSString * platformKey;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSString *platform_key;
/**
 *
 *   是否允许请求热点引导问题接口
 */
@property (nonatomic,assign) BOOL isEnableHotGuide;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) BOOL is_enable_hot_guide;

/**
 *
 *    热点引导问题的扩展字段
 **/
@property (nonatomic,strong) NSDictionary * hotguideDict;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,strong) NSDictionary *margs;


/**
 *
 *   机器人问答是否支持分词联想
 */
@property (nonatomic,assign) BOOL isEnableAutoTips;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) BOOL support;
/**
 *
 *  自定发送商品订单信息类型
 *  0 不发 1 给机器人发送 2 给人工发送  3 机器人和人工都发送
 **/
@property (nonatomic,assign) int goodMsgType;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) int good_msg_type;
/**
 *
 *   自动发送商品订单信息内容
 *   例如：“商品订单编号1403388282”
 **/
@property (nonatomic,copy) NSString * goodMsg;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,copy) NSString *content;

/**
 *
 *  指定客户优先
 *  同PC端 设置-在线客服分配-排队优先设置-指定客户优先   开启传1 默认不设置
 *  开启后 指定客户发起咨询时，如果出现排队，系统将优先接入。
 **/
@property (nonatomic,assign) int queueFirst;
// 启用新的接口命名方式，兼容驼峰命名
@property(nonatomic,assign) int queue_first;

-(id)initByJsonDict:(NSDictionary *) dict;

@end
