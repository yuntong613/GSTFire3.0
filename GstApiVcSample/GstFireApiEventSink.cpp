
#include "stdafx.h"
#include "GstFireApiEventSink.h"
#include "Resource.h"
#include "GstFireApiTestDlg.h"


HRESULT _stdcall CGstFireApiEventSink::OnFireDeviceEvent(SHORT nControllerID, BSTR bstrDeviceId, BSTR bstrDescription, SHORT nStatus, BSTR bstrDeviceTypeName, BSTR bstrZoneDescription, BSTR bstrDeviceLoopCode, SHORT nDevProperty)
{
	CGstFireApiTestDlg* pDlg=(CGstFireApiTestDlg*)AfxGetMainWnd();

	CString strDeviceId			=bstrDeviceId;			 
	CString strDescription		=bstrDescription;		 
	CString strDeviceTypeName	=bstrDeviceTypeName;	 
	CString strZoneDescription	=bstrZoneDescription;	 
	CString strDeviceLoopCode	=bstrDeviceLoopCode;	 

	pDlg->OnFireDeviceEvent( nControllerID, strDeviceId, strDescription,  nStatus, strDeviceTypeName, strZoneDescription, strDeviceLoopCode,  nDevProperty);
/*
	用户代码
*/
	
	return S_OK;
}
HRESULT _stdcall CGstFireApiEventSink::OnFireSystemEvent(SHORT nControllerID,SHORT  nEventType,LONG lValue)
{
/*
	用户代码
*/
	CGstFireApiTestDlg* pDlg=(CGstFireApiTestDlg*)AfxGetMainWnd();
	pDlg->OnFireSystemEvent( nControllerID, nEventType,  lValue);
	
	return S_OK;
}

HRESULT _stdcall CGstFireApiEventSink::OnFireCommandEvent( SHORT nControllerId, BSTR bstrCommandName, LONG lValue)
{
/*
	用户代码
*/
	CGstFireApiTestDlg* pDlg=(CGstFireApiTestDlg*)AfxGetMainWnd();
	pDlg->OnFireCommandEvent( nControllerId, bstrCommandName,  lValue);

	
	return S_OK;
}
;
