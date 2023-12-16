#pragma once
#include "Controls.h"
class Factory {
public:
    virtual Form* createForm() = 0;
    virtual Label* createLabel() = 0;
    virtual TextBox* createTextBox() = 0;
    virtual ComboBox* createComboBox() = 0;
    virtual Button* createButton() = 0;
};


