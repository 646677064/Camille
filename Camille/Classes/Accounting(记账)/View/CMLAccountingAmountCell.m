//
//  CMLAccountingAmountCell.m
//  Camille
//
//  Created by 杨淳引 on 16/3/12.
//  Copyright © 2016年 shayneyeorg. All rights reserved.
//

#import "CMLAccountingAmountCell.h"

@interface CMLAccountingAmountCell () <UITextFieldDelegate>

@end

@implementation CMLAccountingAmountCell

#pragma mark - Public

+ (instancetype)loadFromNib {
    CMLAccountingAmountCell *cell = [[NSBundle mainBundle]loadNibNamed:@"CMLAccountingAmountCell" owner:self options:nil][0];
    cell.amountTextField.text = @"金额";
    cell.amountTextField.delegate = cell;
    return cell;
}

- (BOOL)isAmountAvailable {
    NSString *searchText = self.amountTextField.text;
    NSError *error = NULL;
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"^[0-9]+([.]{0,1}[0-9]+){0,1}$" options:NSRegularExpressionCaseInsensitive error:&error];
    NSTextCheckingResult *result = [regex firstMatchInString:searchText options:0 range:NSMakeRange(0, [searchText length])];
    if (result) {
        CMLLog(@"金额格式正确");
        return YES;
        
    } else {
        CMLLog(@"金额格式错误");
        return NO;
    }
}

#pragma mark - UITextFieldDelegate

- (void)textFieldDidEndEditing:(UITextField *)textField {
    if (!self.amountTextField.text.length) {
        self.amountTextField.text = @"金额";
    }
}

@end




