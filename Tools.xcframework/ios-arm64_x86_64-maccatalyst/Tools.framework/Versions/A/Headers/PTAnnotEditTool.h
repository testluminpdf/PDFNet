//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTTool.h>
#import <Tools/PTSelectionRectContainerView.h>
#import <Tools/PTAnnotStyleViewController.h>

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotEditTool;
@class PTSelectionRectContainerView;

/**
 * The `PTAnnotEditToolDelegate` protocol allows the adopting class to respond to messages sent by the
 * `PTAnnotEditTool` class.
 */
PT_OBJC_RUNTIME_NAME(AnnotEditToolDelegate)
@protocol PTAnnotEditToolDelegate <NSObject>

@optional

/**
 * Notifies the delegate that editing of a free text annotation has begun.
 */
- (void)annotEditTool:(PTAnnotEditTool *)annotEditTool didBeginEditingFreeText:(PTFreeText *)annot withTextView:(UITextView *)textView;

/**
 * Allows the delegate to control if an annotation's appearance should be rendered as a vector or a bitmap when selected. If the delegate method is not implemented, all annotations that can be rendered as vectors will be.
 *
 * @param annotEditTool The annot edit tool.
 *
 * @param annot The annotation that will be rendered.
 *
 * @param pageNumber The page number of the annotation.
 *
 * @note Only certain annotation types can be rendered with vector appearances.
 */
- (BOOL)annotEditTool:(PTAnnotEditTool *)annotEditTool shouldRenderAnnotationAsVector:(PTAnnot *)annot onPageNumber:(unsigned long)pageNumber;

@end

/**
 * The PTAnnotEditTool is used to change the properties, position and size of annotations.
 * It also handles link annotations.
 */
PT_OBJC_RUNTIME_NAME(AnnotEditTool)
@interface PTAnnotEditTool : PTTool <UIPopoverPresentationControllerDelegate, UITextViewDelegate, PTAnnotStyleViewControllerDelegate>

/**
 The transparent parent view that holds the shaded annotation selection rectangle and resize handles.
 */
@property (nonatomic, readonly, strong) PTSelectionRectContainerView* selectionRectContainerView;

/**
 * When the user is resizing the annotation, the resize handle that is currently in use.
 */
@property (readonly, nonatomic, weak) UIView* touchedSelectWidget;

/**
 * When true, only corner resize handles are available, and the aspect ratio will be maintained.
 * Default is true for stamp and signatures annotations, false for others.
 */
@property (nonatomic, assign) BOOL maintainAspectRatio;

/**
 * When enabled, a visual guide is shown while resizing an annotation to indicate the
 * line along which the annotation's original aspect ratio is maintained.
 *
 * This property is enabled by default.
 */
@property (nonatomic, assign, getter=isAspectRatioGuideEnabled) BOOL aspectRatioGuideEnabled;

/**
 * The minimum size that annotations can be resized to, expressed in page space.
 * The default value is 0.
 */
@property (nonatomic, assign) CGFloat minimumAnnotationSize;

/**
 * The maximum size that annotations can be resized to, expressed in page space.
 * By default, there is no maximum size limit.
 */
@property (nonatomic, assign) CGFloat maximumAnnotationSize;

/**
 * The `PTAnnotEditTool`'s delegate object.
 */
@property (nonatomic, weak, nullable) id<PTAnnotEditToolDelegate> delegate;

/**
 * Selects the specified annotation.
 *
 * @param annotation the annotation to select
 *
 * @param pageNumber the page number of the annotation
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 *
 * @see `-selectAnnotation:onPageNumber:showMenu:`
 */
- (BOOL)selectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned int)pageNumber;

/**
 * Selects the specified annotation and optionally shows the annotation selection menu.
 *
 * @param annotation the annotation to select
 *
 * @param pageNumber the page number of the annotation
 *
 * @param showMenu whether the annotation selection menu should be shown
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 */
- (BOOL)selectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned int)pageNumber showMenu:(BOOL)showMenu;

/**
 * An array of selected annotations.
 */
@property (nonatomic, copy) NSArray<PTAnnot *> *selectedAnnotations;

/**
 * Sets the annotation's border thickness.
 */
-(void)setAnnotationBorder:(float)thickness;

/**
 * Selects the annotation where the user tapped or long pressed. If it is a link, the link
 * will be followed.
 */
-(BOOL)makeNewAnnotationSelection:(UIGestureRecognizer*)gestureRecognizer;

/**
 * Deselects the currently selected annotation `currentAnnotation`.
 */
-(void)deselectAnnotation;

/**
 * Sets the `currentAnnotation`'s opacity.
 */
-(void)setAnnotationOpacity:(double)opacity;

/**
 * Action to flatten the currently selected annotations.
 */
- (void)flattenSelectedAnnotations:(id)sender;

/**
 * Action to copy the currently selected annotations to the pasteboard.
 */
- (void)copySelectedAnnotations:(id)sender;

// used by PTTextMarkupEditTool

/**
 * Allows the user to set the `currentAnnotation`'s stroke color.
 */
-(void)editSelectedAnnotationStrokeColor;

/**
 * Allows the user to set the `currentAnnotation`'s border thickness.
 */
-(void)editSelectedAnnotationBorder;

/**
 * Allows the user to set the `currentAnnotation`'s opacity.
 */
-(void)editSelectedAnnotationOpacity;

/**
 * Edits the currently selected `PTFreeText` annotation's contents.
 */
- (void)editSelectedAnnotationFreeText;

/**
 * Allows the user to edit the `currentAnnotation`'s style.
 */
-(void)editSelectedAnnotationStyle;

/**
 * Commits the user-selected style for the `currentAnnotation`.
 */
-(void)commitSelectedAnnotationStyle;

/**
 * Allows the user to edit the `currentAnnotation`'s date. This method only functions correctly if the
 * `currentAnnotation` has an `extendedAnnotType` of `PTExtendedAnnotTypeDateText`.
 */
- (void)editSelectedDateTextAnnotationDate;

/**
 * Action method to export and save the currently selected file attachment annotation to disk.
 */
- (void)saveFileAttachmentAnnotation:(nullable id)sender;

#pragma mark - Redaction methods

- (void)redactDoc;

#pragma mark - File Attachment

/**
 *  Used to allow the toolmanager that the user wishes to open a file attachment
 *
 * @param fileAttachment The file attachment.
 *
 * @param pageNumber The page number that the annotation is on.
 */
-(void)handleFileAttachment:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber;

/**
 * Override point for when the user has requested to save the file attchment
 *
 * @param fileAttachment The file attachment to be saved.
 *
 * @param pageNumber The page number that the annotation is on.
 */
-(void)saveFileAttachment:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber;

#pragma mark - Helper methods
/** @name Helper methods
 */

/**
 * Returns a tight page bounding box around the annotation.
 *
 * The default implementation of this method returns the value of `-[PTAnnot GetRect]`.
 *
 * @param annot the annotation
 *
 * @return a tight page bounding box around the annotation
 */
-(PTPDFRect *)tightPageBoundingBoxFromAnnot:(PTAnnot *)annot;

/**
 * Returns a tight screen bounding box around the annotation.
 *
 * The default implementation of this method returns the value of `-[PTAnnot GetRect]`, in screen
 * coordinates.
 *
 * @param annot the annotation
 *
 * @param pageNumber the annotation's page number
 *
 * @return a tight screen bounding box around the annotation
 */
- (CGRect)tightScreenBoundingBoxForAnnot:(PTAnnot *)annot onPageNumber:(int)pageNumber;

/**
 * Bounds a point in screen space to the current page's crop box.
 *
 * @param point a point in screen space
 *
 * @return a point in screen space, guaranteed to be within the page.
 */
- (CGPoint)boundPointToPage:(CGPoint)point;

/**
 * Ensures that a rect in page space is within the page it's on.
 *
 * @param pageRect the rect in page space
 *
 * @param pageNumber the page number
 *
 * @return the new rectangle, guaranteed to be within the page.
 */
- (PTPDFRect *)boundPageRect:(PTPDFRect *)pageRect toPage:(int)pageNumber;

/**
 * Ensures that a new rect's position lies within the page it's on.
 *
 * @param annotRect the annotation's proposed new rectangle.
 *
 * @param resizing if the annotation was changed via a resize (as opposed to a move)
 *
 * @return the new rectangle, guaranteed to be within the page.
 */
- (CGRect)boundRectToPage:(CGRect)annotRect isResizing:(BOOL)resizing;

#pragma mark - Subclassing

/**
 * The frame for editing the currently selected free text annotation, in the
 * `selectionRectContainerView`'s local coordinate system.
 */
- (CGRect)frameForEditingFreeTextAnnotation;

@end

NS_ASSUME_NONNULL_END
