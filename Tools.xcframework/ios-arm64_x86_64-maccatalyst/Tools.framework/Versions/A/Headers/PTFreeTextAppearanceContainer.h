//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(FreeTextAppearanceContainer)
@interface PTFreeTextAppearanceContainer : NSObject

@property (nonatomic, assign) CGSize size;

@property (nonatomic, strong, nullable) UIColor *backgroundColor;

@property (nonatomic, strong, nullable) UIColor *borderColor;

@property (nonatomic, assign) CGFloat borderWidth;

@property (nonatomic, assign) CGFloat alpha;

#pragma mark - Text

@property (nonatomic, readonly, strong) NSTextContainer *textContainer;

@property (nonatomic, readonly, strong) NSLayoutManager *layoutManager;

@property (nonatomic, readonly, strong) NSTextStorage *textStorage;

#pragma mark - Drawing

- (void)drawAtPoint:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
