/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IDEBUGPORTNOTIFY2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IDEBUGPORTNOTIFY2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

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

class IDebugPortNotify2NotImpl :
	public IDebugPortNotify2
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IDebugPortNotify2NotImpl)

public:

	typedef IDebugPortNotify2 Interface;

	STDMETHOD(AddProgramNode)(
		/*[in]*/ IDebugProgramNode2* /*pProgramNode*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(RemoveProgramNode)(
		/*[in]*/ IDebugProgramNode2* /*pProgramNode*/)VSL_STDMETHOD_NOTIMPL
};

class IDebugPortNotify2MockImpl :
	public IDebugPortNotify2,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IDebugPortNotify2MockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IDebugPortNotify2MockImpl)

	typedef IDebugPortNotify2 Interface;
	struct AddProgramNodeValidValues
	{
		/*[in]*/ IDebugProgramNode2* pProgramNode;
		HRESULT retValue;
	};

	STDMETHOD(AddProgramNode)(
		/*[in]*/ IDebugProgramNode2* pProgramNode)
	{
		VSL_DEFINE_MOCK_METHOD(AddProgramNode)

		VSL_CHECK_VALIDVALUE_INTERFACEPOINTER(pProgramNode);

		VSL_RETURN_VALIDVALUES();
	}
	struct RemoveProgramNodeValidValues
	{
		/*[in]*/ IDebugProgramNode2* pProgramNode;
		HRESULT retValue;
	};

	STDMETHOD(RemoveProgramNode)(
		/*[in]*/ IDebugProgramNode2* pProgramNode)
	{
		VSL_DEFINE_MOCK_METHOD(RemoveProgramNode)

		VSL_CHECK_VALIDVALUE_INTERFACEPOINTER(pProgramNode);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IDEBUGPORTNOTIFY2_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
