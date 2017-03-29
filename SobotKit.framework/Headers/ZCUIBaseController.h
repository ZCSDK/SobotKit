//
//  ZCUIBaseController.h
//  SobotKit
//
//  Created by zhangxy on 15/11/12.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>


/**ZCPageBlockType回调类型*/
typedef NS_ENUM(NSInteger,ZCPageBlockType) {
    ZCPageBlockGoBack     = 1,// 点击返回
    ZCPageBlockLoadFinish = 2,// 加载界面完成，可对UI进行修改
};

typedef NS_ENUM(NSInteger, ButtonClickTag) {
    BUTTON_BACK   = 1, // 返回
    BUTTON_CLOSE  = 2, // 关闭(未使用)
    BUTTON_UNREAD = 3, // 未读消息
    BUTTON_MORE   = 4, // 清空历史记录
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
 *  创建TitleView
 */
-(void)createTitleView;


// button点击事件
-(IBAction)buttonClick:(UIButton *) sender;

@end




