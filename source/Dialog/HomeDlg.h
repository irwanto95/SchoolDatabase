
// HomeDlg.h : header file
//

#pragma once


// CHomeDlg dialog
class CHomeDlg : public CDialogEx
{
// Construction
public:
	CHomeDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOME_DIALOG };
#endif

	afx_msg void OnBnClickedBtnStudentDbMenu();

// Implementation
protected:
	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void LoadText();

protected:
	HICON m_hIcon;
};
