
// calculatorDlg.h : header file
//

#pragma once


// CcalculatorDlg dialog
class CcalculatorDlg : public CDialogEx
{
private:
	CFont font;
	CFont font2;
	double result;
	double preNum;
	int operation;  //0-3 represents +-*/
	bool hasDP;   //判断是否已有小数点
	int status; 
	void init();
	void addNumber(CString num);  
	void operationFunc(int index);
	bool isNumber(CString& s);

// Construction
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

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
};
