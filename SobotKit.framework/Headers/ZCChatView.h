//
//  ZCChatView.h
//  SobotKit
//
//  Created by lizhihui on 2018/1/29.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ZCTopView.h"
#import "ZCKitInfo.h"

#import "ZCChatController.h"

@protocol ZCChatViewDelegate <NSObject>

@optional
// 头部点击事件，(返回/清理消息)
-(void)topViewBtnClick:(ZCBtnClickTag )Tag;

// 标题改变
-(void)onTitleChanged:(NSString *) title;

// 跳转留言
//-(void)openLeaveMsgClick:(NSString*)tipMsg;// 点击留言跳转到用户自己留言页面，SDK 不在处理留言
@end



@interface ZCChatView : UIView


@property (nonatomic,strong) ZCChatController * superController;

/** 未知说辞计数*/
@property (nonatomic, assign) NSUInteger       unknownWordsCount;

// 初始化
-(instancetype)initWithFrame:(CGRect)frame WithSuperController:(UIViewController *)superController;

// 设置页面代理
@property (nonatomic,assign) id<ZCChatViewDelegate>delegate;

// 是否显示顶部导航
@property (nonatomic,assign) BOOL hideTopViewNav;

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



// 显示聊天窗口
-(void)showZCChatView:(ZCKitInfo *)kitInfo;

// 隐藏聊天窗口，回收页面数据
-(void)dismissZCChatView;

/**
 *
 *  清除历史记录
 *
 **/
-(void)cleanHistoryMessage;

/**
 *
 *  返回判断
 *
 **/
-(void)confimGoBack;

@end
