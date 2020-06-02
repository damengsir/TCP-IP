#if !defined(AFX_TESTSOCKET_H__3F8F2AA2_0927_4DEE_AF57_24B24C78521D__INCLUDED_)
#define AFX_TESTSOCKET_H__3F8F2AA2_0927_4DEE_AF57_24B24C78521D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CTestSocket command target
class CTesttransferDlg;

class CTestSocket : public CAsyncSocket
{
// Attributes
public:
	CTesttransferDlg* m_pdlg;
	BYTE* m_pResendBuf;//�ط����ݻ�����
	int m_iResendlen;//�ط����ݳ���
	int m_iResendLeft;//ʣ���ط����ݳ���
	BYTE m_bResend;//�Ƿ���Ҫ�ط�

// Operations
public:
	void EnableResend(BYTE bSend) {m_bResend=bSend;}
	CTestSocket();
	virtual ~CTestSocket();

// Overrides
public:
	void SetResend(BYTE* pbuf,int len);
	void SetParent(CTesttransferDlg* pdlg);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestSocket)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CTestSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTSOCKET_H__3F8F2AA2_0927_4DEE_AF57_24B24C78521D__INCLUDED_)
