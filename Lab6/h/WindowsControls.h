#pragma once
#include "Controls.h"
#include <iostream>

class WindowsForm : public Form {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в WindowsForm" << std::endl;
    }
};

class WindowsLabel : public Label {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в WindowsLabel" << std::endl;
    }
};

class WindowsTextBox : public TextBox {
public:
    void OnValueChanged() override {
        std::cout << "Windows TextBox обновлен" << std::endl;
        this->setCommand("OnValueChanged");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в WindowsTextBox" << std::endl;
    }
};

class WindowsComboBox : public ComboBox {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в WindowsComboBox" << std::endl;
    }
};

class WindowsButton : public Button {
    void Click() override {
        std::cout << "Клик по Windows Button" << std::endl;
        this->setCommand("Click");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в WindowsButton" << std::endl;
    }
};