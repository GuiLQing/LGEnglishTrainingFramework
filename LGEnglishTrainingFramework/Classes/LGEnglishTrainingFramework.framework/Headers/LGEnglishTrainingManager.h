//
//  LGEnglishTrainingManager.h
//  LGEnglishTrainingFramework
//
//  Created by lg on 2019/4/29.
//  Copyright © 2019 lg. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define LGETManager LGEnglishTrainingManager.defaultManager
#define LGETTrainingResGradeKey [NSString stringWithFormat:@"%@%@%@", LGETManager.userID, LGETManager.freeStudyBaseUrl, @"TrainResGradeKey"]
#define LGETTrainModekey [NSString stringWithFormat:@"%@%@%@", LGETManager.userID, LGETManager.freeStudyBaseUrl, @"TrainModekey"]
/** vipStatus 会员状态（1：已开通，但距离到期时间较长；2：未开通；3：已过期；4：已开通，但快过期） */
#define LGETVipStatusKey [NSString stringWithFormat:@"%@%@vipStatus", LGETManager.userID, LGETManager.freeStudyBaseUrl]

@interface LGEnglishTrainingManager : NSObject

/** 用户ID */
@property (nonatomic, strong) NSString *userID;
/** 用户名 */
@property (nonatomic, strong) NSString *userName;
/** 服务器接口地址:http://ip:port */
@property (nonatomic, strong) NSString *severUrl;

@property (nonatomic, strong) NSString *classID;

@property (nonatomic, strong) NSString *serverVersionCode;

@property (nonatomic, strong) NSString *freeStudyBaseUrl;

@property (nonatomic, strong) NSString *studyLevel;

@property (nonatomic, strong) NSString *photoPath;

@property (nonatomic, assign, readonly) NSInteger levelId;
/** 跳转知识点学习课件 */
@property (nonatomic, copy) void (^jumpToLGKnowledgeBlock)(UIViewController *fromController, NSString *klgCode);

+ (LGEnglishTrainingManager *)defaultManager;

- (void)presentEnglishTrainingControllerBy:(UIViewController *)controller;

@property (nonatomic, copy) void (^printBundleUrlPath)(NSString *url);

@end

NS_ASSUME_NONNULL_END
