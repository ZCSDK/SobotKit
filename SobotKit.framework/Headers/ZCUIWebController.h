//
//  ZCUIWebController.h
//  SobotKit
//
//  Created by zhangxy on 15/11/12.
//  Copyright © 2015年 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZCUIBaseController.h"

/**
 *  智齿 WebVC页面
 *
 *
 */
@interface ZCUIWebController : ZCUIBaseController

/**
 *  初始化 v2.7.9支持传入html字符串展示
 *
 *  @param url 网址url
 *
 *  @return ZCUIWebController
 */
-(id)initWithURL:(NSString *)url;


@end
