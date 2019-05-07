#include "StdAfx.h"
#include "common.h"
#include "YSerialDevice.h"
#include "IniFile.h"
#include "ItemBrowseDlg.h"
#include "YSerialItem.h"
#include <cstringt.h>
#include "ModelDll.h"
#include "OPCIniFile.h"
#include "json.h"

extern CModelDllApp theApp;

YSerialDevice::YSerialDevice(LPCSTR pszAppPath)
{
	y_lUpdateTimer = 0;
	m_nUseLog = 0;
	CString strConfigFile(pszAppPath);
	strConfigFile+= _T("\\Settings.ini");
	if(!InitConfig(strConfigFile))
	{
		return;
	}

	CString strListItemsFile(pszAppPath);
	strListItemsFile += _T("\\ListItems.ini");
	COPCIniFile opcFile;
	if (!opcFile.Open(strListItemsFile,CFile::modeRead|CFile::typeText))
	{
		AfxMessageBox("Can't open INI file!");
		return;
	}
	CArchive ar(&opcFile,CArchive::load);
	Serialize(ar);
	opcFile.Close();
}

YSerialDevice::~YSerialDevice(void)
{
	POSITION pos = m_ItemsArray.GetStartPosition();
	YSerialItem* pItem = NULL;
	CString strItemName;
	while(pos){
		m_ItemsArray.GetNextAssoc(pos,strItemName,(CObject*&)pItem);
		if(pItem)
		{
			delete pItem;
			pItem = NULL;
		}
	}
	m_ItemsArray.RemoveAll();
}

void YSerialDevice::Serialize(CArchive& ar)
{
	if (ar.IsStoring()){
	}else{
		Load(ar);
	}
}

BOOL YSerialDevice::InitConfig(CString strFilePath)
{
	if(!PathFileExists(strFilePath))
		return FALSE;
	CIniFile iniFile(strFilePath);
	m_nUseLog = iniFile.GetUInt("param","Log",0);

	return TRUE;
}

void YSerialDevice::Load(CArchive& ar)
{
	LoadItems(ar);
}

void YSerialDevice::LoadItems(CArchive& ar)
{
	COPCIniFile* pIniFile = static_cast<COPCIniFile*>(ar.GetFile());
	YOPCItem* pItem  = NULL;
	int nItems = 0;
	CString strTmp("Item");
	CString strItemName;
	CString strItemDesc;
	CString strValue;
	DWORD dwItemPId = 0L;
	strTmp+=CString(_T("List"));
	if(pIniFile->ReadNoSeqSection(strTmp)){
		nItems = pIniFile->GetItemsCount(strTmp,"Item");
		for (int i=0;i<nItems && !pIniFile->Endof();i++ )
		{
			try{
				if (pIniFile->ReadIniItem("Item",strTmp))
				{
					if (!pIniFile->ExtractSubValue(strTmp,strValue,1))
						throw new CItemException(CItemException::invalidId,pIniFile->GetFileName());
					dwItemPId = atoi(strValue);
					if(!pIniFile->ExtractSubValue(strTmp,strItemName,2))strItemName = _T("Unknown");
					if(!pIniFile->ExtractSubValue(strTmp,strItemDesc,3)) strItemDesc = _T("Unknown");
					pItem = new YShortItem(dwItemPId,strItemName,strItemDesc);
					if(GetItemByName(strItemName))
						delete pItem;
					else 
						m_ItemsArray.SetAt(pItem->GetName(),(CObject*)pItem);
				}
			}
			catch(CItemException* e){
				if(pItem) delete pItem;
				e->Delete();
			}
		}
	}
}

void YSerialDevice::OnUpdate()
{
// 	y_lUpdateTimer--;
// 	if(y_lUpdateTimer>0)return;
// 	y_lUpdateTimer = m_lRate/1000;

}

void YSerialDevice::HandleData(CString szText)
{
	szText += "\r\n";
	OutPutLog(szText);
	Json::Reader rd;
	Json::Value root;
	if (rd.parse((LPCSTR)szText, root))
	{
		if (root["info"].isNull())
		{
			return;
		}

		CString strInfoType = root["info"].asCString();
		if (strInfoType == "OnFireDeviceEvent")
		{
			SHORT nControllerID = root["nControllerID"].asInt();
			CString strDeviceId = root["strDeviceId"].asCString();
			CString strDescription = root["strDescription"].asCString();
			SHORT nStatus = root["nStatus"].asInt();
			CString strDeviceTypeName = root["strDeviceTypeName"].asCString();
			CString strZoneDescription = root["strZoneDescription"].asCString();
			CString strDeviceLoopCode = root["strDeviceLoopCode"].asCString();
			SHORT nDevProperty = root["nDevProperty"].asInt();

			OnFireDeviceEvent(nControllerID, strDeviceId, strDescription, nStatus, strDeviceTypeName, strZoneDescription, strDeviceLoopCode, nDevProperty);
		}
	}
}

int YSerialDevice::QueryOnce()
{
// 	y_lUpdateTimer--;
// 	if(y_lUpdateTimer>0)return;
// 	y_lUpdateTimer = m_lRate/1000;

	return 0;
}

void YSerialDevice::BeginUpdateThread()
{
	m_Service.SetDevice(this);
	m_Service.Create(10666, SOCK_DGRAM);
}

void YSerialDevice::EndUpdateThread()
{
	m_Service.Close();
}

bool YSerialDevice::SetDeviceItemValue(CBaseItem* pAppItem)
{
	return false;
}

void YSerialDevice::OutPutLog(CString strMsg)
{
	if(m_nUseLog)
		m_Log.Write(strMsg);
}


void YSerialDevice::OnFireSystemEvent(SHORT nControllerID, SHORT nEventType, LONG	lValue)
{
	CString	strControllerID;	strControllerID.Format("%03d", nControllerID);
	CString	strEventType;		strEventType.Format("%03d", nEventType);
	CString	strValue;			strValue.Format("%03d", lValue);

	CString	strTime = COleDateTime::GetCurrentTime().Format("%y-%m-%d %H:%M:%S");

	strControllerID = strControllerID + "    (ControllerID)";
	switch (nEventType)
	{
	case 1:
	{
		strEventType = strEventType + "    (ConnectEvent)";
		if (lValue == 0) strValue = strValue + "    Connected	与服务器建立连接";
		if (lValue == 1) strValue = strValue + "    NormalDisconnection	正常断开";
		if (lValue == 2) strValue = strValue + "    ServerCloseConnection	服务器关闭连接";
		if (lValue == 3) strValue = strValue + "    ServerStop	服务器停止";
		if (lValue == 4) strValue = strValue + "    ErrorSendingMessage	";
		if (lValue == 5) strValue = strValue + "    ErrorReceivingMessage	";
		if (lValue == 6) strValue = strValue + "    ErrorUsernameOrPwd	服务器拒绝(用户名或口令错)";
		if (lValue == 10) strValue = strValue + "    服务器与控制器通讯停止";
		if (lValue == 11) strValue = strValue + "    控制器无应答（通讯异常）";
		if (lValue == 12) strValue = strValue + "    服务器与控制器通讯正常";
		if (lValue == -1) strValue = strValue + "    Unknown	异常(失控)";

		return;
	}
	break;
	case 2:
	{
		strEventType = strEventType + "    (ControllerEvent)";
		if (lValue == 0) strValue = strValue + "    ";
		if (lValue == 1) strValue = strValue + "    ";
		if (lValue == 2) strValue = strValue + "    ";
		if (lValue == 3) strValue = strValue + "    ";
		if (lValue == 4) strValue = strValue + "    ";

		if (lValue == 11) strValue = strValue + "    控制器复位";
		if (lValue == 12) strValue = strValue + "    控制器状态";
		if (lValue == 13) strValue = strValue + "    控制器消音";
	}
	break;
	case 3:
	{
		strEventType = strEventType + "    (DownloadEvent)";
		strValue.Format("left: %d kbyte", lValue);
	}
	break;
	default:
	{

	}
	break;
	}

}
void YSerialDevice::OnFireDeviceEvent(SHORT nControllerID, CString strDeviceId, CString strDescription, SHORT nStatus, CString strDeviceTypeName, CString strZoneDescription, CString strDeviceLoopCode, SHORT nDevProperty)
{
	CString strLog;
	strLog.Format("DevID %s,Desc %s,Status %d", strDeviceId, strDescription, nStatus);
	OutPutLog(strLog);

	CString	strControllerID;	
	strControllerID.Format("%03d", nControllerID);
	CString	strStatus;			
	strStatus = GetDeviceStatus(nStatus);

	YOPCItem* pItem = NULL;
 	CString strItemName;
	strItemName.Format("%d-%s", nControllerID, strDeviceId);
 	pItem = GetItemByName(strItemName);

	CString strValue = "0";
	switch (nStatus)
	{
	case 0:
		strValue = "0";
		break;
	case 16:
		strValue = "1";
		break;
	case 256:
		strValue = "2";
		break;
	default:
		break;
	}
	if (pItem)
		pItem->OnUpdate(strValue);
}


CString YSerialDevice::GetDeviceStatus(SHORT nStatus)
{
	CString strStatus;
	strStatus.Format("%03d  ", nStatus);

	if (strStatus == "000") strStatus += "AE_DeviceNomal";	//设备正常
	if (strStatus == 20) strStatus += "AE_DeviceRestore";	//设备恢复.
	if (strStatus == 21) strStatus += "AE_DeviceAlarm";		//设备报警.
	if (strStatus == 22) strStatus += "AE_DeviceStart";		//设备启动.
	if (strStatus == 23) strStatus += "AE_DeviceStop";		//设备停止.
	if (strStatus == 24) strStatus += "AE_DeviceAction";		//设备动作.

	if (strStatus == 30) strStatus += "AE_DeviceFault";		//设备故障.(原10)
	if (strStatus == 31) strStatus += "AE_DeviceIsolate";	//设备隔离.
	if (strStatus == 32) strStatus += "AE_DeviceRelease";	//设备释放.

	return strStatus;
}


CString YSerialDevice::GetCommandReply(LONG lValue)
{

	CString strStatus;
	strStatus.Format("%03d  ", lValue);

	if (lValue == 0) strStatus += "(RET_Successful		成功)";
	if (lValue == 1) strStatus += "(RET_Busy			控制器忙)";
	if (lValue == 2) strStatus += "(RET_ParamInvalide	参数非法)";
	if (lValue == 3) strStatus += "(RET_ShakeHandFail	握手失败)";
	if (lValue == 4) strStatus += "(RET_GstComError		内部错误)";
	if (lValue == 5) strStatus += "(RET_ReplyError		应答错误)";
	if (lValue == 6) strStatus += "(RET_ReplyTimeout	应答超时)";
	if (lValue == 10) strStatus += "(RET_Rs232Error		串口失败)";
	if (lValue == 255) strStatus += "(RET_NOTCommand		协议里没有此命令)";

	return strStatus;
}

void YSerialDevice::OnFireCommandEvent(SHORT nControllerId, BSTR bstrCommandName, LONG lValue)
{

}