#include "pch.h"
#include "CalculatorModel.h"
#include <iostream>
#include <string>
#include <sstream>

CalculatorModel::CalculatorModel() {
	m_result = 0;
	m_preNum = 0;
	m_status = 1;
	m_text2 = _T("");
	m_text = _T("0");
	m_operation = NONE;
	m_hasDP = false;
}
//
void CalculatorModel::addNumber(CString num) {
	CString s("0");
	if (num.Compare(s) != 0) {
		if (m_status) {
			m_text = num;
			m_status = 0;
		}
		else {
			m_text += num;
		}
	}
	else {
		if (m_text.GetLength() == 1 && _ttoi(m_text) == 0) {
			return;
		}
		if (m_status) {
			m_text = s;
		}
		else {
			m_text += s;
		}
	}

}


void CalculatorModel::addDot() {
	if (m_hasDP) {
		return;
	}
	if (m_status) {
		m_status = 0;
	}
	CString s(".");
	m_text += s;
	m_hasDP = true;
}

bool CalculatorModel::isNumber(CString& s) {
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

void CalculatorModel::operationFunc(OPARATION op) {
	if (!isNumber(m_text)) {
		m_text = _T("0");
		return;
	}
	if (op != EQUAL) {
		m_preNum = _tstof(m_text);
		m_status = 1;
		m_hasDP = 0;
		m_operation = op;
		m_text2 = m_text;
	}
	switch (op) {
	case PLUS:
		m_text2 += _T("+");
		break;
	case MINUS:
		m_text2 += _T("-");
		break;
	case MULTIPLY:
		m_text2 += _T("*");
		break;
	case DIVIDE:
		m_text2 += _T("/");
		break;
	case EQUAL:
		double curr = _tstof(m_text);
		if (m_operation == NONE) {
			m_text2 = _T("");
			m_operation = PLUS;
		}
		m_text2 += m_text;
		m_text2 += _T("=");
		switch (m_operation) {
		case PLUS:
			m_result = curr + m_preNum;
			m_text = CalculatorModel::getResult();
			break;
		case MINUS:
			m_result = m_preNum - curr;
			m_text = CalculatorModel::getResult();
			break;
		case MULTIPLY:
			m_result = curr * m_preNum;
			m_text = CalculatorModel::getResult();
			break;
		case DIVIDE:
			if (curr == 0.0) {
				m_text = _T("除数不能为零");
				m_result = 0;
				m_text2 = _T("");
				break;
			}
			m_hasDP = false;
			m_result = m_preNum / curr;
			m_text = CalculatorModel::getResult();
			break;
		}
		m_preNum = 0;
		m_operation = NONE;
		m_status = 1;
	}
}

void CalculatorModel::init() {
	m_result = 0;
	m_preNum = 0;
	m_operation = NONE;
	m_status = 1;
	m_text2 = _T("");
	m_text = _T("0");
	m_hasDP = false;
}

CString CalculatorModel::getResult() {
	std::ostringstream stream;
	stream.imbue(std::locale(""));

	stream << std::fixed << m_result;
	CString s(stream.str().c_str());
	return s;
}

CString CalculatorModel::getText() {
	return m_text;
}

CString CalculatorModel::getText2() {
	return m_text2;
}