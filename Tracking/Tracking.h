//
//  Tracking.h
//  ReYun_Tracking
//
//  Created by jesse on 2018/1/19.
//  Copyright © 2018年 yun. All rights reserved.
//
#define REYUN_TRACKING_VERSION @"1.6.2"
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@protocol DeferredDeeplinkCalllback <NSObject>
@optional
- (void)onDeferredDeeplinkCalllback:(NSDictionary *)params;
@end

@interface Tracking : NSObject
//开启打印日志   正式上线包请关掉
+(void) setPrintLog :(BOOL)print;
// 开启数据统计
+ (void)initWithAppKey:(NSString *)appKey withChannelId:(NSString *)channelId;
//延迟深度链接回调代理设置
+ (void)setDeferredDeeplinkCalllbackDelegate:(id<DeferredDeeplinkCalllback>) delegate ;
//注册成功后调用
+ (void)setRegisterWithAccountID:(NSString *)account;
//登陆成功后调用
+ (void)setLoginWithAccountID:(NSString *)account;
//生成订单
+(void)setDD:(NSString *)ryTID hbType:(NSString*)hbType hbAmount:(float)hbAmount;
// 支付完成，付费分析,记录玩家充值的金额（人民币单位是元）
+(void)setRyzf:(NSString *)ryTID ryzfType:(NSString*)ryzfType hbType:(NSString*)hbType hbAmount:(float)hbAmount;
//广告展示时调用
+(void)onAdShow:(NSString *)adPlatform adId:(NSString *)adId;
//广告点击时调用
+(void)onAdClick:(NSString *)adPlatform adId:(NSString *)adId;
//页面展示时调用 pageID代表页面唯一标识，如果使用pageName作为pageID参数值，请确保pageName的唯一性
+(void)trackViewAppear:(NSString *)pageID;
//页面消失时调用，与trackViewAppear:函数成对调用，追踪页面展示时长
+(void)trackViewDisAppear:(NSString *)pageID;
//是否开启APP使用时长监测
+(void)setTrackAppDuration:(BOOL)track;
//自定义事件
+(void)setEvent:(NSString *)eventName;
//获取设备信息
+(NSString*)getDeviceId;
@end
NS_ASSUME_NONNULL_END
