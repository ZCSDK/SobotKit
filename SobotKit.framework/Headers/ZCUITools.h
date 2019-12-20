//
//  ZCUITools.h
//  SobotKit
//
//  Created by zhangxy on 15/11/11.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  ZC UI工具类
 *  获取SobotKit.bundle中的图片 获取完整bundle路径 自定义字体 自定义字体颜色 自定义颜色 检查是否有相册和相机权限 获取录音配置 验证文件是否过期 设置View 边框颜色和宽度
 */
@interface ZCUITools : NSObject

/**
 *  根据图片名称，获取SobotKit.bundle中的图片
 *
 *  @param imageName 图片名称，如xxx@2x.png,只用传递xxx即可
 *
 *  @return
 */
+(UIImage *) zcuiGetBundleImage:(NSString *) imageName;
+(UIImage *)zcuiGetExpressionBundleImage:(NSString *)imageName;

/**
 *  获取表情库
 *
 *  @return 返回字典，key为汉字，value为图片名称
 */
+ (NSArray *)allExpressionArray;

/**
 *  获取完整bundle路径
 *
 *  @param bundlePath  文件路径
 *
 *  @return <#return value description#>
 */
+(NSString*) zcuiFullBundlePath:(NSString*)bundlePath;


/**
 *  是否开启语音开关
 *
 *  @return return
 */
+(BOOL) zcgetOpenRecord;

/**
 *  是否设置相册的背景图片
 *
 *  @return 默认为NO
 */
+(BOOL) zcgetPhotoLibraryBgImage;


#pragma mark 自定义字体
+(UIFont *)zcgetTitleFont;
+(UIFont *)zcgetListKitTitleFont;
+(UIFont *)zcgetListKitDetailFont;
+(UIFont *)zcgetCustomListKitDetailFont;
+(UIFont *)zcgetListKitTimeFont;
+(UIFont *)zcgetKitChatFont;
+(UIFont *)zcgetVoiceButtonFont;
+(UIFont *)zcgetTitleGoodsFont;
+(UIFont *)zcgetDetGoodsFont;

#pragma mark -- 自定义字体颜色
/**
 *  顶部字体颜色
 *
 *  @return
 */
+(UIColor *)zcgetTopViewTextColor;
+(UIColor *)zcgetTopSubheadTextColor;


/**
 *  左边气泡里面文字颜色
 *
 *  @return
 *
 */
+(UIColor *)zcgetLeftChatTextColor;

/**
 *  右边气泡里面文字的颜色
 *
 *  @return
 */
+(UIColor *)zcgetRightChatTextColor;

/**
 *  时间文字的颜色
 *
 *  @return
 */
+(UIColor *)zcgetTimeTextColor;

/**
 *  提示气泡文字的颜色
 *
 *  @return
 */
+(UIColor *)zcgetTipLayerTextColor;

/**
 *  客服名字颜色
 *
 *  @return
 *
 */
+(UIColor *)zcgetServiceNameTextColor;


/**
 *  获取文本链接颜色
 *
 *  @return 
 */
//+(NSString *)zcgetLinkColor:(BOOL) isRight;


/**
 *  商品详情页cell中title的文字颜色
 *
 */
+(UIColor*)zcgetGoodsTextColor;


/**
 *  商品详情cell中摘要的文字颜色
 *
 */
+(UIColor *)zcgetGoodsDetColor;


/**
 *  商品详情cell中标签的文字颜色
 *
 */
+(UIColor *)zcgetGoodsTipColor;


/**
 * 商品详情cell中发送按钮的文字颜色
 *
 */
+(UIColor *)zcgetGoodsSendColor;



/**
 *  提交评价后会话将结束
 *
 */
+(UIColor *)zcgetSatisfactionColor;


#pragma mark -- 帮助中心
/**
 *
 * 帮助中心 导航条中间文字颜色
 *
 **/
+(UIColor *)zcgetscTopTextColor;

/**
 *
 *  帮助中心 导航条文字font
 *
 **/
+(UIFont *)zcgetscTopTextFont;

/**
 *
 *  帮助中心 导航条背景色
 *
 **/
+(UIColor *)zcgetscTopBgColor;


/**
 *
 *  帮助中心，导航条 返回文字颜色
 *
 **/
+(UIColor *)zcgetscTopBackTextColor;

/**
 *
 *  帮助中心 导航条 返回文字的字号
 *
 **/
+(UIFont *)zcgetscTopBackTextFont;

#pragma mark 自定义颜色


/**
 *  暂不评价文字颜色
 *
 */
+(UIColor *)zcgetNoSatisfactionTextColor;


/**
 * 评价页面中 已解决，未解决 按钮的 高亮状态的文字颜色
 *
 */
+(UIColor *)zcgetSatisfactionTextSelectedColor;


/**
 * 评价页面中 已解决，未解决 按钮的 高亮状态的 背景颜色
 *
 */
+(UIColor *)zcgetSatisfactionBgSelectedColor;

/**
 *  商品中发送按钮的背景色
 *
 *
 */
+(UIColor *)zcgetGoodSendBtnColor;

/**
 *  整体背景颜色
 *
 *  @return
 */
+(UIColor *) zcgetBackgroundColor;

/**
 *  获取系统配置颜色
 *
 *  @return  配置颜色
 *
 */
+(UIColor *) zcgetDynamicColor;

/**
 *
 *   机器人问答 提示转人工的按钮的 文字颜色
 *
 **/
+(UIColor *) zcgetTurnServerBtnColor;


/**
 *  左边气泡颜色
 *
 *  @return
 */
+(UIColor *)zcgetLeftChatColor;

/**
 *  右边气泡颜色
 *
 *  @return
 */
+(UIColor *)zcgetRightChatColor;


/**
 *  左边气泡复制选中的背景色
 *
 *
 */
+(UIColor *)zcgetLeftChatSelectedColor;

/**
 * 右边气泡复制选中的背景色
 *
 */
+(UIColor *)zcgetRightChatSelectdeColor;


/**
 *   底部bottom的背景颜色
 *
 *   @return
 */
+(UIColor *)zcgetBackgroundBottomColor;


/**
 *   底部bottom输入框线条背景颜色
 *
 *   @return
 */
+(UIColor *)zcgetBackgroundBottomLineColor;


/**
 *   评价按钮边框线颜色
 *
 *   @return
 */
+(UIColor *)zcgetCommentButtonLineColor;
+(UIColor *)zcgetCommentButtonBgColor;
+(UIColor *)zcgetCommentButtonBgHighColor;


/**
 *   评价按钮文字颜色
 *
 *   @return
 */
+(UIColor *)zcgetCommentCommitButtonColor;

/**
 *   提示气泡的背景颜色
 *
 *   @return
 */
+(UIColor *)zcgetBgTipAirBubblesColor;

/**
 *  提交评价按钮的文字颜色
 *
 *  @return
 */
+(UIColor *)zcgetSubmitEvaluationButtonColor;


/**
 *  提示cell中客服昵称的文字颜色
 *
 *  @return
 */
+(UIColor *)zcgetNickNameColor;



/**
 *  聊天气泡中左边链接的颜色
 *
 *  @return
 */
+(UIColor *)zcgetChatLeftLinkColor;

/**
 *  多轮会话模板四的超链颜色
 *
 *  @return
 */
+(UIColor *)zcgetChatMultLinkColor;

/**
 *  聊天气泡中右边链接的颜色
 *
 *  @return
 */
+(UIColor *)zcgetChatRightlinkColor;


/**
 *  聊天语音cell选中的背景色
 *
 *
 **/
+(UIColor *)zcgetChatRightVideoSelBgColor;

/**
 *
 *  富文本中的线条颜色
 *
 **/
+(UIColor *)zcgetLineRichColor;

/**
 *  相册的导航栏背景颜色
 *
 *
 *  @return
 */
+ (UIColor *)zcgetImagePickerBgColor;



/**
 *
 *  顶踩 按钮 默认文字颜色
 *
 **/
+( UIColor *) zcgetTopBtnNolColor;

/**
 *
 *  顶踩 按钮 选中文字颜色
 *
 **/
+( UIColor *) zcgetTopBtnSelColor;

/**
 *
 *   顶踩按钮 置灰文字颜色
 *
 **/
+( UIColor *) zcgetTopBtnGreyColor;


/**
 *
 *   留言页面 中 提交按钮的文字颜色
 *
 **/
+(UIColor *)zcgetLeaveSubmitTextColor;

/**
 *
 *   留言页面中 提交按钮的背景颜色
 *
 **/
+(UIColor *)zcgetLeaveSubmitImgColor;


/**
 *  连接中的网络状态Btutton背景色
 *  @return
 **/
//+(UIColor *)zcgetsocketStatusButtonBgColor;

/**
 * 连接中的网络状态Button 的文字颜色
 */
//+(UIColor *)zcgetsocketStatusButtonTitleColor;


/**
 *  客服评价页面 满意度星级说明
 */
+(UIColor *)zcgetScoreExplainTextColor;

/**
 *   多轮会话 展开的和收起的 btn 的文字颜色
 */
+(UIColor *)zcgetOpenMoreBtnTextColor;

/**
 *  相册导航栏标题文字
 *
 *  @return
 */
+(UIColor *)zcgetImagePickerTitleColor;

/**
 *  检查是否有相册权限
 *
 *  @return YES,有，
 */
+(BOOL)isHasPhotoLibraryAuthorization;


/**
 *  检查是否有相机权限
 *
 *  @return YES,有，
 */
+(BOOL)isHasCaptureDeviceAuthorization;

/**
 *  获取录音配置
 *
 *  @return 录音配置dict
 */
+ (NSDictionary*)getAudioRecorderSettingDict;

/**
 *  是否开启语音权限
 *
 *  @return YES 开启
 */
+(BOOL)isOpenVoicePermissions;

/**
 *  更改字符串颜色，转换为UIColor
 *
 *  @param hexColor #ffffff
 *
 *  @return UIColor
 */
+(UIColor *)getColor:(NSString *)hexColor;



/**
 *
 * 更改通告栏的背景色
 *
 *
 *@ return UIColor
 *
 */
+(UIColor *)getNotifitionTopViewBgColor;


/**
 *
 *  通告的文字颜色
 *
 *  @return UIColor
 */
+(UIColor *)getNotifitionTopViewLabelColor;


/**
 *
 *  通告的文字 字号 大小
 *
 *  @return UIFont
 */
+(UIFont *)zcgetNotifitionTopViewFont;


/**
 *  验证文件是否过期
 *
 *  @param filePath 文件路径
 *
 *  @return 时间（day）
 */
+ (int)IntervalDay:(NSString *) filePath;
+ (BOOL)imageIsValid:(NSString *) filePath;
+ (BOOL)videoIsValid:(NSString *) filePath;


/**
 *  设置View 边框
 *
 *  @param color       边框颜色
 *  @param borderWidth 边框宽度
 *  @param view        要设置的View
 */
+ (void)addBottomBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addBottomBorderWithColor:(UIColor *)color andWidth:(CGFloat) borderWidth andViewWidth:(CGFloat)viewWidth withView:(UIView *) view;
+ (void)addLeftBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addRightBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addTopBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth withView:(UIView *) view;
+ (void)addTopBorderWithColor: (UIColor *) color andWidth:(CGFloat) borderWidth andViewWidth:(CGFloat) viewWidth withView:(UIView *) view;

/**
 *  设置view抖动
 *
 *  @param viewToShake view
 */
+(void)zcShakeView:(UIView*)viewToShake;


/**
 根据文件地址或类型，获取文件icon

 @param filePath 文件地址
 @param type 文件类型
 @return 
 */
+(UIImage *) getFileIcon:(NSString * ) filePath fileType:(int) type;

/**
 *  为http链接添加a标签，并且过滤掉本身在a标签中的http
 *
 *  @param originalStr <#originalStr description#>
 *
 *  @return <#return value description#>
 */
+ (NSString *)zcTransformString:(NSString *)originalStr;

/**
 *  识别发送的超链
 *  @param  contentText 超链文本内容
 */
+ (NSString *)zcAddTransformString:(NSString *)contentText;



@end
