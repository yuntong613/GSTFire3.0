// GstFireApiEventSink.h: interface for the CGstFireApiEventSink class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GSTFIREAPIEVENTSINK_H__E963447B_3D7B_4D3E_9276_8B823E941F68__INCLUDED_)
#define AFX_GSTFIREAPIEVENTSINK_H__E963447B_3D7B_4D3E_9276_8B823E941F68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "GstFireApi.h"

class CGstFireApiEventSink : public IDispEventImpl<1, CGstFireApiEventSink,&DIID__IGstFireApiCtlEvents,&LIBID_GSTFIREAPILib,1,0>  
{
public:
	CGstFireApiEventSink(){};
	virtual ~CGstFireApiEventSink(){};

		BEGIN_SINK_MAP(CGstFireApiEventSink)
            SINK_ENTRY_EX(1,    DIID__IGstFireApiCtlEvents,  1, OnFireSystemEvent)
            SINK_ENTRY_EX(1,    DIID__IGstFireApiCtlEvents,  2, OnFireDeviceEvent)
            SINK_ENTRY_EX(1,    DIID__IGstFireApiCtlEvents,  3, OnFireCommandEvent)
       END_SINK_MAP()

        HRESULT _stdcall OnFireCommandEvent( SHORT nControllerId, BSTR bstrCommandName, LONG lValue)
//		{
//		/*
//			用户代码
//		*/
//			
//			return S_OK;
//		}
		;

        HRESULT _stdcall OnFireSystemEvent( SHORT nControllerID, SHORT nEventType,LONG lValue)
//		{
//		/*
//			用户代码
//		*/
//			
//			return S_OK;
//		}
		;
        HRESULT _stdcall OnFireDeviceEvent(SHORT nControllerID, BSTR bstrDeviceId, BSTR bstrDescription, SHORT nStatus, BSTR bstrDeviceTypeName, BSTR bstrZoneDescription, BSTR bstrDeviceLoopCode, SHORT nDevProperty)
//		{								
//		/*
//			用户代码
//		*/
//			switch(0)
//			{
//			
//			case 0: //  Connected, 
//				break;
//			case 1: // NormalDisconnection, 
//				break;
//			case 2: // ServerCloseConnection,
//				break;
//			case 3: // ServerStop, 
//				break;
//			case 4: // ErrorSendingMessage, 
//				break;
//			case 5: // ErrorReceivingMessage
//				break;
//			default:
//				break;
//			}
//			
//			return S_OK;
//		}
		;

};

#endif // !defined(AFX_GSTFIREAPIEVENTSINK_H__E963447B_3D7B_4D3E_9276_8B823E941F68__INCLUDED_)
