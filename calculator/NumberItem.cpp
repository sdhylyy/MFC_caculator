#include "pch.h"
#include "NumberItem.h"

void NumberItem::doOperation(CalculatorModel* calculator) {
	calculator->addNumber(this->val);
}
