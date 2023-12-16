#pragma once
#include "Controls.h"
#include <iostream>

class MacOSForm : public Form {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в MacForm" << std::endl;
    }
};

class MacOSLabel : public Label {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в MacLabel" << std::endl;
    }
};

class MacOSTextBox : public TextBox {
public:
    void OnValueChanged() override {
        std::cout << "Mac TextBox обновлен" << std::endl;
        this->setCommand("OnValueChanged");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в MacTextBox" << std::endl;
    }
};

class MacOSComboBox : public ComboBox {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в MacComboBox" << std::endl;
    }
};

class MacOSButton : public Button {
    void Click() override {
        std::cout << "Клик по MacButton" << std::endl;
        this->setCommand("Click");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в MacButton" << std::endl;
    }
};
