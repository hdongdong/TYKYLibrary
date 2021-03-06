//
//  TJSessionDownloadTool.h
//  TAIJIToolsFramework
//
//  Created by Apple on 2016/11/9.
//  Copyright © 2016年 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,ImageDownloadState) {
    WaitingDownloadState,      //准备下载
    DownloadingState,          //正在下载
    DownloadSuccessState,      //下载成功
    DownloadFailState          //下载失败

};

@protocol TJSessionDownloadToolDelegate <NSObject>

//发送下载进度
- (void)changeProgressValue:(NSString *)progress;//发送下载进度

//下载成功或失败
- (void)downLoadedSuccessOrFail:(BOOL)state withUrl:(NSString *)urlStr;

@end

@interface CTDownloadWithSession : NSObject

@property (nonatomic, weak) id<TJSessionDownloadToolDelegate>delegate;
@property (nonatomic, strong) NSString *percentStr; //下载进度百分比
@property (nonatomic, strong) NSString *filePath;   //下载完成后存入的本地路径
@property (nonatomic, strong) NSString *urlStr;     //下载链接
@property (nonatomic, assign) ImageDownloadState downloadState;

/**
 *  传入下载地址 实例化下载对象
 */
+ (instancetype)initWithUrlStr:(NSString *)urlStr
                      filePath:(NSString *)filePath;

- (void)startDownload;//开始下载
- (void)pauseDownload;//暂停下载
- (void)resumeDownload;//继续下载
- (void)cancelDownload;//取消下载

@end
