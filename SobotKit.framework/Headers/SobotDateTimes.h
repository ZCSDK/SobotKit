//
//  SobotDateTimes.h
//  SobotCommon
//
//  Created by zhangxy on 2021/8/30.
//

#import <Foundation/Foundation.h>

//@"YYYY-MM-dd HH:mm:ss SSS"
#define SOBOT_FORMATE_DATETIME @"YYYY-MM-dd HH:mm:ss"

NS_ASSUME_NONNULL_BEGIN

@interface SobotDateTimes : NSObject


NSString *sobotGetCurrentTimes(void);

/**
 *  日期格式
 *
 *  @param fromate 格式
 *  @param date    要格式的日期
 *
 *  @return 格式化后的字符串
 */
NSString * sobotDateTransformString(NSString* fromate,NSDate*date);

/**
 *  longlong类型日期，转换为字符串
 *
 *  @param fromate  格式
 *  @param longdate 转换的类型，主要php和java日期精确度不一样
 */
NSString * sobotLongdateTransformString(NSString* fromate,long long longdate);

/**
 *  字符串转日期
 */
NSDate * sobotStringFormateDate(NSString * stringDate);

/**
 *  计算日期与当前时间的差
 */
NSString *sobotIntervalSinceNow(NSString *theDate);



/**
 返回时差小时
 **/
int sobotIntervalDateSinceSimpleNow(NSString *theDate);


// 计数日期之间的差值
NSTimeInterval sobotDiffTimeSinceNow(NSString *theDate);

/**
 *  获取日期的年,返回哪一年
 */
NSInteger sobotGetDataYear(NSDate *date);

// 时间戳转date
NSDate * sobotStringFormateDateToDate(NSString * stringDate);

@end

NS_ASSUME_NONNULL_END
