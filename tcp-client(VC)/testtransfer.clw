; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestSocket
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "testtransfer.h"

ClassCount=4
Class1=CTesttransferApp
Class2=CTesttransferDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CTestSocket
Resource3=IDD_TESTTRANSFER_DIALOG

[CLS:CTesttransferApp]
Type=0
HeaderFile=testtransfer.h
ImplementationFile=testtransfer.cpp
Filter=N

[CLS:CTesttransferDlg]
Type=0
HeaderFile=testtransferDlg.h
ImplementationFile=testtransferDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CTesttransferDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=testtransferDlg.h
ImplementationFile=testtransferDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTTRANSFER_DIALOG]
Type=1
Class=CTesttransferDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_IP,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_PORT,edit,1350631552
Control5=IDC_BUTTON_CONNECT,button,1342242816
Control6=IDC_EDIT_SEND,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_BUTTON_SEND,button,1342242816
Control9=IDC_EDIT_REC,edit,1352728580
Control10=IDC_STATIC,button,1342177287

[CLS:CTestSocket]
Type=0
HeaderFile=TestSocket.h
ImplementationFile=TestSocket.cpp
BaseClass=CAsyncSocket
Filter=N
VirtualFilter=q
LastObject=CTestSocket

