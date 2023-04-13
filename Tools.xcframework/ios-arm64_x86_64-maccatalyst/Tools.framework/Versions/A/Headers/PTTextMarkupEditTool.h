//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTTextSelectTool.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Tool for editing existing text markup annotations, such as highlights, underlines, etc.
 * In addition to changing basic properties like colour and opacity, it can change the
 * annotation's size, and it's type (e.g. turn a highlight into an underline).
 */
PT_OBJC_RUNTIME_NAME(TextMarkupEditTool)
@interface PTTextMarkupEditTool : PTTextSelectTool

/**
 * Selects the specified text markup annotation.
 *
 * @param annotation the annotation to select
 *
 * @param pageNumber the page number of the annotation
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 */
- (BOOL)selectTextMarkupAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned int)pageNumber;

/**
 * Copies the PDF text under the selected text markup annotation to the system clipboard/pasteboard.
 *
 * This method is called by default by the "Copy" selection menu item.
 */
- (void)copySelectedMarkupText:(id)sender;

/**
 * Shows a menu that allows changing the text markup type for the currently selected annotation(s).
 *
 * This method is called by default by the "Type" selection menu item.
 */
- (void)editSelectedAnnotationType:(id)sender;

/**
 * Flattens the currently selected text markup annotation(s).
 *
 * This method is called by default by the "Flatten" selection menu item.
 */
- (void)flattenSelectedAnnotations:(id)sender;

@end

NS_ASSUME_NONNULL_END
