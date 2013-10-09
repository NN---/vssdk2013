/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IENUMDEBUGPENDINGBREAKPOINTS2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IENUMDEBUGPENDINGBREAKPOINTS2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "msdbg.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IEnumDebugPendingBreakpoints2NotImpl :
	public IEnumDebugPendingBreakpoints2
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IEnumDebugPendingBreakpoints2NotImpl)

public:

	typedef IEnumDebugPendingBreakpoints2 Interface;

	STDMETHOD(Next)(
		/*[in]*/ ULONG /*celt*/,
		/*[out,size_is(celt),length_is(*pceltFetched)]*/ IDebugPendingBreakpoint2** /*rgelt*/,
		/*[in,out]*/ ULONG* /*pceltFetched*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(Skip)(
		/*[in]*/ ULONG /*celt*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(Reset)()VSL_STDMETHOD_NOTIMPL

	STDMETHOD(Clone)(
		/*[out]*/ IEnumDebugPendingBreakpoints2** /*ppEnum*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(GetCount)(
		/*[out]*/ ULONG* /*pcelt*/)VSL_STDMETHOD_NOTIMPL
};

class IEnumDebugPendingBreakpoints2MockImpl :
	public IEnumDebugPendingBreakpoints2,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IEnumDebugPendingBreakpoints2MockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IEnumDebugPendingBreakpoints2MockImpl)

	typedef IEnumDebugPendingBreakpoints2 Interface;
	struct NextValidValues
	{
		/*[in]*/ ULONG celt;
		/*[out,size_is(celt),length_is(*pceltFetched)]*/ IDebugPendingBreakpoint2** rgelt;
		/*[in,out]*/ ULONG* pceltFetched;
		HRESULT retValue;
	};

	STDMETHOD(Next)(
		/*[in]*/ ULONG celt,
		/*[out,size_is(celt),length_is(*pceltFetched)]*/ IDebugPendingBreakpoint2** rgelt,
		/*[in,out]*/ ULONG* pceltFetched)
	{
		VSL_DEFINE_MOCK_METHOD(Next)

		VSL_CHECK_VALIDVALUE(celt);

		VSL_SET_VALIDVALUE_INTERFACEARRAY(rgelt, celt, *(validValues.pceltFetched));

		VSL_SET_VALIDVALUE(pceltFetched);

		VSL_RETURN_VALIDVALUES();
	}
	struct SkipValidValues
	{
		/*[in]*/ ULONG celt;
		HRESULT retValue;
	};

	STDMETHOD(Skip)(
		/*[in]*/ ULONG celt)
	{
		VSL_DEFINE_MOCK_METHOD(Skip)

		VSL_CHECK_VALIDVALUE(celt);

		VSL_RETURN_VALIDVALUES();
	}
	struct ResetValidValues
	{
		HRESULT retValue;
	};

	STDMETHOD(Reset)()
	{
		VSL_DEFINE_MOCK_METHOD_NOARGS(Reset)

		VSL_RETURN_VALIDVALUES();
	}
	struct CloneValidValues
	{
		/*[out]*/ IEnumDebugPendingBreakpoints2** ppEnum;
		HRESULT retValue;
	};

	STDMETHOD(Clone)(
		/*[out]*/ IEnumDebugPendingBreakpoints2** ppEnum)
	{
		VSL_DEFINE_MOCK_METHOD(Clone)

		VSL_SET_VALIDVALUE_INTERFACE(ppEnum);

		VSL_RETURN_VALIDVALUES();
	}
	struct GetCountValidValues
	{
		/*[out]*/ ULONG* pcelt;
		HRESULT retValue;
	};

	STDMETHOD(GetCount)(
		/*[out]*/ ULONG* pcelt)
	{
		VSL_DEFINE_MOCK_METHOD(GetCount)

		VSL_SET_VALIDVALUE(pcelt);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IENUMDEBUGPENDINGBREAKPOINTS2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
