//
//  ETBaseNavigationController.h
//  LGEnglishTrainingFramework
//
//  Created by lg on 2019/4/29.
//  Copyright © 2019 lg. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ETBaseNavigationController : UINavigationController

@property (nonatomic, strong) UIPanGestureRecognizer *backGesture;

@end

NS_ASSUME_NONNULL_END
