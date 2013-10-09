

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

#ifndef __IVsSccGlyphs_h__
#define __IVsSccGlyphs_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsSccGlyphs_FWD_DEFINED__
#define __IVsSccGlyphs_FWD_DEFINED__
typedef interface IVsSccGlyphs IVsSccGlyphs;

#endif 	/* __IVsSccGlyphs_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_IVsSccGlyphs_0000_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IVsSccGlyphs_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVsSccGlyphs_0000_0000_v0_0_s_ifspec;

#ifndef __IVsSccGlyphs_INTERFACE_DEFINED__
#define __IVsSccGlyphs_INTERFACE_DEFINED__

/* interface IVsSccGlyphs */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSccGlyphs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C82CA77-A583-4fd1-8C15-0B3995D9AB2F")
    IVsSccGlyphs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCustomGlyphList( 
            /* [in] */ ULONG BaseIndex,
            /* [out] */ __RPC__out PDWORD_PTR pdwImageListHandle) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IVsSccGlyphsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __RPC__in IVsSccGlyphs * This,
            /* [in] */ __RPC__in REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __RPC__in IVsSccGlyphs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __RPC__in IVsSccGlyphs * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCustomGlyphList )( 
            __RPC__in IVsSccGlyphs * This,
            /* [in] */ ULONG BaseIndex,
            /* [out] */ __RPC__out PDWORD_PTR pdwImageListHandle);
        
        END_INTERFACE
    } IVsSccGlyphsVtbl;

    interface IVsSccGlyphs
    {
        CONST_VTBL struct IVsSccGlyphsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSccGlyphs_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IVsSccGlyphs_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IVsSccGlyphs_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IVsSccGlyphs_GetCustomGlyphList(This,BaseIndex,pdwImageListHandle)	\
    ( (This)->lpVtbl -> GetCustomGlyphList(This,BaseIndex,pdwImageListHandle) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsSccGlyphs_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


