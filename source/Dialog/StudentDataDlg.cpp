// StudentDataDlg.cpp : implementation file
//

#include "pch.h"
#include "StudentDataDlg.h"
#include "StudentRegisterDlg.h"
#include "afxdialogex.h"

#include "Data/Student.h"
#include "Utils/Texts.h"

// CStudentDataDlg dialog

IMPLEMENT_DYNAMIC(CStudentDataDlg, CDialogEx)

CStudentDataDlg::CStudentDataDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_DB, pParent)
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

}

CStudentDataDlg::~CStudentDataDlg()
{
	m_studentList.clear();
}

BOOL CStudentDataDlg::OnInitDialog()
{
	LoadText();
	
	return CDialogEx::OnInitDialog();
}

void CStudentDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDENT_LIST, m_studentListBox);
}

void CStudentDataDlg::LoadText()
{
	SetWindowText(Texts::GetStringL("STR_DB_STUDENT"));

	GetDlgItem(IDC_BTN_NEW)->SetWindowTextW(Texts::GetStringL("STR_NEW"));
	GetDlgItem(IDC_TEXT_STUDENT_NAME_LIST)->SetWindowTextW(Texts::GetStringL("STR_STUDENT_NAME_LIST"));
}


BEGIN_MESSAGE_MAP(CStudentDataDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_NEW, &CStudentDataDlg::OnBnClickedBtnNew)
END_MESSAGE_MAP()


// CStudentDataDlg message handlers


void CStudentDataDlg::OnBnClickedBtnNew()
{
	CStudentRegisterDlg reg;
	reg.DoModal();

	auto student = reg.GetData();
	m_studentList.push_back(student);
	m_studentListBox.AddString(Utillity::ToLPCTSTR(student->GetName()));
}
