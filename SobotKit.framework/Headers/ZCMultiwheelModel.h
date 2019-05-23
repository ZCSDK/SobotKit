//
//  ZCMultiwheelModel.h
//  SobotKit
//
//  Created by lizhihui on 2017/12/4.
//  Copyright © 2017年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZCMultiwheelModel : NSObject

@property (nonatomic,copy) NSString          * conversationId;// "8a6f49a0-2148-4d6d-84f0-dacf56c1f930",多轮会话id
@property (nonatomic,copy) NSString          * docId;// 1a3a05c7025044e9a44a55e87c8dd0b9
@property (nonatomic,assign) BOOL             endFlag; // false 多轮会话是否结束
@property (nonatomic,strong) NSMutableArray   *interfaceRetList;// 问题列表
@property (nonatomic,copy) NSString          * level;
@property (nonatomic,strong) NSString         * outPutParamList;// "movieId#movieId"
@property (nonatomic,copy) NSString          * retCode;//"000000",接口返回的请求状态
@property (nonatomic,assign) int            templateId;// 模板类型

// 0 横向，1、标签，2竖，3富媒体 4、存文本  5、1511
@property (nonatomic,assign) int            msgType;// 模板类型
//@property (nonatomic,strong) NSMutableArray         *inputContentList;// \"北京,上海,成都\",     手动输入
@property (nonatomic,copy) NSString          *retErrorMsg;// 失败时返回的数据

@property (nonatomic,copy) NSString          *remindQuestion;// "机器人提示问题",

@property (nonatomic,copy) NSString          * msg;// 消息体，机器人的回复

@property (nonatomic,assign) BOOL            isHistoryMessages;// 是否是历史记录


@property (nonatomic,assign) int              moreCurrtCount;// 记录当前的查看的个数
/**
 *  初始化
 *
 *  @param dict 解析后的数据（字典类型）
 *
 *  @return ZCLibRich
 */
-(id) initWithMyDict:(NSDictionary *)dict withAnswerType:(NSString *)answerType;


-(NSString *)getRequestText:(NSDictionary *)model;
-(NSString *)getQuestion:(NSDictionary *)model;

@end


