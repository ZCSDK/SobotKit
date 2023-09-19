//
//  ZCSatisfactionConfig.h
//  SobotChatClient
//
//  Created by zhangxy on 2023/8/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCSatisfactionConfig : NSObject

@property (nonatomic,assign) int isCreated;// 0,未复制，1赋值

// scoreFlag==0星级: 0代表5星,1代表不选中
// scoreFlag==1分值: 0代表10分，1代表5分，2代表0分，3代表不选中
@property (nonatomic,assign) int defaultQuestionFlag;//：“问题是否解决”默认选中状态：(0)-未解决 (1)-解决 (-1/2)-不选中
@property (nonatomic,assign) int defaultType;//：默认显示星级  0-5星,1-0星 / 0-10分，1-5分，2-0分，3-不选中
@property (nonatomic,assign) int isQuestionFlag;//：人工客服是否解决问题开关  1-开启 0-关闭
@property (nonatomic,assign) int isQuestionMust;//：“问题是否解决”是否为必填选项： 0-非必填 1-必填
@property (nonatomic,assign) int scoreFlag;//：星级类型 0-旧版5星级评价  1-nps评价 
@property (nonatomic,assign) int status;//：模板状态开关 0-关闭 1-开启


// 0自定义，1默认
@property (nonatomic,assign) int isDefaultButton;
@property (nonatomic,strong) NSString *buttonDesc;//": "提交",

// 0自定义，1默认
@property (nonatomic,assign) int isDefaultGuide;
@property (nonatomic,strong) NSString *guideCopyWriting;//": "服务评价",

@property (nonatomic,assign) int isDefault;//": 1
// 1显示，0不显示
@property (nonatomic,assign) int txtFlag;//": 1

// 未使用
@property (nonatomic,strong) NSString *txtDesc;//": "引导文案欢迎给我们的服务提建议",


/**  子集 */
@property (nonatomic,strong) NSMutableArray * list;


-(id)initWithMyDict:(NSDictionary *)dict;


@end

NS_ASSUME_NONNULL_END
