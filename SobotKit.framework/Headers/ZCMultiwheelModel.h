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

// 如果inputContentList字段不为空，显示为链接样式
@property (nonatomic,assign) BOOL   showLinkStyle;// 问题列表


@property (nonatomic,copy) NSString          * level;
@property (nonatomic,strong) NSString         * outPutParamList;// "movieId#movieId"
@property (nonatomic,copy) NSString          * retCode;//"000000",接口返回的请求状态

// 0，模板一，带标题的图文，interfaceRetList，  当interfaceRetList和inputContentList都为空时，作为普通富文本消息处理，当inputContentList不为空是，用模板二处理
//1：模板二，文字选项(有框和无框居左)， inputContentList
// 2：模板3，不带标题的图文，interfaceRetList
//3：模板4 查看详情(interfaceRetList第一个，有图文+查看详情)，
//4：自定义模板（interfaceRetList第一个的title和外部answerStrip(未结束remindQuestion)）
// 99:自定义模板 （interfaceRetList第一个的tempStr和外部answerStrip(未结束remindQuestion)）
// templateid为空：inputContentList和interfaceRetList都为空显示4自定义模板的样式，任意一个不为空，显示1 模板二，文字选项(有框和无框居左)
@property (nonatomic,assign) int            templateId;// 模板类型

// 2.8.2  clickFlag 0: 只能点击一次，1 可以多次点击
@property (nonatomic,copy) NSString *clickFlag;

// 0,1,2,3,4
@property (nonatomic,assign) int            templateIdType;// 模板类型

//@property (nonatomic,strong) NSMutableArray         *inputContentList;// \"北京,上海,成都\",     手动输入[{"年龄":"18"},{"性别":"女"}]
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
-(id) initWithMyDict:(NSDictionary *)dict;


-(NSString *)getRequestText:(NSDictionary *)model;
-(NSString *)getQuestion:(NSDictionary *)model;

@end


