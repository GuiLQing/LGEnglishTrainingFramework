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
@property (nonatomic, copy) NSString *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;
/** 服务器接口地址:http://ip:port */
@property (nonatomic, copy) NSString *severUrl;
/** 年级ID */
@property (nonatomic, copy) NSString *classID;

@property (nonatomic, copy) NSString *serverVersionCode;

@property (nonatomic, copy) NSString *freeStudyBaseUrl;

@property (nonatomic, copy) NSString *studyLevel;

@property (nonatomic, copy) NSString *photoPath;

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

@end

NS_ASSUME_NONNULL_END
