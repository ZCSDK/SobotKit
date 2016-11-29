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
@property(nonatomic,strong) UIButton    * closeButton;

/**
 *  标题
 */
@property(nonatomic,strong) UILabel    * titleLabel;

/**
 *  创建TitleView
 */
-(void)createTitleView;

@end




