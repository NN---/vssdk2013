/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSOBJECTBROWSERDESCRIPTION2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSOBJECTBROWSERDESCRIPTION2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "vsshell.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IVsObjectBrowserDescription2NotImpl :
	public IVsObjectBrowserDescription2
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsObjectBrowserDescription2NotImpl)

public:

	typedef IVsObjectBrowserDescription2 Interface;

	STDMETHOD(AddDescriptionText)(
		/*[in]*/ LPCWSTR /*pText*/,
		/*[in]*/ VSOBDESCRIPTIONSECTION /*obdSect*/,
		/*[in]*/ VSOBJECTINFO* /*pHyperJump*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(ClearDescriptionText)()VSL_STDMETHOD_NOTIMPL
};

class IVsObjectBrowserDescription2MockImpl :
	public IVsObjectBrowserDescription2,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsObjectBrowserDescription2MockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsObjectBrowserDescription2MockImpl)

	typedef IVsObjectBrowserDescription2 Interface;
	struct AddDescriptionTextValidValues
	{
		/*[in]*/ LPCWSTR pText;
		/*[in]*/ VSOBDESCRIPTIONSECTION obdSect;
		/*[in]*/ VSOBJECTINFO* pHyperJump;
		HRESULT retValue;
	};

	STDMETHOD(AddDescriptionText)(
		/*[in]*/ LPCWSTR pText,
		/*[in]*/ VSOBDESCRIPTIONSECTION obdSect,
		/*[in]*/ VSOBJECTINFO* pHyperJump)
	{
		VSL_DEFINE_MOCK_METHOD(AddDescriptionText)

		VSL_CHECK_VALIDVALUE_STRINGW(pText);

		VSL_CHECK_VALIDVALUE(obdSect);

		VSL_CHECK_VALIDVALUE_POINTER(pHyperJump);

		VSL_RETURN_VALIDVALUES();
	}
	struct ClearDescriptionTextValidValues
	{
		HRESULT retValue;
	};

	STDMETHOD(ClearDescriptionText)()
	{
		VSL_DEFINE_MOCK_METHOD_NOARGS(ClearDescriptionText)

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSOBJECTBROWSERDESCRIPTION2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
