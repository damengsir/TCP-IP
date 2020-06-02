// testtransferDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testtransfer.h"
#include "testtransferDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CTesttransferDlg dialog

CTesttransferDlg::CTesttransferDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTesttransferDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTesttransferDlg)
	m_strEditIP = _T("192.168.1.90");
	m_iEditPort = 50000;
	m_strEditRec = _T("");
	m_strEditSend = _T("1234567890");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTesttransferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTesttransferDlg)
	DDX_Text(pDX, IDC_EDIT_IP, m_strEditIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_iEditPort);
	DDX_Text(pDX, IDC_EDIT_REC, m_strEditRec);
	DDX_Text(pDX, IDC_EDIT_SEND, m_strEditSend);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTesttransferDlg, CDialog)
	//{{AFX_MSG_MAP(CTesttransferDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTesttransferDlg message handlers

BOOL CTesttransferDlg::OnInitDialog()
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
	m_sock.SetParent(this);
	SetConnectState(0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTesttransferDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTesttransferDlg::OnPaint() 
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
HCURSOR CTesttransferDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTesttransferDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();
}

void CTesttransferDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(m_iState!=0)
		SetConnectState(0);
	
	CDialog::OnCancel();
}

void CTesttransferDlg::OnButtonConnect() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_iState==1)//代表已连接
	{
		m_sock.EnableResend(0);
		m_sock.Close();
		SetConnectState(0);
	}
	else if(m_iState==0)
	{
		m_sock.Create();
		m_sock.EnableResend(0);
		SetConnectState(2);
		m_sock.Connect(m_strEditIP,m_iEditPort);
	}
	UpdateData(FALSE);
}

void CTesttransferDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	EnableSend(0);
	UpdateData(TRUE);
	LPTSTR pstr=m_strEditSend.GetBuffer(m_strEditSend.GetLength()+1);
	int res=m_sock.Send(pstr,m_strEditSend.GetLength()+1);
	if((res==SOCKET_ERROR&&m_sock.GetLastError()==WSAEWOULDBLOCK)||
		(res>0&&res<m_strEditSend.GetLength()+1))
	{
		m_sock.SetResend((BYTE*)(pstr+((res==-1)?0:res)),
			(m_strEditSend.GetLength()+1)-((res==-1)?0:res));
	}
	else if(res==SOCKET_ERROR&&m_sock.GetLastError()!=WSAEWOULDBLOCK)
	{
		MessageBox("发送失败");
		EnableSend(1);
	}
	else
		EnableSend(1);
	m_strEditSend.ReleaseBuffer();
	UpdateData(FALSE);
}

void CTesttransferDlg::EnableSend(int ienable)
{
	GetDlgItem(IDC_BUTTON_SEND)->EnableWindow(ienable);
}

//0连接断开，1已连接，2正在连接
void CTesttransferDlg::SetConnectState(int istate)
{
	switch(istate)
	{
	case 0:
		{
			GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText("连接");
			GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(TRUE);
			EnableSend(0);
		}
		break;
	case 1:
		{
			GetDlgItem(IDC_BUTTON_CONNECT)->SetWindowText("断开");
			GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(TRUE);
			EnableSend(1);
		}
		break;
	case 2:
		{
			GetDlgItem(IDC_BUTTON_CONNECT)->EnableWindow(FALSE);
			EnableSend(0);
		}
		break;
	}
	m_iState=istate;
}

void CTesttransferDlg::AddRecData(char *pstr)
{
	UpdateData(TRUE);
	m_strEditRec+=pstr;
	UpdateData(FALSE);
}
