// testtransfer.h : main header file for the TESTTRANSFER application
//

#if !defined(AFX_TESTTRANSFER_H__573B0C2C_1F83_44DF_B8B2_F5F8B169A73C__INCLUDED_)
#define AFX_TESTTRANSFER_H__573B0C2C_1F83_44DF_B8B2_F5F8B169A73C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTesttransferApp:
// See testtransfer.cpp for the implementation of this class
//

class CTesttransferApp : public CWinApp
{
public:
	CTesttransferApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttransferApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTesttransferApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTRANSFER_H__573B0C2C_1F83_44DF_B8B2_F5F8B169A73C__INCLUDED_)
