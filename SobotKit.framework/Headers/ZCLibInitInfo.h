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
*  app_key   app唯一标识  （代替原appKey）
*/
@property(nonatomic,strong) NSString *app_key;
// 请使用app_key替换
@property (nonatomic,strong) NSString   *appKey NS_DEPRECATED_IOS(1.5,2_8_0);

// 签名 MD5（app_key+partnerid+secret+create_time）
@property(nonatomic,strong) NSString *sign;
// 签名使用的时间戳
@property(nonatomic,strong) NSString *create_time;

// 未使用，内部测试专用
@property(nonatomic,strong) NSString *secret;


#pragma mark 电商相关参数，普通版本无需关注
/**
*  customer_code   商户对接id （仅电商版适用，如果没有app_key，请提供此编码）
*/
@property(nonatomic,strong) NSString *customer_code;
// 统一命名，使用customer_code替换
@property (nonatomic,strong) NSString   *customerCode NS_DEPRECATED_IOS(1.5,2_8_0);


/**
* 电商版本，初始化私钥
*/
@property(nonatomic,strong) NSString *platform_key;
// 使用platform_key替换
@property (nonatomic,copy) NSString * platformKey NS_DEPRECATED_IOS(1.0,2_8_0,"platform_key");


/**
 跨公司转接人工(仅电商版本可用)
 默认0不开启   1-全部溢出，2-忙碌时溢出，3-不在线时溢出
 */
@property(nonatomic,assign) int flow_type;
//使用flow_type替换
@property (nonatomic,assign)  int flowType NS_DEPRECATED_IOS(1.0,2_8_0);

/**
 跨公司转接人工(仅电商版本可用),转接到指定的公司ID
 */
@property(nonatomic,strong) NSString *flow_companyid;
// 使用flow_companyid替换
@property (nonatomic,strong)  NSString  * flowCompanyId NS_DEPRECATED_IOS(1.0,2_8_0);

/**
 跨公司转接人工(仅电商版本可用),转接到的公司技能组
 */
@property(nonatomic,strong) NSString *flow_groupid;
// 使用flow_groupid替换
@property (nonatomic,strong)  NSString  * flowGroupId NS_DEPRECATED_IOS(1.0,2_8_0);

/**
平台通道参数，初始化成功后会自动赋值
*/
@property(nonatomic,strong,readonly) NSString *platform_userid;
// 使用platform_userid替换
@property (nonatomic,strong,readonly) NSString *platformUserId NS_DEPRECATED_IOS(1.0,2_8_0,"platform_userid");


#pragma mark 用户信息相关字段
/**
*  用户唯一标识（对接用户可靠身份，不能写死，相同的值会获取同一份历史数据，不建议为null，如果为空会以设备区别）
*  最大不能超过300个字符
*  将自动备注到客户资料 （所有渠道统一参数名称，替换原有的userId）
*/
@property(nonatomic,strong) NSString *partnerid;

/**
*  用户昵称,用户咨询工作台显示名称，默认null，显示地区用户
*/
@property(nonatomic,strong) NSString *user_nick;
// 2.8.0以后使用user_nick
@property (nonatomic,strong) NSString   *nickName NS_DEPRECATED_IOS(1.0,2_8_0,"user_nick");

/**
*  用户的真实姓名， 将自动备注到客户资料，默认null
*/
@property(nonatomic,strong) NSString *user_name;
// 使用user_name替换
@property(nonatomic,strong) NSString   *realName NS_DEPRECATED_IOS(1.0,2_8_0,"user_name");

/**
*  用户电话，默认null
*/
@property(nonatomic,strong) NSString *user_tels;
// 使用user_tels 替换
@property (nonatomic,strong) NSString   *phone NS_DEPRECATED_IOS(1.0,2_8_0,"user_tels");

/**
*  用户邮箱，默认null
*/
@property(nonatomic,strong) NSString *user_emails;
//使用user_emails替换
@property (nonatomic,strong) NSString   *email NS_DEPRECATED_IOS(1.0,2_8_0,"user_emails");

/**
*  自定义用户头像，将自动备注到客户资料
*/
@property(nonatomic,strong) NSString *face;
// 使用face替换
@property (nonatomic,strong) NSString *avatarUrl NS_DEPRECATED_IOS(1.0,2_8_0,"face");


/**
*  接入来源页面标题，默认nil
*/
@property(nonatomic,strong) NSString *visit_title;
// 使用visit_title替换
@property(nonatomic,strong) NSString *sourceTitle NS_DEPRECATED_IOS(1.0,2_8_0,"visit_title");


/**
*  接入的来源URL，默认nil
*/
@property(nonatomic,strong) NSString *visit_url;
// 使用visit_url替换
@property (nonatomic,strong) NSString *sourceURL NS_DEPRECATED_IOS(1.0,2_8_0,"visit_url");


/**
 *  指定客户是否为vip，0:普通 1:vip
 *  同PC端 设置-在线客服分配-排队优先设置-VIP客户排队优先   开启传1 默认不设置
 *  开启后 指定客户发起咨询时，如果出现排队，系统将优先接入。
 **/
@property (nonatomic,copy) NSString *isVip;

/**
 *
 *  指定客户的vip等级，传入等级
 *  同PC端 设置-自定义字段-VIP等级(注意设置编码，不是显示值)
 **/
@property (nonatomic,copy) NSString *vip_level;

/**
 *用户标签,多个字段用逗号分隔
 **/
@property (nonatomic,copy) NSString *user_label;

/**
*  自定义用户资料,key-value随意定义，会自动显示在工作台客户资料中，默认nil
*/
@property(nonatomic,strong) NSDictionary *params;

// 使用 params替换
@property (nonatomic,strong) NSDictionary *customInfo NS_DEPRECATED_IOS(1.0,2_8_0,"params");


/**
* 固定KEY的自定义字段
* null
* 所有的KEY均在工作台创建设置后生效（设置->自定义字段->用户信息字段）
*/
@property(nonatomic,strong) NSDictionary *customer_fields;
// 使用customer_fields 替换
@property (nonatomic,strong) NSDictionary *customerFields NS_DEPRECATED_IOS(1.0,2_8_0,"customer_fields");


/**
*  用户的qq号码,默认nil
*/
@property(nonatomic,strong) NSString *qq;
// 使用qq替换
@property (nonatomic,strong) NSString *qqNumber NS_DEPRECATED_IOS(1.0,2_8_0,"qq");

/**
* 备注，默认nil,将自动显示到客服工作台客户资料
*/
@property(nonatomic,strong) NSString *remark;
// 使用 remark替换
@property (nonatomic,strong) NSString *userRemark NS_DEPRECATED_IOS(1.0,2_8_0,"remark");



#pragma mark 基础功能相关
/**
*  自定义接待模式 默认 0 ，跟随系统设置
*  1只有机器人，2.仅人工 ，3.智能客服-机器人优先，4智能客服-人工客服优先'
*/
@property(nonatomic,assign) int service_mode;
// 使用service_mode替换
@property (nonatomic,assign) int serviceMode NS_DEPRECATED_IOS(1.0,2_8_0,"service_mode");


/**
*  指定机器人ID  （可以转接到对应的机器人）
*/
@property(nonatomic,strong) NSString *robotid;
// 使用robotid替换
@property (nonatomic,strong) NSString  *robotId NS_DEPRECATED_IOS(1.0,2_8_0);

// 机器人自定义别名，与自己业务关联
@property (nonatomic,strong) NSString  *robot_alias NS_AVAILABLE_IOS(2.8.6);

/**
*   指定客服ID，  默认不设置
*/
@property(nonatomic,strong) NSString *choose_adminid;
// 请使用 choose_adminid代替
@property (nonatomic,strong)  NSString  * receptionistId NS_DEPRECATED_IOS(1.0,2_8_0);


/**
*  指定客服 转接类型
*       0 可转入其他客服 ， 1 必须转入指定客服
  （注意：如果当前指定的客服不在线，选择之后不能在转接到其他客服）
*/
@property(nonatomic,assign) int tran_flag;
//  指定客服 转接类型，使用tran_flag替换
@property (nonatomic,assign) int  tranReceptionistFlag NS_DEPRECATED_IOS(1.0,2_8_0);

/**
 *  转人工 指定技能组 溢出
 *  例如： [{"actionType":"to_group","optionId":"3","deciId":"162bb6bb038d4a9ea018241a30694064","spillId":"7"}, {"actionType":"to_group","optionId":"4","deciId":"a457f4dfe92842f8a11d1616c1c58dc1"}]
 参数说明：
 actionType:执行动作类型：to_group:转接指定技能组
 optionId:是否溢出  指定技能组时：3：溢出，4：不溢出。
 deciId:指定的技能组。
 spillId:溢出条件  指定客服组时：4:技能组无客服在线,5:技能组所有客服忙碌,6:技能组不上班,7:智能判断
 *
 */
@property(nonatomic,strong) NSArray *transferaction;
// 使用 transferaction 替换
@property (nonatomic,strong) NSArray *customGroupType NS_DEPRECATED_IOS(1.0,2_8_0,"transferaction");


/**
*  转人工传入 服务总结自定义字段
**/
@property(nonatomic,strong) NSDictionary *summary_params;
// 使用 summary_params 替换
@property (nonatomic,strong) NSDictionary * summaryParams NS_DEPRECATED_IOS(1.0,2_8_0,"summary_params");


/**
*
*  多轮会话 自定义字段 ， 默认 null
**/
@property(nonatomic,strong) NSDictionary *multi_params;
// 使用multi_params替换
@property (nonatomic,strong) NSDictionary *multiParams NS_DEPRECATED_IOS(1.0,2_8_0,"multi_params");


/**
*  指定技能组编号
*  转人工不在显示技能组选择框，直接转接到设置的技能组,不传不起作用
*/
@property(nonatomic,strong) NSString *groupid;
// 使用groupid替换
@property (nonatomic,strong) NSString *skillSetId NS_DEPRECATED_IOS(1.0,2_8_0,"groupid");


/**
*  指定技能组名称
*  转人工不在显示技能组选择框，直接转接到设置的技能组,不传不起作用(必须设置groupid，但是设置不起作用)
*/
@property(nonatomic,strong) NSString *group_name;
// 使用group_name替换
@property (nonatomic,strong) NSString   *skillSetName NS_DEPRECATED_IOS(1.0,2_8_0,"group_name");


/**
*  聊天页顶部标题 的自定义方式 ，0.默认，显示头像
 1.企业名称  2.自定义字段，3.仅显示文字、4显示头像和文字
*/
@property(nonatomic,strong) NSString *title_type;
// 使用title_type替换
@property (nonatomic,strong) NSString  *titleType NS_DEPRECATED_IOS(1.0,2_8_0,"title_type");


/**
*  聊天页顶部标题自定义字段 ,需配合title_tyoe使用
*/
@property(nonatomic,strong) NSString *custom_title;
// 使用custom_title替换
@property (nonatomic,strong) NSString  *customTitle NS_DEPRECATED_IOS(1.0,2_8_0,"custom_title");


/**
*  聊天页顶部标题自定义图片，,需配合title_tyoe使用
*/
@property(nonatomic,strong) NSString *custom_title_url;


/**
历史记录时间范围，单位分钟(例:100-表示从现在起前100分钟的会话,最小5分钟)
最大支持查询60天，如果不传是查询所有的
*/
@property(nonatomic,assign) int scope_time;
// 使用scope_time替换
@property (nonatomic,assign) int  scopeTime NS_DEPRECATED_IOS(1.0,2_8_0,"scope_time");


/**
*  自定义客服欢迎语,默认为空 （如果传入，优先使用该字段）
*/
@property(nonatomic,strong) NSString *admin_hello_word;
@property (nonatomic,strong) NSString * customAdminHelloWord NS_DEPRECATED_IOS(1.0,2_8_0,"admin_hello_word");


/**
*  自定义机器人欢迎语,默认为空 （如果传入，优先使用该字段）
*/
@property(nonatomic,strong) NSString *robot_hello_word;
@property (nonatomic,strong) NSString * customRobotHelloWord NS_DEPRECATED_IOS(1.0,2_8_0,"robot_hello_word");


/**
*  自定义用户超时提示语,默认为空 （如果传入，优先使用该字段）
*/
@property(nonatomic,strong) NSString *user_tip_word;
@property (nonatomic,strong) NSString * customUserTipWord NS_DEPRECATED_IOS(1.0,2_8_0,"user_tip_word");


/**
*  自定义客服不在线的说辞,默认为空 （如果传入，优先使用该字段）
*/
@property(nonatomic,strong) NSString *admin_offline_title;
@property (nonatomic,strong) NSString * customAdminNonelineTitle NS_DEPRECATED_IOS(1.0,2_8_0,"admin_offline_title");


/**
*  自定义客服超时提示语,默认为空 （如果传入，优先使用该字段）
*/
@property(nonatomic,strong) NSString *admin_tip_word;
@property (nonatomic,strong) NSString * customAdminTipWord NS_DEPRECATED_IOS(1.0,2_8_0,"admin_tip_word");


/**
*  自定义用户超时下线提示语,默认为空 （如果传入，优先使用该字段）
*/
@property(nonatomic,strong) NSString *user_out_word;
@property (nonatomic,strong) NSString * customUserOutWord NS_DEPRECATED_IOS(1.0,2_8_0,"user_out_word");


/**
*  通告图标 的url
*/
@property(nonatomic,strong) NSString *notifition_icon_url;
@property (nonatomic,strong) NSString   * notifitionIconUrl NS_DEPRECATED_IOS(1.0,2_8_0,"notifition_icon_url");



/**
*   是否允许请求热点引导问题接口，默认NO，不请求
*/
@property(nonatomic,assign) BOOL is_enable_hot_guide;
@property (nonatomic,assign) BOOL isEnableHotGuide NS_DEPRECATED_IOS(1.0,2_8_0,"is_enable_hot_guide");


/**
* 热点引导问题的扩展字段
*/
@property(nonatomic,strong) NSDictionary *margs;
@property (nonatomic,strong) NSDictionary * hotguideDict NS_DEPRECATED_IOS(1.0,2_8_0,"margs");


/**
*  自定发送商品订单信息类型，默认0
*  0 不发 1 给机器人发送 2 给人工发送  3 机器人和人工都发送
**/
@property(nonatomic,assign) int good_msg_type;
@property (nonatomic,assign) int goodMsgType NS_DEPRECATED_IOS(1.0,2_8_0,"good_msg_type");

//  ZCMessageTypeText  = 0, //文本
//  ZCMessageTypePhoto = 1, //图片
//  ZCMessageTypeFile  = 12, // 文件
//  ZCMessageTypeVideo = 23, // 视频
@property(nonatomic,assign) NSInteger auto_send_msgtype;

/**
*   自动发送文本内容，需要good_msg_type配合使用，单独设置无效
*   例如：“商品订单编号1403388282”，当auto_send_msgtype为图片、声音、文件、视频是，传本地资源路径(且只有人工支持)
*/
@property(nonatomic,copy) NSString *content;
// 使用content替换
@property (nonatomic,copy) NSString * goodMsg NS_DEPRECATED_IOS(1.0,2_8_0,"content");



/**
 *  指定客户优先
 *  同PC端 设置-在线客服分配-排队优先设置-指定客户优先   开启传1 默认不设置
 *  开启后 指定客户发起咨询时，如果出现排队，系统将优先接入。
 */
@property(nonatomic,assign) int queue_first;
// 使用queue_first替换
@property (nonatomic,assign) int queueFirst NS_DEPRECATED_IOS(1.0,2_8_0,"queue_first");


// 内部使用，uni-app渠道图片路径
@property(nonatomic,copy) NSString *wwwStaticPath NS_AVAILABLE_IOS(2.8.5);

/*
 默认语言，默认为en_lproj,可选ar_lproj,zh-Hans_lproj,zh-Hant_lproj....
 */
@property(nonatomic,copy) NSString *default_language NS_AVAILABLE_IOS(2.8.6);

/*
 指定语言，指定后系统不会在自动切换，如果不存在，会从服务器同步
 例如：可选ar_lproj,zh-Hans_lproj,zh-Hant_lproj,en_lproj...
 */
@property(nonatomic,copy) NSString *absolute_language NS_AVAILABLE_IOS(2.8.6);



/*
 指定接口语言，
 例如：en、zh-Hant、zh-Hans、pt、ar等
 */
@property(nonatomic,copy) NSString *locale NS_AVAILABLE_IOS(2.8.9);




/*
 指定引导语,不同的用户设置特定的引导语
 */
@property(nonatomic,assign) int faqId NS_AVAILABLE_IOS(2.9.2);


/**
 appInit 接口 0-非第一次进入 1-第一次进入
 */
@property(nonatomic,assign) int isFirstEntry  NS_AVAILABLE_IOS(3.0.2);



-(id)initByJsonDict:(NSDictionary *) dict;

@end
