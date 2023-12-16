#pragma once
#include <string>
#include <iostream>
#include "Control.h"

class Form : public Control {
public:
    void addControl(Control* control) {
        this->contV.push_back(*control);
        this->setCommand("addControl");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в Form" << std::endl;
    }

private:
    std::vector<Control> contV;
};

class Label : public Control {
public:
    void setText(std::string text) {
        this->text = text;
        this->setCommand("setText");
        printCurrentMethodCall(this->getCommand());
    }
    std::string getText() {
        this->setCommand("getText");
        printCurrentMethodCall(this->getCommand());
        return this->text;
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в Label" << std::endl;
    }
private:
    std::string text;
};

class TextBox : public Control {
public:
    void setText(std::string text) {
        if (this->text != text) {
            OnValueChanged();
        }
        this->setCommand("setText");
        printCurrentMethodCall(this->getCommand());
        this->text = text;
    }
    std::string getText() {
        this->setCommand("getText");
        printCurrentMethodCall(this->getCommand());
        return this->text;
    }
    virtual void OnValueChanged() {
        std::cout << "Текст обновлен" << std::endl;
        this->setCommand("OnValueChanged");
        printCurrentMethodCall(this->getCommand());
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в TextBox" << std::endl;
    }
private:
    std::string text;
};

class ComboBox : public Control {
public:
    int getSeletecedIndex() {
        this->setCommand("getSelectedIndex");
        printCurrentMethodCall(this->getCommand());
        return this->selectedIndex;
    }
    void setSelectedIndex(int index) {
        this->selectedIndex = index;
        this->setCommand("setSelectedIndex");
        printCurrentMethodCall(this->getCommand());
    }
    void setItems(std::vector<std::string> items) {
        this->items = items;
        this->setCommand("setItems");
        printCurrentMethodCall(this->getCommand());
    }
    std::vector<std::string> getItems() {
        this->setCommand("getItems");
        printCurrentMethodCall(this->getCommand());
        return this->items;
    }
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в ComboBox" << std::endl;
    }
private:
    std::vector<std::string> items;
    int selectedIndex;
};

class Button : public Control {
public:
    void setText(std::string text) {
        this->text = text;
        this->setCommand("setText");
        printCurrentMethodCall(this->getCommand());
    }
    std::string getText() {
        this->setCommand("getText");
        printCurrentMethodCall(this->getCommand());
        return this->text;
    }
    virtual void Click() = 0;
    void printCurrentMethodCall(const std::string& methodName) override {
        std::cout << "Метод " << methodName << " вызван в Button" << std::endl;
    }
private:
    std::string text;
};