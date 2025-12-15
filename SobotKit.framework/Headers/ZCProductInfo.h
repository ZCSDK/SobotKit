//
//  ProductInfo.h
//  SobotKit
//
//  Created by zhangxy on 2016/10/18.
//  Copyright © 2016年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 内容字段：标题（必填）、页面地址url（必填）、摘要、标签、缩略图url
 */
@interface ZCProductInfo : NSObject

// 标题
// not null
@property (nonatomic,strong) NSString *title;

// 页面链接
// not null
@property (nonatomic,strong) NSString *link;

// 摘要
@property (nonatomic,strong) NSString *desc;

// 标签
@property (nonatomic,strong) NSString *label;

// 缩略图地址
@property (nonatomic,strong) NSString *thumbUrl;

@end
