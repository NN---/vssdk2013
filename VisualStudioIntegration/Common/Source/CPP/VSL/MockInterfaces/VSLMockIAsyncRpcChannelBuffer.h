/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

This code is a part of the Visual Studio Library.

***************************************************************************/

#ifndef IASYNCRPCCHANNELBUFFER_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
#define IASYNCRPCCHANNELBUFFER_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5

#if _MSC_VER > 1000
#pragma once
#endif

#include "ObjIdl.h"

#pragma warning(push)
#pragma warning(disable : 4510) // default constructor could not be generated
#pragma warning(disable : 4610) // can never be instantiated - user defined constructor required
#pragma warning(disable : 4512) // assignment operator could not be generated
#pragma warning(disable : 6011) // Dereferencing NULL pointer (a NULL derference is just another kind of failure for a unit test

namespace VSL
{

class IAsyncRpcChannelBufferNotImpl :
	public IAsyncRpcChannelBuffer
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IAsyncRpcChannelBufferNotImpl)

public:

	typedef IAsyncRpcChannelBuffer Interface;

	STDMETHOD(Send)(
		/*[in,out]*/ RPCOLEMESSAGE* /*pMsg*/,
		/*[in]*/ ISynchronize* /*pSync*/,
		/*[out]*/ ULONG* /*pulStatus*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(Receive)(
		/*[in,out]*/ RPCOLEMESSAGE* /*pMsg*/,
		/*[out]*/ ULONG* /*pulStatus*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(GetDestCtxEx)(
		/*[in]*/ RPCOLEMESSAGE* /*pMsg*/,
		/*[out]*/ DWORD* /*pdwDestContext*/,
		/*[out]*/ void** /*ppvDestContext*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(GetProtocolVersion)(
		/*[in,out]*/ DWORD* /*pdwVersion*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(GetBuffer)(
		/*[in]*/ RPCOLEMESSAGE* /*pMessage*/,
		/*[in]*/ REFIID /*riid*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(SendReceive)(
		/*[in,out]*/ RPCOLEMESSAGE* /*pMessage*/,
		/*[out]*/ ULONG* /*pStatus*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(FreeBuffer)(
		/*[in]*/ RPCOLEMESSAGE* /*pMessage*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(GetDestCtx)(
		/*[out]*/ DWORD* /*pdwDestContext*/,
		/*[out]*/ void** /*ppvDestContext*/)VSL_STDMETHOD_NOTIMPL

	STDMETHOD(IsConnected)()VSL_STDMETHOD_NOTIMPL
};

class IAsyncRpcChannelBufferMockImpl :
	public IAsyncRpcChannelBuffer,
	public MockBase
{

VSL_DECLARE_NONINSTANTIABLE_BASE_CLASS(IAsyncRpcChannelBufferMockImpl)

public:

VSL_DEFINE_MOCK_CLASS_TYPDEFS(IAsyncRpcChannelBufferMockImpl)

	typedef IAsyncRpcChannelBuffer Interface;
	struct SendValidValues
	{
		/*[in,out]*/ RPCOLEMESSAGE* pMsg;
		/*[in]*/ ISynchronize* pSync;
		/*[out]*/ ULONG* pulStatus;
		HRESULT retValue;
	};

	STDMETHOD(Send)(
		/*[in,out]*/ RPCOLEMESSAGE* pMsg,
		/*[in]*/ ISynchronize* pSync,
		/*[out]*/ ULONG* pulStatus)
	{
		VSL_DEFINE_MOCK_METHOD(Send)

		VSL_SET_VALIDVALUE(pMsg);

		VSL_CHECK_VALIDVALUE_INTERFACEPOINTER(pSync);

		VSL_SET_VALIDVALUE(pulStatus);

		VSL_RETURN_VALIDVALUES();
	}
	struct ReceiveValidValues
	{
		/*[in,out]*/ RPCOLEMESSAGE* pMsg;
		/*[out]*/ ULONG* pulStatus;
		HRESULT retValue;
	};

	STDMETHOD(Receive)(
		/*[in,out]*/ RPCOLEMESSAGE* pMsg,
		/*[out]*/ ULONG* pulStatus)
	{
		VSL_DEFINE_MOCK_METHOD(Receive)

		VSL_SET_VALIDVALUE(pMsg);

		VSL_SET_VALIDVALUE(pulStatus);

		VSL_RETURN_VALIDVALUES();
	}
	struct GetDestCtxExValidValues
	{
		/*[in]*/ RPCOLEMESSAGE* pMsg;
		/*[out]*/ DWORD* pdwDestContext;
		/*[out]*/ void** ppvDestContext;
		HRESULT retValue;
	};

	STDMETHOD(GetDestCtxEx)(
		/*[in]*/ RPCOLEMESSAGE* pMsg,
		/*[out]*/ DWORD* pdwDestContext,
		/*[out]*/ void** ppvDestContext)
	{
		VSL_DEFINE_MOCK_METHOD(GetDestCtxEx)

		VSL_CHECK_VALIDVALUE_POINTER(pMsg);

		VSL_SET_VALIDVALUE(pdwDestContext);

		VSL_SET_VALIDVALUE(ppvDestContext);

		VSL_RETURN_VALIDVALUES();
	}
	struct GetProtocolVersionValidValues
	{
		/*[in,out]*/ DWORD* pdwVersion;
		HRESULT retValue;
	};

	STDMETHOD(GetProtocolVersion)(
		/*[in,out]*/ DWORD* pdwVersion)
	{
		VSL_DEFINE_MOCK_METHOD(GetProtocolVersion)

		VSL_SET_VALIDVALUE(pdwVersion);

		VSL_RETURN_VALIDVALUES();
	}
	struct GetBufferValidValues
	{
		/*[in]*/ RPCOLEMESSAGE* pMessage;
		/*[in]*/ REFIID riid;
		HRESULT retValue;
	};

	STDMETHOD(GetBuffer)(
		/*[in]*/ RPCOLEMESSAGE* pMessage,
		/*[in]*/ REFIID riid)
	{
		VSL_DEFINE_MOCK_METHOD(GetBuffer)

		VSL_CHECK_VALIDVALUE_POINTER(pMessage);

		VSL_CHECK_VALIDVALUE(riid);

		VSL_RETURN_VALIDVALUES();
	}
	struct SendReceiveValidValues
	{
		/*[in,out]*/ RPCOLEMESSAGE* pMessage;
		/*[out]*/ ULONG* pStatus;
		HRESULT retValue;
	};

	STDMETHOD(SendReceive)(
		/*[in,out]*/ RPCOLEMESSAGE* pMessage,
		/*[out]*/ ULONG* pStatus)
	{
		VSL_DEFINE_MOCK_METHOD(SendReceive)

		VSL_SET_VALIDVALUE(pMessage);

		VSL_SET_VALIDVALUE(pStatus);

		VSL_RETURN_VALIDVALUES();
	}
	struct FreeBufferValidValues
	{
		/*[in]*/ RPCOLEMESSAGE* pMessage;
		HRESULT retValue;
	};

	STDMETHOD(FreeBuffer)(
		/*[in]*/ RPCOLEMESSAGE* pMessage)
	{
		VSL_DEFINE_MOCK_METHOD(FreeBuffer)

		VSL_CHECK_VALIDVALUE_POINTER(pMessage);

		VSL_RETURN_VALIDVALUES();
	}
	struct GetDestCtxValidValues
	{
		/*[out]*/ DWORD* pdwDestContext;
		/*[out]*/ void** ppvDestContext;
		HRESULT retValue;
	};

	STDMETHOD(GetDestCtx)(
		/*[out]*/ DWORD* pdwDestContext,
		/*[out]*/ void** ppvDestContext)
	{
		VSL_DEFINE_MOCK_METHOD(GetDestCtx)

		VSL_SET_VALIDVALUE(pdwDestContext);

		VSL_SET_VALIDVALUE(ppvDestContext);

		VSL_RETURN_VALIDVALUES();
	}
	struct IsConnectedValidValues
	{
		HRESULT retValue;
	};

	STDMETHOD(IsConnected)()
	{
		VSL_DEFINE_MOCK_METHOD_NOARGS(IsConnected)

		VSL_RETURN_VALIDVALUES();
	}
};


} // namespace VSL

#pragma warning(pop)

#endif // IASYNCRPCCHANNELBUFFER_H_10C49CA1_2F46_11D3_A504_00C04F5E0BA5
