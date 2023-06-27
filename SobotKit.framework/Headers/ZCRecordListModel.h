//
//  ZCRecordListModel.h
//  SobotKit
//
//  Created by lizhihui on 2019/3/5.
//  Copyright © 2019 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCRecordListModel : NSObject

//"content":"ydysy",
//"flag":1,
//"newFlag":1,
//"ticketCode":20190305000001,
//"ticketId":"235a803c9fc64419ad12fa3f761640bb",
//"time":1551777295,
//"timeStr":"2019-03-05 17:14:55"

@property (nonatomic,copy) NSString * content; // 工单描述
@property (nonatomic,copy) NSMutableAttributedString * contentAttr; // 工单描述

@property (nonatomic,assign) int flag;  //1 创建了  2 受理了 3 关闭了

@property (nonatomic,assign) int newFlag; // 是否更新

@property (nonatomic,copy) NSString * ticketCode;  //工单编号

@property (nonatomic,copy) NSString * ticketId; // 工单id

@property (nonatomic,copy) NSString * time;

@property (nonatomic,copy) NSString * ticketTitle; // 标题

@property (nonatomic,copy) NSString * timeStr;

//@property (nonatomic,assign) BOOL isRead;// 标记是否已读
@property (nonatomic,copy) NSString * serviceNick;// 客服昵称
@property (nonatomic,copy) NSString * customerId;// 客户id


// flag ==2 时 ，有子集  replayList

@property (nonatomic,strong) NSMutableArray * replayList;

@property (nonatomic,copy) NSString * dealUserName; // 回复的昵称 客服昵称或者用户昵称

@property (nonatomic,copy) NSString * replyContent;// 回复内容

@property (nonatomic,assign)  int startType; // 0 客服  1客户

@property (nonatomic,copy) NSString * replyTime; // 回复的时间 时间戳1552296719 需要处理
@property (nonatomic,copy) NSString * replyTimeStr; // 回复的时间 时间戳1552296719 需要处理

@property (nonatomic,strong) NSMutableAttributedString *replyTimeStrAttr;


// flag == 3 的时候有子集 触发评价相关
@property (nonatomic,assign) int isOpen;// isOpen（是否开启满意度评价  0 未开启  1 开启）

@property (nonatomic,assign) int isEvalution; // isEvalution

@property (nonatomic,copy) NSString * score;// 评价得分

@property (nonatomic,copy) NSString * remark;// 反馈意见

@property (nonatomic,assign) int txtFlag ; //评价文本框开关  0 关闭  1 开启

@property (nonatomic,strong) NSMutableArray * ticketScoreInfooList;// （星级内容

// 2.8.2
@property (nonatomic,strong) NSMutableArray * fileList; // 文件




-(id)initWithMyDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
