#include <iostream>
#include "h/Factory.h"
#include "h/WindowsFactory.h"
#include "h/LinuxFactory.h"
#include "h/MacOSFactory.h"

int main() {
     std::cout << "Choose OS: Windows | Linux | Mac" << std::endl;
     std::string OS;
     std::cin >> OS;
     Factory* factory = nullptr;
     if (OS == "Windows") {
         factory = new WindowsFactory();
     }
     else if (OS == "Linux") {
         factory = new LinuxFactory();
     }
     else if (OS == "Mac") {
         factory = new MacOSFactory();
     }

     if(factory == nullptr) return -1;
     Form* form = factory->createForm();
     Label* label = factory->createLabel();
     TextBox* textBox = factory->createTextBox();
     ComboBox* comboBox = factory->createComboBox();
     Button* button = factory->createButton();

     label->setPosition(100, 100);
     label->setText("Hello world");
     textBox->setPosition(200, 100);
     textBox->setText("Press F to pay respects");
     std::vector<std::string> items = { "Dark", "Light" };
     comboBox->setItems(items);
     comboBox->setPosition(1820, 1000);
     comboBox->setSelectedIndex(0);
     std::cout << "Chosen theme: " << comboBox->getItems()[comboBox->getSeletecedIndex()] << std::endl;
     button->setText("OK");
     button->setPosition(150, 150);
     button->Click();
     form->addControl(label);

     delete factory;

    return 0;
}
