## SDK 2.8.7 版本更新说明
1、工单、留言最大附件数增加到10个  
2、机器人别名和编号不在同步到入参中  
3、emoji表情，通过表情删除按钮会删除不完整  
4、多语言指定从右往左阅读语言后，再切换普通语言需要手动设置页面左右位置  
5、优化排队消息显示到页面最下面，否则机器人引导语会遮挡排队信息，横屏无法看到排队信息  
6、重新初始化添加机器人别名、vip等级、用户标签等判断条件   
7、发送文件、视频，限制最大上传支持50M  
8、优化聊天页面获取当前UIViewController方法，多级present页面，可能无法获取正确的上层控制器  

## SDK 2.8.6 版本更新说明
1、优化人工客服咨询返回时“暂不评价”逻辑  
2、【新增】机器人别名，可根据别名指定机器人    

```js
// 设置机器人别名
[ZCLibClient getZCLibClient].libInitInfo.robot_alias = @"自定义内容";

```


3、【新增】多语言支持动态更新，支持指定使用语言

```js
// 默认中文
[ZCLibClient getZCLibClient].libInitInfo.absolute_language = @"zh-Hant_lproj";

```

4、优化未读消息数清理流程  
5、优化preset进入页面返回逻辑，解决再次进入页面清空问题  
6、优化暗黑模式跟随系统设置动态切换  
7、支持隐藏聊天时间   
8、优化获取系统相册权限方案   
9、拍照发送偶尔发送失败问题    



## SDK 2.8.5.2 版本更新说明  
1、多伦会话连接知识库类型无法显示问题  
2、人工显示结束会话按钮触发评价时也可配置"暂不评价"  
3、仅人工查询工单留言不及时问题  

## SDK 2.8.5.1 版本更新说明
1、多伦消息没有值，导致页面卡顿问题
2、订单卡片设置背景无效问题

## SDK 2.8.5 版本更新说明
1、【新增】适配暗黑模式(夜间模式)  

```js

	ZCKitInfo *uiInfo=[ZCKitInfo new];
	// 默认为0,跟随系统设置, 1强制使用暗黑风格
    uiInfo.themeStyle = 1;
   
   // 默认为YES，当为暗黑模式时候自定义颜色属性将失效
   // 如果要保持暗黑模式时自定义颜色生效，设置为NO
    uiInfo.useDefaultDarkTheme = YES;

```

2、【新增】人工客服满意度评价新增默认星级设置，5星好评可设置标签,可设置默认0星  
3、【新增】工作台留言回复回复内容如果为空时不显示默认内容，统一只显示状态    
4、【新增】机器人多伦问答支持推送顶、踩功能  
5、【新增】防诈骗提醒策略  
6、【新增】新增默认语言设置，系统默认无法识别语言时显示英文，可根据自己情况设置其它默认语言

```js
// 默认中文
[ZCLibClient getZCLibClient].libInitInfo.default_language = @"zh-Hant_lproj";

```

7、【优化】新增初始化方法，修改域名设置方式，不设置默认使用SaaS域名

```
// 初始化是设置域名，如果不设置，默认SaaS域名
[ZCSobotApi initSobotSDK:@"your appkey" host:@"" result:^(id  _Nonnull object) {
    
}];
	
```   
8、【优化】SDK多级跳转返回消息同步  
9、【优化】使用自定义导航，顶部有白边问题  
10、【优化】留言统一翻译为message，解决无客服在线Email无法识别为留言入口问题    
11、【优化】机器人咨询会话结束后重新开始会话显示上一次问答内容      
12、【优化】客户帮助中心标题过长无法显示完整问题   
13、【优化】聊天页面自动根据translucent适配UI位置  
14、【优化】支持用户退出会话时触发弹出评价后不评价离开会话，现在"暂不评价"  
15、【优化】人工推荐评级，不选择是否解决默认选中"未解决" 问题    
16、【优化】 返回提示isShowReturnTips功能优化，统一返回提醒文字和处理流程   
17、【优化】获取UIWindow对象优化，解决新建UIWindow对象或新建工程AppDelegate无window对象问题   
18、【优化】留言模板中提醒文字过长，发送文件UI异常问题 



## SDK 2.8.4.2 版本更新说明
1、【优化】多伦会话新增消息类型无法识别问题，导致页面卡死


## SDK 2.8.4.1 版本更新说明

1、【优化】兼容iOS13 获取windowbug，解决发送图片可能崩溃问题
2、【优化】解决刷新历史记录一次问题
3、【优化】富文本邮箱、URL识别冲突问题

## SDK 2.8.4 版本更新说明
  
1、【新增】 添加留言评价主动提醒开关   

2、【新增】 回答类型转人工的answer_type优化  

3、【新增】新增隐藏“+”号菜单栏按钮配置     

4、【优化】通告消息置顶字符限制放大到50    

5、【优化】丰富电话号码识别格式，可自定义电话表达式格式  

6、【优化】键盘类动态高度判断  

7、【优化】表情键盘优化，解决图片资源问题    

8、【优化】优化多语言RTL类型UI适配问题  


## SDK 2.8.3 版本更新说明

1 新增viplevel和userlabel

2 增加 留言记录回复查询

3 添加 留言添加partnerid

4 增加 机器人未知回答直接转人工

5 增加适配 横竖屏和国际化



## SDK 2.8.2 版本更新说明
1、【新增】支持横竖屏动态切换，满足客户多种使用场景

2、【新增】留言回复功能，留言也可以持续交互沟通

3、【新增】统一配置连接拦截事件、规范接拦截范围“帮助中心、留言、聊天、留言记录”均可拦截

4、【新增】当前聊天状态变化监听，"机器人、人工、离线"可以实时获取，更准确的调用人工或机器人接口发送消息

5、【新增】留言内容中的附件展示

6、【新增】支持机器人多伦问题引导添加换行

7、【新增】支持机器人多伦问题可多次回点

8、【优化】国际化翻译和展示效果

9、【优化】长连接内部判断是否退出后台，配置是否自动断开保证客户APP后台运行	

10、【优化】个别情况无法关键字转人工

11、【优化】没有人工欢迎语是，自动发送商品信息失效

12、【优化】 客服发送特别长内容显示不完整

13、【优化】 结束会话以后显示的标题不对，变成机器人的了

14、【优化】验证一些使用场景，解决了一些历史遗留问题

	留言记录完成状态无法查看(接口优化)
	
	第一次留言完成，无法立即查看问题(接口优化)
	
	iOS 滑动返回页面数据回收问题
	
	历史记录订单卡片信息不全(接口优化)

## ## 
## SDK 2.8.1 版本更新说明
1 【优化】录音，播放录音发送通知

```
   
 // 监听录音，播放录音
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(audioPlayer_stop) name:@"ZCAudioPlayer_stop" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(audioPlayer_play) name:@"ZCAudioPlayer_play" object:nil];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(recordPlayer_start) name:@"ZCRecordPlayer_start" object:nil];

    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(recordPlayer_stop) name:@"ZCRecordPlayer_stop" object:nil];
```
2 【优化】标题显示逻辑
3 【优化】滑动返回 消息数目问题

## SDK 2.7.14 版本更新说明
1、【新增】支持横竖屏动态切换，满足客户多种使用场景

2、【新增】留言回复功能，留言也可以持续交互沟通

3、【新增】统一配置连接拦截事件、规范接拦截范围“帮助中心、留言、聊天、留言记录”均可拦截

4、【新增】当前聊天状态变化监听，"机器人、人工、离线"可以实时获取，更准确的调用人工或机器人接口发送消息

5、【新增】留言内容中的附件展示

6、【新增】支持机器人多伦问题引导添加换行

7、【优化】国际化翻译和展示效果

8、【优化】没有人工欢迎语是，自动发送商品信息失效

9、【优化】 客服发送特别长内容显示不完整

10、【优化】验证一些使用场景，解决了一些历史遗留问题

留言记录完成状态无法查看(接口优化)

第一次留言完成，无法立即查看问题(接口优化)

iOS 滑动返回页面数据回收问题

历史记录订单卡片信息显示不全(接口优化)

## ## 
## SDK 2.7.13.1 版本更新说明[2019-12-06]
1、支持显示订单信息  

2、支持配置自动改发送订单  

3、修改关键字转人工UI切换bug  

4、优化提前清理数据问题    

5、优化国际化文件内容，补全缺失文件   

6、聊天页面横屏优化

## SDK 2.7.13 版本更新说明
1 【优化】录音，播放录音发送通知

   

```
 // 监听录音，播放录音
  [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(audioPlayer_stop) name:@"ZCAudioPlayer_stop" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(audioPlayer_play) name:@"ZCAudioPlayer_play" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(recordPlayer_start) name:@"ZCRecordPlayer_start" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(recordPlayer_stop) name:@"ZCRecordPlayer_stop" object:nil];
```
2 【优化】标题显示逻辑
3 【优化】滑动返回 消息数目问题

## SDK 2.8.0 版本更新说明
1 【优化】去掉聊天标题，双方昵称，标题栏显示客服头像。

2 【优化】聊天气泡更换，留言样式改变

3  【优化】询前表单UI优化，评价页面UI优化

## SDK 2.7.12 版本更新说明
```
1 【增加】点击退出按钮后新增客户确认浮层
/**
*  返回是否显示提示
*  默认为 YES
*/
@property (nonatomic,assign) BOOL isShowReturnTips;
```
2 【增加】留言模板支持开启工单标题的填写
3  【优化】电商留言溢出接口优化
```
**
 跨公司转接人工(仅电商版本可用)
 */
// 默认0不开启 1-全部溢出，2-忙碌时溢出，3-不在线时溢出
@property (nonatomic,assign)  int   flowType;
```
4 【增加】留言新增视频选择
5  【增加】可配置是否是VIP用户

```
/**
 *
 *  指定客户是否为vip，0:普通 1:vip
 *  同PC端 设置-在线客服分配-排队优先设置-VIP客户排队优先   开启传1 默认不设置
 *  开启后 指定客户发起咨询时，如果出现排队，系统将优先接入。
 **/
@property (nonatomic,copy) NSString *isVip;
```
## SDK 2.7.11 版本更新说明
1、【优化】使用WKWebView替换UIWebView，需要兼容iOS 8.0以前版本客户请联系售后

2、【优化】兼容iOS 13推送

3、【优化】解决@available方法引起的编译问题

4、【优化】仅人工模式不能与机器人发消息

## ## SDK 2.7.10 版本更新说明
1、解决webview查看txt乱码问题，优先使用UTF-8编码解析

2、解决iOS 13 使用presentViewController方式启动不兼容问题，添加.modalPresentationStyle = UIModalPresentationOverFullScreen;

3、补全国际化标签

4、商品标签颜色自定义

## SDK 2.7.9 版本更新说明
1 [增加] 工单回复富文本优化

2 [增加] 图片增加二维码识别

3 [增加] 会话锁定功能

## SDK 2.7.8 版本更新说明
1 [增加] 人工自定义功能和机器人自定义功能拆分

2 [增加] 新增多轮问题答案支持富文本形式展示

3 [增加] 点击拍摄按钮，弹出权限按钮，不同意授权后提示去授权

4 [增加] 增加控制关闭按钮弹出评价的开关字段

5 [优化] 长文本显示

6 [优化] 全面屏机型输入表情符号过多显示问题

7 [优化] 点击拍摄按钮，弹出权限提示

```
/**
 * 自定义输入框下方更多(+号图标)按钮下面内容(不会替换原有内容，会在原有基础上追加)
 * 修改机器人模式的按钮
 * 填充内容为：ZCLibCusMenu.h
 *  title:按钮名称
 *  url：点击链接(点击后会调用初始化linkBock)
 *  imgName:本地图片名称，如xxx@2x.png,icon=xxx
 */
@property (nonatomic,strong) NSMutableArray * cusRobotMoreArray;
/**
 *
 *   针对关闭按钮，单独设置是否显示评价界面，默认不显示
 *
 **/
@property (nonatomic,assign) BOOL isShowCloseSatisfaction;
```
## SDK 2.7.7 版本更新说明
1 [修复]  字段summaryParams无法发送问题   

2 [修复]  发送消息卡片问题

## SDK 2.7.6 版本更新说明
1 [新增]人工咨询页面结束会话按钮

2 [新增]消息卡片消息类型开放

3 [新增]转人工支持传入服务总结自定义字段

4 [新增]横屏限制接口

```
 服务总结自定义字段需要与后台自定义字段-服务总结自定义字段配合使用
 initInfo.summaryParams = @{@"your keyId":@"your value"};
 横屏限制接口
 isShowPortratit,默认是NO
```
## SDK 2.7.5 版本更新说明
1 [新增]  自定义转人工事件   

2 [新增]  商品卡片消息类型    

3 [新增]  服务总结自定义字段支持传参   

4 [新增]  多轮会话中自定义字段“multi-Params”   

5 [优化]  标签链接UI优化   

6 [优化]  支持富文本形式展现知识库词条文本内容  

7 [优化]  机器人设置-机器人引导问题展示--增加“换一组”功能   

8 [优化]  输入框遮挡聊天气泡  

 

```
自定义转人工事件 

如果实现该方法，SDK中转人工事件将交由外部控制处理，您可以跳转到自己设计的技能组页面，或者切换商品信息等，最后调取 -(void)turnServiceWithGroupId:(NSString *)groupId  Obj:(id)obj Msg:(NSString*)msg KitInfo:(ZCKitInfo*)uiInfo ZCTurnType:(NSInteger)turnType Keyword:(NSString*)keyword KeywordId:(NSString*)keywordId;方法去执行转人工操作。

/**
 * 自定义转人工回调事件
 * 拦截SDK 转人工事件 用于跳转到自己的app页面动态处理转人工 配置技能组id 商品信息等参数
 ***/
@property (nonatomic,strong)  TurnServiceBlock    turnServiceBlock;

/**
 *  自定义 转人工事件（在turnServiceBlock回调事件中调用）
 *   groupId 传入技能组id
 *   obj   转人工参数
     msg   转人工信息
    uiInfo   配置商品信息和自动发送参数
    turnType  转人工事件类型（按钮触发，关键字触发等）
    Keyword 关键字
    keywordId 关键字id
 **/
-(void)turnServiceWithGroupId:(NSString *)groupId  Obj:(id)obj Msg:(NSString*)msg KitInfo:(id)uiInfo ZCTurnType:(NSInteger)turnType Keyword:(NSString*)keyword KeywordId:(NSString*)keywordId;

示例代码：
  [ZCLibClient getZCLibClient].turnServiceBlock = ^(id obj,NSString *msg,NSInteger turnType, NSString *keyword ,NSString *keywordId) {
            ZCProductInfo *productInfo = [ZCProductInfo new];
            productInfo.thumbUrl = @"商品图片URL";
            productInfo.title = @"商品标题";
            productInfo.desc = @"摘要";
            productInfo.label = @"标签";
            productInfo.link = @"http://www.sobot.com";
            uiInfo.productInfo = productInfo;
            uiInfo.isSendInfoCard = YES;// 转人工工成功后是否自动发送该商品卡片信息
        [[ZCLibClient getZCLibClient] turnServiceWithGroupId:@"技能组id" Obj:obj Msg:msg KitInfo:uiInfo ZCTurnType:turnType Keyword:keyword KeywordId:keywordId];
    };
```
## ## SDK 2.7.4 版本更新说明
1 [新增]  通告设置拓展  

2 [新增]  留言转离线消息及回复功能    

3 [新增]  帮助中心   

4 [新增]  支持“指定客户优先”设置   

5 [新增]  工单满意度   

6 [新增]  发送订单信息功能   

7 [优化]  清空聊天记录新增二次确认浮层  

8 [新增]  查看对应商户客服是否正在和用户聊天API（仅电商版使用）

```

/**
 *  启动 客户帮助中心
 *  @param info         初始化参数，详情见ZCLibInitInfo not null
 *  @param byController 当前执行跳转的VC           not null
 *  @param delegate     ZCUIChatDelagete        聊天页面的代理，如果实现这个代理用户可以实现留言跳转到自定义页面
 *  @param pageClick    点击返回，UI修改, object为ZCChatController（使用系统导航栏场景） 或者 ZCChatView（使用SDK自定义导航栏场景） 
 *  @param linkBlock    点击消息链接回调，可以为null(注意：如果传递实现后内部将直接返回url，不在做跳转处理)
 */
+(void)openZCServiceCentreVC:(ZCKitInfo *) info

                with:(UIViewController *) byController

                 onItemClick:(void (^)(ZCUIBaseController *object,ZCOpenType type))itemClickBlock;

发送订单信息

1.配置按钮

ZCKitInfo *uiInfo=[ZCKitInfo new];
NSMutableArray *arr = [[NSMutableArray alloc] init];
        ZCLibCusMenu *menu1 = [[ZCLibCusMenu alloc] init];
        menu1.title = [NSString stringWithFormat:@"订单"];
        menu1.url = [NSString stringWithFormat:@"sobot://sendOrderMsg"];;
        menu1.imgName = @"zcicon_sendpictures";
        [arr addObject:menu1];
    uiInfo.cusMoreArray = arr;

2.实现发送事件

[ZCSobot startZCChatVC:uiInfo with:self target:nil pageBlock:^(id object, ZCPageBlockType type) {

    } messageLinkClick:^BOOL(NSString *link) {
        if( [link hasPrefix:@"sobot://sendOrderMsg"]){
            // 发送位置信息
             [ZCSobot sendeOrderMsg:@"订单号：123456789012\n商品1：瓜子200g*1\n商品链接：www.sobot.com商品描述：瓜子...\n商品2：农夫山泉500ml*12\n商品链接：www.sobot.com商品描述:..."];          
               return YES;
        }
       return NO;
    }];
```
```
/**
 *   获取对应商户客服是否正在和用户聊天（仅电商版使用）
 *   appkey：商户id   uid： ZCPlatformInfo 类中的uid 
 **/

+(BOOL)getPlatformIsArtificialWithAppkey:(NSString *)appkey Uid:(NSString*)uid;

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{
 ZCPlatformInfo *info = [_listArray objectAtIndex:indexPath.row];
[ZCSobot getPlatformIsArtificialWithAppkey:info.appkey Uid:info.uid];

}
```
## SDK 2.7.2 版本更新说明
1 [新增]  留言模板   

2 [新增]  留言工单客户可在原渠道查看工单回复    

3 [新增]  咨询页面新增自定义按钮（评价、呼叫）   

4 [新增]  转人工溢出功能  

5 [优化]  机器人转人工业务逻辑

```

2.7.2新增初始化方法

/**

 初始化智齿客服 2.7.2开始使用

 @param appkey 智齿appkey(如果是电商版本，请填写自己公司的APPKEY)

 @param resultBlock 初始化结果回调

 */

-(void)initSobotSDK:(NSString *) appkey result:(void (^)(id object))resultBlock;

原方法： -(void)initSobotSDK:(NSString *) appkey;可以继续使用

```

## SDK 2.7.0 版本更新说明
1 [新增] 推送消息支持来源

2 [新增] 本地消息格式优化

3 [新增] 发送地理位置

4 [新增] 拍摄和发送小视频

5 [新增] 根据后台设置客服超时回复在一通会话中出现次数的限制

## SDK 2.6.9 版本更新说明
1 [新增] 上传文件功能

## SDK 2.6.7 版本更新说明
1 [新增] 机器人切换业务时切换欢迎语

2 [新增] 商家删除指定商户接口(仅电商版使用）

3 [新增] 清空用户下的所有未读消息(本地清空)

## SDK 2.6.6 版本更新说明
1 [新增]iPhone 新机型适配

2 [新增]增加商户对接id(仅电商版使用)

3 初始化方法中 pageBlock 中原 ZCChatController *object 替换为 id object 

```

[ZCSobot startZCChatVC:uiInfo with:self target:nil pageBlock:^(id object, ZCPageBlockType type) {

                // 点击返回

                if(type==ZCPageBlockGoBack){

//                    NSLog(@"点击了关闭按钮");

                }

                // 页面UI初始化完成，可以获取UIView，自定义UI

                if(type==ZCPageBlockLoadFinish){

//                    NSLog(@"页面加载完成");

                }

    } messageLinkClick:nil];

```

## ## SDK 2.6.5 版本更新说明
1 聊天页导航栏新增评级入口（可选）

2 机器人顶踩UI优化

3 新增获取商家信息列表功能（仅电商版使用）

## SDK 2.6.4 版本更新说明
1[新增] 自定义发送消息功能 

2[新增] 自定义排队说辞

## SDK 2.6.3 版本更新说明
1[新增] UI自定义属性

>更多按钮默认图片  

>更多按钮选中图片  

>转人工按钮默认图片  

>转人工按选中图片  

>返回按钮默认图片  

>返回按钮选中图片  

>返回按钮的默认背景色  

>返回按钮的高亮背景色  

>导航栏背景色 

>自定义输入框下方更多(+号图标)按钮下面内容cusMoreArray 

2[新增] 智能路由逻辑处理

3[修改] 方法变更

```  

原： -(void)initZCIMCaht ；方法弃用

原：+(void)closeZCServer:(BOOL)isClosePush; 方法弃用

原：-(void)aginitIMChat; 方法弃用

新增：

/**

 @note 检查当前消息通道是否建立，没有就重新建立

 如果调用 closeIMConnection 后，可调用此方法重新建立链接

 */

-(void)checkIMConnected;

/**

 @note 关闭当前消息通道，使其不再接受消息

 */

-(void)closeIMConnection;

/**

 移除IM所有监听，可能会影响应用在后台存活时长，如果调用此方法后需要checkIMObserverWithCreate重新激活

 网络监听 ZCNotification_NetworkChange

 UIApplicationDidBecomeActiveNotification

 UIApplicationDidEnterBackgroundNotification

 */

-(void)removeIMAllObserver;

/**

 检查当前监听是否被移除，如果移除就重新注册

 */

-(void)checkIMObserverWithRegister;

```

## SDK 2.6.2 版本更新说明
1、修改留言页面电话和邮箱字段赋值异常的bug

2、修改SDK语言文件获取路径为nil的bug

## SDK 2.6.1 版本更新说明
1、【新增】关键字提醒功能  

2、【新增】关键字转人工功能   

3、【新增】机器人多轮会话模板 

## SDK 2.6.0 版本更新说明
1、【新增】机器人切换业务功能  

2、【新增】快捷入口功能  

3、【新增】客服消息撤回提示 

4、【优化】表情资源文件和语言文件文件路径结构  

注：

 1.原ZCEmojiExpression.bundle 表情资源包不在需要导入到项目中，现放到 SobotKit.bundle包中的emoji文件中。  

 2.原SobotLocalizable.strings 语言文件现放在SobotKit.bundle中。 

 3.手动集成SDK 需要导入到项目中的文件 SobotKit.framework 和SobotKit.bundle 。

## SDK 2.5.5 版本更新说明
1、优化技能组UI

2、优化通告显示效果

3、新增设备信息分类

4、优化启动方法   

   SDK启动方法：

+(void)startZCChatVC:(ZCKitInfo *) info

        with:(UIViewController *) byController

       target:(id<ZCChatControllerDelegate>) delegate

      pageBlock:(void (^)(ZCChatController *object,ZCPageBlockType type))pageClick

  messageLinkClick:(void (^)(NSString *link)) messagelinkBlock

## SDK 2.5.4 版本更新说明
1.取消旧的启动方式，替换startZCChatView方法，使用以下方式取代：

[[ZCLibClient getZCLibClient] initSobotSDK:@"your appkey"];

[ZCSobot startZCChatVC:

## SDK 2.5.3 版本更新说明
1.外抛自定义ZCTopView文件

## SDK 2.5.2 版本更新说明
1、多轮会话中模板二和模板三增加分页; 

## SDK 2.5.0 版本更新说明
1、代码重构，新增ZCChatView.h，可自定义页面大小; 

2、ZCUIChatController更名为ZCChatController，原ZCUIChatController将不再维护; 

3、新增自适应系统导航逻辑，不在对系统导航单独隐藏; 

4、优化初始化方法，启动之前新增初始化方法 

-(void)initSobotSDK:(NSString *)appkey;

## SDK 2.4.3 版本更新说明
1、增加机器人分词联想（自动补全）功能

## SDK 2.4.2 版本更新说明
1、增加机器人热点引导问题功能

## SDK 2.4.1 版本更新说明
1、增加机器人多轮会话功能

## SDK 2.4.0 版本更新说明
1、智能转人工

## SDK 2.3.3 版本更新说明
1、优化图片加载方式  

2、适配iOS 11 UI 

3、优化代码，解决获取异常信息可能引起异常冲突文件

## SDK 2.3.2 版本更新说明
1、新增机器人语音翻译功能  

2、留言增加自定义字段设置

## SDK 2.3.0版本更新说明
1、支持人工客服满意度自定义设置  

2、满意度评价页交互优化  

3、通告置顶  

4、自动转留言设置  

5、初始化对接字段调整为后台自定义字段 

6、支持设置转留言到客户自定义的页面  

7、自动应答可设置开关 

## SDK 2.2.2版本更新说明
1、优化网络监听管理类 

## SDK 2.2.1版本更新说明
1、通告自定义 

2、自动应答(说辞)自定义  

3、用户排队达到阀值可以自动跳转到留言页  

4、优化消息通道稳定性

5、新增可配置的自定义参数

## SDK 2.2.0版本更新说明
1、 SDK支持设置【机器人引导转人工】 

2、 评价机器人推送 （顶、踩） 

3、 支持客户自己配置用户提交完成人工满意度评价后释放会话  

4、 留言支持添加图片 





