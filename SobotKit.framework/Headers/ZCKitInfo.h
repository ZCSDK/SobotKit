//
//  ZCKitInitInfo.h
//  SobotKit
//
//  Created by zhangxy on 15/11/13.
//  Copyright © 2015年 zhichi. All rights reserved.
//
#import "ZCLibInitInfo.h"
#import "ZCProductInfo.h"



////////////////////////////////////////////////////////////////
// 自定义回调）
////////////////////////////////////////////////////////////////
@protocol ZCReceivedMessageDelegate <NSObject>

/**
 *  未读消息数获取
 *
 *  @param object 当前消息
 *  @param nleft  未读消息数
 */
-(void)onReceivedMessage:(id) message unRead:(int) nleft;

@end

/**
 *  未读消息数，block方式获取
 *
 *  @param message 当前消息
 *  @param nleft   未读消息数
 */
typedef void(^ReceivedMessageBlock)(id message,int nleft);


/**
 *  配置初始化自定义类
 *  自定义字体（可选） 自定义背景、边框线颜色（可选） 初始化必须参数（ZCLibInitInfo）
 */
@interface ZCKitInfo : NSObject

/**
 *  初始化必须参数（sysNum）
 */
@property(nonatomic,strong) ZCLibInitInfo *info;


/**
 *  接口域名
 */
@property(nonatomic,strong) NSString *apiHost;


/**
 *  是否保持会话，默认NO,点击返回直接断开会话链接
 */
//@property (nonatomic,assign) BOOL    isKeepSession;


/**
 *  自定义关闭的时候是否推送满意度评价
 *  默认为N0;
 *
 */
@property (nonatomic,assign) BOOL    isShowEvaluate;

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
 *  是否开启语音功能
 *  默认开启
 */
@property (nonatomic,assign) BOOL    isOpenRecord;


/**
 *  留言时是否显示手机号
 *
 *  默认 关闭
 */
@property (nonatomic,assign) BOOL    isShowPhoneNumber;

/**
 *  留言时是否显示昵称
 *
 *  默认关闭
 */
@property (nonatomic,assign) BOOL    isShowNickName;

/**
 *  留言时是否必须输入手机号（在显示手机号的情况下）
 *
 *  默认不输入
 */
@property (nonatomic,assign) BOOL    isAddPhoneNumber;

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


////////////////////////////////////////////////////////////////
// 自定义背景、边框线颜色，（可选）
////////////////////////////////////////////////////////////////

/**
 *  对话页面背景
 */
@property (nonatomic,strong) UIColor    *backgroundColor;

/**
 *  自定义风格颜色：导航
 *
 */
@property (nonatomic,strong) UIColor    *customBannerColor;


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
 *  是否设置相册背景图片
 */
@property (nonatomic ,assign) BOOL    isSetPhotoLibraryBgImage;



@property (nonatomic,strong) id<ZCReceivedMessageDelegate> delegate;
@property (nonatomic,strong) ReceivedMessageBlock          receivedBlock;

@end
