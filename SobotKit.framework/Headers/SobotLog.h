//
//  SobotLog.h
//  SobotLog
//
//  Created by zhangxy on 2021/8/26.
//

#import <Foundation/Foundation.h>


#define SLog(format,args...) [SobotLog logInfo:format,##args]
#define SLogDebug(format,args...) [SobotLog logDebug:format,##args]
#define SLogError(format,args...) [SobotLog logError:format,##args]
#define SLogWaring(format,args...) [SobotLog logWarning:format,##args]


// 日志输出头，再方法内部不能获取方法和行号，需要调用时传递
#define SobotLogHeader [NSString stringWithFormat:@"\n========SobotLog========\n%@ %@\n%s[%d]",[[NSBundle mainBundle] bundleIdentifier],[NSDate date],__FUNCTION__,__LINE__]

typedef NS_ENUM(NSInteger,SobotLogType) {
    SobotLogTypeInfo        = 0,
    SobotLogTypeUnknow,     // 写入
    SobotLogTypeError,      // 写入
    SobotLogTypeException,  // 写入
    SobotLogTypeDebug,      // 写入
    SobotLogTypeMessage    // 写入
};

@interface SobotLog : NSObject

+(NSString *) getLogVersion;


/// 设置调试模式，默认为NO，如果不显示日志设置为YES
/// @param isDebug  默认为NO
+(void)setDebug:(BOOL) isDebug;


/// 是否开启日志记录，默认为NO不记录
/// @param isOpen  默认为NO
+(void)openCacheLog:(BOOL)isOpen;


// 输出日志
+(void)log:(NSString *) log cache:(BOOL) isCache type:(SobotLogType) logType;

/**
 *  输出指定标签日志
 *
 *  @param format    日志内容
 */
+(void)logInfo:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
+(void)logHeader:(NSString *) header info:(NSString *)format, ... NS_FORMAT_FUNCTION(2,3);

// 外部日志开关控制输出内容
+(void)logDebug:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);

// 开发调试使用
+(void)logError:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
+(void)logWarning:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);



/**
写入日志信息
 
 @param title 日志标题
 @param message 日志内容
 @param logType 日志类型
 */
+(void)cacheLog:(NSString *) title content:(NSString *)message logType:(SobotLogType) logType;
/**
 *  根据设定的过期时长，清理日志，默认是1天
 */
+(void)cleanCache;

+(void)writefile:(NSString *)string withPath:(NSString *) filePath;


/**
 根据路径清理文件

 @param filePath 缓存路径
 */
+(void)cleanCache:(NSString *) filePath;


/**
 获取统计日志

 @return 日志内容
 */
+(NSString * )getAnalysisFilePath;


/**
 获取日志文件列表

 @return 文件列表
 */
+(NSMutableArray *) getLogFileList;

/**
 *  获取缓存日志
 *
 *  @return 缓存日志路径，当天
 */
+(NSString * )getLogFilePath;

/**
 *  获取缓存日志
 *
 *  @param dateString 具体哪一天的日志，格式yyyyMMdd
 *
 *  @return 缓存日志路径
 */
+(NSString * )getLogFilePath:(NSString *) dateString;



/**
 *  读取文件内容
 *
 *  @param filePath 文件完整路径，可通过getLogFilePath(:)获取
 *
 *  @return 文件内容
 */
+(NSString *) readFileContent:(NSString *) filePath;


@end
