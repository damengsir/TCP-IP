// testtransferDlg.h : header file
//

#if !defined(AFX_TESTTRANSFERDLG_H__DB4F537F_E2FC_465F_B00B_0837F94CF90C__INCLUDED_)
#define AFX_TESTTRANSFERDLG_H__DB4F537F_E2FC_465F_B00B_0837F94CF90C__INCLUDED_

#include "TestSocket.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTesttransferDlg dialog

class CTesttransferDlg : public CDialog
{
// Construction
public:
	void AddRecData(char* pstr);
	int m_iState;
	void SetConnectState(int istate);
	void EnableSend(int ienable);
	CTestSocket m_sock;
	CTesttransferDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTesttransferDlg)
	enum { IDD = IDD_TESTTRANSFER_DIALOG };
	CString	m_strEditIP;
	int		m_iEditPort;
	CString	m_strEditRec;
	CString	m_strEditSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttransferDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTesttransferDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTRANSFERDLG_H__DB4F537F_E2FC_465F_B00B_0837F94CF90C__INCLUDED_)
