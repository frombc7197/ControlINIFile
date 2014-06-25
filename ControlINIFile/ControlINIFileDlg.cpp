
// ControlINIFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ControlINIFile.h"
#include "ControlINIFileDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CControlINIFileDlg dialog



CControlINIFileDlg::CControlINIFileDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControlINIFileDlg::IDD, pParent)
	, m_edit1(_T(""))
	, m_edit2(_T(""))
	, m_edit3(_T(""))
	, m_edit4(_T(""))
	, m_static1(_T(""))
	, m_static2(_T(""))
	, m_static3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlINIFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	DDX_Text(pDX, IDC_STATIC1, m_static1);
	DDX_Text(pDX, IDC_STATIC2, m_static2);
	DDX_Text(pDX, IDC_STATIC3, m_static3);
}

BEGIN_MESSAGE_MAP(CControlINIFileDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CControlINIFileDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CControlINIFileDlg::OnBnClickedButtonLoad)
END_MESSAGE_MAP()


// CControlINIFileDlg message handlers

BOOL CControlINIFileDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CControlINIFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CControlINIFileDlg::OnPaint()
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
HCURSOR CControlINIFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlINIFileDlg::OnBnClickedButtonSave()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	CString szFilename;
	CString szData1;
	CString szData2;
	CString szData3;
	TCHAR szPath[_MAX_PATH];
	
	GetModuleFileName(NULL,szPath,sizeof(szPath));
	szFilename.Format(_T("%s"),szPath);
	int i = szFilename.ReverseFind(_T('.'));
	szFilename = szFilename.Left(i);
	szFilename.Append(_T(".ini"));
	
	szData1 = m_edit1.GetBuffer();
	szData2 = m_edit2.GetBuffer();
	szData3 = m_edit3.GetBuffer();

	WritePrivateProfileString(_T("DATA"),_T("Data1"),szData1,szFilename);
	WritePrivateProfileString(_T("DATA"),_T("Data2"),szData2,szFilename);
	WritePrivateProfileString(_T("DATA2"),_T("Data3"),szData3,szFilename);
}


void CControlINIFileDlg::OnBnClickedButtonLoad()
{
	// TODO: Add your control notification handler code here
	CString szFilename;
	CString szData1;
	CString szData2;
	CString szData3;
	CString szSection, szKey, szValue;
	TCHAR szBUF[MAX_PATH]={0,};
	TCHAR szPath[_MAX_PATH];

	GetModuleFileName(NULL,szPath,sizeof(szPath));
	szFilename.Format(_T("%s"),szPath);
	int i = szFilename.ReverseFind(_T('.'));
	szFilename = szFilename.Left(i);
	szFilename.Append(_T(".ini"));

	szSection = _T("DATA");
	szKey = _T("DATA1");
	GetPrivateProfileString(szSection,szKey,_T(""),szBUF,MAX_PATH,szFilename);
	szData1.Format(_T("%s"),szBUF);
	szKey = _T("DATA2");
	GetPrivateProfileString(szSection,szKey,_T(""),szBUF,MAX_PATH,szFilename);
	szData2.Format(_T("%s"),szBUF);

	szSection = _T("DATA2");
	szKey = _T("DATA3");
	GetPrivateProfileString(szSection,szKey,_T(""),szBUF,MAX_PATH,szFilename);
	szData3.Format(_T("%s"),szBUF);


	m_static1 = szData1.GetBuffer(); 
	m_static2 = szData2.GetBuffer(); 
	m_static3 = szData3.GetBuffer(); 

	UpdateData(FALSE);
}
