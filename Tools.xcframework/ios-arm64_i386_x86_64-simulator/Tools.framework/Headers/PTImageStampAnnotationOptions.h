//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotationOptions.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An object that contains options for image stamp annotations.
 */
PT_OBJC_RUNTIME_NAME(ImageStampAnnotationOptions)
@interface PTImageStampAnnotationOptions : PTAnnotationOptions

/**
 * Whether the annotation can be rotated. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isRotationEnabled) BOOL rotationEnabled;

/**
 * Whether the annotation can be cropped. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isCropEnabled) BOOL cropEnabled;

/**
 * Whether the annotation's opacity can be changed. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isOpacityEnabled) BOOL opacityEnabled;

/**
 * An array of maximum allowed image stamp dimensions (in pixels) which can be selected by the user.
 * Any images with dimensions larger than the selected size will be resized.
 */
@property (nonatomic, copy) NSArray<NSNumber*>* maxImageDimensions;

@end

NS_ASSUME_NONNULL_END
