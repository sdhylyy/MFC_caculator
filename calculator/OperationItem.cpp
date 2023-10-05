#include "pch.h"
#include "OperationItem.h"

void OperationItem::doOperation(CalculatorModel* calculator) {
	calculator->operationFunc(this->op);
}
