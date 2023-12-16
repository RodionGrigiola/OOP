#pragma once
#include "Controls.h"
#include <iostream>

class LinuxForm : public Form {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << "вызван в LinuxForm" << std::endl;
    }
};

class LinuxLabel : public Label {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в LinuxLabel" << std::endl;
    }
};

class LinuxTextBox : public TextBox {
public:
    void OnValueChanged() override {
        std::cout << "Linux TextBox обновлен" << std::endl;
        this->setCommand("OnValueChanged");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в LinuxTextBox" << std::endl;
    }
};

class LinuxComboBox : public ComboBox {
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в LinuxComboBox" << std::endl;
    }
};

class LinuxButton : public Button {
    void Click() override {
        std::cout << "Клик по LinuxButton" << std::endl;
        this->setCommand("Click");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в LinuxButton" << std::endl;
    }
};

