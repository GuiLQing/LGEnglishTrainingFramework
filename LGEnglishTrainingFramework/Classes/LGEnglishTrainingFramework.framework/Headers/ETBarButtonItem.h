//
//  ETBarButtonItem.h
//  LGEnglishTrainingFramework
//
//  Created by lg on 2019/7/5.
//  Copyright © 2019 lg. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ETBarButtonItemType) {
    ETBarButtonItemTypeBack,
    ETBarButtonItemTypeFilter,
    ETBarButtonItemTypeSearch,
    ETBarButtonItemTypeMore,
};

@protocol ETBarButtonItemDelegate <NSObject>

@optional

- (void)clickBarButtonItem:(UIBarButtonItem *)sender type:(ETBarButtonItemType)type;
- (void)clickBackBarButtonItem:(UIBarButtonItem *)sender;

@end

@interface ETBarButtonItem : UIBarButtonItem

@property (nonatomic, assign, readonly) ETBarButtonItemType barButtonItemType;

@property (nonatomic, weak) id<ETBarButtonItemDelegate> delegate;

+ (NSArray *)barButtonItemsWithTypes:(NSArray *)types delegate:(id)delegate;

@end

NS_ASSUME_NONNULL_END
