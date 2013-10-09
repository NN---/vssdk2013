

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __context2_h__
#define __context2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsUserContextExport_FWD_DEFINED__
#define __IVsUserContextExport_FWD_DEFINED__
typedef interface IVsUserContextExport IVsUserContextExport;

#endif 	/* __IVsUserContextExport_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_context2_0000_0000 */
/* [local] */ 

#pragma once

enum __VSUSERCONTEXTEXPORTTEXTFLAGS
    {
        VSUC_ETFlags_None	= 0,
        VSUC_ETFlags_StandardXML	= 0x1,
        VSUC_ETFlags_IncludeChildren	= 0x10
    } ;
typedef DWORD VSUSERCONTEXTEXPORTTEXTFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_context2_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_context2_0000_0000_v0_0_s_ifspec;

#ifndef __IVsUserContextExport_INTERFACE_DEFINED__
#define __IVsUserContextExport_INTERFACE_DEFINED__

/* interface IVsUserContextExport */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsUserContextExport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B50F15A4-C42D-4dc1-AE09-7D2069EC58E9")
    IVsUserContextExport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUserContextAsText( 
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            __RPC__in BSTR bstrOptions,
            __RPC__deref_in_opt BSTR *pbstrKeywords,
            __RPC__deref_in_opt BSTR *pbstrAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserContextAsSafeArray( 
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            __RPC__in BSTR bstrF1Keyword,
            __RPC__deref_in_opt SAFEARRAY * *ppKeywords,
            __RPC__deref_in_opt SAFEARRAY * *ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSubcontextsFromSafeArrays( 
            __RPC__in_opt IVsMonitorUserContext *pMUC,
            __RPC__in SAFEARRAY * pKeywords,
            __RPC__in SAFEARRAY * pAttributes) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVsUserContextExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVsUserContextExport * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVsUserContextExport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVsUserContextExport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserContextAsText )( 
            __RPC__in IVsUserContextExport * This,
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            __RPC__in BSTR bstrOptions,
            __RPC__deref_in_opt BSTR *pbstrKeywords,
            __RPC__deref_in_opt BSTR *pbstrAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserContextAsSafeArray )( 
            __RPC__in IVsUserContextExport * This,
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            __RPC__in BSTR bstrF1Keyword,
            __RPC__deref_in_opt SAFEARRAY * *ppKeywords,
            __RPC__deref_in_opt SAFEARRAY * *ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSubcontextsFromSafeArrays )( 
            __RPC__in IVsUserContextExport * This,
            __RPC__in_opt IVsMonitorUserContext *pMUC,
            __RPC__in SAFEARRAY * pKeywords,
            __RPC__in SAFEARRAY * pAttributes);
        
        END_INTERFACE
    } IVsUserContextExportVtbl;

    interface IVsUserContextExport
    {
        CONST_VTBL struct IVsUserContextExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUserContextExport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVsUserContextExport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVsUserContextExport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVsUserContextExport_GetUserContextAsText(This,dwFlags,bstrOptions,pbstrKeywords,pbstrAttributes)	\
    ( (This)->lpVtbl -> GetUserContextAsText(This,dwFlags,bstrOptions,pbstrKeywords,pbstrAttributes) ) 

#define IVsUserContextExport_GetUserContextAsSafeArray(This,dwFlags,bstrF1Keyword,ppKeywords,ppAttributes)	\
    ( (This)->lpVtbl -> GetUserContextAsSafeArray(This,dwFlags,bstrF1Keyword,ppKeywords,ppAttributes) ) 

#define IVsUserContextExport_CreateSubcontextsFromSafeArrays(This,pMUC,pKeywords,pAttributes)	\
    ( (This)->lpVtbl -> CreateSubcontextsFromSafeArrays(This,pMUC,pKeywords,pAttributes) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsUserContextExport_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     __RPC__in unsigned long *, __RPC__in LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


