//
//  ETBaseViewController.h
//  LGEnglishTrainingFramework
//
//  Created by lg on 2019/4/29.
//  Copyright © 2019 lg. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ETBarButtonItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface ETBaseViewController : UIViewController <ETBarButtonItemDelegate>

@property (nonatomic, assign) BOOL registeredKeyboardObserve;
@property (nonatomic, assign) BOOL closeSideslip;           //是否关闭侧滑iOS默认手势，默认不关闭
@property (nonatomic, assign) BOOL closeFullScreenSideslip; //是否关闭全屏滑动，当侧滑关闭的时候，全屏滑动失效

//键盘监听
- (void)keyboardWillShowWithKeyboardHeight:(CGFloat)keyboardHeight duration:(NSTimeInterval)duration;
- (void)keyboardWillHideWithDuration:(NSTimeInterval)duration;

- (void)setViewLoadingShow:(BOOL)show;
- (void)setViewNoDataShow:(BOOL)show;
@property (copy, nonatomic) NSString *noDataText;
- (void)setViewLoadErrorShow:(BOOL)show;
@property (copy, nonatomic) NSString *loadErrorText;
- (void)againLoadData;

@end

NS_ASSUME_NONNULL_END
