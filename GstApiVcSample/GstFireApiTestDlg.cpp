// GstFireApiTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GstFireApiTest.h"
#include "GstFireApiTestDlg.h"
#include "json.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "GstFireApi_i.c"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGstFireApiTestDlg dialog

CGstFireApiTestDlg::CGstFireApiTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGstFireApiTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGstFireApiTestDlg)
	m_lReserved = 0;
	m_strServerIP = _T("192.168.1.110");
	m_strConnectState = _T("");
	m_strPassword = _T("101");
	m_strReserved = _T("");
	m_strUserName = _T("abcd");
	m_bAuto = FALSE;
	m_bManual = FALSE;
	m_bSpurt = FALSE;
	m_nControllerId = 1;
	m_strDeviceId = _T("");
	m_bShowCommand = true;
	m_bShowDevice = true;
	m_bShowSystem = true;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGstFireApiTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGstFireApiTestDlg)
	DDX_Control(pDX, IDC_CBO_DEVICE_STATE, m_cboDeviceState);
	DDX_Control(pDX, IDC_LIST_RESULT, m_listResult);
	DDX_Text(pDX, IDC_EDIT_PORT, m_lReserved);
	DDX_Text(pDX, IDC_EDIT_SERVERIP, m_strServerIP);
	DDX_Text(pDX, IDC_EDIT_CONNECT, m_strConnectState);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_strReserved);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	DDX_Check(pDX, IDC_CHK_AUTO, m_bAuto);
	DDX_Check(pDX, IDC_CHK_MANUAL, m_bManual);
	DDX_Check(pDX, IDC_CHK_SPURT, m_bSpurt);
	DDX_Text(pDX, IDC_EDIT_CONTROLLERID, m_nControllerId);
	DDX_Text(pDX, IDC_EDIT_DEVICEID, m_strDeviceId);
	DDX_Check(pDX, IDC_CHK_COMMAND, m_bShowCommand);
	DDX_Check(pDX, IDC_CHK_DEVICE, m_bShowDevice);
	DDX_Check(pDX, IDC_CHK_SYSTEM, m_bShowSystem);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGstFireApiTestDlg, CDialog)
	//{{AFX_MSG_MAP(CGstFireApiTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CONNECT, OnBtnConnect)
	ON_BN_CLICKED(IDC_BTN_DISCONNECT, OnBtnDisconnect)
	ON_BN_CLICKED(IDC_BTN_CLEAR, OnBtnClear)
	ON_BN_CLICKED(IDC_BTN_RESET, OnBtnReset)
	ON_BN_CLICKED(IDC_BTN_MUTE, OnBtnMute)
	ON_BN_CLICKED(IDC_BTN_SET_TIME, OnBtnSetTime)
	ON_BN_CLICKED(IDC_BTN_SET_STATE, OnBtnSetState)
	ON_BN_CLICKED(IDC_BTN_SET_DEVICE_STATE, OnBtnSetDeviceState)
	ON_BN_CLICKED(IDC_BTN_LOG_CLEAR, OnBtnLogClear)
	ON_BN_CLICKED(IDC_CHK_SYSTEM, OnChkSystem)
	ON_BN_CLICKED(IDC_CHK_DEVICE, OnChkDevice)
	ON_BN_CLICKED(IDC_CHK_COMMAND, OnChkCommand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGstFireApiTestDlg message handlers

BOOL CGstFireApiTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
/*=====Add By Wzc=====Start*/
/*2005.4.22 13:50*/
	HRESULT			hr;
	hr = CoInitialize(0);
	if (!SUCCEEDED(hr))
	{
	}

	hr = CoCreateInstance( CLSID_GstFireApiCtl  , NULL, CLSCTX_INPROC_SERVER,
					IID_IGstFireApiCtl , (void**) &m_IGstFireApiCtl);
	if (!SUCCEEDED(hr))
	{
			AfxMessageBox("CoCreateInstance Failed.");
		return FALSE;  
	}

    m_IGstFireApiCtl->QueryInterface(IID_IGstFireApiCtl, 
        (void**)&m_pControlUnk);

	m_pGstFireApiEventSink = new CGstFireApiEventSink();

    if (m_pGstFireApiEventSink) 
        hr = m_pGstFireApiEventSink->DispEventAdvise(m_pControlUnk);
	else
       AfxMessageBox("Event Creater Failed.");
/*=====Add By Wzc=====End*/


	m_Sock.Create(10667, SOCK_DGRAM);

	OnBtnConnect();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGstFireApiTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGstFireApiTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGstFireApiTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CGstFireApiTestDlg::DestroyWindow() 
{

	m_Sock.Close();
    if (m_pGstFireApiEventSink)
	{
        m_pGstFireApiEventSink->DispEventUnadvise(m_pControlUnk);	//断开事件
        m_pControlUnk->Release();									//释放查询指针
	    delete m_pGstFireApiEventSink;								//删除事件接收对象
	}
	if (m_IGstFireApiCtl)
	{
		HRESULT hResult;
		m_IGstFireApiCtl->DisConnectToServer(&hResult);
		m_IGstFireApiCtl->Release();
	}


	CoUninitialize();

	return CDialog::DestroyWindow();
}

void CGstFireApiTestDlg::OnBtnDisconnect() 
{
	long lResult;
	m_IGstFireApiCtl->DisConnectToServer(&lResult);
	if(lResult==S_OK)
	{


	}
	else
	{

	}
	
}
void CGstFireApiTestDlg::OnBtnConnect() 
{
	UpdateData(true);
	m_strConnectState="Connecting...";
	UpdateData(false);

	long lResult;

    m_strReserved="";
	m_IGstFireApiCtl->ConnectToServer(m_strServerIP.AllocSysString(),m_strUserName.AllocSysString(),m_strPassword.AllocSysString(),m_strReserved.AllocSysString(),0,&lResult);
	if(lResult==S_OK)
	{

	}
	else
	{
		AfxMessageBox("Connect Error Occur!");
	}

}



void CGstFireApiTestDlg::OnFireSystemEvent( SHORT nControllerID, SHORT nEventType, LONG	lValue)
{
		CString	strControllerID;	strControllerID.Format("%03d",nControllerID);
		CString	strEventType;		strEventType.Format("%03d",nEventType);
		CString	strValue;			strValue.Format("%03d",lValue);

		CString	strTime=COleDateTime::GetCurrentTime().Format("%y-%m-%d %H:%M:%S");

		strControllerID=strControllerID+"    (ControllerID)";
		switch(nEventType)
		{
		case 1:
			{	
				strEventType=strEventType +"    (ConnectEvent)";
				if(lValue==0 ) strValue=strValue + "    Connected	与服务器建立连接";
				if(lValue==1 ) strValue=strValue + "    NormalDisconnection	正常断开";
				if(lValue==2 ) strValue=strValue + "    ServerCloseConnection	服务器关闭连接";
				if(lValue==3 ) strValue=strValue + "    ServerStop	服务器停止";
				if(lValue==4 ) strValue=strValue + "    ErrorSendingMessage	";
				if(lValue==5 ) strValue=strValue + "    ErrorReceivingMessage	";
				if(lValue==6 ) strValue=strValue + "    ErrorUsernameOrPwd	服务器拒绝(用户名或口令错)";
				if(lValue==10) strValue=strValue + "    服务器与控制器通讯停止";
				if(lValue==11) strValue=strValue + "    控制器无应答（通讯异常）";
				if(lValue==12) strValue=strValue + "    服务器与控制器通讯正常";
				if(lValue==-1) strValue=strValue + "    Unknown	异常(失控)";

				m_strConnectState=strValue;
				UpdateData(false);
				return;
			}
			break;
		case 2:
			{
				strEventType=strEventType +"    (ControllerEvent)";
				if(lValue==0	) strValue=strValue + "    ";
				if(lValue==1	) strValue=strValue + "    ";
				if(lValue==2	) strValue=strValue + "    ";
				if(lValue==3	) strValue=strValue + "    ";
				if(lValue==4	) strValue=strValue + "    ";

				if(lValue==11	) strValue=strValue + "    控制器复位";
				if(lValue==12	) strValue=strValue + "    控制器状态";
				if(lValue==13	) strValue=strValue + "    控制器消音";
			}
			break;
		case 3:
			{
				strEventType=strEventType +"    (DownloadEvent)";
				strValue.Format("left: %d kbyte",lValue);
			}
			break;
		default:
			{

			}
			break;
		}

	if(m_bShowSystem)
	{
		m_listResult.InsertString(0,"");
		m_listResult.InsertString(0,strValue);
		m_listResult.InsertString(0,strEventType );
		m_listResult.InsertString(0,strControllerID );
		m_listResult.InsertString(0,strTime +": OnFireSystemEvent");
	}
	
}
void CGstFireApiTestDlg::OnFireDeviceEvent(SHORT nControllerID, CString strDeviceId, CString strDescription, SHORT nStatus, CString strDeviceTypeName, CString strZoneDescription, CString strDeviceLoopCode, SHORT nDevProperty)
{
	if(m_bShowDevice)
	{

		CString	strControllerID;	strControllerID.Format("%03d",nControllerID);
		CString	strStatus;			strStatus=GetDeviceStatus(nStatus);
		CString	strDevProperty;		strDevProperty.Format("%03d",nDevProperty);

		CString	strTime=COleDateTime::GetCurrentTime().Format("%y-%m-%d %H:%M:%S");
		m_listResult.InsertString(0,"");
		m_listResult.InsertString(0,strDevProperty );
		m_listResult.InsertString(0,strDeviceLoopCode );
		m_listResult.InsertString(0,strZoneDescription );
		m_listResult.InsertString(0,strDeviceTypeName );
		m_listResult.InsertString(0,strStatus );
		m_listResult.InsertString(0,strDescription );
		m_listResult.InsertString(0,strDeviceId );
		m_listResult.InsertString(0,strControllerID );
		m_listResult.InsertString(0,strTime + ": OnFireDeviceEvent");
	}

	Json::Value root;
	root["info"] = "OnFireDeviceEvent";
	root["nControllerID"] = nControllerID;
	root["strDeviceId"] = (LPCTSTR)strDeviceId;
	root["strDescription"] = (LPCTSTR)strDescription;
	root["nStatus"] = nStatus;
	root["strDeviceTypeName"] = (LPCTSTR)strDeviceTypeName;
	root["strZoneDescription"] = (LPCTSTR)strZoneDescription;
	root["strDeviceLoopCode"] = (LPCTSTR)strDeviceLoopCode;
	root["nDevProperty"] = nDevProperty;

	Json::FastWriter wt;
	CString strSend = wt.write(root).c_str();

	m_Sock.SendTo((LPCTSTR)strSend, strSend.GetLength(), 10666, "127.0.0.1");

}

void CGstFireApiTestDlg::OnFireCommandEvent( SHORT nControllerId, BSTR bstrCommandName, LONG lValue)
{
	if(m_bShowCommand)
	{
		CString	strControllerId;	strControllerId.Format("%03d",nControllerId);
		CString	strCommandName;		strCommandName=bstrCommandName;
		CString	strStatus;			strStatus=GetCommandReply(lValue);

		CString	strTime=COleDateTime::GetCurrentTime().Format("%y-%m-%d %H:%M:%S");
		m_listResult.InsertString(0,"");
		m_listResult.InsertString(0,strStatus );
		m_listResult.InsertString(0,strCommandName );
		m_listResult.InsertString(0,strControllerId );
		m_listResult.InsertString(0,strTime + ": OnFireCommandEvent");
	}
}

CString CGstFireApiTestDlg::GetDeviceStatus(SHORT nStatus)
{
	CString strStatus;
	strStatus.Format("%03d  ",nStatus);

	if(strStatus==20) strStatus+="AE_DeviceRestore";	//设备恢复.
	if(strStatus==21) strStatus+="AE_DeviceAlarm";		//设备报警.
	if(strStatus==22) strStatus+="AE_DeviceStart";		//设备启动.
	if(strStatus==23) strStatus+="AE_DeviceStop";		//设备停止.
	if(strStatus==24) strStatus+="AE_DeviceAction";		//设备动作.

	if(strStatus==30) strStatus+="AE_DeviceFault";		//设备故障.(原10)
	if(strStatus==31) strStatus+="AE_DeviceIsolate";	//设备隔离.
	if(strStatus==32) strStatus+="AE_DeviceRelease";	//设备释放.

	return strStatus;
}


CString CGstFireApiTestDlg::GetCommandReply(LONG lValue)
{

	CString strStatus;
	strStatus.Format("%03d  ",lValue);

	if(lValue == 0 ) strStatus += "(RET_Successful		成功)";
	if(lValue == 1 ) strStatus += "(RET_Busy			控制器忙)";
	if(lValue == 2 ) strStatus += "(RET_ParamInvalide	参数非法)";
	if(lValue == 3 ) strStatus += "(RET_ShakeHandFail	握手失败)";
	if(lValue == 4 ) strStatus += "(RET_GstComError		内部错误)";
	if(lValue == 5 ) strStatus += "(RET_ReplyError		应答错误)";
	if(lValue == 6 ) strStatus += "(RET_ReplyTimeout	应答超时)";
	if(lValue == 10) strStatus += "(RET_Rs232Error		串口失败)";
	if(lValue ==255) strStatus += "(RET_NOTCommand		协议里没有此命令)";

	return strStatus;
}



void CGstFireApiTestDlg::OnBtnClear() 
{

	UpdateData();
	long lResult;
	m_IGstFireApiCtl->ClearController(m_nControllerId,&lResult);
	
}

void CGstFireApiTestDlg::OnBtnReset() 
{
	UpdateData();
	long lResult;
	m_IGstFireApiCtl->ResetController(m_nControllerId,&lResult);
	
	
}

void CGstFireApiTestDlg::OnBtnMute() 
{
	UpdateData();
	long lResult;
	m_IGstFireApiCtl->MuteController(m_nControllerId,0,&lResult);
	
}

void CGstFireApiTestDlg::OnBtnSetTime() 
{
	UpdateData();
	long lResult;
	m_IGstFireApiCtl->SetFireSystemTime(m_nControllerId,&lResult);
	
}

void CGstFireApiTestDlg::OnBtnSetState() 
{
	UpdateData();
	long lResult;
	m_IGstFireApiCtl->SetControllerState(m_nControllerId,m_bAuto,m_bManual,m_bSpurt,&lResult);
	
	
}

void CGstFireApiTestDlg::OnBtnSetDeviceState() 
{
	UpdateData();
	long lResult;
	int nState=m_cboDeviceState.GetCurSel();
	m_IGstFireApiCtl->SetDeviceState(m_nControllerId,m_strDeviceId.AllocSysString(),nState,&lResult);
 
}

void CGstFireApiTestDlg::OnBtnLogClear() 
{
	m_listResult.ResetContent();
	
}

void CGstFireApiTestDlg::OnChkSystem() 
{
	UpdateData();
	
}

void CGstFireApiTestDlg::OnChkDevice() 
{
	UpdateData();
}

void CGstFireApiTestDlg::OnChkCommand() 
{
	UpdateData();
	
}

