//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A static/abstract utility class that provides convenience APIs for dealing with files.
 */
PT_EXTERN
PT_OBJC_SUBCLASSING_RESTRICTED
PT_OBJC_RUNTIME_NAME(FileUtilities)
@interface PTFileUtilities : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * Returns the file system representation (ie. file path) for a file URL.
 *
 * @param fileURL The file URL
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return the file system representation for the file URL, or `nil` if an error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
+ (nullable NSString *)fileSystemRepresentationForURL:(NSURL *)fileURL
                                            withError:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

#pragma mark - File identity

/**
 * Returns the file resource identifier for a file URL.
 *
 * @param fileResourceIdentifier The location where the file resource identifier value should be stored
 *
 * @param fileURL The file URL
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the file resource identifier could be determined for the file URL, or `NO` if an
 * error occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 */
+ (BOOL)getFileResourceIdentifier:(out id<NSCopying, NSCoding, NSSecureCoding, NSObject> _Nullable __autoreleasing * _Nonnull)fileResourceIdentifier
                           forURL:(NSURL *)fileURL
                            error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

/**
 * Returns whether the file URLs are represented by the same file system object.
 *
 * Files or directories on different file system volumes cannot be represented by the same file system
 * object.
 *
 * @param isFileSystemObjectEqual The location where the boolean result should be stored
 *
 * @param fileURL The file URL
 *
 * @param otherFileURL The other file URL
 *
 * @param outError On input, a pointer to an error object. If an error occurs, this pointer is set to
 * an actual error object containing the error information. You may specify `nil` for this parameter
 * if you do not want the error information.
 *
 * @return `YES` if the URLs' file system objects could be determined and compared, or `NO` if an error
 * occurred
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to indicate that
 * it throws an error in cases of failure.
 *
 * @see `+getFileResourceIdentifier:forURL:error:`
 */
+ (BOOL)isFileSystemObjectEqual:(out BOOL * _Nonnull)isFileSystemObjectEqual
                     forFileURL:(NSURL *)fileURL
                         andURL:(NSURL *)otherFileURL
                          error:(out NSError * _Nullable __autoreleasing * _Nullable)outError;

@end

NS_ASSUME_NONNULL_END
