// GstFireApiTest.h : main header file for the GSTFIREAPITEST application
//

#if !defined(AFX_GSTFIREAPITEST_H__E1C74777_5FBD_4A8D_BE22_F733F064004D__INCLUDED_)
#define AFX_GSTFIREAPITEST_H__E1C74777_5FBD_4A8D_BE22_F733F064004D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "GstFireApiTest_i.h"

/////////////////////////////////////////////////////////////////////////////
// CGstFireApiTestApp:
// See GstFireApiTest.cpp for the implementation of this class
//

class CGstFireApiTestApp : public CWinApp
{
public:
	CGstFireApiTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGstFireApiTestApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGstFireApiTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GSTFIREAPITEST_H__E1C74777_5FBD_4A8D_BE22_F733F064004D__INCLUDED_)
