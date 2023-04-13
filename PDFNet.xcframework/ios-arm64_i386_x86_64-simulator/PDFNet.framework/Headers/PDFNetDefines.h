//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <PDFNet/PDFNetConfig.h>

#import <Foundation/Foundation.h>

#if defined(__cplusplus)
    #define PDFNET_EXTERN extern "C"
#else
    #define PDFNET_EXTERN extern
#endif

#pragma mark - Preprocessor macros

/**
 * PDFNET_STRINGIFY
 *
 * Convert a token to a C-string literal using the '#' preprocessor operator.
 *
 * An extra level of macro-indirection is required to expand any macros or
 * defines in the macro parameter.
 */
#define PDFNET_STRINGIFY__(x) #x
#define PDFNET_STRINGIFY(x) PDFNET_STRINGIFY__(x)

/**
 * PDFNET_PASTE
 *
 * Concatenate two tokens into a single token using the '##' preprocessor operator.
 *
 * An extra level of macro-indirection is required to expand any macros or
 * defines in the macro parameters.
 */
#define PDFNET_PASTE__(x, y) x##y
#define PDFNET_PASTE(x, y) PDFNET_PASTE__(x, y)

#pragma mark - Miscellaneous Defines

/**
 * PDFNET_OBJC_RUNTIME_PREFIX
 *
 * Defines the prefix to be added to Objective-C class and protocol names in the runtime.
 */
#ifndef PDFNET_OBJC_RUNTIME_PREFIX
    #define PDFNET_OBJC_RUNTIME_PREFIX
#endif

#pragma mark - Attributes

/**
 * objc_runtime_name attribute
 *
 * @see https://clang.llvm.org/docs/AttributeReference.html#objc-runtime-name
 */
#if __has_attribute(objc_runtime_name)
    #define PDFNET_OBJC_RUNTIME_NAME(name) \
        __attribute__((objc_runtime_name(PDFNET_STRINGIFY(PDFNET_PASTE(PDFNET_OBJC_RUNTIME_PREFIX, name)))))
#else
    #define PDFNET_OBJC_RUNTIME_NAME(name)
#endif

/**
 * unused and used attributes.
 */

#if __has_attribute(unused)
    #define PDFNET_UNUSED_ATTRIBUTE __attribute__((unused))
#else
    #define PDFNET_UNUSED_ATTRIBUTE
#endif /* __has_attribute(unused) */

#if __has_attribute(used)
    #define PDFNET_USED_ATTRIBUTE __attribute__((used))
#else
    #define PDFNET_USED_ATTRIBUTE
#endif /* __has_attribute(used) */

/**
 * visibility attribute.
 */

#if __has_attribute(visibility)
    #define PDFNET_VISIBILITY_ATTRIBUTE(value) __attribute__((visibility(value)))
#else
    #define PDFNET_VISIBILITY_ATTRIBUTE(value)
#endif /* __has_attribute(visibility) */

#define PDFNET_VISIBILITY_HIDDEN PDFNET_VISIBILITY_ATTRIBUTE("hidden")
