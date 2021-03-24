//
//  ZCLibRich.h
//  ZCLibLib
//
//  Created by zhangxy on 15/11/9.
//  Copyright © 2015年 ZCLibLib. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCMultiwheelModel.h"

/**消息体类型*/
typedef NS_ENUM(NSInteger,ZCMessageType) {
    // 0文本 1图片 2音频 3、富文本带标签、4 富文本中有图片 5 富文本中纯文字 6 富文本中有视频，9、10为一个json字符串 15，多轮会话  7.热点引导, 12文件,24商品信息
    ZCMessageTypeText  = 0, //文本
    ZCMessageTypePhoto = 1, //图片
    ZCMessageTypeSound = 2, // 声音
//    ZCMessageTypeRich  = 3, // 富文本
    ZCMessageTypeRichPhoto  = 4, // 富文本
    ZCMessageTypeRichTextJson = 5, // 对象
    ZCMessageTypeRichVideo = 6,
    ZCMessageTypeHotGuide = 7,
    ZCMessageTypeLoopRobotRich  = 11, // 多伦会话，按普通文本处理
    ZCMessageTypeFile  = 4, // 文件
    ZCMessageTypeLoopChat = 15,
    ZCMessageTypeLocation  = 22, // 位置
    ZCMessageTypeVideo = 3,
//    ZCMessagetypeCard   = 101,//商品卡片消息
    ZCMessageTypeCard = 24,//商品卡片消息
    ZCMessageTypeOrder= 25,//订单卡片消息
    ZCMessageTypeRobotCommonProblemGuide = 102, // 机器人 常见问题引导
    
    ZCMessagetypeStartSound = -4,//正在录音
    ZCMessagetypeCancelSound = -5,//取消正在闪烁的语音cell
};

typedef NS_ENUM(NSInteger,ZCMessageRichType) {
//    对象类型：
//    * 0-富文本
//    * 1-多伦会话
//    * 2-位置
//    * 3-小卡片
//    * 4-订单卡片
    
    ZCMessageRichTypeText  = 0,//-富文本
    ZCMessageRichTypeLoop = 1, //多伦
    ZCMessageRichTypeLocation = 2, // 位置
    ZCMessageRichTypeGoods = 3, // 商品卡片
    ZCMessageRichTypeOrder  = 4, // 订单
    ZCMessageRichTypeBrowseTrack  = 114, // 浏览轨迹
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
@property (nonatomic,assign  ) ZCMessageType              msgType;

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
 * DOC(0,"doc"),
 PPT(1,"ppt"),
 XLS(2,"xls"),
 PDF(3,"pdf"),
 MP3(4,"mp3"),
 MP4(5,"mp4"),
 RAR(6,"rar"),
 TXT(7,"txt"),
 OTHER(8,"other");
 */

@property (nonatomic,assign  ) int              fileType;
@property (nonatomic,strong  ) NSString         *fileSize;
@property (nonatomic,strong  ) NSString         *fileName;




// 富文本类型
@property (nonatomic,assign  ) ZCMessageRichType          richType;


// 富文本数组:0：文本，1：图片，2：音频，3：视频，4：文件
// {type:0,1,2,3,msg:}
@property (nonatomic,strong  ) NSArray * richMsgList;


// 新消息体
@property (nonatomic,strong) NSArray         *goods;
@property (nonatomic,assign) int          orderStatus;//:订单状态
@property (nonatomic,copy) NSString          *orderStatusStr;//:订单状态
@property (nonatomic,copy) NSString          *orderCode;//:订单编号
@property (nonatomic,copy) NSString          *orderUrl;//:订单链接
@property (nonatomic,copy) NSString          *createTime;//:创建时间
@property (nonatomic,copy) NSString          *totalFee;//:总金额
@property (nonatomic,copy) NSString          *goodsCount;//:商品个数
@property (nonatomic,copy) NSString          *createTimeFormat;//：格式化后的时间url:位置链接地址
@property (nonatomic,copy) NSString          *picUrl;//:位置缩略图

@property (nonatomic,copy) NSString          *richMoreUrl;//富文本内容
@property (nonatomic,copy) NSString          *snapshot;//富文本内容

@property (nonatomic,copy) NSString          *thumbnail;//富文本内容
@property (nonatomic,copy) NSString          *label;//富文本内容
@property (nonatomic,copy) NSString          *url;//富文本内容


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
