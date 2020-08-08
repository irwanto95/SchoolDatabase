#pragma once

class Student;
MAKE_SHARED(Student);
// CStudentDataDlg dialog

class CStudentDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentDataDlg)

public:
	LISTV(StudentPtr) StudentList;

	CStudentDataDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStudentDataDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_DB };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	void LoadText();

private:
	// List of student data's text
	CListBox	m_studentListBox;
	StudentList m_studentList;

public:
	afx_msg void OnBnClickedBtnNew();
};
