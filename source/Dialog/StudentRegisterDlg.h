#pragma once

class Student;
MAKE_SHARED(Student);

// CStudentRegisterDlg dialog

class CStudentRegisterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentRegisterDlg)

public:

	CStudentRegisterDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStudentRegisterDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_REGISTER };
#endif

	StudentPtr GetData() { return m_pStudent; };

	afx_msg void OnBnClickedOk();

protected:
	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	void LoadText();

private:
	// Name input by user
	CEdit m_inName;
	CEdit m_inBirthPlace;
	CDateTimeCtrl m_inBirthDate;

	StudentPtr m_pStudent;
};
