
// MFCHostAppDlg.h : header file
//

#pragma once


// CMFCHostAppDlg dialog
class CMFCHostAppDlg : public CDialogEx
{
// Construction
public:
	CMFCHostAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCHOSTAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	HWND wpfHwnd;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void CreateWpfControl();
	DECLARE_MESSAGE_MAP()
};

public ref class WPFPageHost
{
public:
	WPFPageHost() {};
	static MyWpfControl::UserControlWithTextbox^ wpfControl;
	//initial property settings
	static System::Windows::Media::Brush^ initBackBrush;
	static System::Windows::Media::Brush^ initForeBrush;
	static System::Windows::Media::FontFamily^ initFontFamily;
	static System::Windows::FontStyle initFontStyle;
	static System::Windows::FontWeight initFontWeight;
	static double initFontSize;
};
