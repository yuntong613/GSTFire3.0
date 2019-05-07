#pragma once
#include "YOPCDevice.h"
#include "Log.h"
#include "resource.h"
#include "CInfoService.h"
class YSerialDevice :
	public YOPCDevice
{
public:
	enum{ DEVICENAME = IDS_DEVICENAME};
	YSerialDevice(LPCSTR pszAppPath);
	virtual ~YSerialDevice(void);
	virtual bool SetDeviceItemValue(CBaseItem* pAppItem);
	virtual void OnUpdate();
	virtual void HandleData(CString szText);
	virtual void Serialize(CArchive& ar);
	BOOL InitConfig(CString strFilePath);
	void Load(CArchive& ar);
	void LoadItems(CArchive& ar);
	int QueryOnce();

	virtual void BeginUpdateThread();
	virtual void EndUpdateThread();

public:
	long y_lUpdateTimer;
public:
	int m_nUseLog;
	CLog m_Log;
	void OutPutLog(CString strMsg);

	void OnFireSystemEvent(SHORT nControllerID, SHORT nEventType, LONG lValue);
	void OnFireDeviceEvent(SHORT nControllerID, CString strDeviceId, CString strDescription, SHORT nStatus, CString strDeviceTypeName, CString strZoneDescription, CString strDeviceLoopCode, SHORT nDevProperty);
	CString GetDeviceStatus(SHORT nStatus);
	CString GetCommandReply(LONG lValue);
	void OnFireCommandEvent(SHORT nControllerId, BSTR bstrCommandName, LONG lValue);
	//	void EventInformation(CHAR nControlorID, CHAR nEventType, BSTR bstrDeviceID, CHAR Value);
public:
	CInfoService m_Service;
};
