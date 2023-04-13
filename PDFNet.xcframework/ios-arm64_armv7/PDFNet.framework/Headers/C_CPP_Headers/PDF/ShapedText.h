//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CPPPDFShapedText
#define PDFTRON_H_CPPPDFShapedText
#include <C/PDF/TRN_ShapedText.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>

namespace pdftron { namespace PDF { 
class Font;

/**
 * The class ShapedText.
 * A sequence of positioned glyphs -- the visual representation of a
 * given text string
 */
class ShapedText
{
public:
	//enums:
	enum ShapingStatus {
		e_FullShaping = 0,
		e_PartialShaping = 1,
		e_NoShaping = 2
	};
	enum FailureReason {
		e_NoFailure = 0,
		e_UnsupportedFontType = 1,
		e_NotIndexEncoded = 2,
		e_FontDataNotFound = 3
	};
	ShapedText();
	ShapedText(const ShapedText& other);
	ShapedText(TRN_ShapedText impl);
	ShapedText& operator= (const ShapedText& other);
	~ShapedText();
	
	void Destroy();

	//methods:
	
	/**
	 * Scaling factor of this shaped text relative to the em size. A scaling factor of 1 means that all units are relative to the em size. PDF scaling is typically 1000 units per em.
	 * 
	 * @return returns the scaling factor for the glyph positions.
	 */
	double GetScale() const;
	
	/**
	 * Get the state of the shaping operation. Even if the shaping did not fully succeed, this object can be added to an elementbuilder, and will fallback to placing unshped text. See GetFailureReason() in the case this method returns something other than FullShaping.
	 * 
	 * @return .
	 */
	ShapingStatus GetShapingStatus() const;
	
	/**
	 * In the case where GetShapingStatus() returns something other than FullShaping, this method will return a more detailed reason behind the failure.
	 * 
	 * @return .
	 */
	FailureReason GetFailureReason() const;
	
	/**
	 * The original source text string.
	 * 
	 * @return returns the source text string.
	 */
	UString GetText() const;
	
	/**
	 * Number of glyphs present in the shaped text. Might be different from the .
	 * 
	 * @return returns the number of utf32 codepoints in this shaped text.
	 */
	int GetNumGlyphs() const;
	
	/**
	 * Get the glyph ID at the indicated place in the shaped sequence. This number is specific to the font file used to generate the shaping results, and does not always have a clean mapping to a particular Unicode codepoint in the original string.
	 * 
	 * @param index -- the index of the glyph to be retrieved. Must be less than GetNumGlyphs().
	 * @return returns the glyph ID for the indicated place in the shaped result.
	 */
	UInt32 GetGlyph(UInt32 index) const;
	
	/**
	 * The X position of the glyph at the requested index. This number has been scaled by GetScale().
	 * 
	 * @param index -- the index of the glyph position to be retrieved. Must be less than GetNumGlyphs().
	 * @return returns the X position for the glyph at the specified index.
	 */
	double GetGlyphXPos(UInt32 index) const;
	
	/**
	 * The Y position of the glyph at the requested index. This number has been scaled by GetScale().
	 * 
	 * @param index -- the index of the glyph position to be retrieved. Must be less than GetNumGlyphs().
	 * @return returns the Y position for the glyph at the specified index.
	 */
	double GetGlyphYPos(UInt32 index) const;

#ifndef SWIGHIDDEN
	TRN_ShapedText m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/ShapedText.inl>
} //end pdftron
} //end PDF


#endif //PDFTRON_H_CPPPDFShapedText
