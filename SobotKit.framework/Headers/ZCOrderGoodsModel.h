//
//  ZCOrderGoodsModel.h
//  SobotKit
//
//  Created by 张新耀 on 2019/9/29.
//  Copyright © 2019 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
发送订单消息字段：
 订单状态: orderStatus
 订单编号: orderCode
 订单创建时间: createTime
 商品图片链接: goodsPicturesUrls
 订单链接: orderUrl  ，
 商品描述: goodsDesc
 商品件数: goodsCount
 总金额: totalFee，单位为分，显示时会默认格式化为元，例如，传入100，显示效果为1.00元
*/
@interface ZCOrderGoodsModel : NSObject

/*
待付款: 1,
待发货: 2,
运输中: 3,
派送中: 4,
已完成: 5,
待评价: 6,
已取消: 7,
其它: 不在编码中的
 */
@property (nonatomic,assign) int orderStatus;

// 自定义订单状态，仅当orderStatus=0时生效
@property (nonatomic,strong) NSString *statusCustom;

@property (nonatomic,strong) NSString *orderCode;

// Java 中的long类型，例如[NSString stringWithFormat:@"%.0f",[[NSDate date] timeIntervalSince1970]*1000*1000]
// 例如：1569491413000，不是这样的值，会发送不成功
@property (nonatomic,strong) NSString *createTime;

// 商品信息
// [{@"name":@"商品名称",@"pictureUrl":@"图片地址"}]
@property (nonatomic,strong) NSArray *goods;

//此链接可监听链接点击事件，拦截后自行处理
@property (nonatomic,strong) NSString *orderUrl;
@property (nonatomic,strong) NSString *goodsCount;


/// 单位为分，只能是int类型的数字（显示时会默认格式化为元，例如，传入100，显示效果为1.00元）
@property (nonatomic,strong) NSString *totalFee;

// 获取状态字符串内容
+(NSString *)getOrderStatusMsg:(int) status;
@end

NS_ASSUME_NONNULL_END
