//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

#import <PDFNet/PDFNet.h>
#import <Tools/ToolsDefines.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDocumentConversionService;

/**
 * Constants to identify different conversion types.
 */
typedef NSString * PTConversionTaskType NS_TYPED_ENUM;

/**
 * Word.
 */
PT_EXPORT PTConversionTaskType const PTConversionTaskTypeWord;

/**
 * Excel.
 */
PT_EXPORT PTConversionTaskType const PTConversionTaskTypeExcel;

/**
 * PowerPoint.
 */
PT_EXPORT PTConversionTaskType const PTConversionTaskTypePowerPoint;

/**
 * HTML.
 */
PT_EXPORT PTConversionTaskType const PTConversionTaskTypeHTML;

/**
 * Constants to identify conversion job status.
 */
typedef NSString * const PTDocumentConversionJobStatus NS_TYPED_ENUM;

/**
 * Completed.
 */
PT_EXPORT PTDocumentConversionJobStatus const PTDocumentConversionJobStatusCompleted;

/**
 * Failed.
 */
PT_EXPORT PTDocumentConversionJobStatus const PTDocumentConversionJobStatusFailed;

/**
 * Cancelled.
 */
PT_EXPORT PTDocumentConversionJobStatus const PTDocumentConversionJobStatusCancelled;

/**
 * The `PTDocumentConversionServiceDelegate` protocol allows the adopting class to respond to messages
 * from the `PTDocumentConversionService` class.
 */
PT_OBJC_RUNTIME_NAME(DocumentConversionServiceDelegate)
@protocol PTDocumentConversionServiceDelegate <NSObject>
@optional

/**
 * This method is called when a conversion job is started on the server.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param jobID The ID of the job on the server.
 */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService didStartConversionJobWithID:(NSString*)jobID;

/**
 * This method is called when a conversion job is stopped on the server.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param jobID The ID of the job on the server.
 */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService didStopConversionJobWithID:(NSString*)jobID;

/**
 * This method is called when a conversion job is finished on the server.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param status The status of the finished job.
 *
 * @param jobID The ID of the job on the server.
 */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService didFinishConversionJobWithStatus:(PTDocumentConversionJobStatus)status forJobID:(NSString*)jobID;

/**
 * This method is called when a converted file has been downloaded from the server.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param filePath The path to the downloaded file.
 *
 * @param jobID The ID of the job on the server.
 */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService didDownloadConvertedFileToPath:(NSString*)filePath forJobID:(NSString*)jobID;

/**
 * This method is called when a conversion job fails for any reason.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param error The ID of the job on the server.
 */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService conversionFailedWithError:(NSError*)error;

/**
 * This method is called when a conversion job receives a progress update during file upload.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param progress The progress of the upload as a value between 0.0 and 1.0.
 *
 * @param jobID The ID of the job on the server.
 * */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService didReceiveFileUploadProgressUpdate:(float)progress forJobID:(NSString*)jobID;

/**
 * This method is called when a conversion job receives a progress update during file download.
 *
 * @param documentConversionService The document conversion service which manages the job.
 *
 * @param progress The progress of the download as a value between 0.0 and 1.0.
 *
 * @param jobID The ID of the job on the server.
 * */
-(void)documentConversionService:(PTDocumentConversionService*)documentConversionService didReceiveFileDownloadProgressUpdate:(float)progress forJobID:(NSString*)jobID;

@end

/**
 * The `PTDocumentConversionService` class is used to perform and manage conversion of PDF documents to other formats
 * via a REST API service. A separate license key for the service is required.
 *
 */
PT_EXPORT
PT_OBJC_RUNTIME_NAME(DocumentConversionService)
@interface PTDocumentConversionService : NSObject

/**
 * The document conversion service's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTDocumentConversionServiceDelegate> delegate;

/**
 * The client ID for the conversion service REST API.
 */
@property (class, nonatomic, copy) NSString *clientID;

/**
 * The client secret for the conversion service REST API.
 */
@property (class, nonatomic, copy) NSString *clientSecret;

/**
 * Starts a conversion job of a given input document and specified filename.
 *
 * @param taskType the type of the conversion job to be started.
 *
 * @param doc the input document to be converted.
 *
 * @param filename the name of the document to be converted including the .pdf extension. The converted output file will use the root filename and append the appropriate file extension.
 */
- (void)startConversionJobOfType:(PTConversionTaskType)taskType withDoc:(PTPDFDoc*)doc filename:(NSString*)filename;

/**
 * Cancels the service's active conversion job if one exists.
 */
-(void)cancelActiveConversionJob;

@end

NS_ASSUME_NONNULL_END
