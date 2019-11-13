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

+ (LGEnglishTrainingManager *)defaultManager;

/** 用户ID */
@property (nonatomic, copy) NSString *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;
/** 英语训练基础服务器地址 */
@property (nonatomic, copy) NSString *englishTrainingBaseUrl;
/** 年级ID */
@property (nonatomic, copy) NSString *classID;
/** 自学基础服务器地址 */
@property (nonatomic, copy) NSString *freeStudyBaseUrl;

@property (nonatomic, copy) NSString *studyLevel;

@property (nonatomic, copy) NSString *photoPath;

/** 进入英语训练模块需要调用大数据推送登陆接口，要传入必要的参数 */
@property (nonatomic, copy) NSString *schoolName;   //学校名称
@property (nonatomic, copy) NSString *schoolID;     //学校ID
@property (nonatomic, copy) NSString *gradeName;    //年级名称
@property (nonatomic, copy) NSString *gradeID;      //年级ID
@property (nonatomic, copy) NSString *groupName;    //班级名称
@property (nonatomic, copy) NSString *groupID;      //班级ID
@property (nonatomic, copy) NSString *courseNO;     //课程ID
@property (nonatomic, copy) NSString *courseName;   //课程名称
@property (nonatomic, copy) NSString *subjectName;  //学科名称
@property (nonatomic, copy) NSString *subjectID;    //学科ID
@property (nonatomic, copy) NSString *token;        //用户登录令牌

/** 付费VIP模式 (default is YES) */
@property (nonatomic, assign) BOOL isVipMode;
/** 非VIP模式试听秒数 */
@property (nonatomic, assign) NSInteger nonVipListeningTestTime;
/** 是否开启非VIP限制 */
@property (nonatomic, assign, readonly) BOOL isOpenNonVipLimit;

@property (nonatomic, assign, readonly) NSInteger levelId;

#pragma mark - 英语训练回调

///** (自学模块使用)打开侧边栏 */
//@property (nonatomic, copy) void (^englishTrainingOpenSidebar)(UIViewController *fromController);
/** 跳转知识点学习课件 */
@property (nonatomic, copy) void (^jumpToLGKnowledgeBlock)(UIViewController *fromController, NSString *klgCode);
@property (nonatomic, copy) void (^jumpToLGKnowledgeAlertBlock) (UIViewController *fromController,NSString *klgCode);

@property (nonatomic, copy) void (^englishTrainingNetworkCallback)(NSDictionary *response);

@property (nonatomic, copy) void (^englishTrainingWillDismissBlock)(void);

#pragma mark - 对接英语训练跳转

/** trainingMode 训练模式 听力训练：1 口语训练：2 阅读训练：3 */
/** resType 资源格式 听力训练：1-词汇（听写模式），2-篇章（听写模式），3-听力选择（听力选择模式） 口语训练：1-朗读，2-跟读，1|2-朗读|跟读，3-配音 */

/** 跳转到英语训练主界面 */
- (void)presentEnglishTrainingHomeControllerBy:(UIViewController *)controller;

/** 跳转到英语训练资料预览界面 */
- (void)presentEnglishPreviewControllerBy:(UIViewController *)controller trainingMode:(NSInteger)trainingMode resType:(NSString *)resType resCode:(NSString *)resCode;

/** 跳转到英语训练模块训练界面 */
- (void)presentEnglishTrainingControllerBy:(UIViewController *)controller planId:(NSString *)planId trainingMode:(NSInteger)trainingMode resType:(NSString *)resType resCode:(NSString *)resCode lastProgress:(NSNumber *)lastProgress;


- (void (^)(UIViewController *controller))presentEnglishTrainingHomeController;
- (void (^)(UIViewController *controller, NSInteger trainingMode, NSString *resType, NSString *resCode))presentEnglishPreviewController;
- (void (^)(UIViewController *controller, NSString *planId, NSInteger trainingMode, NSString *resType, NSString *resCode, NSNumber *lastProgress))presentEnglishTrainingController;

#ifdef DEBUG
/** 测试使用 */
- (void)pushToSpeakDubbingViewControllerByNavigationController:(UINavigationController *)navigationController;
#endif

@end

NS_ASSUME_NONNULL_END
