#pragma once
#include "Item.h"
class NumberItem :
    public Item
{
public:
    NumberItem(CString val) {
        this->val = val;
    }
    CString val;
    void doOperation(CalculatorModel* calculator);
};

