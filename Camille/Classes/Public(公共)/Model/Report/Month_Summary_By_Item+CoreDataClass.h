//
//  Month_Summary_By_Item+CoreDataClass.h
//  Camille
//
//  Created by 杨淳引 on 2017/3/31.
//  Copyright © 2017年 shayneyeorg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

@interface Month_Summary_By_Item : NSManagedObject

+ (void)getMonthItemSummaryInYear:(NSString *)year month:(NSString *)month autoUpdateIfNoRecord:(BOOL)autoUpdate callback:(void(^)(CMLResponse *response))callBack;

+ (void)updateMonthItemSummaryInYear:(NSString *)year month:(NSString *)month callback:(void(^)(CMLResponse *response))callBack;

@end

NS_ASSUME_NONNULL_END

#import "Month_Summary_By_Item+CoreDataProperties.h"
