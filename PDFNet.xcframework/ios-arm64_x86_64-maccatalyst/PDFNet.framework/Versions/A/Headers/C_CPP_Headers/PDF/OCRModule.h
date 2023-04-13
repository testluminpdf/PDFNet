//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CPPPDFOCRModule
#define PDFTRON_H_CPPPDFOCRModule
#include <C/PDF/TRN_OCRModule.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>
#include <PDF/OCROptions.h>

namespace pdftron { namespace PDF { 
class PDFDoc;

/**
 * The class OCRModule.
 * static interface to PDFTron SDKs OCR functionality
 */
class OCRModule
{
public:
	
	//methods:
	
	/**
	 * Find out whether the OCR module is available (and licensed).
	 * 
	 * @return returns true if OCR operations can be performed.
	 */
	static bool IsModuleAvailable();

	/**
	 * Find out whether the IRIS OCR module is available.
	 * 
	 * @return returns true if the IRIS ocr module has been located.
	 */
	static bool IsIRISModuleAvailable();
	
	/**
	 * Convert an image to a PDF with searchable text.
	 * 
	 * @param dst -- The destination document.
	 * @param src -- The path to the input image.
	 * @param options -- OCR options (optional).
	 */
	static void ImageToPDF(PDFDoc dst, const UString& src, OCROptions* options);
	
	/**
	 * Add searchable and selectable text to raster images within a PDF.
	 * 
	 * @param dst -- The source and destination document.
	 * @param options -- OCR options (optional).
	 */
	static void ProcessPDF(PDFDoc dst, OCROptions* options);
	
	/**
	 * Perform OCR on an image and return resulting JSON string. Side effect: source image is converted to PDF and stored in the destination document.
	 * The box is a summary for a text fragment bounding box (leftmost x, bottommost y, width, height)
	 * The box coordinates are in units of points (1/72 of an inch), with the origin at the top left, and larger x and y coordinates representing further right and down, respectively
	 *
	 * @param dst -- The destination document.
	 * @param src -- The path to the input image.
	 * @param options -- OCR options (optional).
	 * @return JSON string represeting OCR results.
	 */
	static UString GetOCRJsonFromImage(PDFDoc dst, const UString& src, OCROptions* options);
	
	/**
	 * Perform OCR on raster images within a PDF and return resulting JSON string.
	 * The box is a summary for a text fragment bounding box (leftmost x, bottommost y, width, height)
	 * The box coordinates are in units of points (1/72 of an inch), with the origin at the top left, and larger x and y coordinates representing further right and down, respectively
	 *
	 * @param src -- The source document.
	 * @param options -- OCR options (optional).
	 * @return JSON string represeting OCR results.
	 */
	static UString GetOCRJsonFromPDF(PDFDoc src, OCROptions* options);
	
	/**
	 * Add hidden text layer to a PDF consisting of raster image(s).
	 * 
	 * @param dst -- The source and destination document.
	 * @param json -- JSON representing OCR results.
	 */
	static void ApplyOCRJsonToPDF(PDFDoc dst, const UString& json);
	
	/**
	 * Perform OCR on an image and return resulting XML string. Side effect: source image is converted to PDF and stored in the destination document.
	 * The box is a summary for a text fragment bounding box (leftmost x, bottommost y, width, height)
	 * The box coordinates are in units of points (1/72 of an inch), with the origin at the top left, and larger x and y coordinates representing further right and down, respectively
	 *
	 * @param dst -- The destination document.
	 * @param src -- The path to the input image.
	 * @param options -- OCR options (optional).
	 * @return XML string represeting OCR results.
	 */
	static UString GetOCRXmlFromImage(PDFDoc dst, const UString& src, OCROptions* options);
	
	/**
	 * Perform OCR on raster images within a PDF and return resulting XML string.
	 * The box is a summary for a text fragment bounding box (leftmost x, bottommost y, width, height)
	 * The box coordinates are in units of points (1/72 of an inch), with the origin at the top left, and larger x and y coordinates representing further right and down, respectively
	 * 
	 * @param src -- The source document.
	 * @param options -- OCR options (optional).
	 * @return XML string represeting OCR results.
	 */
	static UString GetOCRXmlFromPDF(PDFDoc src, OCROptions* options);
	
	/**
	 * Add hidden text layer to a PDF consisting of raster image(s).
	 * 
	 * @param dst -- The source and destination document.
	 * @param xml -- XML representing OCR results.
	 */
	static void ApplyOCRXmlToPDF(PDFDoc dst, const UString& xml);

};

#include <Impl/OCRModule.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFOCRModule