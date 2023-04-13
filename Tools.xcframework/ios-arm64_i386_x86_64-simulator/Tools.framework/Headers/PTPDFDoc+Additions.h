//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <PDFNet/PDFNet.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Convenience methods for locking a `PTPDFDoc` with exception and error handling.
 */
PT_EXTERN
@interface PTPDFDoc (Additions)

/**
 * Synchronously acquires a read lock for this `PTPDFDoc` instance and executes the given block on
 * the current queue.
 *
 * @param block The block to perform.
 */
- (void)LockReadWithBlock:(void (NS_NOESCAPE ^)(PTPDFDoc *pdfDoc))block
    NS_SWIFT_UNAVAILABLE("Use the throwing `PTPDFDoc.lockRead(_:)` function instead");

/**
 * Synchronously acquires a write lock for this `PTPDFDoc` instance and executes the given block.
 *
 * Simultaneous write access to a PTPDFDoc instance is not allowed. A write lock cannot be acquired
 * if the thread already holds a read lock. Attempting to do so is an error.
 *
 * @param block The block to perform.
 */
- (void)LockWithBlock:(void (NS_NOESCAPE ^)(PTPDFDoc *pdfDoc))block
    NS_SWIFT_UNAVAILABLE("Use the throwing `PTPDFDoc.lock(_:)` function instead");

/**
 * Synchronously acquires a read lock for this `PTPDFDoc` instance and executes the given block on
 * the current queue. Any `NSException` thrown while locking or unlocking the document, or executing the block, is converted into an `NSError` object and returned in the `error` parameter.
 *
 * @param block The block to perform.
 *
 * @param error On input, a pointer to an error object. If an error occurs (an `NSException`
 * is thrown), this pointer is set to an actual error object containing the error
 * information. You may specify `nil` for this parameter if you do not want the error
 * information.
 *
 * @return `YES` if the document could be locked and the block could be run successfully. If
 * an error occurs (an `NSException` is thrown), this method returns `NO` and assigns an
 * appropriate error object to the `error` parameter.
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to
 * indicate that it throws an error in cases of failure.
 */
- (BOOL)LockReadWithBlock:(void (NS_NOESCAPE ^)(void))block
                    error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

/**
 * Synchronously acquires a write lock for this `PTPDFDoc` instance and executes the given block.
 *
 * Simultaneous write access to a PTPDFDoc instance is not allowed. A write lock cannot be acquired
 * if the thread already holds a read lock. Attempting to do so is an error.
 *
 * Any `NSException` thrown while locking or unlocking the document, or executing the block,
 * is converted into an `NSError` object and returned in the `error` parameter.
 *
 * @param block The block to perform.
 *
 * @param error On input, a pointer to an error object. If an error occurs (an `NSException`
 * is thrown), this pointer is set to an actual error object containing the error
 * information. You may specify `nil` for this parameter if you do not want the error
 * information.
 *
 * @return `YES` if the document could be locked and the block could be run successfully. If
 * an error occurs (an `NSException` is thrown), this method returns `NO` and assigns an
 * appropriate error object to the `error` parameter.
 *
 * @note In Swift, this method returns `Void` and is marked with the `throws` keyword to
 * indicate that it throws an error in cases of failure.
 */
- (BOOL)LockWithBlock:(void (NS_NOESCAPE ^)(void))block
                error:(out NSError * _Nullable __autoreleasing * _Nullable)error;

#pragma mark - Pages

/**
 * Enumerates through the pages in this document and calls the provided block for each page.
 *
 * @param block The block to be executed for each page in the document.
 *
 * @note This method requires a read-lock on the `PTPDFDoc`.
 */
- (void)enumeratePagesWithBlock:(void (NS_NOESCAPE ^)(unsigned int pageNumber,
                                                      PTPage *page,
                                                      BOOL *stop))block;

/**
 * Enumerates through the pages in this document between the start and end page numbers and calls the
 * provided block for each page.
 *
 * @param block The block to be executed for each page in the document.
 *
 * @note This method requires a read-lock on the `PTPDFDoc`.
 */
- (void)enumeratePagesFromPageNumber:(unsigned int)startPageNumber
                        toPageNumber:(unsigned int)endPageNumber
                           withBlock:(void (NS_NOESCAPE ^)(unsigned int pageNumber,
                                                           PTPage *page,
                                                           BOOL *stop))block;

#pragma mark - Annotations

/**
 * Generates a new unique ID for the given annotation.
 *
 * @param annotation The annotation for which to generate and set a new unique identifier
 *
 * @note This method requires a write-lock on the PTPDFDoc.
 */
- (void)GenerateUniqueIDForAnnotation:(PTAnnot *)annotation;

@end

NS_ASSUME_NONNULL_END
