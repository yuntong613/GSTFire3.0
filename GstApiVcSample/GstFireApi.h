/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Jan 01 08:52:07 2006
 */
/* Compiler settings for E:\LocalWork\GstGMC\GstApi\Source\GstFireApi.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __GstFireApi_h__
#define __GstFireApi_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IGstFireApiCtl_FWD_DEFINED__
#define __IGstFireApiCtl_FWD_DEFINED__
typedef interface IGstFireApiCtl IGstFireApiCtl;
#endif 	/* __IGstFireApiCtl_FWD_DEFINED__ */


#ifndef ___IGstFireApiCtlEvents_FWD_DEFINED__
#define ___IGstFireApiCtlEvents_FWD_DEFINED__
typedef interface _IGstFireApiCtlEvents _IGstFireApiCtlEvents;
#endif 	/* ___IGstFireApiCtlEvents_FWD_DEFINED__ */


#ifndef __GstFireApiCtl_FWD_DEFINED__
#define __GstFireApiCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class GstFireApiCtl GstFireApiCtl;
#else
typedef struct GstFireApiCtl GstFireApiCtl;
#endif /* __cplusplus */

#endif 	/* __GstFireApiCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IGstFireApiCtl_INTERFACE_DEFINED__
#define __IGstFireApiCtl_INTERFACE_DEFINED__

/* interface IGstFireApiCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IGstFireApiCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FDF21F69-63AD-48B2-A5A5-D47CCFDA79FA")
    IGstFireApiCtl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConnectToServer( 
            /* [in] */ BSTR bstrServer,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrPassword,
            /* [in] */ BSTR bstrReserved,
            /* [in] */ long lReserved,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisConnectToServer( 
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsConnected( 
            /* [out] */ BOOL __RPC_FAR *pbConnected,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ForceUpdateData( 
            /* [in] */ int nControllerId,
            /* [in] */ BSTR bstrDeviceId,
            /* [in] */ long lReserved,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetController( 
            /* [in] */ int nControllerId,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearController( 
            /* [in] */ int nControllerId,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFireSystemTime( 
            /* [in] */ int nControllerId,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetControllerState( 
            /* [in] */ int nControllerId,
            /* [in] */ BOOL bCanAuto,
            /* [in] */ BOOL bCanManual,
            /* [in] */ BOOL bCanSpurt,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDeviceState( 
            /* [in] */ int nControllerId,
            /* [in] */ BSTR bstrDeviceId,
            /* [in] */ int nState,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MuteController( 
            /* [in] */ int nControllerId,
            /* [in] */ int nReserved,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSystemLog( 
            /* [in] */ BSTR bstrSQL,
            /* [out] */ long __RPC_FAR *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IGstFireApiCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IGstFireApiCtl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IGstFireApiCtl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConnectToServer )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ BSTR bstrServer,
            /* [in] */ BSTR bstrUserName,
            /* [in] */ BSTR bstrPassword,
            /* [in] */ BSTR bstrReserved,
            /* [in] */ long lReserved,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisConnectToServer )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsConnected )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [out] */ BOOL __RPC_FAR *pbConnected,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceUpdateData )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [in] */ BSTR bstrDeviceId,
            /* [in] */ long lReserved,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetController )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearController )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFireSystemTime )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetControllerState )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [in] */ BOOL bCanAuto,
            /* [in] */ BOOL bCanManual,
            /* [in] */ BOOL bCanSpurt,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDeviceState )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [in] */ BSTR bstrDeviceId,
            /* [in] */ int nState,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MuteController )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ int nControllerId,
            /* [in] */ int nReserved,
            /* [out] */ long __RPC_FAR *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSystemLog )( 
            IGstFireApiCtl __RPC_FAR * This,
            /* [in] */ BSTR bstrSQL,
            /* [out] */ long __RPC_FAR *pResult);
        
        END_INTERFACE
    } IGstFireApiCtlVtbl;

    interface IGstFireApiCtl
    {
        CONST_VTBL struct IGstFireApiCtlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IGstFireApiCtl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IGstFireApiCtl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IGstFireApiCtl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IGstFireApiCtl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IGstFireApiCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IGstFireApiCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IGstFireApiCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IGstFireApiCtl_ConnectToServer(This,bstrServer,bstrUserName,bstrPassword,bstrReserved,lReserved,pResult)	\
    (This)->lpVtbl -> ConnectToServer(This,bstrServer,bstrUserName,bstrPassword,bstrReserved,lReserved,pResult)

#define IGstFireApiCtl_DisConnectToServer(This,pResult)	\
    (This)->lpVtbl -> DisConnectToServer(This,pResult)

#define IGstFireApiCtl_IsConnected(This,pbConnected,pResult)	\
    (This)->lpVtbl -> IsConnected(This,pbConnected,pResult)

#define IGstFireApiCtl_ForceUpdateData(This,nControllerId,bstrDeviceId,lReserved,pResult)	\
    (This)->lpVtbl -> ForceUpdateData(This,nControllerId,bstrDeviceId,lReserved,pResult)

#define IGstFireApiCtl_ResetController(This,nControllerId,pResult)	\
    (This)->lpVtbl -> ResetController(This,nControllerId,pResult)

#define IGstFireApiCtl_ClearController(This,nControllerId,pResult)	\
    (This)->lpVtbl -> ClearController(This,nControllerId,pResult)

#define IGstFireApiCtl_SetFireSystemTime(This,nControllerId,pResult)	\
    (This)->lpVtbl -> SetFireSystemTime(This,nControllerId,pResult)

#define IGstFireApiCtl_SetControllerState(This,nControllerId,bCanAuto,bCanManual,bCanSpurt,pResult)	\
    (This)->lpVtbl -> SetControllerState(This,nControllerId,bCanAuto,bCanManual,bCanSpurt,pResult)

#define IGstFireApiCtl_SetDeviceState(This,nControllerId,bstrDeviceId,nState,pResult)	\
    (This)->lpVtbl -> SetDeviceState(This,nControllerId,bstrDeviceId,nState,pResult)

#define IGstFireApiCtl_MuteController(This,nControllerId,nReserved,pResult)	\
    (This)->lpVtbl -> MuteController(This,nControllerId,nReserved,pResult)

#define IGstFireApiCtl_GetSystemLog(This,bstrSQL,pResult)	\
    (This)->lpVtbl -> GetSystemLog(This,bstrSQL,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_ConnectToServer_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ BSTR bstrServer,
    /* [in] */ BSTR bstrUserName,
    /* [in] */ BSTR bstrPassword,
    /* [in] */ BSTR bstrReserved,
    /* [in] */ long lReserved,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_ConnectToServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_DisConnectToServer_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_DisConnectToServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_IsConnected_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [out] */ BOOL __RPC_FAR *pbConnected,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_IsConnected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_ForceUpdateData_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [in] */ BSTR bstrDeviceId,
    /* [in] */ long lReserved,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_ForceUpdateData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_ResetController_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_ResetController_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_ClearController_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_ClearController_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_SetFireSystemTime_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_SetFireSystemTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_SetControllerState_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [in] */ BOOL bCanAuto,
    /* [in] */ BOOL bCanManual,
    /* [in] */ BOOL bCanSpurt,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_SetControllerState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_SetDeviceState_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [in] */ BSTR bstrDeviceId,
    /* [in] */ int nState,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_SetDeviceState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_MuteController_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ int nControllerId,
    /* [in] */ int nReserved,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_MuteController_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IGstFireApiCtl_GetSystemLog_Proxy( 
    IGstFireApiCtl __RPC_FAR * This,
    /* [in] */ BSTR bstrSQL,
    /* [out] */ long __RPC_FAR *pResult);


void __RPC_STUB IGstFireApiCtl_GetSystemLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IGstFireApiCtl_INTERFACE_DEFINED__ */



#ifndef __GSTFIREAPILib_LIBRARY_DEFINED__
#define __GSTFIREAPILib_LIBRARY_DEFINED__

/* library GSTFIREAPILib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_GSTFIREAPILib;

#ifndef ___IGstFireApiCtlEvents_DISPINTERFACE_DEFINED__
#define ___IGstFireApiCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IGstFireApiCtlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IGstFireApiCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8369BE3C-7BAD-4C7F-A062-6ECBFB534B78")
    _IGstFireApiCtlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IGstFireApiCtlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IGstFireApiCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IGstFireApiCtlEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IGstFireApiCtlEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IGstFireApiCtlEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IGstFireApiCtlEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IGstFireApiCtlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IGstFireApiCtlEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IGstFireApiCtlEventsVtbl;

    interface _IGstFireApiCtlEvents
    {
        CONST_VTBL struct _IGstFireApiCtlEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IGstFireApiCtlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IGstFireApiCtlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IGstFireApiCtlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IGstFireApiCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IGstFireApiCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IGstFireApiCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IGstFireApiCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IGstFireApiCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_GstFireApiCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("137226BC-29B4-4158-ABF0-5E78D77933BB")
GstFireApiCtl;
#endif
#endif /* __GSTFIREAPILib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
