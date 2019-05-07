#pragma once
#include "basedevice.h"
#include "BaseItem.h"
#include "YOPCItem.h"


class YOPCDevice :
	public CBaseDevice
{
public:
	YOPCDevice(void);
	virtual ~YOPCDevice(void);
	virtual void OnUpdate()=0;
	virtual bool SetDeviceItemValue(CBaseItem* pAppItem)=0;
	YOPCItem* GetItemById(DWORD dwItemID)const;
	YOPCItem* GetItemByName(const CString strName)const;
	int GetItemsCount()const{ return (int)(m_ItemsArray.GetCount());}
	const CMapStringToOb* GetItemArray()const{ return &m_ItemsArray;}
	bool ShowItemBrowseDlg(CObArray* pDevItemArray);
	virtual void HandleData(CString szText) = 0;
	virtual void BeginUpdateThread() = 0;
	virtual void EndUpdateThread() = 0;
	virtual void OnFireSystemEvent(SHORT nControllerID, SHORT nEventType, LONG lValue) = 0;
	virtual void OnFireDeviceEvent(SHORT nControllerID, CString strDeviceId, CString strDescription, SHORT nStatus, CString strDeviceTypeName, CString strZoneDescription, CString strDeviceLoopCode, SHORT nDevProperty) = 0;
	virtual void OnFireCommandEvent(SHORT nControllerId, BSTR bstrCommandName, LONG lValue) = 0;
protected:
	CMapStringToOb m_ItemsArray;
};