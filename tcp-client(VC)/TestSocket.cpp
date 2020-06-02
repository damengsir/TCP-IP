// TestSocket.cpp : implementation file
//

#include "stdafx.h"
#include "testtransfer.h"
#include "TestSocket.h"
#include "testtransferDlg.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestSocket

CTestSocket::CTestSocket()
{
	m_pResendBuf=NULL;
	m_iResendlen=0;
	m_bResend=0;
}

CTestSocket::~CTestSocket()
{
	if(m_pResendBuf!=NULL)
		delete []m_pResendBuf;
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CTestSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CTestSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CTestSocket member functions

void CTestSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	Close();
	m_pdlg->SetConnectState(0);
	
	CAsyncSocket::OnClose(nErrorCode);
}

void CTestSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		m_pdlg->SetConnectState(1);
	}
	else
	{
		m_pdlg->SetConnectState(0);
		Close();
		m_pdlg->MessageBox("¡¨Ω” ß∞‹");
	}
	CAsyncSocket::OnConnect(nErrorCode);
}


void CTestSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode==0)
	{
		BYTE buffer[1025]={0};
		int res=Receive(buffer,1024);
		string as;

		char const hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B','C','D','E','F' };
		for (int i = 0; i < 9; ++i) {
			const char ch = buffer[i];
			as.append(&hex[(ch & 0xF0) >> 4], 1);
			as.append(&hex[ch & 0xF], 1);
		}

		if(res>0)
		{
			/*buffer[res]=0;
			m_pdlg->AddRecData((char*)buffer);*/
			//as[res] = 0;
			m_pdlg->AddRecData((char*)as.c_str());
		}
	}
	
	CAsyncSocket::OnReceive(nErrorCode);
}

void CTestSocket::SetParent(CTesttransferDlg *pdlg)
{
	m_pdlg=pdlg;
}

void CTestSocket::SetResend(BYTE *pbuf, int len)
{
	if(m_pResendBuf!=NULL)
		delete []m_pResendBuf;
	m_pResendBuf=new BYTE[len];
	memcpy(m_pResendBuf,pbuf,len);
	m_iResendlen=len;
	m_iResendLeft=len;
}

void CTestSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(m_bResend==1&&m_pResendBuf!=NULL&&m_iResendlen>0)
	{
		int res=Send(m_pResendBuf+(m_iResendlen-m_iResendLeft),m_iResendLeft);
		if(res==SOCKET_ERROR)
		{
			if(GetLastError()!=WSAEWOULDBLOCK)
			{
				Close();
				m_pdlg->SetConnectState(0);
				m_pdlg->MessageBox("∑¢ÀÕ ß∞‹");
			}
		}
		else
		{
			m_iResendLeft-=res;
			if(m_iResendLeft==0)
			{
				EnableResend(0);
				m_pdlg->EnableSend(1);
				delete []m_pResendBuf;
				m_pResendBuf=NULL;
				m_iResendlen=0;
			}
		}
	}
	CAsyncSocket::OnSend(nErrorCode);
}
