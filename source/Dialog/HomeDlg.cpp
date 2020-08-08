
// HomeDlg.cpp : implementation file
//

#include "pch.h"
#include "HomeDlg.h"
#include "StudentDataDlg.h"

#include "afxdialogex.h"

#include "Utils/Texts.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CHomeDlg dialog



CHomeDlg::CHomeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHomeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CHomeDlg::LoadText()
{
	CFont font;
	font.CreateFont(
		12,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial"));              // lpszFacename

	GetDlgItem(IDC_TEXT_HOME_TITLE)->SetFont(&font);
	GetDlgItem(IDC_TEXT_HOME_TITLE)->SetWindowTextW(Texts::GetStringL("STR_HOME_TITLE"));
	GetDlgItem(IDC_TEXT_TITLE_SCHOOL_NAME)->SetWindowTextW(Texts::GetStringL("STR_SCHOOL_NAME"));
	GetDlgItem(IDC_GROUP_MAINMENU)->SetWindowTextW(Texts::GetStringL("STR_MAIN_MENU"));
	GetDlgItem(IDC_BTN_STUDENT_DB_MENU)->SetWindowTextW(Texts::GetStringL("STR_DB_STUDENT"));
	GetDlgItem(IDC_BTN_CLASS_DB_MENU)->SetWindowTextW(Texts::GetStringL("STR_DB_CLASS"));
	GetDlgItem(IDC_BTN_EMPLOYEE_DB_MENU)->SetWindowTextW(Texts::GetStringL("STR_DB_EMPLOYEE"));
	GetDlgItem(IDC_BTN_COURSE_DB_MENU)->SetWindowTextW(Texts::GetStringL("STR_DB_COURSE"));
	GetDlgItem(IDC_BTN_INVENTORY_DB_MENU)->SetWindowTextW(Texts::GetStringL("STR_DB_INVENTORY"));
}

BEGIN_MESSAGE_MAP(CHomeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_STUDENT_DB_MENU, &CHomeDlg::OnBnClickedBtnStudentDbMenu)
END_MESSAGE_MAP()


// CHomeDlg message handlers

BOOL CHomeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	CString appTitle, tmp;
	ASSERT(tmp.LoadString(IDS_APP_NAME));

	appTitle.Append(tmp);
	appTitle.Append(L" - ver ");
	ASSERT(tmp.LoadString(IDS_APP_VERSION));

	appTitle.Append(tmp);
	SetWindowText(appTitle);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	LoadText();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHomeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHomeDlg::OnPaint()
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
HCURSOR CHomeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHomeDlg::OnBnClickedBtnStudentDbMenu()
{
	CStudentDataDlg dlgStudentDB;
	dlgStudentDB.DoModal();
}
