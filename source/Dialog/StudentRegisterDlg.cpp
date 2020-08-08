// D:\Projects\Apps_Win\SchoolDatabase\trunk\source\Dialog\StudentRegisterDlg.cpp : implementation file
//

#include "pch.h"
#include "StudentRegisterDlg.h"
#include "afxdialogex.h"

#include "Data/Student.h"
#include "Utils/Texts.h"

// CStudentRegisterDlg dialog

IMPLEMENT_DYNAMIC(CStudentRegisterDlg, CDialogEx)

CStudentRegisterDlg::CStudentRegisterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_REGISTER, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
}

CStudentRegisterDlg::~CStudentRegisterDlg()
{
	m_pStudent.reset();
}

BOOL CStudentRegisterDlg::OnInitDialog()
{
	LoadText();

	return CDialogEx::OnInitDialog();
}

void CStudentRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT_NAME, m_inName);
	DDX_Control(pDX, IDC_INPUT_BIRTH_PLACE, m_inBirthPlace);
	DDX_Control(pDX, IDC_INPUT_DATE, m_inBirthDate);
}

void CStudentRegisterDlg::LoadText()
{
	GetDlgItem(IDC_TEXT_NAME)->SetWindowTextW(Texts::GetStringL("STR_NAME"));
	GetDlgItem(IDC_TEXT_BIRTH_PLACE)->SetWindowTextW(Texts::GetStringL("STR_BIRTH_PLACE"));
	GetDlgItem(IDC_TEXT_BIRTH_DATE)->SetWindowTextW(Texts::GetStringL("STR_BIRTH_DATE"));
}


BEGIN_MESSAGE_MAP(CStudentRegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStudentRegisterDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStudentRegisterDlg message handlers


void CStudentRegisterDlg::OnBnClickedOk()
{
	CString name, birthPlace;
	m_inName.GetWindowTextW(name);
	m_inBirthPlace.GetWindowTextW(birthPlace);

	CTime date;
	m_inBirthDate.GetTime(date);

	string nameStr = CW2A(name);
	m_pStudent = make_shared<Student>(nameStr.c_str(), "Laki");
	
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
