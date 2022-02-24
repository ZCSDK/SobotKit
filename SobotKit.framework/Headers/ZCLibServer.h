//
//  ZCLibServer.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ZCLibMessageConstants.h"
#import "ZCLibStatusDefine.h"
#import "ZCLibConfig.h"


/**
 *  ZC 接口核心类。
 *  <p/>
 *  所有 ZC 相关方法、监听器都由此调用和设置。
 */
@interface ZCLibServer : NSObject

/**
 *  获取核心操作类对象
 *  【注意：本方法不是单例模式，需要使用时自行保持对象为全局变量】
 *  @return 智齿核心处理类实例。
 */
+ (ZCLibServer *)getLibServer;

/**
 *  连接到智齿客服
 成功调用一次就可以，主要初始化一些必要参数，自动连接人工服务通道
  初始化参数,必须先设置[ZCLibClient getZCLibClient].libInitInfo
 *
 *  @param
 *  @param successBlock         初始化成功，返回初始化对象，同 getZClibConfig
 *  @param errorBlock           初始化失败，返回失败状态
 *  @param sysNumIncorrectBlock 企业编号错误
 */
- (void)initSobotChat:(void (^)(ZCLibConfig *config))successBlock
                 error:(void (^)(ZCNetWorkCode status,NSString *errorMessage))errorBlock
       appIdIncorrect:(void (^)(NSString *appId))appIdIncorrectBlock;

/**
 *  获取留言转离线消息配置接口
 *
 *  @param
 *  @param successBlock         请求成功 返回  msgLeaveTxt、 msgLeaveContentTxt参数值
 *  @param errorBlock           请求失败，返回失败状态
 */
- (void)initLeaveMsgConfig:(NSString *)groupId
                       uid:(NSString *)uid
                     error:(void (^)(ZCNetWorkCode status,NSString *errorMessage))errorBlock
                   success:(void(^)(NSString *msgLeaveTxt,NSString *msgLeaveContentTxt,NSString *leaveExplain)) successBlock;


/// 3.0.6新增接口
/// @param parameters  转人工参数
/// @param _config 当前初始化返回对象
/// @param startBlock   开始
/// @param resultBlock 结果回调（如果是fail，result是一个key为error的错误原因）
-(void)connectOnlineCustomer:(ZCLibOnlineCustomerParams *) parameters
                      config:(ZCLibConfig *) _config
                       start:(void(^)())startBlock
                      result:(void (^)(NSDictionary *result, ZCConnectUserStatusCode)) resultBlock;
/**
 *  转接人工
 *
 *  @param groupId     技能组
 *  @param groupName   技能组编号
 *  @param aid         对接客服ID
 *  @param tranFlag    是否必须转入指定客服
 *  @param isWaiting   当前是不是重复点击
 *  @param startBlock  开始请求
 *  @param errorBlock  转接失败
 *  @param resultBlock 请求结果
 *  @param transferType  转人工类型，0-不转，1-重复提问转人工，2-情绪负向转人工
 *  @param queueFlag 如果为1，展示排队或者客服不在线提示，为0不展示
 */
//-(void)connectOnlineCustomer:(NSString *) groupId
//                   groupName:(NSString *) groupName
//                      config:(ZCLibConfig *) _config
//                         Aid:(NSString *) aid
//                    TranFlag:(int) tranFlag
//                     Keyword:(NSString*)keyword
//                   KeywordId:(NSString *)keywordId
//                     current:(BOOL) isWaiting
//                TransferType:(int)transferType
//                   QueueFlag:(int)queueFlag
//                  ActionType:(NSArray*)actionType
//                  QueueFirst:(int)queueFirst
//                       start:(void(^)())startBlock
//                      result:(void (^)(NSDictionary *dict, ZCConnectUserStatusCode status)) resultBlock;

/**
 *  把本地数据，封装到展示Model上
  *
  *  @param action  当天消息动作类型
  *  @param msgType 消息类型ZCMessageType
  *  @param voiceDuration 声音时长
  *  @param style 提示类型，0是普通消息，大于0是提醒消息-2是弹屏商品信息
  *  @param content   消息内容
  *  @param isSend  YES自己发送，NO，按当前状态设置发送者
  *  @param _config 初始化对象
  *  @return
  */
+(ZCLibMessage *)setLocalDataToArr:(ZCTipMessageType) action
                              type:(int)msgType
                          duration:(NSString *) voiceDuration
                             style:(NSInteger) style
                              send:(BOOL) isSend
                              name:(NSString *)user_nick
                           content:(id )count
                            config:(ZCLibConfig *) config;



/**
 发送消息
 根据ZCLibConfig中的isArtificial类型，自动判断是否为机器人
 @param message 消息体,如图片、视频地址，字符串
 @param docId    引导说辞的问题编号
 @param type     消息类型
 @param duration 声音长度，如00:20,字符串类型，直接用于显示
 @param config 初始化返回
 @param roboflag
 @param extendsParams 扩展参数，如位置（lng经度,lat纬度，localLabel大标题  localName地址，file缩略图）
 @param startBlock    开始发送，返回用于显示的消息模型
 @param successBlock  发送成功，返回用于显示状态的消息模型
 @param progressBlock 发送进度，主要是图片和语言需要
 @param failBlock     发送失败，包括内容为空、文件不纯在、网络错误等，返回用于显示状态的消息模型，如果消息未发送，没有模型返回
 */
-(void)sendMessage:(NSString *)message
          questionId:(NSString*)docId
           msgType:(ZCMessageType ) type
          duration:(NSString *)duration
            config:(ZCLibConfig *)config
         robotFlag:(NSString *)roboflag
              dict:(NSDictionary *) extendsParams
             start:(void(^)(ZCLibMessage *message)) startBlock
           success:(void(^)(ZCLibMessage *message,ZCMessageSendCode sendCode)) successBlock
          progress:(void(^)(ZCLibMessage *message)) progressBlock
              fail:(void(^)(ZCLibMessage *message,ZCMessageSendCode errorCode)) failBlock;


/**
 发送机器人接口

 @param text 文档
 @param flag 
 int flag = 0;
 if(![@"" isEqual:sobotConvertToString(docId)]){
 flag = 1;
 }
 @param docId 问题的docId
 @param _config 当前config
 @param robotflag 机器人id
 @param startBlock 开始发送
 @param successBlock 发送成功
 @param failedBlock 发送失败
 */
-(void)sendToRobot:(NSString *)text
          showText:(NSString *)showText
       questionStr:(NSString *)question
      questionFlag:(int)flag
           msgType:(ZCMessageType ) type
        questionId:(NSString*)docId
            config:(ZCLibConfig *) _config
         robotFlag:(NSString *)robotflag
          duration:(NSString *)duration
             start:(void (^)(ZCLibMessage *))startBlock
           success:(void (^)(ZCLibMessage *, ZCMessageSendCode))successBlock
          progress:(void(^)(ZCLibMessage *message)) progressBlock
            failed:(void (^)(ZCLibMessage *, ZCMessageSendCode))failedBlock;

// 发送消息给人工客服
-(void)sendToUser:(NSString *)text
           config:(ZCLibConfig *) _config
          msgType:(ZCMessageType ) type
            start:(void (^)(ZCLibMessage *))startBlock
          success:(void (^)(ZCLibMessage *, ZCMessageSendCode))successBlock
           failed:(void (^)(ZCLibMessage *, ZCMessageSendCode))failedBlock;


// 转人工之前，发送消息给人工客服
-(void)sendFirstMsgToUser:(NSString *)text
           config:(ZCLibConfig *) _config
          msgType:(ZCMessageType ) type
            start:(void (^)(ZCLibMessage *))startBlock
          success:(void (^)(ZCLibMessage *, ZCMessageSendCode))successBlock
           failed:(void (^)(ZCLibMessage *, ZCMessageSendCode))failedBlock;


/**
 获取机器人引导语

 @param config 初始化信息
 @param robotId 机器人编号(指定机器人时配置)
 @param startBlock 开始
 @param successBlock 成功
 @param failBlock 失败
 */
- (void)getRobotGuide:(ZCLibConfig *) config
            robotFlag:(NSString *) robotId
                start:(void(^)(ZCLibMessage *message)) startBlock
              success:(void(^)(ZCLibMessage *message,ZCMessageSendCode sendCode)) successBlock
                 fail:(void(^)(ZCLibMessage *message,ZCMessageSendCode errorCode)) failBlock;




/**
 获取平台商户消息列表(仅平台电商版有用)
 @param userId 接入的用户Id
 @param startBlock 开始
 @param successBlock 成功
 @param failBlock 失败
 */
-(void)getPlatformMemberNews:(NSString *) partnerid
                 start:(void(^)()) startBlock
               success:(void(^)(NSMutableArray *news,NSDictionary *dictionary,ZCNetWorkCode sendCode)) successBlock
                failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;



/**
 根据商家appkey删除商户
 
 @param listId 消息列表返回的Id
 @param startBlock
 @param successBlock
 @param failedBlock
 */
-(void)delPlatformMemberByUser:(NSString *) listId
                       start:(void(^)()) startBlock
                     success:(void(^)(NSDictionary *dictionary,ZCNetWorkCode sendCode)) successBlock
                      failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 获取历史记录所有cid

 @param time
 历史记录时间范围，单位分钟(例:100-表示从现在起前100分钟的会话)
 @param config 初始化返回的配置对象，（仅使用uid）
 @param startBlock 开始
 @param successBlock 成功
 @param failBlock 失败
 */
-(void)getChatUserCids:(int) time
                config:(ZCLibConfig *) config
                 start:(void(^)()) startBlock
               success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

/**
 *  获取历史记录
 *
 *  @param cid       当前要查询的cid
 *  @param startBlock   开始查询
 *  @param successBlock 查询成功
 *  @param failedBlock  查询失败
 */
-(void)getHistoryMessages:(NSString *) cid
                  withUid:(NSString *) uid
                    start:(void(^)()) startBlock
                  success:(void(^)(NSMutableArray *messages,ZCNetWorkCode sendCode)) successBlock
                   failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 *  评价客户
 *
 *  @param params 参数说明
 cid 会话编号
 isresolve 是否解决问题，1是没有解决，0解决
 problem = 问题编号，没有传空 机器人：答非所问1 理解能力差2 问题不能回答3 不礼貌4  人工： 服务态度差,5  回答不及时,6 没解决问题,7 不礼貌,8
 source 分数（✨）
 suggest 描述
 type   0评价机器人，1评价人工
 userId 用户uid
 */
-(void)doComment:(NSMutableDictionary *) params result:(void (^)(ZCNetWorkCode code,int status,NSString *msg))resultBlock;


/**
 *  发送留言
 *  @param ticketContent 工单内容
 *  @param customerEmail 邮箱地址
 *  @param customerPhone 手机号码
 */
-(void)sendLeaveMessage:(NSMutableDictionary *) params
                 config:(ZCLibConfig *) config
             TemplateId:(NSString *)templateId
                success:(void (^)(ZCNetWorkCode code,int status,NSString *msg))successBlock
                 failed:(void (^)(NSString *errorMessage, ZCNetWorkCode erroCode))failedBlock;



/**
 *  获取技能组
 *  @param  startBlock     开始请求的回调
 *  @param  successBlock   请求成功的回调
 *  @param  failedBlock    请求失败的回调
 */
-(void)getSkillSet:(ZCLibConfig *) config
             start:(void (^)())startBlock
           success:(void(^)(NSMutableArray *messages,ZCNetWorkCode sendCode)) successBlock
            failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;



/**
 *  发送正在输入内容
 *
 *  @param content      正在输入的文本内容
 *  @param successBlock
 *  @param failedBlock  
 */
-(void)sendInputContent:(ZCLibConfig *) config
                content:(NSString *) content
                success:(void(^)(ZCNetWorkCode sendCode)) successBlock
                 failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;



/**
 *  登出
 */
-(void)logOut:(ZCLibConfig *) config;



/**
 退出推送
 */
-(void)loginOutPush:(void(^)(NSString *partnerid,NSString *token,NSError *err)) resultBlock;

/**
 *  下载文件
 *
 *  @param url           文件URL
 *  @param startBlock    开始下载
 *  @param successBlock  下载完成
 *  @param progressBlock 下载进度
 *  @param failBlock     下载结束
 */
-(void)downFileWithURL:(NSString *)url
             start:(void(^)()) startBlock
           success:(void(^)(NSData *data)) successBlock
          progress:(void(^)(float progress)) progressBlock
              fail:(void(^)(ZCNetWorkCode errorCode)) failBlock;


/**
 *  清空历史消息
 *
 *  @param uid 用户id
 */
-(void)cleanHistoryMessage:(NSString *) uid
                   success:(void(^)(NSData *data)) successBlock
                      fail:(void(^)(ZCNetWorkCode errorCode)) failBlock;


/**
config: 获取uid、cid、robotFlag
commentMessage：获取 docId 词条ID，docName 词条名称
Integer status 反馈结果-顶/踩 1 顶 0 踩
 */
-(void)rbAnswerComment:(ZCLibConfig *) config
               message:(ZCLibMessage *) commentMessage
                status:(int) status
                 start:(void(^)())startBlock
               success:(void(^)(ZCNetWorkCode code)) successBlock
                  fail:(void(^)(ZCNetWorkCode errorCode)) failBlock;


/**
 @parma filePath:文件路径
 @parma commanyId: 企业编号
 */
-(void)fileUploadForLeave:(NSString *) filePath
                config:(ZCLibConfig *) libConfig
                    start:(void(^)())startBlock
                  success:(void(^)(NSString *fileURL,ZCNetWorkCode code)) successBlock
                     fail:(void(^)(ZCNetWorkCode errorCode)) failBlock;


/**
 *  获取人工客服评价标签
 *  @parma uid 用户id
 *
 */
- (void)satisfactionMessage:(NSString*) uid
                      start:(void(^)())startBlock
                    success:(void(^)(NSDictionary * messageArr,ZCNetWorkCode code)) successBlock
                       fail:(void(^)(NSString* msg, ZCNetWorkCode errorCode)) failedBlock;



/**
 *  获取 询前表单自定义字段数据
 *   @param  uid   用户id
 *   @param  startBlock     开始请求的回调
 *   @param  successBlock   请求成功的回调
 *   @param  failedBlock    请求失败的回调
 *   @param  cusFieldArray  询前表单自定义字段
 **/
-(void)getAskTabelWithUid:(NSString *)uid
                        start:(void (^)())startBlock
                      success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                       failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 *   提交询前表单的接口
 *   @param   uid           用户ID
 *    @param  params        用户自定义字段
 *   @param  successBlock   请求成功的回调
 *   @param  failedBlock    请求失败的回调
 *   @param  cusFieldArray  询前表单自定义字段
 */
-(void)postAskTabelWithUid:(NSString *)uid
                     Parms:(NSMutableDictionary *) params
                     start:(void (^)())startBlock
                   success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                    failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;




/**
 *   获取省市县 接口
 *
 *
 **/
-(void)getAddressWithLevel:(int)level
             nextaddressId:(NSString *)addId
                     start:(void (^)())startBlock
                   success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                    failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;



/**
    获取热点引导问题
 
 @param config 初始化信息
 @param Parms 用户传入的自定义字段
 @param startBlock 开始
 @param successBlock 成功
 @param failBlock 失败
 */
- (void)getHotGuide:(ZCLibConfig *) _config
              Parms:(NSMutableDictionary *) params
              start:(void(^)(ZCLibMessage *message)) startBlock
            success:(void(^)(ZCLibMessage *message,ZCMessageSendCode sendCode)) successBlock
               fail:(void(^)(ZCLibMessage *message,ZCMessageSendCode errorCode)) failBlock;

/**
     获取 分词联想接口
      @param config 初始化信息  用户uid
      @param Parms   机器人编号  问题
      @param startBlock 开始
      @param successBlock 成功
      @param failBlock 失败

 **/
-(void)getrobotGuess:(ZCLibConfig *)config
               Parms:(NSMutableDictionary *) params
               start:(void(^)(ZCLibMessage *message)) startBlock
             success:(void(^)(NSDictionary *dict,ZCMessageSendCode sendCode)) successBlock
                fail:(void(^)(NSString *errorMsg,ZCMessageSendCode errorCode)) failBlock;


/**
 *  获取机器人列表接口
 *
 *
 **/
-(void)getrobotlist:(ZCLibConfig *)config
               start:(void (^)())startBlock
             success:(void(^)(NSDictionary *dict,ZCMessageSendCode sendCode)) successBlock
                fail:(void(^)(NSString *errorMsg,ZCMessageSendCode errorCode)) failBlock;



/**
 *  获取 快捷入口标签 接口
 *
 *
 **/
-(void)getLableInfoList:(ZCLibConfig*)config
                  start:(void(^)())startBlocl
                success:(void(^)(NSDictionary *dict,ZCMessageSendCode sendCode)) successBlock
                   fail:(void(^)(NSString * errorMsg,ZCMessageSendCode errorCode)) failBlock;

/**
 *
 *  获取留言模板  post  带技能组ID 接口
 *
 **/
-(void)getWsTemplateList:(ZCLibConfig *)config
                     uid:(NSString*)uid
                 groupId:(NSString *)groupId
                   start:(void (^)())startBlock
                 success:(void(^)(NSDictionary *dict,ZCMessageSendCode sendCode)) successBlock
                    fail:(void(^)(NSString *errorMsg,ZCMessageSendCode errorCode)) failBlock;


/**
 *   获取 留言模板基础配置 2.7.1新增
 *  @param  uid          用户ID
 *  @param  templateld          留言模板id
 *  @param  startBlock     开始请求的回调
 *  @param  successBlock   请求成功的回调
 *  @param  failedBlock    请求失败的回调
 */
-(void)postMsgTemplateConfigWithUid:(NSString *)uid
                         Templateld:(NSString *)templateld
                              start:(void (^)())startBlock
                            success:(void(^)(NSDictionary *dict,NSMutableArray * typeArr,ZCNetWorkCode sendCode)) successBlock
                             failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

/**
 *  获取留言模板自定义字段 2.7.1新增
 *  @param  templateld          留言模板id
 *  @param  uid          用户ID
 *  @param  startBlock     开始请求的回调
 *  @param  successBlock   请求成功的回调
 *  @param  failedBlock    请求失败的回调
 *
 **/
-(void)postTemplateFieldInfoWithUid:(NSString *)uid
                         Templateld:(NSString *)templateld
                              start:(void (^)())startBlock
                            success:(void(^)(NSDictionary *dict,NSMutableArray * cusFieldArray,ZCNetWorkCode sendCode)) successBlock
                             failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

/**
 *  获取用户留言记录列表接口 2.7.1 新增
 *   uid  用户id
 *
 **/
-(void)postUserTicketInfoListWithConfig:(ZCLibConfig*)config
                                  start:(void (^)())startBlock
                                success:(void(^)(NSDictionary *dict,NSMutableArray * itemArray,ZCNetWorkCode sendCode)) successBlock
                                 failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

/**
 *  获取用户留言记录详情页接口 2.7.1 新增
 *  ticketld  工单id
 *  dict : {
 *  partnerid
 *  uid
 *  companyId
 * }
 *
 **/
-(void)postUserDealTicketinfoListWith:(NSDictionary *)dict
                             ticketld:(NSString *)ticketld
                                start:(void (^)())startBlock
                              success:(void(^)(NSDictionary *dict,NSMutableArray * itemArray,ZCNetWorkCode sendCode)) successBlock
                               failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 *   获取 留言模板基础配置 2.7.1新增
 *  @param  config        初始化对象
 *  @param  param          回复字典
 *  @{@"ticketId":@"工单编号",
 *  @"replyContent":@"回复内容",
 *  @"fileStr":@"附件路径，多个附件中间以分号分隔",
 *  @"companyId":@"公司id"}
 *  @param  startBlock     开始请求的回调
 *  @param  successBlock   请求成功的回调
 *  @param  failedBlock    请求失败的回调
 */
-(void)replyLeaveMessage:(ZCLibConfig*)config
             replayParam:(NSDictionary *)params
                   start:(void (^)())startBlock
                 success:(void(^)(NSDictionary *dict,NSMutableArray * itemArray,ZCNetWorkCode sendCode)) successBlock
                  failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 *   获取 留言 回复内容
 *  @param  param          回复字典
 *  @{
 *  @"partnerId":@"用户id",
 *  @"companyId":@"公司id"}
 *  @param  startBlock     开始请求的回调
 *  @param  successBlock   请求成功的回调
 *  @param  failedBlock    请求失败的回调
 */
-(void)getLastReplyLeaveMessage:(NSMutableDictionary *)params
                      start:(void (^)())startBlock
                    success:(void(^)(NSDictionary *dict,NSMutableArray * itemArray,ZCNetWorkCode sendCode)) successBlock
                     failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;
/**
 *   设置留言回复已读状态
 *  @param  param          回复字典
 *  @{@"ticketId":@"工单编号",
 *  @"partnerId":@"对接id",
 *  @"companyId":@"公司id"}
 *  @param  startBlock     开始请求的回调
 *  @param  successBlock   请求成功的回调
 *  @param  failedBlock    请求失败的回调
 */
-(void)updateUserTicketReplyInfo:(NSMutableDictionary *)params
                           start:(void (^)())startBlock
                         success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                          failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;



/**
 *  获取用户留言是否有反馈的接口 2.7.1 新增
 *  如果初始化appint接口里面返回的customerId有值，才能调用该接口，如果customerId没值则不可能有最新留言回复
 *
 **/
-(void)postcheckUserTicketInfoWith:(ZCLibConfig*)config
                                start:(void (^)())startBlock
                              success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                               failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 *  获取帮助中心分类列表数据 2.7.4 新增
 *  appid ：appkey
 *
 **/
-(void)getCategoryWith:(NSString*)appId
                             start:(void (^)())startBlock
                           success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                            failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 * 帮助中心  根据分类查询分类下的问题
 * appid ：appkey
 * categoryId： 分类id
 **/
-(void)getHelpDocByCategoryIdWith:(NSString*)appId
            CategoryId:(NSString *)categoryId
                 start:(void (^)())startBlock
               success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

/**
 * 帮助中心  根据词条id查询词条详情
 * appid ：appkey
 * docId： 词条id
 **/
-(void)getHelpDocByDocIdWith:(NSString*)appId
                       DocId:(NSString *)docId
                       start:(void (^)())startBlock
                     success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                      failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;


/**
 * 留言转离线消息接口
 * uid ：用户id
 * content： 留言内容
 * groupId : 技能组ID
 **/
-(void)getLeaveMsgWith:(NSString*)uid
               Content:(NSString *)content
               groupId:(NSString *)groupId
                 start:(void (^)())startBlock
               success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

/**
 *
 *  提交工单评价 （工单详情页面触发评价）
 *
 **/
-(void)postAddTicketSatisfactionWith:(NSString*)ticketId
                                 Uid:(NSString*)uid
                           CompanyId:(NSString*)companyId
                               Score:(NSString*)score
                              Remark:(NSString*)remark
                               start:(void (^)())startBlock
                             success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                              failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;
/**
 *
 *   sdk保存发给用户的系统消息 (机器人点踩，触发转人工提示语 并发送给服务端保存)
 *
 **/
-(void)insertSysMsg:(ZCLibConfig *) config
                msg:(NSString*)msg
             start:(void (^)())startBlock
           success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
             failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;




/// sdk敏感词授权
/// @param config  获取uid用
/// @param type 0 拒绝 1同意
/// @param startBlock 开始
/// @param successBlock 成功，返回成功的dict
/// @param failedBlock  失败
-(void)authSendMessageSensitive:(ZCLibConfig *) config
                           type:(NSInteger) type
                          start:(void (^)())startBlock
                        success:(void(^)(NSDictionary *dict,ZCNetWorkCode sendCode)) successBlock
                         failed:(void(^)(NSString *errorMessage,ZCNetWorkCode errorCode)) failedBlock;

@end
