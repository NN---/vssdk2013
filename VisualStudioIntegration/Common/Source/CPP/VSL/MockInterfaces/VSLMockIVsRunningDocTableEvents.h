/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IVSRUNNINGDOCTABLEEVENTS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IVSRUNNINGDOCTABLEEVENTS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

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

class IVsRunningDocTableEventsNotImpl :
	public IVsRunningDocTableEvents
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsRunningDocTableEventsNotImpl)

public:

	typedef IVsRunningDocTableEvents Interface;

	STDMETHOD(OnAfterFirstDocumentLock)(
		/*[in]*/ VSCOOKIE /*docCookie*/,
		/*[in]*/ VSRDTFLAGS /*dwRDTLockType*/,
		/*[in]*/ DWORD /*dwReadLocksRemaining*/,
		/*[in]*/ DWORD /*dwEditLocksRemaining*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(OnBeforeLastDocumentUnlock)(
		/*[in]*/ VSCOOKIE /*docCookie*/,
		/*[in]*/ VSRDTFLAGS /*dwRDTLockType*/,
		/*[in]*/ DWORD /*dwReadLocksRemaining*/,
		/*[in]*/ DWORD /*dwEditLocksRemaining*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(OnAfterSave)(
		/*[in]*/ VSCOOKIE /*docCookie*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(OnAfterAttributeChange)(
		/*[in]*/ VSCOOKIE /*docCookie*/,
		/*[in]*/ VSRDTATTRIB /*grfAttribs*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(OnBeforeDocumentWindowShow)(
		/*[in]*/ VSCOOKIE /*docCookie*/,
		/*[in]*/ BOOL /*fFirstShow*/,
		/*[in]*/ IVsWindowFrame* /*pFrame*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(OnAfterDocumentWindowHide)(
		/*[in]*/ VSCOOKIE /*docCookie*/,
		/*[in]*/ IVsWindowFrame* /*pFrame*/)VSL_STDMETHOD_NOTIMPL
};

class IVsRunningDocTableEventsMockImpl :
	public IVsRunningDocTableEvents,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IVsRunningDocTableEventsMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IVsRunningDocTableEventsMockImpl)

	typedef IVsRunningDocTableEvents Interface;
	struct OnAfterFirstDocumentLockValidValues
	{
		/*[in]*/ VSCOOKIE docCookie;
		/*[in]*/ VSRDTFLAGS dwRDTLockType;
		/*[in]*/ DWORD dwReadLocksRemaining;
		/*[in]*/ DWORD dwEditLocksRemaining;
		HRESULT retValue;
	};

	STDMETHOD(OnAfterFirstDocumentLock)(
		/*[in]*/ VSCOOKIE docCookie,
		/*[in]*/ VSRDTFLAGS dwRDTLockType,
		/*[in]*/ DWORD dwReadLocksRemaining,
		/*[in]*/ DWORD dwEditLocksRemaining)
	{
		VSL_DEFINE_MOCK_METHOD(OnAfterFirstDocumentLock)

		VSL_CHECK_VALIDVALUE(docCookie);

		VSL_CHECK_VALIDVALUE(dwRDTLockType);

		VSL_CHECK_VALIDVALUE(dwReadLocksRemaining);

		VSL_CHECK_VALIDVALUE(dwEditLocksRemaining);

		VSL_RETURN_VALIDVALUES();
	}
	struct OnBeforeLastDocumentUnlockValidValues
	{
		/*[in]*/ VSCOOKIE docCookie;
		/*[in]*/ VSRDTFLAGS dwRDTLockType;
		/*[in]*/ DWORD dwReadLocksRemaining;
		/*[in]*/ DWORD dwEditLocksRemaining;
		HRESULT retValue;
	};

	STDMETHOD(OnBeforeLastDocumentUnlock)(
		/*[in]*/ VSCOOKIE docCookie,
		/*[in]*/ VSRDTFLAGS dwRDTLockType,
		/*[in]*/ DWORD dwReadLocksRemaining,
		/*[in]*/ DWORD dwEditLocksRemaining)
	{
		VSL_DEFINE_MOCK_METHOD(OnBeforeLastDocumentUnlock)

		VSL_CHECK_VALIDVALUE(docCookie);

		VSL_CHECK_VALIDVALUE(dwRDTLockType);

		VSL_CHECK_VALIDVALUE(dwReadLocksRemaining);

		VSL_CHECK_VALIDVALUE(dwEditLocksRemaining);

		VSL_RETURN_VALIDVALUES();
	}
	struct OnAfterSaveValidValues
	{
		/*[in]*/ VSCOOKIE docCookie;
		HRESULT retValue;
	};

	STDMETHOD(OnAfterSave)(
		/*[in]*/ VSCOOKIE docCookie)
	{
		VSL_DEFINE_MOCK_METHOD(OnAfterSave)

		VSL_CHECK_VALIDVALUE(docCookie);

		VSL_RETURN_VALIDVALUES();
	}
	struct OnAfterAttributeChangeValidValues
	{
		/*[in]*/ VSCOOKIE docCookie;
		/*[in]*/ VSRDTATTRIB grfAttribs;
		HRESULT retValue;
	};

	STDMETHOD(OnAfterAttributeChange)(
		/*[in]*/ VSCOOKIE docCookie,
		/*[in]*/ VSRDTATTRIB grfAttribs)
	{
		VSL_DEFINE_MOCK_METHOD(OnAfterAttributeChange)

		VSL_CHECK_VALIDVALUE(docCookie);

		VSL_CHECK_VALIDVALUE(grfAttribs);

		VSL_RETURN_VALIDVALUES();
	}
	struct OnBeforeDocumentWindowShowValidValues
	{
		/*[in]*/ VSCOOKIE docCookie;
		/*[in]*/ BOOL fFirstShow;
		/*[in]*/ IVsWindowFrame* pFrame;
		HRESULT retValue;
	};

	STDMETHOD(OnBeforeDocumentWindowShow)(
		/*[in]*/ VSCOOKIE docCookie,
		/*[in]*/ BOOL fFirstShow,
		/*[in]*/ IVsWindowFrame* pFrame)
	{
		VSL_DEFINE_MOCK_METHOD(OnBeforeDocumentWindowShow)

		VSL_CHECK_VALIDVALUE(docCookie);

		VSL_CHECK_VALIDVALUE(fFirstShow);

		VSL_CHECK_VALIDVALUE_INTERFACEPOINTER(pFrame);

		VSL_RETURN_VALIDVALUES();
	}
	struct OnAfterDocumentWindowHideValidValues
	{
		/*[in]*/ VSCOOKIE docCookie;
		/*[in]*/ IVsWindowFrame* pFrame;
		HRESULT retValue;
	};

	STDMETHOD(OnAfterDocumentWindowHide)(
		/*[in]*/ VSCOOKIE docCookie,
		/*[in]*/ IVsWindowFrame* pFrame)
	{
		VSL_DEFINE_MOCK_METHOD(OnAfterDocumentWindowHide)

		VSL_CHECK_VALIDVALUE(docCookie);

		VSL_CHECK_VALIDVALUE_INTERFACEPOINTER(pFrame);

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IVSRUNNINGDOCTABLEEVENTS_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
