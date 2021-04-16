//
//  ZCChatView.h
//  SobotKit
//
//  Created by lizhihui on 2018/1/29.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>


#import "ZCKitInfo.h"


#import "ZCUIBaseController.h"


@protocol ZCChatViewDelegate <NSObject>

@optional
// 头部点击事件，(返回/清理消息)
-(void)topViewBtnClick:(ZCButtonClickTag )Tag;

// 标题改变
-(void)onTitleChanged:(NSString *) title imageUrl:(NSString *) url;

// 跳转留言
-(void)onLeaveMsgClick:(NSString*)tipMsg;

- (void)onPageStatusChange:(BOOL)isArtificial;

@end



@interface ZCChatView : UIView

typedef NS_ENUM(NSInteger,ZCChatViewGoBackType) {
    ZCChatViewGoBackType_normal    = 1, // 返回按钮
    ZCChatViewGoBackType_close    = 2,  // 关闭按钮
    
};
/** 未知说辞计数*/
@property (nonatomic, assign) NSUInteger       unknownWordsCount;

// 初始化
-(instancetype)initWithFrame:(CGRect)frame WithSuperController:(UIViewController *)superController customNav:(BOOL)isCreated;

// 设置页面代理
@property (nonatomic,weak) id<ZCChatViewDelegate>delegate;

// 是否显示顶部导航
@property (nonatomic,assign) BOOL hideTopViewNav;

/**
 *  顶部的View
 */
@property(nonatomic,strong) UIView      * topView;

/**
 *  关闭按钮（返回）
 */
@property(nonatomic,strong) UIButton    * backButton;

/**
 *  关闭按钮（关闭，弹评价，但是会直接关闭）
 */
@property(nonatomic,strong) UIButton    * closeButton;

/**
 清空聊天记录
 */
@property(nonatomic,strong) UIButton    * moreButton;

/**
 *
 *  评价
 *
 **/
@property (nonatomic,strong) UIButton * evaluationBtn;


/**
 *
 *  评价
 *
 **/
@property (nonatomic,strong) UIButton * telBtn;




/**
 *   跳转到用户自己的 留言VC
 **/
@property(nonatomic,assign) BOOL  isJumpCustomLeaveVC;


-(UITextView *) getChatTextView;

// 显示聊天窗口
-(void)showZCChatView:(ZCKitInfo *)kitInfo;

// 隐藏聊天窗口，回收页面数据
-(void)dismissZCChatView;

-(void)saveDataToLocal;

/**
 *
 *  清除历史记录
 *
 **/
-(void)cleanHistoryMessage;

/**
 *  返回事件
 **/
//-(void)confimGoBack;


/**
 返回后关闭通道，离线用户
 */
//-(void)confimGoBackCloseChat;

- (void)confimGoBackWithType:(ZCChatViewGoBackType )type;


/**
 *
 *   跑马灯动画
 *
 **/
-(void)beginAniantions;

/**
 *
 *  去评价
 *
 **/
-(void)goEvaluation;
/*
  设置 成员变量 isClickCloseBtn 为false
  在isShowReturnTips 为true 切点击了暂时离开 去调用
 */
- (void)setIsCloseNo;

@end
