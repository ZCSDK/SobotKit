//
//  ZCLibContent.h
//  ZCLibLib
//
//  Created by zhangxy on 15/11/10.
//  Copyright © 2015年 ZCLibLib. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  <#Description#>
 */
@interface ZCLibContent : NSObject

/**
 *  日期
 */
@property (nonatomic,strong) NSString       * date;

/**
 *  内容数组
 */
@property (nonatomic,strong) NSMutableArray * content;

/**
 *  用于特殊提示语显示
 */
@property (nonatomic,strong) NSString       * tips;

/**
 *  提示类型
 */
@property (nonatomic,assign) int            tipStyle;

/**
 *  初始化
 *
 *  @param dict 数据解析后的数据
 *
 *  @return ZCLibContent
 */
-(id)initWithMyDict:(NSDictionary *)dict;

@end
