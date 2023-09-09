
// calculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include <sstream>

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


// CcalculatorDlg dialog



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_text(_T("0"))
	, m_text2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT, m_text);
	DDX_Text(pDX, IDC_TEXT2, m_text2);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_WM_CHAR()
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CcalculatorDlg::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CcalculatorDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CcalculatorDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CcalculatorDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CcalculatorDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CcalculatorDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CcalculatorDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CcalculatorDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CcalculatorDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CcalculatorDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CcalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CcalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CcalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CcalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CcalculatorDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CcalculatorDlg::OnBnClickedButtonEqual)
	ON_WM_CHAR()
//	ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// CcalculatorDlg message handlers

BOOL CcalculatorDlg::OnInitDialog()
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	 //TODO: Add extra initialization here
	m_font.CreatePointFont(200, _T("Arial"));             // lpszFacename
	m_font2.CreatePointFont(150, _T("Arial"));

	GetDlgItem(IDC_TEXT)->SetFont(&m_font,true);
	GetDlgItem(IDC_TEXT2)->SetFont(&m_font2);

	init();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CcalculatorDlg::OnPaint()
{
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalculatorDlg::init() {
	m_result = 0;
	m_preNum = 0;
	m_operation = 0;
	m_status = 1;
	m_text2 = _T("");
	m_text = _T("0");
	m_hasDP = false;
}

void CcalculatorDlg::addNumber(CString num){
	if (m_status) {
		m_text = num;
		m_status = 0;
	}
	else {
		m_text += num;
	}
}

bool CcalculatorDlg::isNumber(CString& s) {
	CStringA temp(s.GetBuffer(0));
	s.ReleaseBuffer();
	std::string str = temp.GetBuffer(0);
	temp.ReleaseBuffer();
	std::istringstream iss(str);
	double value;
	iss >> std::noskipws >> value;  // Use noskipws to prevent skipping white spaces

	// Check if the entire string was consumed by the conversion and there's no trailing characters
	return iss.eof() && !iss.fail();
}

void CcalculatorDlg::operationFunc(int index){

	if (!isNumber(m_text)) {
		m_text = _T("0");
		UpdateData(FALSE);
		return;
	}
	m_preNum = _tstof(m_text);
	m_status = 1;
	m_hasDP = 0;
	m_operation = index;
	m_text2 = m_text;
	switch (index) {
	case 0:
		m_text2 += _T("+");
		break;
	case 1:
		m_text2 += _T("-");
		break;
	case 2:
		m_text2 += _T("*");
		break;
	case 3:
		m_text2 += _T("/");
		break;
	}
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonZero()
{
	// TODO: Add your control notification handler code here

	//CStringA temp(m_text.GetBuffer(0));
	//m_text.ReleaseBuffer();
	//std::string str = temp.GetBuffer(0);
	//temp.ReleaseBuffer();
	CString s("0");
	if (m_text.GetLength() == 1 && _ttoi(m_text) == 0) {
		return;
	}
	if (m_status) {
		m_text = s;
	}
	else {
		m_text += s;
	}

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonOne()
{
	// TODO: Add your control notification handler code here
	CString s("1");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonTwo()
{
	// TODO: Add your control notification handler code here
	CString s("2");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonThree()
{
	// TODO: Add your control notification handler code here
	CString s("3");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonFour()
{
	// TODO: Add your control notification handler code here
	CString s("4");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonFive()
{
	// TODO: Add your control notification handler code here
	CString s("5");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonSix()
{
	// TODO: Add your control notification handler code here
	CString s("6");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonSeven()
{
	// TODO: Add your control notification handler code here
	CString s("7");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonEight()
{
	// TODO: Add your control notification handler code here
	CString s("8");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNine()
{
	// TODO: Add your control notification handler code here
	CString s("9");
	addNumber(s);

	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: Add your control notification handler code here
	if (m_hasDP) {
		return;
	}
	if (m_status) {
		m_status = 0;
	}
	CString s(".");
	m_text += s;
	UpdateData(FALSE);
	m_hasDP = true;
}

void CcalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: Add your control notification handler code here
	operationFunc(0);
}


void CcalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: Add your control notification handler code here
	operationFunc(1);
}


void CcalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: Add your control notification handler code here
	operationFunc(2);
}


void CcalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: Add your control notification handler code here
	operationFunc(3);
}


void CcalculatorDlg::OnBnClickedButtonReset()
{
	// TODO: Add your control notification handler code here
	init();
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: Add your control notification handler code here
	if (!isNumber(m_text)) {
		m_text = _T("0");
		UpdateData(FALSE);
		return;
	}
	double curr= _tstof(m_text);
	m_text2 += m_text;
	m_text2 += _T("=");
	switch (m_operation) {
	case 0:
		m_result = curr + m_preNum;
		m_text = std::to_string(m_result).c_str();
		break;
	case 1:
		m_result =  m_preNum - curr;
		m_text = std::to_string(m_result).c_str();
		break;
	case 2:
		m_result = curr * m_preNum;
		m_text = std::to_string(m_result).c_str();
		break;
	case 3:
		if (curr == 0.0) {
			m_text = _T("除数不能为零");
			m_result = 0;
			m_preNum = 0;
			m_text2 = _T("");
			break;
		}
		m_status = 1;
		m_hasDP = false;
		m_operation = 0;
		m_result = m_preNum/curr;
		m_text = std::to_string(m_result).c_str();
		break;
	}
	m_operation = 0;
	m_status = 1;
	UpdateData(FALSE);
}

void CcalculatorDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	 //TODO: Add your message handler code here and/or call default
	switch (nChar) {
	case '0':
		OnBnClickedButtonZero();
		break;
	case '1':
		OnBnClickedButtonOne();
		break;
	case '2':
		OnBnClickedButtonTwo();
		break;
	case '3':
		OnBnClickedButtonThree();
		break;
	case '4':
		OnBnClickedButtonFour();
		break;
	case '5':
		OnBnClickedButtonFive();
		break;
	case '6':
		OnBnClickedButtonSix();
		break;
	case '7':
		OnBnClickedButtonSeven();
		break;
	case '8':
		OnBnClickedButtonEight();
		break;
	case '9':
		OnBnClickedButtonNine();
		break;
	case '.':
		OnBnClickedButtonDot();
		break;
	case 8:
		OnBnClickedButtonReset();
		break;
	case '+':
		OnBnClickedButtonPlus();
		break;
	case '-':
		OnBnClickedButtonMinus();
		break;
	case '*':
		OnBnClickedButtonMultiply();
		break;
	case '/':
		OnBnClickedButtonDivide();
		break;
	case '=':
		OnBnClickedButtonEqual();
		break;
	}
}



BOOL CcalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
	return CDialogEx::PreTranslateMessage(pMsg);
}
