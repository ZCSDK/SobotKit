//
//  ZCStatusDefine.h
//  ZCLibLib
//
//  Created by zhangxy on 15/10/22.
//  Copyright © 2015年 ZCLib. All rights reserved.
//
/**
 *  @enum 智齿连接业务状态码
 */
typedef NS_ENUM(NSInteger, ZCConnectStatusCode) {
    /**
     *  连接失败。
     */
     ZC_CONNECT_FAIL = -1,
    /**
     *  本地调用传入参数错误。
     */
     ZC_INVALID_ARGUMENT = -1000,
    /**
     *  其它地方登陆了
     */
    ZC_CONNECT_KICKED_OFFLINE_BY_OTHER_CLIENT = 6,
    /**
     *  链接人工成功
     */
    ZC_CONNECT_SUCCESS = 200,
    
    
    /**
     *  连接中
     */
    ZC_CONNECT_START = 201,
};


/**
 *  @enum 智齿连接业务状态码
 */
typedef NS_ENUM(NSInteger, ZCConnectUserStatusCode) {
    
    /** * 人工服务连接失败，已重新连接。 */
    ZCConnectUserServerFailed = -1,
    
    /** * 连接失败, 排队中。 */
    ZCConnectUserOfWaiting = 0,

    /** * 连接成功。 */
    ZCConnectUserSuccess = 1,
    
    /** * 没有客服在线。 */
    ZCConnectUserNoAdmin = 2,
    
    /** * 用户被拉黑 */
    ZCConnectUserBeBlock = 3,
    
    /** * 用户已经转人工无需再次请求 */
    ZCConnectUserBeConnected = 4,
    
    // 机器人超时下线，转人工
    ZCConnectUserRobotTimeout = 5,
    
    //如果设置指定客服的id。并且设置不是必须转入，服务器返回status=6.这个时候要设置receptionistId为null
        //为null以后继续转人工逻辑。如果技能组开启就弹技能组，如果技能组没有开启，就直接转人工
    ZCConnectUserNextTry = 6,
    
    /**  排队达到阀值 */
    ZCConnectUserWaitingThreshold = 7
    
};


/**
 *  @enum 智齿消息业务状态码
 */
typedef NS_ENUM(NSInteger, ZCMessageSendCode) {
    /**
     *  发送消息成功。
     */
     ZC_SENDMessage_Success = 0,
    /**
     *  新消息回复。
     */
     ZC_SENDMessage_New = 1,
    
    /**
     *  发送消息失败。
     */
     ZC_SENDMessage_FAIL = -1,
    
    /**
     *  发送消息失败
     */
    ZC__SENDMessage_FAIL_STATUS = 1002,
    /**
     *  发送消息为空
     */
     ZC_SENDMessage_NULL = -2,
    
    /**
     *  文件不存在。
     */
     ZC_File_NotFound = -1000,
    
};


/**
 *  @enum 网络请求
 */
typedef NS_ENUM(NSInteger, ZCNetWorkCode) {
    /**
     *  访问成功。
     */
     ZC_NETWORK_SUCCESS = 0,
    
    /**
     *  访问成功，但是空数据。
     */
     ZC_NETWORK_NULL_DATA = 1,
    
    /**
     *  连接失败。
     */
     ZC_NETWORK_FAIL = -1,
    
    /**
     *  参数错误。
     */
    ZC_PARAMS_FAIL = -2,
};
