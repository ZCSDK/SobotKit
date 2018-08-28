//
//  ZCLibCusMenu.h
//  SobotKit
//
//  Created by lizhihui on 2018/5/25.
//  Copyright © 2018年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 自定义菜单
 *
 **/
@interface ZCLibCusMenu : NSObject

// 菜单标题
@property (nonatomic,strong) NSString * title;

// 点击事件
@property (nonatomic,strong) NSString * url;

// 备用字段（不用填写）
@property (nonatomic,assign) NSInteger  lableId;

// 菜单图标(更多时使用,选填)
@property (nonatomic,strong) NSString * imgName;
// 按下效果，选填
@property (nonatomic,strong) NSString * imgNamePress;

-(id)initWithMyDict:(NSDictionary *)dict;
@end
