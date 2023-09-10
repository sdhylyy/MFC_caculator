#pragma once
#include "BasicCalculatorModel.h"
#include <string>
class CalculatorModel :public BasicCalculatorModel
{
public:
	CalculatorModel();
	void addNumber(CString num) ;
	void addDot();
	bool isNumber(CString& s);
	void operationFunc(OPARATION op);
	void init();
	CString getResult();
	CString getText();
	CString getText2();

private:
	double m_result;
	double m_preNum;
	bool m_hasDP;   //判断是否已有小数点
	int m_status;
	OPARATION m_operation;
	CFont m_font;
	CFont m_font2;
	CString m_text;
	CString m_text2;
};

