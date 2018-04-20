//
//  ZCTopView.h
//  SobotKit
//
//  Created by lizhihui on 2018/1/29.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, ZCBtnClickTag) {
    Btn_BACK   = 1, // 返回
    Btn_MORE   = 3, // 清空历史记录
};

typedef void(^TopViewBtnClickBlock)(int ZCBtnClickTag);

@interface ZCTopView : UIView

@property (nonatomic,copy) TopViewBtnClickBlock btnClickBlock;



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


-(instancetype)initWithFrame:(CGRect)frame;

@end
