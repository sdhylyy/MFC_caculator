#pragma once
#include <afxwin.h>
#include "Item.h"
class CalculatorButton :
    public CButton
{
public:
    Item* item;
    CalculatorButton() {
        this->item = NULL;
    }
    CalculatorButton(Item* item) {
        this->item = item;
    }
    ~CalculatorButton() {
        delete(item);
    }
};

