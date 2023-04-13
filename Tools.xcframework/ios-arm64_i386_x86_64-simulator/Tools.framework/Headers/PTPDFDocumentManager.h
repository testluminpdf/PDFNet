//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Instances of the `PTPDFDocumentManager` class control how documents are accessed, usually by a
 * viewer component.
 */
PT_EXTERN
PT_OBJC_RUNTIME_NAME(PDFDocumentManager)
@interface PTPDFDocumentManager : NSObject <PTOverridable>

/**
 * Initializes a new `PTPDFDocumentManager` instance.
 *
 * @return an initialized `PTPDFDocumentManager` instance
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

#pragma mark - Document cache directory

/**
 * The URL of the directory where documents are cached.
 *
 * The document cache is used for remote (HTTP) file downloads, documents converted from other formats,
 * and any other document-related operation that needs a safe location on-disk.
 *
 * The default value of this property is the return value of the class method
 * `+[PTPDFDocumentManager defaultDocumentCacheDirectoryURLWithError:]`.
 */
@property (nonatomic, strong) NSURL *documentCacheDirectoryURL;

/**
 * Returns the URL of the default directory used for caching documents.
 *
 * @param outError On input, a pointer to an error object. If an error occurs , this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the default document cache directory URL, or `nil` if an error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
+ (nullable NSURL *)defaultDocumentCacheDirectoryURLWithError:(out NSError * _Nullable __autoreleasing * _Nullable)outError NS_WARN_UNUSED_RESULT;

@end

NS_ASSUME_NONNULL_END
