//
//  ZCPlatformInfo.h
//  SobotKit
//
//  Created by zhangxy on 2017/9/4.
//  Copyright © 2017年 zhichi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZCLibConfig.h"
#import "ZCLibMessage.h"

/** 平台APPKEY */
extern NSString * const PLATFORMKEY_APPKEY;
extern NSString * const PLATFORMKEY_NAME;
extern NSString * const PLATFORMKEY_USERID;
extern NSString * const PLATFORMKEY_AVATAR;
extern NSString * const PLATFORMKEY_LASTMESSAGE;
extern NSString * const PLATFORMKEY_WAITINGMSG;
extern NSString * const PLATFORMKEY_DATE;
extern NSString * const PLATFORMKEY_CONFIGINFO;
extern NSString * const PLATFORMKEY_UNREAD;
extern NSString * const PLATFORMKEY_ISSENDTOROBOT;
extern NSString * const PLATFORMKEY_ISSENDTOUSER;
extern NSString * const PLATFORMKEY_ISPJ_ROBOT;
extern NSString * const PLATFORMKEY_ISPJ_USER;
extern NSString * const PLATFORMKEY_CONFIG;
extern NSString * const PLATFORMKEY_INITINFO;
extern NSString * const PLATFORMKEY_MESSAGEARR;
extern NSString * const PLATFORMKEY_CUSTOMERCODE;

@interface ZCPlatformInfo : NSObject

@property (nonatomic,strong) NSString *listId;
@property (nonatomic,strong) NSString *platformId;
@property (nonatomic,strong) NSString *partnerid;
@property (nonatomic,strong) NSString *app_key;
@property (nonatomic,strong) NSString *companyId;
@property (nonatomic,strong) NSString *platformName;
@property (nonatomic,strong) NSString *avatar;
@property (nonatomic,strong) NSString *lastDate;
@property (nonatomic,strong) NSString *lastMsg;
@property (nonatomic,assign) int       unRead;
@property (nonatomic,strong) NSString *uid;
@property (nonatomic,strong) NSString *lastCid;
@property (nonatomic,strong) NSString *configJson;
@property (nonatomic,strong) NSString * customer_code;// 对应的商户appkey

// 临时数据
@property (nonatomic,assign) BOOL isSendToRobot;
@property (nonatomic,assign) BOOL isSendToUser;
@property (nonatomic,assign) BOOL isPjRobot;
@property (nonatomic,assign) BOOL isPjUser;
@property (nonatomic,strong) NSString *groupId;
@property (nonatomic,strong) NSString *groupName;
@property (nonatomic,strong) NSString     *checkInitKey;
@property (nonatomic,strong) ZCLibConfig  *config;
@property (nonatomic,strong) ZCLibMessage *waitintMessage;
@property (nonatomic,strong) NSMutableArray  *messageArr;

/** 保存历史记录的cid列表 */
@property(nonatomic, strong) NSMutableArray *cidsArray;

-(id) initWithMyDict:(NSDictionary *)dict;

@end
