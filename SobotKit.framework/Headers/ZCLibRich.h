//
//  ZCLibRich.h
//  ZCLibLib
//
//  Created by zhangxy on 15/11/9.
//  Copyright © 2015年 ZCLibLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCMultiwheelModel.h"
typedef NS_ENUM(NSInteger,ZCMsgType) {
    // 0文本 1图片 2音频 4 富文本中有图片 5 富文本中纯文字 6 富文本中有视频 15，多轮会话  7.热点引导, 12文件
    ZCMsgTypeText = 0,
    ZCMsgTypePhoto = 1,
    ZCMsgTypeVoice = 2,
    ZCMsgTypeRich = 4,
    ZCMsgTypeRichText = 5,
    ZCMsgTypeRichVideo = 6,
    ZCMsgTypeHotGuide = 7,
    ZCMsgTypeFile = 12,
    ZCMsgTypeVideo = 23,
    ZCMsgTypeLocation = 22,
    ZCMsgTypeLoopChat = 15,
    ZCMsgTypeCard = 101,
};

/**
 *  配置富媒体
 */
@interface ZCLibRich : NSObject

/**
 *  富媒体更多地址
 */
@property (nonatomic,strong  ) NSString         * richmoreurl;

/**
 *  富媒体图片地址
 */
@property (nonatomic,strong  ) NSString         * richpricurl;

/**
 *  消息体，当时图片和语音时，为图片、语音地址
 */
@property (nonatomic,strong  ) NSString         * msg;

/**
 语音翻译
 */
@property (nonatomic,strong  ) NSString         * msgtranslation;

/**
 *  语音时长
 */
@property (nonatomic,strong  ) NSString         * duration;

/**
 *  0文本 1图片 2音频 4 富文本中有图片 5 富文本中纯文字 6 富文本中有视频 15，多轮会话  7.热点引导, 8文件 ,24 商品卡片
 */
@property (nonatomic,assign  ) ZCMsgType              msgType;

/**
 * 13 doc文件格式
 * 14 ppt文件格式
 * 15 xls文件格式
 * 16 pdf文件格式
 * 17 mp3文件格式
 * 18 mp4文件格式
 * 19 压缩文件格式
 * 20 txt文件格式
 * 21 其他文件格式
 */
@property (nonatomic,assign  ) int              fileType;
@property (nonatomic,strong  ) NSString         *fileSize;


//位置
// 经度
@property (nonatomic,strong  ) NSString         *longitude;
// 维度
@property (nonatomic,strong  ) NSString         *latitude;
// 地址
@property (nonatomic,strong  ) NSString         *localName;
@property (nonatomic,strong  ) NSString         *localLabel;


/**
 *  回答建议
 */
@property (nonatomic,strong  ) NSArray          * sugguestions;


/**
 *  引导回答
 */
@property (nonatomic,strong) NSArray             * suggestionArr;


/**
 *
 *  机器人回复 技能组数据
 *
 **/
@property (nonatomic,strong) NSArray * groupArr;

/**
 *
 *  机器回复 是否智能转人工
 *   // 0 测试数据
 **/
@property (nonatomic,assign) int   turntype;


/**
 *  1 直接回答，2 理解回答，3 不能回答, 4引导回答，6互联网寒暄，
 *  7 私有寒暄（包括第三方天气、快递接口）,8百科, 9 向导回答,10 业务接口    // 151 152 153 待接口 多轮会话的类型
 */
@property (nonatomic,assign  ) int              answerType;

@property (nonatomic,copy) NSString * answerStrip;// 引导语，多轮会话中 15239 1523 1524 时 megtype ==11 时 添加


// 是否开启换一批功能
@property (nonatomic,assign  ) int              guideGroupFlag;

// 没页显示的数量
@property (nonatomic,assign  ) int              guideGroupNum;

// 当前显示页数，从0开始
@property (nonatomic,assign  ) int              guideGroupPage;


/**
 *  建议引导
 */
@property (nonatomic,strong  ) NSString         * stripe;


@property (nonatomic,strong  ) NSString         * question;
@property (nonatomic,strong  ) NSString         * time;

@property (nonatomic,strong  ) NSString         * docId;
@property (nonatomic,strong  ) NSString         * docName;


@property(nonatomic,strong) ZCMultiwheelModel   * multiModel;

// 0用户自己 1.机器人 2，客服
@property(nonatomic,assign) int            senderType;


/** 热点引导 说辞*/
@property (nonatomic,copy) NSString * guide;

/** 热点引导的item 数组 */
@property (nonatomic,strong) NSMutableArray * hotGuideArr;

/** 当前数据是 热点引导*/
@property (nonatomic,assign) BOOL isHotGuide;




/**
 *  初始化
 *
 *  @param dict 解析后的数据（字典类型）
 *  @param senderType  0 用户发送 1机器人发送 2客服发送
 *  @param isSend  区分是发送的，还是历史记录
 *  @return ZCLibRich
 */
-(id) initWithMyDict:(NSDictionary *)dict WithSenderType:(int)senderType IsHistory:(BOOL) isHistory isHotGuide:(BOOL) ishotGuide;

/**
 *  初始化富媒体消息
 *
 *  @param answer  回答
 *
 *  @return ZCLibRich
 */
-(ZCLibRich *) initWithAsnwer:(NSString *)answer WithSenderType:(int)senderType IsHistory:(BOOL) isHistory isHotGuide:(BOOL) ishotGuide;

@end
