//
//  AudioPlayer.h
//  AudioPlayer
//
//  Created by 马远 on 2017/7/12.
//  Copyright © 2017年 Yuan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AudioItem.h"

@interface AudioPlayer : NSObject

/** 是否正在播放 */
@property (nonatomic, assign) BOOL isPlay;

+ (instancetype)shareManager;


- (void)creatPlayList:(NSArray<AudioItem *> *)listArray;

- (void)addItem:(AudioItem *)item;
- (void)removeItem:(AudioItem *)item;
- (void)removeAllItem;

- (NSArray<AudioItem *> *)getCurrentPlayList;
- (AudioItem *)getCurrentPlayItem;
- (NSUInteger)getCurrentIndex;

- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)next;
- (BOOL)last;


/**
 播放完成回调
 */
- (void)playFinish:(void(^)(AudioItem *item))finishBlock;

/**
 播放进度回调
 */
- (void)playProgressValueChanged:(void(^)(AudioItem *currentItem, NSTimeInterval current,NSTimeInterval total))changedBlock;

/**
 加载进度回调
 */
- (void)loadProgressValueChanged:(void(^)(AudioItem *currentItem, NSTimeInterval current,NSTimeInterval total))loadBlock;

/**
 设置播放进度
 当滑动修改进度的时候，建议滑动动作结束后一次性设置改值
 @param value 播放比（0~1）
 @param completionHandler 回调
 */
- (void)seekToValue:(CGFloat)value completionHandler:(void (^)(BOOL finished))completionHandler;

@end
