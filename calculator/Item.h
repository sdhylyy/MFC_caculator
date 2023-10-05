#pragma once
#include "CalculatorModel.h"

class Item
{
public:
	virtual void doOperation(CalculatorModel* calculator) = 0;
};

