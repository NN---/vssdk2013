

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

#ifndef __vsshlctx_h__
#define __vsshlctx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsShellContext_FWD_DEFINED__
#define __IVsShellContext_FWD_DEFINED__
typedef interface IVsShellContext IVsShellContext;

#endif 	/* __IVsShellContext_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "servprov.h"
#include "oaidl.h"
#include "ocidl.h"
#include "context.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IVsShellContext_INTERFACE_DEFINED__
#define __IVsShellContext_INTERFACE_DEFINED__

/* interface IVsShellContext */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsShellContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e819c22-a727-11d2-aa82-00c04f990343")
    IVsShellContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTopContext( 
            /* [out] */ __RPC__deref_out_opt IVsUserContext **ppc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewContext( 
            /* [out] */ __RPC__deref_out_opt IVsUserContext **ppc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextMonitor( 
            /* [out] */ __RPC__deref_out_opt IVsMonitorUserContext **pmuc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCmdUIContext( 
            /* [in] */ DWORD_PTR dwCookie,
            /* [out] */ __RPC__deref_out_opt IVsUserContext **ppc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCmdUIContext( 
            /* [in] */ DWORD_PTR dwCookie,
            /* [in] */ __RPC__in_opt IVsUserContext *pc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddInformationIndex( 
            /* [in] */ __RPC__in LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveInformationIndex( 
            /* [in] */ __RPC__in LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE F1Lookup( 
            /* [in] */ __RPC__in LPCOLESTR pszKeyword) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatusF1WindowLookup( 
            /* [out] */ __RPC__out BOOL *pfIsEnabled,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrWindowName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE F1WindowLookup( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVsShellContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVsShellContext * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVsShellContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVsShellContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTopContext )( 
            __RPC__in IVsShellContext * This,
            /* [out] */ __RPC__deref_out_opt IVsUserContext **ppc);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewContext )( 
            __RPC__in IVsShellContext * This,
            /* [out] */ __RPC__deref_out_opt IVsUserContext **ppc);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextMonitor )( 
            __RPC__in IVsShellContext * This,
            /* [out] */ __RPC__deref_out_opt IVsMonitorUserContext **pmuc);
        
        HRESULT ( STDMETHODCALLTYPE *GetCmdUIContext )( 
            __RPC__in IVsShellContext * This,
            /* [in] */ DWORD_PTR dwCookie,
            /* [out] */ __RPC__deref_out_opt IVsUserContext **ppc);
        
        HRESULT ( STDMETHODCALLTYPE *SetCmdUIContext )( 
            __RPC__in IVsShellContext * This,
            /* [in] */ DWORD_PTR dwCookie,
            /* [in] */ __RPC__in_opt IVsUserContext *pc);
        
        HRESULT ( STDMETHODCALLTYPE *AddInformationIndex )( 
            __RPC__in IVsShellContext * This,
            /* [in] */ __RPC__in LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveInformationIndex )( 
            __RPC__in IVsShellContext * This,
            /* [in] */ __RPC__in LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *F1Lookup )( 
            __RPC__in IVsShellContext * This,
            /* [in] */ __RPC__in LPCOLESTR pszKeyword);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatusF1WindowLookup )( 
            __RPC__in IVsShellContext * This,
            /* [out] */ __RPC__out BOOL *pfIsEnabled,
            /* [out] */ __RPC__deref_out_opt BSTR *pbstrWindowName);
        
        HRESULT ( STDMETHODCALLTYPE *F1WindowLookup )( 
            __RPC__in IVsShellContext * This);
        
        END_INTERFACE
    } IVsShellContextVtbl;

    interface IVsShellContext
    {
        CONST_VTBL struct IVsShellContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsShellContext_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVsShellContext_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVsShellContext_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVsShellContext_GetTopContext(This,ppc)	\
    ( (This)->lpVtbl -> GetTopContext(This,ppc) ) 

#define IVsShellContext_CreateNewContext(This,ppc)	\
    ( (This)->lpVtbl -> CreateNewContext(This,ppc) ) 

#define IVsShellContext_GetContextMonitor(This,pmuc)	\
    ( (This)->lpVtbl -> GetContextMonitor(This,pmuc) ) 

#define IVsShellContext_GetCmdUIContext(This,dwCookie,ppc)	\
    ( (This)->lpVtbl -> GetCmdUIContext(This,dwCookie,ppc) ) 

#define IVsShellContext_SetCmdUIContext(This,dwCookie,pc)	\
    ( (This)->lpVtbl -> SetCmdUIContext(This,dwCookie,pc) ) 

#define IVsShellContext_AddInformationIndex(This,pszPath)	\
    ( (This)->lpVtbl -> AddInformationIndex(This,pszPath) ) 

#define IVsShellContext_RemoveInformationIndex(This,pszPath)	\
    ( (This)->lpVtbl -> RemoveInformationIndex(This,pszPath) ) 

#define IVsShellContext_F1Lookup(This,pszKeyword)	\
    ( (This)->lpVtbl -> F1Lookup(This,pszKeyword) ) 

#define IVsShellContext_QueryStatusF1WindowLookup(This,pfIsEnabled,pbstrWindowName)	\
    ( (This)->lpVtbl -> QueryStatusF1WindowLookup(This,pfIsEnabled,pbstrWindowName) ) 

#define IVsShellContext_F1WindowLookup(This)	\
    ( (This)->lpVtbl -> F1WindowLookup(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsShellContext_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshlctx_0000_0001 */
/* [local] */ 

#define SID_SVsShellContext IID_IVsShellContext


extern RPC_IF_HANDLE __MIDL_itf_vsshlctx_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshlctx_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     __RPC__in unsigned long *, unsigned long            , __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  __RPC__in unsigned long *, __RPC__inout_xcount(0) unsigned char *, __RPC__in BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(__RPC__in unsigned long *, __RPC__in_xcount(0) unsigned char *, __RPC__out BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     __RPC__in unsigned long *, __RPC__in BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


