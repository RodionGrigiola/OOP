#pragma once
#include "Factory.h"
#include "MacOSControls.h"
class MacOSFactory : public Factory
{
public:
    Form* createForm() override {
        return new MacOSForm();
    }
    Label* createLabel() override {
        return new MacOSLabel();
    }

    TextBox* createTextBox() override {
        return new MacOSTextBox();
    }

    ComboBox* createComboBox() override {
        return new MacOSComboBox();
    }

    Button* createButton() override {
        return new MacOSButton();
    }
};

