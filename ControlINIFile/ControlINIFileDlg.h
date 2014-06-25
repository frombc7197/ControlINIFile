
// ControlINIFileDlg.h : header file
//

#pragma once


// CControlINIFileDlg dialog
class CControlINIFileDlg : public CDialogEx
{
// Construction
public:
	CControlINIFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CONTROLINIFILE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonSave();
	CString m_edit1;
	CString m_edit2;
	CString m_edit3;
	CString m_edit4;
	afx_msg void OnBnClickedButtonLoad();
	CString m_static1;
	CString m_static2;
	CString m_static3;
};
