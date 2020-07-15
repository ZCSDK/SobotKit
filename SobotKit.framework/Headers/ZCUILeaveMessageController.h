//
//  ZCUILeaveMessageController.h
//  SobotKit
//
//  Created by lizhihui on 16/1/21.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <SobotKit/SobotKit.h>
//#import "ZCOrderModel.h"

typedef void(^BackRefreshPageBlock)(id _Nonnull object);

/**
 *  ZCUILeaveMessageController 留言VC
 */
@interface ZCUILeaveMessageController : ZCUIBaseController


@property (nonatomic,assign) BOOL             isExitSDK;
@property (nonatomic,assign) BOOL             isNavOpen;

@property (nonatomic,strong) UIViewController *backVC;

@property (nonatomic,assign) NSInteger        exitType;

/**  是否显示排队人数已满*/
@property (nonatomic,assign) BOOL             isShowToat;

@property (nonatomic,strong) NSString         *tipMsg;

@property (nonatomic,assign) int selectedType; // 默认 创建工单 2 留言记录

@property (nonatomic,strong) NSDictionary * templateldIdDic;// {"templateId":1}，模板id从配置列表接口获取


@property(nonatomic,strong)NSMutableArray   *coustomArr;// 用户自定义字段数组

// 2.7.1版本 和留言模板关联 数据从模板接口获取 原初始化接口的数据不在使用
@property (nonatomic , assign) BOOL     telShowFlag;

// 2.8.0 是否显示标题
@property (nonatomic , assign) BOOL     ticketTitleShowFlag;

@property (nonatomic , assign) BOOL     telFlag;

@property (nonatomic , assign) BOOL     enclosureShowFlag;
@property (nonatomic , assign) BOOL     enclosureFlag;

@property (nonatomic , assign) BOOL     emailFlag;
@property (nonatomic , assign) BOOL     emailShowFlag;

// 未使用
@property (nonatomic , assign) int      ticketStartWay;

@property (nonatomic,copy) NSString * _Nullable msgTmp;// "'您好，为了更好地解决您的问题,请告诉我们以下内容：<br>1. 您的姓名 2. 问题描述'"

@property (nonatomic,copy) NSString * _Nullable msgTxt;// "<p>您好，很抱歉我们暂时无法为您提供服务，如需帮助，请留言，我们将尽快联系并解决您的问题</p>"

@property (nonatomic,assign) int  ticketShowFlag;//  1 显示留言记录

@property (nonnull,strong) NSMutableArray * typeArr;// 分类的数据

@property (nonatomic,assign) int tickeTypeFlag ; //1-自行选择分类，要显示  2-指定分类 其他，不显示

@property (nonatomic,copy) NSString * _Nullable ticketTypeId;// 当-指定分类 传这个值

@property (nonatomic,copy) BackRefreshPageBlock backRefreshPageblock;
// 直接退出SDK 并关闭技能组弹框
-(void)setCloseBlock:(void (^)())closeBlock;


@end
