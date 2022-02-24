//
//  ZCUICore.h
//  SobotKit
//
//  Created by zhangxy on 2018/1/29.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCKitInfo.h"
#import "ZCLibInitInfo.h"

//#import "ZCButton.h"
//#import "ZCUIKeyboard.h"

#import "ZCLibMessageConstants.h"

#import "ZCLibConfig.h"
#import "ZCUILeaveMessageController.h"
#import "ZCChatView.h"
#import "ZCLibServer.h"


typedef NS_ENUM(NSInteger,ZCTurnType) {
    ZCTurnType_KeyWord                 = 1,  // 关键字转人工
    ZCTurnType_KeyWordNoGroup,               // 关键字转人工,直接转
    ZCTurnType_KeyWordSmart,                // 智能转人工，静默转
    ZCTurnType_CellGroupClick,              // 点击关键字cell 中技能组
    ZCTurnType_BtnClick,                    // 点击转人工按钮
    ZCTurnType_BtnClickUpOrDown,            // 点击转人工，踩活赞
    ZCTurnType_RepeatOrMood,                // 重复提问转人工 z或者 情绪负向转人工
    ZCTurnType_InitBeConnected,             // 初始化已经是人工
    ZCTurnType_InitOnUserType,              // 初始化仅人工或人工优先
    ZCTurnType_CustomKeyWord,               // 客户自定义关键字转人工，不出转人工按钮，在ZCLibInitInfo中配置
    ZCTurnType_OffMessageAdmin,            // 转接到发送过离线消息的客服
};

typedef NS_ENUM(NSInteger,ZCInitStatus) {
    ZCInitStatusLoading           = 1,  // 正在调用接口初始化
    ZCInitStatusLoadSuc           = 2,  // 初始化完成
    ZCInitStatusFail              = 3,  // 初始化失败
};

typedef NS_ENUM(NSInteger,ZCShowStatus) {
    ZCShowStatusWaiting          = 1,  // 排队
    ZCShowStatusUnRead           = 2,  // 有未读消息
    ZCShowStatusAddMessage       = 3,  // 新增了一条消息
    ZCShowStatusChangedTitle     = 4,  // 更新标题,如果为空就显示原始文案
    ZCShowStatusRobotStyle       = 5,  // 机器人模式
    ZCShowStatusUserStyle        = 6,  // 人工模式
    ZCShowStatusReConnected      = 7,  // 重新接入  新会话
    ZCShowStatusMessageChanged   = 8,  // 消息列表更新
    ZCInitStatusConnecting       = 9,  // 链接中
    ZCInitStatusConnectSuc       = 10,  // 链接成功
    ZCInitStatusConnectFail      = 11,  // 链接失败
    ZCInitStatusOpenNewWindow    = 12,  // 打开新窗口
    ZCShowStatusSatisfaction     = 13,  // 点击新会话键盘 中的满意度按钮 去评价
    ZCShowStatusLeaveMsgPage     = 14,  // 点击新会话键盘 中的留言按钮 去留言
    ZCInitStatusCompleteNoMore   = 15,  // 获取消息完成,并且没有更多数据
    ZCInitStatusStartMessages    = 16,  // 开始获取历史消息
    ZCInitStatusCloseSkillSet    = 17,  // 关闭技能组
    ZCShowStatusConnectingUser   = 18,  // 开始转人工
    ZCShowStatusConnectFinished  = 20,  // 转人工完成,(不保证转成功)
    
    /** 用户长时间不说话提醒 */
    ZCShowNSTimerUserTimeOut     = 21,
    
    /** 客服长时间不说话提醒 */
    ZCShowNSTimerAdminTimeOut    = 22,
    
    /** 添加评价页面 */
    ZCShowCustomActionSheet      = 23,
    
    /** 设置键盘样式 */
    ZCSetKeyBoardStatus          = 24,
    
    /**  刷新 listTabel*/
    ZCSetListTabelRoad           = 25,
    
    ZCShowStatusGoBack           = 26,// 返回到启动页面结束会话
    
    ZCTurnRobotFramChange        = 27,  // 多机器人切换按钮位置发生改变时
        
    ZCShowTurnRobotBtn           = 29, // 是否显示多机器人切换按钮
    
    ZCShowQuickEntryView         = 30,// 显示快捷入口，重新设置页面高度

    ZCShowStatusRefreshing       = 32,// 刷新进度条
    
    
    ZCShowTextHeightChanged      = 33,// 输入框高度变化了
};

/**
 *  ExitType  ENUM
 */
typedef NS_ENUM(NSInteger,LeaveExitType) {
    /** 直接退出SDK */
    LeaveExitTypeISCOLSE         = 1,
    /** 不直接退出SDK*/
    LeaveExitTypeISNOCOLSE       = 2,
    /** 仅人工模式 点击技能组上的留言按钮后,（返回上一页面 提交退出SDK）*/
    LeaveExitTypeISBACKANDUPDATE = 3,
    /** 机器人优先，点击技能组的留言按钮后，（返回技能组 提交和机器人会话）*/
    LeaveExitTypeISROBOT         = 4,
    /** 人工优先，点击技能组的留言按钮后，（返回技能组 提交机器人会话）*/
    LeaveExitTypeISUSER          = 5,
};


typedef NS_ENUM(NSInteger,ZCPagesType) {
    ZC_LeaveMsgPage    = 1,
    ZC_AskTabelPage    = 2,
    ZC_LeaveRecordPage = 3,
    ZC_LeaveOffLine    = 4, //发送留言离线消息，提交留言后 服务端会将用户下线
    ZC_UserClosePage   = 5,// 用户跳转到自己的页面后 关闭智齿页面
};


@protocol ZCUICoreDelegate <NSObject>

@optional
-(void)onPageStatusChanged:(ZCShowStatus )status message:(NSString *) message obj:(id) object;


/**
 *  设置聊天页面的title
 */
-(void)setTitleName:(NSString *)titleName;


/**
 *   聊天页面头部显示 连接中。。。
 **/
-(void)showSoketConentStatus:(ZCConnectStatusCode)statusCode;


/**
 *
 *  跳转到 留言和询前表单页面
 *
 **/
-(void)coreOpenNewPageVC:(ZCPagesType)type IsExist:(LeaveExitType) isExist  isShowToat:(BOOL) isShow  tipMsg:(NSString *)msg  Dict:(NSDictionary*)dict Object:(id)obj trunType:(ZCTurnType )type;
/**
 *
 *  跳转到评价页面 当前类中不能持有 chatView ,chatView 需要服从 ZCUICore的代理
 *
 **/
-(void)JumpCustomActionSheet:(int) sheetType andDoBack:(BOOL) isBack isInvitation:(int) invitationType Rating:(int)rating IsResolved:(int)isResolve;


// 刷新通告栏
-(void)beginAniantions;


// 留言模板页面
-(void)changeLeaveMsgType:(LeaveExitType) isExist;



/**
 评价成功

 @param model 评价成功model
 */
-(void)commentSusccess:(ZCLibMessage *) model;

@end

typedef void(^initResultBlock)(ZCInitStatus code,NSMutableArray *arr,NSString *result);

/**
 UI 相关逻辑处理类
 如：
    判断技能组
    判断是否发送消息
    判断是否显示训前表单
    转人工流程
 */
@interface ZCUICore : NSObject

@property(nonatomic,weak) id<ZCUICoreDelegate> delegate;

@property(nonatomic,copy) initResultBlock ResultBlock;

@property(nonatomic,copy) BOOL (^LinkClickBlock)(NSString *linkUrl); // 1129
@property(nonatomic,copy) void (^PageLoadBlock)(id object,ZCPageBlockType type);

@property(nonatomic,copy) void (^ZCViewControllerCloseBlock)(id object,ZCPageCloseType type); // 1129

@property(nonatomic,copy) void (^ZCClosePageBlock)(ZCPagesType type);

@property(nonatomic,strong) ZCKitInfo     *kitInfo;

@property(nonatomic,assign) BOOL isShowForm;// 是否直接去转人工，不在查询询前表单的接口

/** 记录对接客服ID 之后掉接口返回6 再去转人工 */
@property (nonatomic,assign) BOOL  isDoConnectedUser;

//@property (nonatomic,strong) ZCChatView * chatView; // 用于评价页面添加

@property(nonatomic,assign) BOOL  isDismissSheetPage; // 评价页面是否消失

@property(nonatomic,assign) BOOL  isDismissRobotPage; // 机器人是否消失

//@property (nonatomic,assign) BOOL isDismissSelMgePage; // 留言选择模板是否消失

@property(nonatomic,strong) NSString   *receivedName; // 存储当前页面的title

// 评价完成之后是否要添加满意度cell(刷新客服主动邀请的cell)
@property (nonatomic,assign)  BOOL            isAddServerSatifaction;

@property(nonatomic,strong) NSMutableArray *listArray;

@property(nonatomic,strong) NSMutableArray *cids;// cid 列表

/** 未知说辞计数*/
@property (nonatomic, assign) NSUInteger       unknownWordsCount;

// 播放时动画展示View
@property (nonatomic,strong) UIImageView    *animateView;

// 播放临时model，用于停止播放状态改变
@property (nonatomic,strong) ZCLibMessage    *playModel;

// 关键字转人工，机器人回复
@property (nonatomic,strong) ZCLibMessage    *keyworkRobotReplyModel;


@property (nonatomic,strong) NSString    *checkGroupId;
@property (nonatomic,strong) NSString    *checkGroupName;

// 记录中间变量
@property(nonatomic,assign) BOOL isSayHello;
@property(nonatomic,assign) BOOL isOffline;
@property(nonatomic,assign) BOOL isShowRobotHello; // 是否添加机器人欢迎语
@property (nonatomic,assign) BOOL isEvaluationService; // 是否评价过人工
@property (nonatomic,assign) BOOL isEvaluationRobot; // 是否评价过机器人
@property (nonatomic,assign) BOOL isOfflineBeBlack; // 是否是拉黑
@property(nonatomic,assign) BOOL isSendToUser;  // 给客服发送过消息
@property(nonatomic,assign) BOOL isSendToRobot; // 给机器人发送过消息
@property (nonatomic,assign) BOOL isAddNotice;// 是否添加通告消息

/** 是否正在初始化，网络变化时使用 */
@property (nonatomic,assign)  BOOL             isInitLoading;

@property(nonatomic,strong) ZCLibMessage *lineModel;

// 是否已经执行过转人工，再发送消息的时候使用，YES时，说明已经转过人工了，但是未说过话不做真正的转人工调用
@property (nonatomic,assign) BOOL isAfterConnectUser;
@property(nonatomic,strong) ZCLibMessage *afterModel;


@property(nonatomic,strong) NSDictionary *satisfactionDict; // 评价选项
@property(nonatomic,strong) NSString *inviteSatisfactionCheckLabels; // 邀请评价已选择的标签

@property(nonatomic,assign) BOOL currtChatOver;// 当前是评价完人工结束会话的状态  
+(ZCUICore *)getUICore;

-(ZCLibConfig *) getLibConfig;

-(ZCLibServer *)getAPIServer;

/**
 判断初始化接口
 
 @param info 当前初始化页面
 */
-(void)openSDKWith:(ZCLibInitInfo *) info uiInfo:(ZCKitInfo *) kitInfo Delegate:(id<ZCUICoreDelegate>)delegate blcok:(initResultBlock ) resultBlock ;


/**
 获取当前聊天记录

 @param appkey 那个appkey的聊天记录
 */
-(void)getChatMessages;



/// 转人工之前检查
/// @param type  转人工类型
/// @param message 影响转人工的对象
-(void)checkUserServiceWithType:(ZCTurnType) type model:(ZCLibMessage *) message;



/// 执行转人工，会做训前表单校验
/// @param msgModel 当前影响转人工的机器人回复
/// @param type  转人工类型
-(void)doConnectUserService:(ZCLibMessage *)msgModel connectType:(ZCTurnType) type;



/**
 * 用户自己拦截转人工的事件 调用自己的技能组页面
 * 可以重新设置ZClibInitInfo中的人工客服或是否继续往下转
 **/
-(void)customConnectUserService:(ZCLibMessage *) message KitInfo:(ZCKitInfo*)uiInfo ZCTurnType:(ZCTurnType) turnType;


/**
 隐藏技能组

 @return
 */
-(void)dismissSkillSetView;
-(UIView *)getSkillView;

/**
 *
 *   聊天Value 加载数据
 *   isNew 点击新会话
 **/
-(void)initConfigData:(BOOL)isFrist IsNewChat:(BOOL) isNew;



/**
 键盘页面点击事件处理

 @param status
 */
-(void)keyboardOnClick:(ZCShowStatus ) status;


/**
 *
 *  添加提示类的消息
 *
 **/
-(void)addTipsListenerMessage:(int)action;



/// 加载星级内容，成功以后，数据存在satisfactionDict中
/// @param loadResult 0成功，1失败
- (void)loadSatisfactionDictlock:(void (^)(int)) loadResult;


/**
 获取当前会话数据

 @return 会话列表
 */
-(NSMutableArray *) chatMessages;


/**
 *
 *  执行发送消息
 *
 **/
-(void) sendMessage:(NSString *)text questionId:(NSString*)question type:(ZCMessageType) type duration:(NSString *) time;
-(void) sendMessage:(NSString *)text questionId:(NSString*)question type:(ZCMessageType) type duration:(NSString *) time dict:(NSDictionary *)extendParams;

/**
 发送正在输入文本

 @param textView 文本框
 */
-(void)setInputListener:(UITextView *)textView;

/**
 退出聊天界面
 */
-(void)clearData;



/**
 销毁所有数据
 */
-(void)desctoryZCBlock;
-(void)desctory;



-(NSDictionary *)allExpressionDict;


// style == light ,dark
-(NSDictionary *)getZCThemeColorDict:(NSString *) style;



/**
 *
 *  执行评价逻辑
 *
 **/
-(void)keyboardOnClickSatisfacetion:(BOOL)isBcak;


/**
 *
 *  添加机器人欢迎语
 *
 **/
-(void)keyboardOnClickAddRobotHelloWolrd;


/**
 *
 *   评价页面的代理方法
 *
 **/
- (void)thankFeedBack:(int)type rating:(float)rating IsResolve:(int)isresolve;


/**
 *
 *   调用评价页面
 *
 **/
-(void)CustomActionSheet:(int) sheetType andDoBack:(BOOL) isBack isInvitation:(int) invitationType Rating:(int)rating IsResolved:(int)isResolve;

/**
 *
 *  提交评价
 *
 **/
- (void)commitSatisfactionWithIsResolved:(int)isResolved Rating:(int)rating problem:(NSString *) problem scoreFlag:(float)scoreFlag;

// 感谢您的评价
-(void)thankFeedBack;

/**
 *
 *  清除用户计数
 *   3.0.4 不在使用
 **/
//-(void)cleanUserCount;

/**
 *
 *  清除客服计数
 *   3.0.4不在使用
 **/
//-(void)cleanAdminCount;

/**
 *
 *  切换机器人之后添加机器人欢迎语 和热点引导
 *
 **/
-(void)changeRobotBtnClickAddRobotHelloWolrd;

/**
 *
 *  处理关键字转人工 拆分 人机问答接口的数据
 *
 **/
-(void)splitMessageModel:(ZCLibMessage *)msgModel Index:(NSInteger)index weakself:(ZCUICore*)safeVC;

/**
 *
 * 取消当前发送消息（上传文件）
 *
 **/
-(void)cancelSendFileMsg:(ZCLibMessage *)fileMsg;

// 当前是否显示客服欢迎语
-(BOOL)showChatAdminHello;

// 当前是否显示客服超时提醒
-(BOOL)showChatAdminOutTips;


// 检查是否有新的工单回复
-(void)checkUserTicketinfo;

-(void)pauseCount;

-(void)pauseToStartCount;

/**
 *  把本地数据，封装到展示Model上
 *
 *  @param action  类型
 *  @param msgType 数据类型0文本 1图片 2音频 3富文本
 *  @param voiceDuration 声音时长
 *  @param content   消息内容
 *  @param isOpen  1关闭 0开启
 *  @param _config 初始化对象
 *  @return
 */
-(ZCLibMessage *)setLocalDataToArr:(int) action
                              type:(int)msgType
                          duration:(NSString *) voiceDuration
                             style:(NSInteger) style
                              send:(BOOL) isSend
                              name:(NSString *)user_nick
                           content:(NSString *)content
                            config:(ZCLibConfig *) _config;

// 设置技能组ID 转人工时赋值，重新初始化的时候清空@”“ ，1.留言转离线消息页面使用 2.留言转工单模板接口使用
-(void)saveGroupIdWith:(NSString*)groupId;

// 获取技能组ID
-(NSString*)getTempGroupId;

/*
 *  机器人点踩 触发转人工提示语
 *
 */
-(void)addTipTurnToArtificialMsg;

/**
 *   获取临时存储的UID
 */
-(NSString *)getTempUid;

// 评价完人工结束会话之后 将config置为nil
-(void)setclosepamasAndClearConfig;
@end
