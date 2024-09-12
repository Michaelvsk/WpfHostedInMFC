
// MFCHostAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCHostApp.h"
#include "MFCHostAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace System;

// CMFCHostAppDlg dialog



CMFCHostAppDlg::CMFCHostAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCHOSTAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCHostAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCHostAppDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCHostAppDlg message handlers

BOOL CMFCHostAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CreateWpfControl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCHostAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCHostAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


///
/// WPF integration related stuff
/// 

void CMFCHostAppDlg::CreateWpfControl()
{
	RECT rect;
	this->GetClientRect(&rect);
	HWND parent = this->GetSafeHwnd();

	System::Windows::Interop::HwndSourceParameters^ sourceParams = gcnew System::Windows::Interop::HwndSourceParameters(
		"hi" // NAME
	);
	sourceParams->PositionX = rect.left;
	sourceParams->PositionY = rect.top;
	sourceParams->Width = rect.right;
	sourceParams->Height = rect.bottom;
	sourceParams->ParentWindow = System::IntPtr(parent);
	sourceParams->WindowStyle = WS_VISIBLE | WS_CHILD; // style
	System::Windows::Interop::HwndSource^ source = gcnew System::Windows::Interop::HwndSource(*sourceParams);

	MyWpfControl::UserControlWithTextbox^ wpfControl = gcnew MyWpfControl::UserControlWithTextbox();
	WPFPageHost::wpfControl = wpfControl;
	wpfControl->Width = rect.right;
	wpfControl->Height = rect.bottom;
	wpfControl->Focusable = true;
	source->RootVisual = wpfControl;

	wpfHwnd = (HWND)source->Handle.ToPointer();
}