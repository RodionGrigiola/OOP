#pragma once
#include "Factory.h"
#include "linuxControls.h"

class LinuxFactory : public Factory
{
public:
    Form* createForm() override {
        return new LinuxForm();
    }
    Label* createLabel() override {
        return new LinuxLabel();
    }

    TextBox* createTextBox() override {
        return new LinuxTextBox();
    }

    ComboBox* createComboBox() override {
        return new LinuxComboBox();
    }

    Button* createButton() override {
        return new LinuxButton();
    }
};

