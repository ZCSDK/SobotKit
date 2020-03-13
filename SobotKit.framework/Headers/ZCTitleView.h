//
//  ZCTitleView.h
//  SobotKit
//
//  Created by 张新耀 on 2019/9/2.
//  Copyright © 2019 zhichi. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZCTitleView : UIView



/**
 设置聊天页面顶部标题

 @param title 标题
 @param image 图片地址(支持本地和网络地址)
 */
-(void)setTitle:(NSString *) title image:(NSString *) imageUrl;

@end

NS_ASSUME_NONNULL_END
