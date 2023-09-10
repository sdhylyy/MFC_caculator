#pragma once

#include "framework.h"
class BasicCalculatorModel
{
public:
	enum OPARATION {
		PLUS, MINUS, MULTIPLY, DIVIDE, EQUAL,NONE
	};
	virtual void addNumber(CString num) = 0;
	virtual void operationFunc(OPARATION op) = 0;
	virtual bool isNumber(CString& s) = 0;
};

