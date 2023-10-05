
// calculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include"CalculatorModel.h"
#include <iostream>
#include <string>
#include <sstream>
#include <gdiplus.h>
#include <afxwin.h>
using namespace Gdiplus;

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
	CString s0("0");
	m_btnNumberZero.item = new NumberItem(s0);
	CString s1("1");
	m_btnNumberOne.item = new NumberItem(s1);
	CString s2("2");
	m_btnNumberTwo.item = new NumberItem(s2);
	CString s3("3");
	m_btnNumberThree.item = new NumberItem(s3);
	CString s4("4");
	m_btnNumberFour.item = new NumberItem(s4);
	CString s5("5");
	m_btnNumberFive.item = new NumberItem(s5);
	CString s6("6");
	m_btnNumberSix.item = new NumberItem(s6);
	CString s7("7");
	m_btnNumberSeven.item = new NumberItem(s7);
	CString s8("8");
	m_btnNumberEight.item = new NumberItem(s8);
	CString s9("9");
	m_btnNumberNine.item = new NumberItem(s9);
	CalculatorModel::OPARATION op= CalculatorModel::PLUS;
	m_btnAdd.item = new OperationItem(op);
	CalculatorModel::OPARATION op2 = CalculatorModel::MINUS;
	m_btnMinus.item = new OperationItem(op2);
	CalculatorModel::OPARATION op3 = CalculatorModel::MULTIPLY;
	m_btnMultiply.item = new OperationItem(op3);
	CalculatorModel::OPARATION op4 = CalculatorModel::DIVIDE;
	m_btnDivide.item = new OperationItem(op4);
	CalculatorModel::OPARATION op5 = CalculatorModel::EQUAL;
	m_btnEqual.item = new OperationItem(op5);
	m_btnDot.item = new DotItem();
	m_btnReset.item = new ResetItem();
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_ZERO, m_btnNumberZero);
	DDX_Control(pDX, IDC_BUTTON_ONE, m_btnNumberOne);
	DDX_Control(pDX, IDC_BUTTON_TWO, m_btnNumberTwo);
	DDX_Control(pDX, IDC_BUTTON_THREE, m_btnNumberThree);
	DDX_Control(pDX, IDC_BUTTON_FOUR, m_btnNumberFour);
	DDX_Control(pDX, IDC_BUTTON_FIVE, m_btnNumberFive);
	DDX_Control(pDX, IDC_BUTTON_SIX, m_btnNumberSix);
	DDX_Control(pDX, IDC_BUTTON_SEVEN, m_btnNumberSeven);
	DDX_Control(pDX, IDC_BUTTON_EIGHT, m_btnNumberEight);
	DDX_Control(pDX, IDC_BUTTON_NINE, m_btnNumberNine);
	DDX_Control(pDX, IDC_BUTTON_DOT, m_btnDot);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_btnAdd);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_btnMinus);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_btnMultiply);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_btnDivide);
	DDX_Control(pDX, IDC_BUTTON_EQUAL, m_btnEqual);
	DDX_Control(pDX, IDC_BUTTON_RESET, m_btnReset);

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
ON_WM_SIZE()
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
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	init();
	CRect rect;
	GetWindowRect(&rect);
	SetWindowPos(
		NULL,               // specifies that the window created with the HWND_TOPMOST style is placed above all non-topmost windows and stays above them, even when deactivated
		rect.left,          // New X position
		rect.top,           // New Y position
		300,           // New width of the window
		400,          // New height of the window
		SWP_NOZORDER | SWP_NOACTIVATE  // Ignores the hWndInsertAfter parameter; Does not activate the window
	);
	doResize();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CcalculatorDlg::doResize() {
	CRect rect;
	GetClientRect(&rect);
	int hGap = 5;
	int wGap = 5;
	int textHeight = 144;
	int bottomGap = 5;
	int gridWidth = (rect.Width() - wGap) / 4;
	int gridHeight = (rect.Height() - textHeight - bottomGap) / 5;
	int buttonWidth = gridWidth - wGap;
	int buttonHeight = gridHeight - hGap;
	m_buttonFont.DeleteObject();
	m_buttonFont.CreatePointFont(buttonHeight*3, _T("Arial"));
	m_btnReset.MoveWindow(gridWidth * 3 + wGap, textHeight, buttonWidth, buttonHeight);
	m_btnReset.SetFont(&m_buttonFont);
	m_btnReset.Invalidate();
	m_btnNumberOne.MoveWindow(wGap, textHeight + gridHeight, buttonWidth, buttonHeight);
	m_btnNumberOne.SetFont(&m_buttonFont);
	m_btnNumberOne.Invalidate();
	m_btnNumberTwo.MoveWindow(gridWidth + wGap, textHeight + gridHeight, buttonWidth, buttonHeight);
	m_btnNumberTwo.SetFont(&m_buttonFont);
	m_btnNumberTwo.Invalidate();
	m_btnNumberThree.MoveWindow(gridWidth * 2 + wGap, textHeight + gridHeight, buttonWidth, buttonHeight);
	m_btnNumberThree.SetFont(&m_buttonFont);
	m_btnNumberThree.Invalidate();
	m_btnAdd.MoveWindow(gridWidth * 3 + wGap, textHeight + gridHeight, buttonWidth, buttonHeight);
	m_btnAdd.SetFont(&m_buttonFont);
	m_btnAdd.Invalidate();
	m_btnNumberFour.MoveWindow(wGap, textHeight + gridHeight * 2, buttonWidth, buttonHeight);
	m_btnNumberFour.SetFont(&m_buttonFont);
	m_btnNumberFour.Invalidate();
	m_btnNumberFive.MoveWindow(gridWidth + wGap, textHeight + gridHeight * 2, buttonWidth, buttonHeight);
	m_btnNumberFive.SetFont(&m_buttonFont);
	m_btnNumberFive.Invalidate();
	m_btnNumberSix.MoveWindow(gridWidth * 2 + wGap, textHeight + gridHeight * 2, buttonWidth, buttonHeight);
	m_btnNumberSix.SetFont(&m_buttonFont);
	m_btnNumberSix.Invalidate();
	m_btnMinus.MoveWindow(gridWidth * 3 + wGap, textHeight + gridHeight * 2, buttonWidth, buttonHeight);
	m_btnMinus.SetFont(&m_buttonFont);
	m_btnMinus.Invalidate();
	m_btnNumberSeven.MoveWindow(wGap, textHeight + gridHeight * 3, buttonWidth, buttonHeight);
	m_btnNumberSeven.SetFont(&m_buttonFont);
	m_btnNumberSeven.Invalidate();
	m_btnNumberEight.MoveWindow(gridWidth + wGap, textHeight + gridHeight * 3, buttonWidth, buttonHeight);
	m_btnNumberEight.SetFont(&m_buttonFont);
	m_btnNumberEight.Invalidate();
	m_btnNumberNine.MoveWindow(gridWidth * 2 + wGap, textHeight + gridHeight * 3, buttonWidth, buttonHeight);
	m_btnNumberNine.SetFont(&m_buttonFont);
	m_btnNumberNine.Invalidate();
	m_btnMultiply.MoveWindow(gridWidth * 3 + wGap, textHeight + gridHeight * 3, buttonWidth, buttonHeight);
	m_btnMultiply.SetFont(&m_buttonFont);
	m_btnMultiply.Invalidate();
	m_btnDot.MoveWindow(wGap, textHeight + gridHeight * 4, buttonWidth, buttonHeight);
	m_btnDot.SetFont(&m_buttonFont);
	m_btnDot.Invalidate();
	m_btnNumberZero.MoveWindow(gridWidth + wGap, textHeight + gridHeight * 4, buttonWidth, buttonHeight);
	m_btnNumberZero.SetFont(&m_buttonFont);
	m_btnNumberZero.Invalidate();
	m_btnEqual.MoveWindow(gridWidth * 2 + wGap, textHeight + gridHeight * 4, buttonWidth, buttonHeight);
	m_btnEqual.SetFont(&m_buttonFont);
	m_btnEqual.Invalidate();
	m_btnDivide.MoveWindow(gridWidth * 3 + wGap, textHeight + gridHeight * 4, buttonWidth, buttonHeight);
	m_btnDivide.SetFont(&m_buttonFont);
	m_btnDivide.Invalidate();
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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalculatorDlg::init() {
	myCalculator.init();
}

void CcalculatorDlg::addNumber(CString num){
	myCalculator.addNumber(num);
}

bool CcalculatorDlg::isNumber(CString& s) {
	return myCalculator.isNumber(s);
}

void CcalculatorDlg::operationFunc(CalculatorModel::OPARATION op){

	myCalculator.operationFunc(op);
}

void CcalculatorDlg::OnBnClickedButtonZero()
{
	// TODO: Add your control notification handler code here

	m_btnNumberZero.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonOne()
{
	// TODO: Add your control notification handler code here
	m_btnNumberOne.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonTwo()
{
	// TODO: Add your control notification handler code here
	m_btnNumberTwo.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonThree()
{
	// TODO: Add your control notification handler code here
	m_btnNumberThree.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonFour()
{
	// TODO: Add your control notification handler code here
	m_btnNumberFour.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonFive()
{
	// TODO: Add your control notification handler code here
	m_btnNumberFive.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonSix()
{
	// TODO: Add your control notification handler code here
	m_btnNumberSix.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonSeven()
{
	// TODO: Add your control notification handler code here
	m_btnNumberSeven.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonEight()
{
	// TODO: Add your control notification handler code here
	m_btnNumberEight.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonNine()
{
	// TODO: Add your control notification handler code here
	m_btnNumberNine.item->doOperation(&myCalculator);

	updateView();
}


void CcalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: Add your control notification handler code here
	m_btnDot.item->doOperation(&myCalculator);
	updateView();

}

void CcalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: Add your control notification handler code here
	m_btnAdd.item->doOperation(&myCalculator);
	updateView();
}


void CcalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: Add your control notification handler code here
	m_btnMinus.item->doOperation(&myCalculator);
	updateView();
}


void CcalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: Add your control notification handler code here
	m_btnMultiply.item->doOperation(&myCalculator);
	updateView();
}


void CcalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: Add your control notification handler code here
	m_btnDivide.item->doOperation(&myCalculator);
	updateView();
}


void CcalculatorDlg::OnBnClickedButtonReset()
{
	// TODO: Add your control notification handler code here
	m_btnReset.item->doOperation(&myCalculator);
	updateView();
}


void CcalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: Add your control notification handler code here
	m_btnEqual.item->doOperation(&myCalculator);
	updateView();
}

void CcalculatorDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	 //TODO: Add your message handler code here and/or call default
	myCalculator.onChar(nChar);
	updateView();
}

BOOL CcalculatorDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CcalculatorDlg::updateView() {
	//CClientDC dc(this);
 //   dc.TextOut(100,100, myCalculator.getText());
	CClientDC dc(this);
	Graphics graphics(dc);
	RedrawWindow(CRect(0, 0, static_cast<int>(dc.GetDeviceCaps(HORZRES)), 200));

	Gdiplus::Font font(L"Arial", 16); // Font name and size
	SolidBrush brush(Color(255, 0, 0, 0)); // Text color (Black)

	PointF origin(10.0f, 10.0f); // Text starting position

	graphics.DrawString(myCalculator.getText2(), -1, &font, origin, &brush);

	PointF origin2(10.0f, 110.0f);
	graphics.DrawString(myCalculator.getText(), -1, &font, origin2, &brush);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalculatorDlg::OnPaint()
{
	CDialogEx::OnPaint();
}


void CcalculatorDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (IsWindowVisible()) {
		doResize();
	}

}
