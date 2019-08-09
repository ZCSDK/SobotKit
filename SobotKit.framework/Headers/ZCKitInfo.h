//
//  ZCKitInitInfo.h
//  SobotKit
//
//  Created by zhangxy on 15/11/13.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import "ZCProductInfo.h"


/**
 *  配置初始化自定义类（UI配置相关）
 *  自定义字体（可选） 自定义背景、边框线颜色（可选）
 */
@interface ZCKitInfo : NSObject



/**
 仅支持竖屏
 */
@property (nonatomic,assign) BOOL isShowPortrait;

/**
 *
 *  SDK 页面中使用自定义的导航栏不在使用 系统的导航栏（影藏）
 *  默认 为NO 跟随集成项目
 **/
@property (nonatomic,assign) BOOL navcBarHidden;

/**
 *  接口域名,从2.6.5版本开始，本属性不起作用，请使用ZCLibInitInfo.apiHost
 *  @deprecated 2018-09-05: Use ZCLibInitInfo.h  instead
 */
@property(nonatomic,strong) NSString *apiHost;

/**
 *
 *   人工状态，是否可以发送位置
 【 注意：
 由于各家定位插件特别多，智齿没有实现选择位置功能，所以需要自行传递位置到SDK以及打开显示，步骤如下：
 1、实现messageLinkClick事件（ZCSobot startZCChatVC函数中）
 2、当收到link = sobot://sendlocation 调用智齿接口发送位置信息
 3、当收到link = sobot://openlocation?latitude=xx&longitude=xxx&address=xxx 可根据自己情况处理相关业务
】
 *
 **/
@property (nonatomic,assign) BOOL canSendLocation;


/**
 *
 *   导航栏右上角 是否显示 评价按钮  默认不显示
 *
 **/
@property (nonatomic,assign) BOOL isShowEvaluation;

/**
 *
 *   针对关闭按钮，单独设置是否显示评价界面，默认不显示
 *
 **/
@property (nonatomic,assign) BOOL isShowCloseSatisfaction;

/**
 *
 *   导航栏右上角 是否显示 拨号按钮 默认不显示    注意：和isShowEvaluation 互斥 只能设置一个有效
 *
 **/
@property (nonatomic,assign) BOOL isShowTelIcon;


/**
 *
 *   导航栏左上角 是否显示 关闭按钮 默认不显示，关闭按钮，点击后无法监听后台消息
 *
 **/
@property (nonatomic,assign) BOOL isShowClose;

/**
 *  设置电话号码
 *  当导航栏右上角 显示 拨号按钮时  （和isShowTelIcon 一起设置有效）
 *
 **/
@property (nonatomic,copy) NSString * customTel;


////////////////////////////////////////////////////////////////
//   和UI相关的配置参数自定义可选项                                //
//                                                            //
////////////////////////////////////////////////////////////////


/**
 *  是否使用Images
 *  默认为NO 未开启
 *
 */
@property (nonatomic,assign) BOOL      isUseImagesxcassets;

/**
 *  评价完人工是否关闭会话（人工满意度评价后释放会话）
 *  默认为NO 未开启
 *
 */
@property (nonatomic,assign) BOOL      isCloseAfterEvaluation;

/**
 *  返回时是否开启满意度评价
 *  默认为NO 未开启
 *
 */
@property (nonatomic,assign) BOOL      isOpenEvaluation;

/**
 *  自定义关闭的时候是否推送满意度评价
 *  默认为N0;
 *
 */
//@property (nonatomic,assign) BOOL    isShowEvaluate;

/**
 *  机器人优先模式，是否直接显示转人工按钮(值为NO时，会在机器人无法回答时显示转人工按钮)，默认，YES
 */
@property (nonatomic,assign) BOOL    isShowTansfer;

/**
 *  机器人优先模式，通过记录机器人未知说辞的次数设置是否直接显示转人工按钮
 *  默认 0次。
 */
@property (nonatomic,strong) NSString *unWordsCount;



/**
 *  是否开启智能转人工,(如输入“转人工”，直接转接人工)
 * 需要隐藏转人工按钮，请参见isShowTansfer和unWordsCount属性
 */
@property (nonatomic,assign) BOOL  isOpenActiveUser;

/**
 智能转人工关键字，关键字作为key{@"转人工",@"1",@"R":@"1"}
 */
@property (nonatomic,strong) NSDictionary *activeKeywords;


/**
 *  自定义快捷入口
 *  填充内容为： ZCLibCusMenu.h
 *  url: 快捷入口链接(点击后会调用初始化linkBock)
 *  title: 按钮标题
 *  lableId: 自定义快捷入口的ID
 *
 **/
@property (nonatomic,strong) NSMutableArray * cusMenuArray;



/**
 * 自定义输入框下方更多(+号图标)按钮下面内容(不会替换原有内容，会在原有基础上追加)
 * 修改人工模式的按钮
 * 填充内容为：ZCLibCusMenu.h
 *  title:按钮名称
 *  url：点击链接(点击后会调用初始化linkBock)
 *  imgName:本地图片名称，如xxx@2x.png,icon=xxx
 */
@property (nonatomic,strong) NSMutableArray * cusMoreArray;

/**
 * 自定义输入框下方更多(+号图标)按钮下面内容(不会替换原有内容，会在原有基础上追加)
 * 修改机器人模式的按钮
 * 填充内容为：ZCLibCusMenu.h
 *  title:按钮名称
 *  url：点击链接(点击后会调用初始化linkBock)
 *  imgName:本地图片名称，如xxx@2x.png,icon=xxx
 */
@property (nonatomic,strong) NSMutableArray * cusRobotMoreArray;

/**
 *  是否开启语音功能
 *  默认开启
 */
@property (nonatomic,assign) BOOL    isOpenRecord;


/**
 是否开启机器人语音，（付费，否则语音无法识别）
 默认NO
 */
@property (nonatomic,assign) BOOL    isOpenRobotVoice;



/**
 *  留言时是否显示昵称
 *
 *  默认关闭
 */
@property (nonatomic,assign) BOOL    isShowNickName;


/**
 *  留言时是否必须输入昵称 (在显示昵称的情况下)
 *
 *  默认不输入
 */
@property (nonatomic,assign) BOOL    isAddNickName;


////////////////////////////////////////////////////////////////
// 自定义咨询内容，在转接人工成功时，方便用户发送自己咨询的信息，（可选）
// 标题（必填）、页面地址url（必填）、摘要、标签、缩略图url
////////////////////////////////////////////////////////////////

/**
 *  产品信息
 */
@property(nonatomic,strong) ZCProductInfo *productInfo;



////////////////////////////////////////////////////////////////
// 自定义字体，（可选）
////////////////////////////////////////////////////////////////

/**
 *  顶部标题颜色、评价标题
 */
@property (nonatomic,strong) UIFont    *titleFont;

/**
 *  页面返回按钮，输入框，评价提交按钮、Toast提示语
 */
@property (nonatomic,strong) UIFont    *listTitleFont;

/**
 *  各种按钮，网络提醒
 */
@property (nonatomic,strong) UIFont    *listDetailFont;

/**
 *  是否有以下情况
 */
@property (nonatomic,strong) UIFont    *customlistDetailFont;

/**
 *  消息提醒(转人工、客服接待等)
 */
@property (nonatomic,strong) UIFont    *listTimeFont;

/**
 *  聊天气泡中文字
 */
@property (nonatomic,strong) UIFont    *chatFont;

/**
 *  录音按钮的文字
 */
@property (nonatomic,strong) UIFont    *voiceButtonFont;


/**
 *   商品详情cell 中title的文字
 *
 */
@property (nonatomic,strong) UIFont   *goodsTitleFont;

/**
 *   商品详情cell中 摘要的文字
 *
 */
@property (nonatomic,strong) UIFont   *goodsDetFont;

/**
 *    商品详情cell中 btn的背景色
 *
 */
@property (nonatomic,strong) UIColor    *goodSendBtnColor;


/**
 *
 * 网络状态中的背景色（连接中） （已弃用）
 *  @deprecated 2018-07-31: Use customBannerColor  instead
 *
 */
//@property (nonatomic,strong) UIColor    *socketStatusButtonBgColor;


/**
 *
 * 网络状态中的背景色（连接中） （已弃用）
 *  @deprecated 2018-07-31: Use customBannerColor  instead
 *
 */
//@property (nonatomic,strong) UIColor    *socketStatusButtonTitleColor;


/**
 *  满意度星级说明的文字颜色
 */
@property (nonatomic,strong) UIColor    *scoreExplainTextColor;


////////////////////////////////////////////////////////////////
// 自定义背景、边框线颜色，（可选）
////////////////////////////////////////////////////////////////

/**
 *  对话页面背景
 */
@property (nonatomic,strong) UIColor    *backgroundColor;




/**
 *  自定义风格颜色：导航
 */
@property (nonatomic,strong) UIColor    *customBannerColor;


/**
 *  机器人的问答中 提示转人工按钮的文字颜色
 *
 */
@property (nonatomic,strong) UIColor    *trunServerBtnColor;

/**
 *  相册导航栏的颜色
 *
 */
@property (nonatomic,strong) UIColor   *imagePickerColor;

/**
 *  相册导航栏的标题颜色
 *
 */
@property (nonatomic,strong) UIColor  *imagePickerTitleColor;


/**
 *  左边聊天气泡颜色
 */
@property (nonatomic,strong) UIColor    *leftChatColor;

/**
 *  右边聊天气泡颜色
 */
@property (nonatomic,strong) UIColor    *rightChatColor;

/**
 *  左边聊天气泡复制选中的背景颜色
 */
@property (nonatomic,strong) UIColor    *leftChatSelectedColor;

/**
 *  右边聊天气泡复制选中的背景颜色
 */
@property (nonatomic,strong) UIColor    *rightChatSelectedColor;


/**
 *  底部bottom的背景颜色
 */
@property (nonatomic,strong) UIColor    *backgroundBottomColor;


/**
 *  底部bottom框边框线颜色(输入框、录音按钮、分割线)
 */
@property (nonatomic,strong) UIColor    *bottomLineColor;

/**
 *  评价普通按钮选中背景颜色和边框(默认跟随主题色customBannerColor)
 */
@property (nonatomic,strong) UIColor    *commentOtherButtonBgColor;

/**
 *  评价(立即结束、取消)按钮文字颜色(默认跟随主题色customBannerColor)
 */
@property (nonatomic,strong) UIColor    *commentCommitButtonColor;

/**
 * 评价提交按钮背景颜色和边框(默认跟随主题色customBannerColor)
 */
@property (nonatomic,strong) UIColor    *commentCommitButtonBgColor;

/**
 *  评价提交按钮点击后背景色，默认0x089899, 0.95
 */
@property (nonatomic,strong) UIColor    *commentCommitButtonBgHighColor;


/**
 *  提示气泡的背景颜色
 */
@property (nonatomic,strong) UIColor    *BgTipAirBubblesColor;

/**
 * 语音cell选中的背景色
 *
 */
@property (nonatomic,strong) UIColor    *videoCellBgSelColor;

/**
 *
 *  富文本中的线条颜色
 *
 */
@property (nonatomic,strong) UIColor    *LineRichColor;

/**
 *
 *  通告栏的背景色
 *
 */
@property (nonatomic,strong) UIColor    *notificationTopViewBgColor;

/**
 *
 *  通告栏的文字颜色
 *
 */
@property (nonatomic,strong) UIColor    *notificationTopViewLabelColor;

/**
 *
 *  通告栏的字体设置
 *
 */
@property (nonatomic,strong) UIFont    *notificationTopViewLabelFont;





////////////////////////////////////////////////////////////////
// 自定义文字颜色，（可选）
////////////////////////////////////////////////////////////////

/**
 *  提价评价按钮的文字颜色
 */
@property (nonatomic,strong) UIColor    *submitEvaluationColor;

/**
 *  顶部文字颜色
 */
@property (nonatomic,strong) UIColor    *topViewTextColor;

/**
 *  左边气泡文字颜色
 */
@property (nonatomic,strong) UIColor    *leftChatTextColor;


/**
 *  右边气泡文字颜色
 */
@property (nonatomic,strong) UIColor    *rightChatTextColor;

/**
 *  时间文字的颜色
 */
@property (nonatomic,strong) UIColor    *timeTextColor;

/**
 *  提示气泡文字颜色
 */
@property (nonatomic,strong) UIColor    *tipLayerTextColor;

/**
 *  客服昵称颜色
 */
@property (nonatomic,strong) UIColor    *serviceNameTextColor;

/**
 *  提示cell中客服昵称的文字颜色
 */
@property (nonatomic,strong) UIColor    *nickNameTextColor;


/**
 *  左边气泡中的链接颜色
 */
@property (nonatomic,strong) UIColor   *chatLeftLinkColor;


/**
 *  右边气泡中的链接颜色
 */
@property(nonatomic,strong) UIColor    *chatRightLinkColor;


/**
 *  商品详情cell中title的文字颜色
 *
 */
@property (nonatomic, strong) UIColor   *goodsTitleTextColor;

/**
 *  商品详情cell中摘要的文字颜色
 *
 */
@property (nonatomic, strong) UIColor   *goodsDetTextColor;

/**
 *  商品详情cell中标签的文字颜色
 *
 */
@property (nonatomic ,strong) UIColor   *goodsTipTextColor;

/**
 *  商品详情cell中发送的文字颜色
 *
 */
@property (nonatomic, strong) UIColor   *goodsSendTextColor;

/**
 *  提交评价后将结束会话的文字颜色
 *
 */
@property (nonatomic, strong) UIColor   *satisfactionTextColor;


/**
 *  暂不评价文字颜色
 *
 */
@property (nonatomic, strong) UIColor   *noSatisfactionTextColor;


/**
 *  评价页面中 已解决 未解决  文字的高亮状态颜色
 *
 */
@property (nonatomic, strong) UIColor   *satisfactionTextSelectedColor;


/**
 *  评价页面中 已解决 未解决 按钮的选中的背景色
 *
 */
@property (nonatomic, strong) UIColor   *satisfactionSelectedBgColor;



/**
 *  是否设置相册背景图片
 */
@property (nonatomic ,assign) BOOL    isSetPhotoLibraryBgImage;


/**
 *  多轮会话模板四的超链颜色
 */
@property (nonatomic,strong) UIColor   *chatLeftMultColor;


/**
 *  多轮会话中 展开和收起的文字颜色
 */
@property (nonatomic,strong) UIColor * openMoreBtnTextColor;

/**
 *
 *  更多按钮默认图片
 *
 **/
@property (nonatomic,copy) NSString * moreBtnNolImg;

/**
 *
 *  更多按钮选中图片
 *
 **/
@property (nonatomic,copy) NSString * moreBtnSelImg;

/**
 *
 *  转人工按钮默认图片
 *
 **/
@property (nonatomic,copy) NSString * turnBtnNolImg;

/**
 *
 *  转人工按选中图片
 *
 **/
@property (nonatomic,copy) NSString * turnBtnSelImg;

/**
 *
 *  返回按钮默认图片
 *
 **/
@property (nonatomic,copy) NSString * topBackNolImg;

/**
 *
 *  返回按钮选中图片
 *
 **/
@property (nonatomic,copy) NSString * topBackSelImg;

/**
 *
 *  返回按钮的默认背景色
 *
 **/
@property (nonatomic,strong) UIColor * topBackNolColor;

/**
 *
 *  返回按钮的高亮背景色
 *
 **/
@property (nonatomic,strong) UIColor * topBackSelColor;

/**
 *
 *  导航栏背景色 （单独修改）
 *
 **/
@property (nonatomic,strong) UIColor * topViewBgColor;



/**
 *
 *  顶踩 文字 默认颜色
 *
 **/
@property (nonatomic,strong) UIColor * topBtnNolColor;

/**
 *
 *  顶踩 文字 选中颜色
 *
 **/
@property (nonatomic,strong) UIColor * topBtnSelColor;

/**
 *
 *  顶踩 文字 置灰颜色
 *
 **/
@property (nonatomic,strong) UIColor * topBtnGreyColor;

/**
 *
 *   聊天页面 左上角 返回按钮的文字 （默认 返回）
 *
 **/
@property (nonatomic,copy) NSString * topBackTitle;




/****************   2.7.4  新增  ****************/

/**
 *
 *  留言页面中 提交按钮的文字颜色
 *
 **/
@property (nonatomic,strong) UIColor * leaveSubmitBtnTextColor;



/**
 *
 *  留言页面中 提交按钮的背景颜色
 *
 **/
@property (nonatomic,strong) UIColor * leaveSubmitBtnImgColor;

//**********************     帮助中心       ***************/
/**
 *
 * 帮助中心 标题的文字颜色
 *
 **/
@property (nonatomic,strong) UIColor * scTopTextColor;

/**
 *
 *  帮助中心 标题font
 *
 **/
@property (nonatomic,strong) UIFont * scTopTextFont;


/**
 *
 *  帮助中心 导航条背景色
 *
 **/
@property (nonatomic,strong) UIColor * scTopBgColor;

/**
 *
 * 帮助中心 顶部返回的文字颜色
 *
 **/
@property (nonatomic,strong) UIColor * scTopBackTextColor;

/**
 *
 *  帮助中心 顶部返回按钮的文字字号
 *
 **/
@property (nonatomic,strong) UIFont * scTopBackTextFont;

//**********************     帮助中心    end   ***************/

/**
 *
 *   商品卡片信息是否自动发送（转人工成功时，自动发送商品卡片信息）
 *   默认不发送
 **/
@property (nonatomic,assign) BOOL isSendInfoCard;

@end
