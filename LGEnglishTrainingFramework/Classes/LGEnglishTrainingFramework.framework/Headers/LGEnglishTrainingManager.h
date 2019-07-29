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

static NSString * const LGEnglishTrainingTokenUselessNotification = @"LGEnglishTrainingTokenUselessNotification";

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
/** (自学模块使用)打开侧边栏 */
@property (nonatomic, copy) void (^englishTrainingOpenSidebar)(UIViewController *fromController);
/** 跳转知识点学习课件 */
@property (nonatomic, copy) void (^jumpToLGKnowledgeBlock)(UIViewController *fromController, NSString *klgCode);

+ (LGEnglishTrainingManager *)defaultManager;
/** 跳转到英语训练主界面 */
- (void)presentEnglishTrainingHomeControllerBy:(UIViewController *)controller;
- (void (^)(UIViewController *controller))presentEnglishTrainingHomeController;
/** 跳转到英语训练模块训练界面 */
/** trainingType 词汇听写：1， 句子听写：2， 听力选择：3， 朗读：4， 跟读：5， 跟读及理解：6， 配音：7， 阅读选择：8 */
- (void)presentEnglishTrainingControllerBy:(UIViewController *)controller planId:(NSString *)planId trainingType:(NSInteger)trainingType resCode:(NSString *)resCode lastProgress:(NSNumber *)lastProgress;
- (void (^)(UIViewController *controller, NSString *planId, NSInteger trainingType, NSString *resCode, NSNumber *lastProgress))presentEnglishTrainingController;

@end

NS_ASSUME_NONNULL_END
