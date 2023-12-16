#pragma once
#include "Factory.h"
#include "windowsControls.h"

class WindowsFactory : public Factory {
public:
    Form* createForm() override {
        return new WindowsForm();
    }
    Label* createLabel() override {
        return new WindowsLabel();
    }

    TextBox* createTextBox() override {
        return new WindowsTextBox();
    }

    ComboBox* createComboBox() override {
        return new WindowsComboBox();
    }

    Button* createButton() override {
        return new WindowsButton();
    }
};



