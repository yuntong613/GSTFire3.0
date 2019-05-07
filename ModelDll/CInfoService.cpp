// CInfoService.cpp: 实现文件
//

#include "stdafx.h"
#include "ModelDll.h"
#include "CInfoService.h"
#include "YSerialDevice.h"

// CInfoService

CInfoService::CInfoService()
{
	m_pDevice = NULL;
}

CInfoService::~CInfoService()
{
}


// CInfoService 成员函数


void CInfoService::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	char buff[1024] = { 0 };
	CString strAddr;
	UINT uPort;
	int nRet = ReceiveFrom(buff, 1024, strAddr, uPort);

	if (m_pDevice)
	{
		m_pDevice->HandleData(buff);
	}

	CAsyncSocket::OnReceive(nErrorCode);
}

void CInfoService::SetDevice(YSerialDevice* pDevice)
{
	m_pDevice = pDevice;
}
