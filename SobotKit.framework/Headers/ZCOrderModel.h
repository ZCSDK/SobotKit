//
//  ZCOrderModel.h
//  SobotKit
//
//  Created by lizhihui on 2017/9/13.
//  Copyright © 2017年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ZCOrderModel :NSObject

@property(nonatomic , strong) NSString * ticketDesc;//": "工单问题描述"
@property(nonatomic , strong) NSString * ticketholde;//": "工单问题描述 .占位文字"
@property (nonatomic, strong) NSString *userName;// 当前创建工单的用户昵称
@property (nonatomic, strong) NSString *email;// 邮箱
@property (nonatomic, strong) NSString *tel;// 电话

@property (nonatomic, strong) NSString *ticketTitle;// 2.8.0 工单标题


@property (nonatomic, strong) NSMutableArray *resultList;// 自定义字段的数组
@property (nonatomic, strong) NSMutableArray * fileList;// 附件
@property (nonatomic, strong) NSString * ticketTypeName;// 工单的分类
@property (nonatomic, strong) NSString *ticketType;//": 4
@property (nonatomic, strong) NSString *ticketTypeID;// 工单类型的id


@end
