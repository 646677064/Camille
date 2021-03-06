//
//  CMLCoreDataAccess.h
//  Camille
//
//  Created by 杨淳引 on 16/2/28.
//  Copyright © 2016年 shayneyeorg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CMLAccounting.h"
#import "CMLItemCategory.h"
#import "CMLItem.h"
#import "CMLResponse.h"

@interface CMLCoreDataAccess : NSObject

/**
 *  检查两类记账科目中，“设置 —— 新建分类”这个科目是否存在，不存在则新建
 */
+ (void)checkInitialItem:(NSString *)type;

/**
 *  取出所有一级记账科目(并排序)
 *
 *  @param callBack             回调
 */
+ (void)fetchAllItemCategories:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  取出所有二级记账科目(分组并排序)
 *
 *  @param type                 类型
 *  @param callBack             回调
 */
+ (void)fetchAllItems:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  取出所有二级记账科目(消费结算全要)
 *
 *  @param callBack             回调
 */
+ (void)fetchAllItems:(void(^)(CMLResponse *response))callBack;

/**
 *  取出某个分类下的所有二级记账科目
 *
 *  @param categoryID           一级科目ID
 *  @param type                 类型
 *  @param callBack             回调
 */
+ (void)fetchAllItemsInCategory:(NSString *)categoryID type:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  修改某个二级记账科目
 *
 *  @param item                 修改科目
 *  @param itemName             修改后的科目名称
 *  @param category             修改后所属的分类
 *  @param isAvailable          是否有效
 *  @param callBack             回调
 */
+ (void)alterItem:(CMLItem *)item intoItemName:(NSString *)itemName category:(CMLItemCategory *)category isAvailable:(NSString *)isAvailable callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  删除某个二级记账科目
 *
 *  @param item                 删除科目
 *  @param lastItem             上一科目
 *  @param nextItem             下一科目
 *  @param callBack             回调
 */
+ (void)deleteItem:(CMLItem *)item lastItem:(CMLItem *)lastItem nextItem:(CMLItem *)nextItem callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  新增完整记账科目
 *
 *  @param ItemName             二级科目名称
 *  @param ItemCategoryName     一级科目名称
 *  @param type                 账务类型
 *  @param callBack             回调
 */
+ (void)addItem:(NSString *)itemName inCategory:(NSString *)categoryName type:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  新增一级记账科目(含被删除分类检查)
 *
 *  @param ItemCategoryName     一级科目名称
 *  @param type                 账务类型
 *  @param callBack             回调
 */
+ (void)addCategory:(NSString *)itemCategoryName type:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  新增一级记账科目
 *
 *  @param ItemCategoryName     一级科目名称
 *  @param type                 账务类型
 *  @param callBack             回调
 */
+ (void)addItemCategory:(NSString *)itemCategoryName type:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  修改一级记账科目
 *
 *  @param category             一级科目
 *  @param categoryName         一级科目名称
 *  @param type                 账务类型
 *  @param isAvailable          是否有效
 */
+ (BOOL)alterCategory:(CMLItemCategory *)category intoCategoryName:(NSString *)categoryName categoryType:(NSString *)type isAvailable:(NSString *)isAvailable;

/**
 *  删除某个一级记账科目
 *
 *  @param category             删除科目
 *  @param lastCategory         上一科目
 *  @param nextCategory         下一科目
 *  @param callBack             回调
 */
+ (void)deleteCategory:(CMLItemCategory *)category lastCategory:(CMLItemCategory *)lastCategory nextCategory:(CMLItemCategory *)nextCategory callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  在一级科目下新增二级科目
 *
 *  @param ItemName             二级科目名称
 *  @param categoryID           一级科目ID
 *  @param type                 账务类型
 *  @param callBack             回调
 */
+ (void)saveItem:(NSString *)itemName inCategory:(NSString *)categoryID type:(NSString *)type callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  新增账务记录
 *
 *  @param item                 项目名称
 *  @param amount               项目金额
 *  @param happenTime           发生时间
 *  @param callBack             回调
 */
+ (void)addAccountingWithItem:(NSString *)itemID amount:(NSNumber *)amount type:(NSString *)type happneTime:(NSDate *)happenTime callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  删除账务记录
 *
 *  @param item                 账务
 *  @param callBack             回调
 */
+ (void)deleteAccounting:(CMLAccounting *)accounting callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  按日期分类查询某一月份的收支明细
 */
+ (void)fetchAccountingDetailsOnMonth:(NSDate *)date callBack:(void(^)(CMLResponse *response))callBack;

/**
 *  按科目分类查询某一月份的收支明细
 */
+ (void)fetchAccountingDetailsOnItems:(NSDate *)date callBack:(void(^)(CMLResponse *response))callBack;

@end
