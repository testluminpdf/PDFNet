// This file is autogenerated: please see the codegen template "Options"
#ifndef PDFTRON_H_CPPPDFMergeXFDFOptions
#define PDFTRON_H_CPPPDFMergeXFDFOptions

#include <PDF/OptionsBase.h>

namespace pdftron{ namespace PDF{ 

class MergeXFDFOptions
{
public:
	MergeXFDFOptions();
	~MergeXFDFOptions();

	
	/**
	* Gets the value Force from the options object
	* If true, merge will be performed even if the conditions below are true. If false, the MergeXFDF operation will be aborted with exception if one of these conditions is true: 1)xfdf contains annotations with no 'name' attribute 2)annotations in pdf or xfdf have names that are not unique, i.e. multiple annotations in the same document have the same name. In order for the merge operation to work correctly, all the annotations in xfdf need to have a unique 'name' attribute. If pdf document has unnamed annotatations (no 'NM' attribute), xfdf files generated using PDFTron SDK will still have names that will allow the MergeXFDF algorithm to work.
	* @return a bool, the current value for Force.
	*/
	bool GetForce();

	/**
	* Sets the value for Force in the options object
	* If true, merge will be performed even if the conditions below are true. If false, the MergeXFDF operation will be aborted with exception if one of these conditions is true: 1)xfdf contains annotations with no 'name' attribute 2)annotations in pdf or xfdf have names that are not unique, i.e. multiple annotations in the same document have the same name. In order for the merge operation to work correctly, all the annotations in xfdf need to have a unique 'name' attribute. If pdf document has unnamed annotatations (no 'NM' attribute), xfdf files generated using PDFTron SDK will still have names that will allow the MergeXFDF algorithm to work.
	* @param value: the new value for Force
	* @return this object, for call chaining
	*/
	MergeXFDFOptions& SetForce(bool value);

	
	// @cond PRIVATE_DOC
	#ifndef SWIGHIDDEN
	const SDF::Obj& GetInternalObj() const;
	SDF::Obj& GetInternalObj();

private:
	
	SDF::ObjSet m_obj_set;
	SDF::Obj m_dict;
	#endif
	// @endcond
};

}
}

#include "../Impl/MergeXFDFOptions.inl"
#endif // PDFTRON_H_CPPPDFMergeXFDFOptions
