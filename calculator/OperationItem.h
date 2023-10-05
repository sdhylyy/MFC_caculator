#pragma once
#include "Item.h"
class OperationItem :
    public Item
{
public:
    OperationItem(CalculatorModel::OPARATION op) {
        this->op = op;
    }
    CalculatorModel::OPARATION op;
    void doOperation(CalculatorModel* calculator);
};

