//
//  ZCLocalStore.h
//  SobotKit
//
//  Created by zhangxy on 2016/10/19.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#define ZCLOCALSTRCKARR @"ZCLocalStackArr"
#define ZCLOCALAUTO_MATCHTIMEZONE @"ZCLocalAutoMatchTimeZone"

@interface ZCLocalStore : NSObject


/**
 存储本地数据到NSUserDefault中

 @param value 值
 @param key 键
 */
+(void)addObject:(id) value forKey:(NSString *) key;
+(void)removeObjectByKey:(NSString *) key;

/**
 把dict封装成本地数组存储

 @param arr 字典数组
 @param key 键
 */
+(void)addObjectToArray:(NSDictionary *) arr for:(NSString *) key;



/**
 获取普通存储的值

 @param key 键
 @return 值
 */
+(id)getLocalParamter:(NSString *) key;


/**
 获取数据后转换为JSON

 @param key 键
 @return json字符串
 */
+(NSString *)getLocalJSONData:(NSString *) key;


/**
 获取存储的字典

 @param key 键
 @return 字典类型
 */
+(NSDictionary *)getLocalDictionary:(NSString *)key;



/**
 获取存储的arr

 @param key 键
 @return 数组类型
 */
+(NSArray *)getLocalArray:(NSString *)key;



/**
 对象转JSON字符串

 @param object 字典对象
 @return JSON字符串
 */
+(NSString*)DataTOjsonString:(id)object;
+(NSDictionary*)getObjectDictData:(id)obj;
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;
+ (NSMutableArray *)arrayWithJsonString:(NSString *)jsonString;




@end
