//
//  ZCUIBaseController.h
//  SobotKit
//
//  Created by zhangxy on 15/11/12.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZCTitleView.h"


/**ZCPageBlockType回调类型*/
typedef NS_ENUM(NSInteger,ZCPageBlockType) {
    ZCPageBlockGoBack     = 1,// 点击返回
    ZCPageBlockLoadFinish = 2,// 加载界面完成，可对UI进行修改
    ZCPageBlockLeave      = 3,// 留言
};

typedef NS_ENUM(NSInteger, ZCButtonClickTag) {
    BUTTON_BACK   = 1, // 返回
    BUTTON_CLOSE  = 2, // 关闭(未使用)
    BUTTON_UNREAD = 3, // 未读消息
    BUTTON_MORE   = 4, // 清空历史记录
    BUTTON_TURNROBOT = 5,// 切换机器人
    BUTTON_EVALUATION =6,// 评价
    BUTTON_TEL   = 7,// 拨打电话
    BUTTON_SEND   = 8, // 清空历史记录
};

// 返回监听
typedef NS_ENUM(NSInteger,ZCPageCloseType) {
    ZC_CloseLeave       = 1, // 留言返回
    ZC_CloseChat        = 2, // 会话页面
    ZC_CloseHelpCenter  = 3, // 帮助中心
    ZC_CloseChatList  = 4, // 电商消息中心
    ZC_PhoneCustomerService  = 5, // 电话联系客服
};

/**
 *  智齿SDK中公共UIViewController
 */
@interface ZCUIBaseController : UIViewController

/**
 *  顶部的View
 */
@property(nonatomic,strong) UIView      * topView;

/**
 *  顶部的导航栏的背景图片
 */
@property(nonatomic,strong) UIImageView   * topImageView;

/**
 *  关闭按钮（返回）
 */
@property(nonatomic,strong) UIButton    * backButton;

/**
  清空聊天记录
 */
@property(nonatomic,strong) UIButton    * moreButton;

/**
 *  标题
 */
@property(nonatomic,strong) UILabel    * titleLabel;

/**
 *
 *  导航条底部线条
 *
 **/
@property (nonatomic,strong) UIView * bottomLine;

@property (nonatomic,assign) BOOL  isArtificial;



/**
 *  创建TitleView
 */
-(void)createTitleView;

// 创建titleView 默认随主题 1帮助中心用
-(void)createTitleViewWith:(int)type;
// button点击事件
-(IBAction)buttonClick:(UIButton *) sender;


-(BOOL)orientationChanged;

-(CGFloat) getCurViewWidth;
-(CGFloat) getCurViewHeight;



/// 系统导航，统一创建
/// @param leftTags 左边点击事件：ZCButtonClickTag
/// @param rightTags 右边点击事件：ZCButtonClickTag
- (void)setNavigationBarLeft:(NSArray *)leftTags right:(NSArray *) rightTags;

// 仅有返回按钮
- (void)setNavigationBarStyle;

-(UIButton *)createHelpCenterButtons:(CGFloat ) y sView:(UIView *) superView;
-(void)openZCSDK:(UIButton *)sender;


@end




