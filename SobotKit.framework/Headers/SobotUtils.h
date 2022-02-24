//
//  SobotUtils.h
//  SobotUtils
//
//  Created by zhangxy on 2021/11/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/// 常用工具类
@interface SobotUtils : NSObject


// 当前包的版本
NSString *sobotGetCommonVersion(void);


/**
 *   对象格式化为字符串stringWithFormat
 *  @param object 传入的不定对象
 *
 *  @return 字符串
 */
NSString *sobotConvertToString(id object);


/// 字符串使用CC_MD5转换为32位字符串
/// @param input  待转换字符串
NSString* sobotMd5(NSString* input);


/// 字符串使用SHA256转换为32位字符串
/// @param inputString  待转换字符串
NSString *sobotSHA256(NSString *inputString);


/// 格式化url
/// @param url  字符串
NSString *sobotUrlEncodedString(NSString *url);

// 自定义正则判断url
BOOL sobotIsUrl(NSString *urlString,NSString *regexStr);

/**
 *  去掉首尾部空格
 */
NSString* sobotTrimString (NSString* input);





// 验证
BOOL sobotValidateEmail(NSString* email);
BOOL sobotValidateMobile(NSString* mobile);
// 验证手机号，自定义正则
BOOL sobotValidateMobileWithRegex(NSString* mobile,NSString *regex);
BOOL sobotValidateQQNumber(NSString *qqNumber);
BOOL sobotValiddatePinYin(NSString *pinYin);
/// 纯数字
BOOL sobotValidateNumber(NSString *str);

// 是否为小数
BOOL sobotValidateFloat(NSString *str);

/**
 判断是否是为浮点数
 @param str 字符串,num小数位
 @return yes/no
 */
BOOL sobotValidateFloatWithNum(NSString *str,int num);


BOOL sobotValidateRuleNotBlank(NSString *str);

/**
 *  判断空对象、字符串、长度为0
 */
BOOL sobotIsNull(id object);

/**
 是否为空字符串
 * */
BOOL sobotIsEmpty(NSString* str);


// 格式化url地址
NSString *sobotValidURLString(NSString *urlString);

// 字符串是否为纯汉字
BOOL sobotIsChinese(NSString *str);

// 字符串是否包含中文
BOOL sobotIsInludeChinese(NSString *str);





// 获取Document下的全路径
NSString* sobotGetDocumentsFilePath(const NSString* fileName);

//获取Library路径
NSString* sobotGetLibraryFilePath(const NSString* fileName);

/**
 *  get the Tmp path of download file
 ***/
NSString* sobotGetTempFilePath(NSString* fileName);
/**
 * extract the file name from path
 **/
NSString* sobotGetFileNameByPath(NSString* path);


// 获取bundle的完整路径pathForResource
NSString* sobotGetResourcePath(NSString* basePath, NSString* resName, NSString* resType);
// 获取bundle的完整路径URLForResource
NSURL* sobotGetResourceUrl(NSString* basePath, NSString* resName, NSString* resType);


// 路径是否存在，不区别文件或路径
BOOL sobotCheckFileIsExsis(NSString *filePath);

// 是文件并且不是路径
BOOL sobotCheckFilePathIsExsis(NSString *filePath);

/*删除文件 指向目录为（NSCachesDirectory）临时文件夹*/
BOOL sobotDeleteFileOrPath(NSString *filePath);


//检查路径，没有就创建路径
BOOL sobotCheckPathAndCreate(NSString *path);

//检查路径文件，没有就创建路径和文件
BOOL sobotCheckFileAndCreate(NSString *filePath);





#pragma mark -- SDK 采集用户的设备信息

/**
 *  获取应用BunddleID
 */
NSString *sobotGetAppBunddleID(void);


// 获取系统版本
NSString *sobotGetSystemVersion(void);

// 获取系统版本，方便版本号判断
double sobotGetSystemDoubleVersion(void);

/**
 *  获取app的名称
 *
 */
NSString *sobotGetAppName(void);

/**
 *  获取app的版本号
 */
NSString *sobotGetAppVersion(void);

/**
 *  获取手机的型号名称iPhone 4s、iPhone X
 */
NSString *sobotGetIphoneType(void);


/**
 *  获取运营商信息联通、电信、移动
 */
NSString *sobotGetIphoneOperators(void);

// 获取语言头，如：zh-Hans,zh-Hant,en,ar等
NSString *sobotGetLanguagePrefix(void);

// 判断当前语言是否为默认语言
BOOL sobotIsRTLLayout();


/**
 *  获取设备的尺寸
 *
 */
NSString *sobotGetScreenSize(void);

// 是否为刘海屏
BOOL sobotIsIPhoneX(void);


/// 获取当前展示的window
UIWindow *sobotGetCurWindow(void);


@end
