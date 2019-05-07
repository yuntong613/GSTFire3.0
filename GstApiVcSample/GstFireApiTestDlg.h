// GstFireApiTestDlg.h : header file
//

#if !defined(AFX_GSTFIREAPITESTDLG_H__1A3958EC_259B_40FA_9C35_934F88F4555F__INCLUDED_)
#define AFX_GSTFIREAPITESTDLG_H__1A3958EC_259B_40FA_9C35_934F88F4555F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGstFireApiTestDlg dialog
#include "GstFireApi.h"
#include "GstFireApiEventSink.h"

class CGstFireApiTestDlg : public CDialog
{
// Construction
public:
	CGstFireApiTestDlg(CWnd* pParent = NULL);	// standard constructor

	CSocket m_Sock;
/*=====Add By Wzc=====Start*/
/*2005.4.22 13:56*/
	IGstFireApiCtl*	m_IGstFireApiCtl;
    CGstFireApiEventSink*	m_pGstFireApiEventSink;
    IUnknown* m_pControlUnk;
/*=====Add By Wzc=====End*/

		 
	void OnFireCommandEvent( SHORT nControllerId, BSTR bstrCommandName, LONG lValue);
    void OnFireSystemEvent(SHORT nControllerID, SHORT nEventType, LONG lValue);
	void OnFireDeviceEvent(SHORT nControllerID, CString bstrDeviceId, CString bstrDescription, SHORT nStatus, CString bstrDeviceTypeName, CString bstrZoneDescription, CString bstrDeviceLoopCode, SHORT nDevProperty);
	CString GetDeviceStatus(SHORT nStatus);
	CString GetCommandReply(LONG lValue);



// Dialog Data
	//{{AFX_DATA(CGstFireApiTestDlg)
	enum { IDD = IDD_GSTFIREAPITEST_DIALOG };
	CComboBox	m_cboDeviceState;
	CListBox	m_listResult;
	long	m_lReserved;
	CString	m_strServerIP;
	CString	m_strConnectState;
	CString	m_strPassword;
	CString	m_strReserved;
	CString	m_strUserName;
	BOOL	m_bAuto;
	BOOL	m_bManual;
	BOOL	m_bSpurt;
	int		m_nControllerId;
	CString	m_strDeviceId;
	BOOL	m_bShowCommand;
	BOOL	m_bShowDevice;
	BOOL	m_bShowSystem;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGstFireApiTestDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGstFireApiTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnConnect();
	afx_msg void OnBtnDisconnect();
	afx_msg void OnBtnClear();
	afx_msg void OnBtnReset();
	afx_msg void OnBtnMute();
	afx_msg void OnBtnSetTime();
	afx_msg void OnBtnSetState();
	afx_msg void OnBtnSetDeviceState();
	afx_msg void OnBtnLogClear();
	afx_msg void OnChkSystem();
	afx_msg void OnChkDevice();
	afx_msg void OnChkCommand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GSTFIREAPITESTDLG_H__1A3958EC_259B_40FA_9C35_934F88F4555F__INCLUDED_)
