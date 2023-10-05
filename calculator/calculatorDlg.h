
// calculatorDlg.h : header file
//

#pragma once
#include"CalculatorModel.h"
#include"CalculatorButton.h"
#include"NumberItem.h"
#include"OperationItem.h"
#include"DotItem.h"
#include"ResetItem.h"

// CcalculatorDlg dialog
class CcalculatorDlg : public CDialogEx
{
private:
	CFont m_font;
	CFont m_font2;
	//double m_result;
	//double m_preNum;
	//int m_operation;  //0-3 represents +-*/
	//bool m_hasDP;   //�ж��Ƿ�����С����
	//int m_status; 
	CalculatorModel myCalculator;

	void init();
	void addNumber(CString num);  
	void operationFunc(CalculatorModel::OPARATION op);
	bool isNumber(CString& s);
	void updateView();

// Construction
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// standard constructor
	CalculatorButton m_btnNumberZero;
	CalculatorButton m_btnNumberOne;
	CalculatorButton m_btnNumberTwo;
	CalculatorButton m_btnNumberThree;
	CalculatorButton m_btnNumberFour;
	CalculatorButton m_btnNumberFive;
	CalculatorButton m_btnNumberSix;
	CalculatorButton m_btnNumberSeven;
	CalculatorButton m_btnNumberEight;
	CalculatorButton m_btnNumberNine;
	CalculatorButton m_btnAdd;
	CalculatorButton m_btnMinus;
	CalculatorButton m_btnMultiply;
	CalculatorButton m_btnDivide;
	CalculatorButton m_btnEqual;
	CalculatorButton m_btnDot;
	CalculatorButton m_btnReset;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void doResize();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_text;
	CString m_text2;
public:
	afx_msg void OnBnClickedButtonZero();
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtonTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonFour();
	afx_msg void OnBnClickedButtonFive();
	afx_msg void OnBnClickedButtonSix();
	afx_msg void OnBnClickedButtonSeven();
	afx_msg void OnBnClickedButtonEight();
	afx_msg void OnBnClickedButtonNine();
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonEqual();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
