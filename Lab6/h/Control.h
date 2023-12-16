#pragma once
#include <vector>
#include <string>
#include <iostream>

class Control {
public:
    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
        this->setCommand("setPosition");
        printCurrentMethodCall(this->getCommand());
    }
    std::vector<int> getPosition() {
        this->setCommand("getPosition");
        printCurrentMethodCall(this->getCommand());
        return std::vector<int> {x, y};
    }

    virtual void printCurrentMethodCall(const std::string& methodName) {
        std::cout << "Метод " << methodName << " вызван" << std::endl;
    };

    void setCommand(std::string command) {
        this->command = command;
    }

    std::string getCommand() {
        return this->command;
    }
    int x, y;
private:
    std::string command;
};



