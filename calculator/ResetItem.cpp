#include "pch.h"
#include "ResetItem.h"

void ResetItem::doOperation(CalculatorModel* calculator) {
	calculator->init();
}
