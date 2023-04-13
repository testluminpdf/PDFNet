//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
// !Warning! This file is autogenerated, modify the .codegen file, not this one
// (any changes here will be wiped out during the autogen process)

#ifndef PDFTRON_H_CPPSDFDocSnapshot
#define PDFTRON_H_CPPSDFDocSnapshot
#include <C/SDF/TRN_DocSnapshot.h>

#include <Common/BasicTypes.h>
#include <Common/UString.h>
#include <PDF/PDFDoc.h>

namespace pdftron { namespace SDF { 


/**
 * The class DocSnapshot.
 * Represents a state of the document.
 */
class DocSnapshot
{
public:
	DocSnapshot(const DocSnapshot& other);
	DocSnapshot(TRN_DocSnapshot impl);
	DocSnapshot& operator= (const DocSnapshot& other);
	~DocSnapshot();
	
	void Destroy();

	//methods:
	
	/**
	 * Returns a hash that is unique to particular document states.
	 * 
	 * @return A hash that is unique to particular document states.
	 */
	UInt32 GetHash() const;
	
	/**
	 * Returns whether this snapshot is valid.
	 * 
	 * @return Whether this snapshot is valid.
	 */
	bool IsValid() const;
	
	/**
	 * Returns whether this snapshot's document state is equivalent to another.
	 * 
	 * @param snapshot -- the other snapshot with which to compare.
	 * @return Whether this snapshot's document state is equivalent to another.
	 */
	bool Equals(DocSnapshot snapshot) const;

	// Internal use only
	DocSnapshot();
#ifndef SWIGHIDDEN
	TRN_DocSnapshot m_impl;
#endif

private:

#ifndef SWIGHIDDEN
	mutable bool m_owner; 
#endif
};

#include <Impl/DocSnapshot.inl>
} //end pdftron
} //end SDF


#endif //PDFTRON_H_CPPSDFDocSnapshot
