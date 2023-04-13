//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTFreeTextAppearanceContainer.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Additions to the `PTFreeText` class.
 */
@interface PTFreeText (Additions)

/**
 * Returns the default style string.
 *
 * @return the default style string, or `nil` if the annotation does not have a default style.
 */
- (nullable NSString *)GetDefaultStyle;

/**
 * Sets the default style string.
 *
 * @param defaultStyle The default style string.
 */
- (void)SetDefaultStyle:(nullable NSString *)defaultStyle;

/**
 * Returns the name of the font specified in the default style of the annotation.
 *
 * @return the name of the font specified in the default style of the annotation
 *
 * @see `GetDefaultStyle`
 */
- (nullable NSString *)GetDefaultStyleFontName;

- (NSInteger)GetDefaultStyleVerticalAlignment;

- (void)SetDefaultStyleVerticalAlignment:(NSInteger)verticalAlignment;

- (nullable NSString *)GetRichContents;

- (void)SetRichContents:(nullable NSString *)richContents;

- (NSAttributedString *)GetAttributedStringContents;

@end

NS_ASSUME_NONNULL_END
