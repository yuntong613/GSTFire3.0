#pragma once

// CInfoService 命令目标

class YSerialDevice;
class CInfoService : public CAsyncSocket
{
public:
	CInfoService();
	virtual ~CInfoService();
	virtual void OnReceive(int nErrorCode);
	void SetDevice(YSerialDevice* pDevice);

protected:
	YSerialDevice* m_pDevice;
};


