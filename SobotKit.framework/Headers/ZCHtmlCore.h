//
//  ZCHtmlCore.h
//  SobotKit
//
//  Created by zhangxy on 2019/4/25.
//  Copyright © 2019 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCHtmlCore : NSObject



/**
 解析html字符串，并提起A、B、I标签属性
 例如：@"a<a href=\"https://www.sobot.com\">我是链接</a>fs<b>x</b>菲<b>杰sss<a href=\"https://gg\">gg</a>ss双方</b>减sdfsfd<b>哈哈</b>ssdfsfsdfs<b>st</b>sdfasdfasfdjasfdas<img src= \"https://img2.mukewang.com/54584dc4000118d302200220-100-100.jpg\"/>fdkjasldfjsafdl是的发送到发送到发课教案上；东方丽景水电费卡说大法师打<br/>发是开发<br>的环<i>境阿斯蒂aaahttp://www.sobot.com ssdfasfasf芬看</i>哈s;ajsf"
 

 @param htmlText 需要解析的带html标签的字符串
 @param filterBlock 解析结果
 text:过滤掉字符串后的结果
 arr:包含{tag,location,len,href}的数据
 links:arr的子集，仅包含A标签
 */
+(void)filterHtml:(NSString *) htmlText result:(void(^)(NSString *text,NSMutableArray *arr,NSMutableArray *links)) filterBlock;


/**
 html标签字符串，转换成可识别的文本
 
 @param str 待过滤的字符串
 @return 过滤后的字符串
 */
+ (NSString *)filterHTMLTag:(NSString *)str;

@end

NS_ASSUME_NONNULL_END
