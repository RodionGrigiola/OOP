#include <iostream>
#include <vector>
#include <unordered_map>
#include <thread>

class KeyboardAction {
public:
    virtual void run() = 0;
    virtual void undo() = 0;
    virtual std::string prepareToShow() = 0;
};

class KeyPressAction : public KeyboardAction {
public:
    KeyPressAction(std::string key) : key(key) {}

    void run() override {
        std::cout << key + " is pressed" << std::endl;
    }

    void undo() override {
        std::cout << "Undo last action: " << key << std::endl;
    }

    std::string prepareToShow() override {
        return key;
    }

    std::string key;
};

class MultipleKeysPressAction : public KeyboardAction {

public:
    MultipleKeysPressAction(std::vector<std::string> keys) : keys(keys) {}

    void run() override {
        std::cout << "Shortcut ";
        for (const auto& k : keys) {
            std::cout << k << " + ";
        }
        std::cout << "\b\bis pressed" << std::endl;
    }

    void undo() override {
        std::cout << "Undo last combination: ";
        for (const auto& k : keys) {
            std::cout << k << " + ";
        }
        std::cout << "\b\b  " << std::endl;
    }

    std::string prepareToShow() override {
        std::string result;
        for (const auto& k : keys) {
            result += k + " + ";
        }
        result.erase(result.size() - 3); // Removing the last " + "
        return result;
    }

    std::vector<std::string> keys;
};

class Keyboard {
private:
    std::vector<KeyboardAction *> history;
    std::unordered_map<std::string, KeyboardAction *> actions;

public:
    void pressKey(std::string key) {
        if (actions.find(key) != actions.end()) {
            actions[key]->run();
        } else {
            KeyPressAction *action = new KeyPressAction(key);
            actions[key] = action;
            actions[key]->run();
        }
        history.push_back(actions[key]);
        std::cout << "Console>>> " << showHistory() << std::endl;
    }

    void pressCombo(std::vector<std::string> keys) {
        std::string comboKey;
        for (const auto &k: keys) {
            comboKey += k + " + ";
        }
        comboKey.erase(comboKey.size() - 3); // Removing the last " + "

        if (actions.find(comboKey) != actions.end()) {
            actions[comboKey]->run();
        } else {
            MultipleKeysPressAction *action = new MultipleKeysPressAction(keys);
            actions[comboKey] = action;
            actions[comboKey]->run();
        }
        history.push_back(actions[comboKey]);
//        std::cout << "Console>>> " << showHistory() << std::endl;
    }

    void undo() {
        if (!history.empty()) {
            KeyboardAction *action = history.back();
            action->undo();
            history.pop_back();

            std::cout << "Console>>> " << showHistory() << std::endl;
        } else {
            std::cout << "History is empty" << std::endl;
        }
    }

    std::string showHistory() {
        std::string tmp;
        for (auto element: history) {
            tmp += element->prepareToShow();
        }
        return tmp;
    }

    void renameKey(std::string oldValue, std::string newValue) {
        bool isExists = false;
        for (auto &entry: actions) {
            if (oldValue == entry.second->prepareToShow()) {
                std::cout << "Key " << entry.second->prepareToShow();
                delete entry.second;
                actions[oldValue] = new KeyPressAction(newValue);
                isExists = true;
                std::cout << " was renamed to " << actions[oldValue]->prepareToShow() << std::endl;
            }
        }
        if (!isExists) {
            std::cout << "Such key doesn't exist" << std::endl;
        }
    }

    void renameMultipleKeysCombination(std::string oldValue, std::string newValue) {
        bool isExists = false;
        for (auto &entry: actions) {
            if (oldValue == entry.second->prepareToShow()) {
                std::cout << "Shortcut  " << entry.second->prepareToShow();
                delete entry.second;
                actions[oldValue] = new MultipleKeysPressAction({newValue});
                isExists = true;
                std::cout << " is renamed to " << actions[oldValue]->prepareToShow() << std::endl;
            }
        }
        if (!isExists) {
            std::cout << "Such key doesn't exist" << std::endl;
        }
    }
};

class Workflow {
    public:
        static void showWorkflow(Keyboard &keyboard) {
            keyboard.pressKey("H");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            keyboard.pressKey("E");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            keyboard.pressKey("L");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            keyboard.pressKey("L");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            keyboard.pressKey("O");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            keyboard.undo();
            keyboard.undo();
            keyboard.undo();
            keyboard.undo();
            keyboard.undo();

            keyboard.pressCombo({"Ctrl", "Esc"});
            std::this_thread::sleep_for(std::chrono::seconds(1));
            keyboard.undo();
            std::cout << "------------------------------" << std::endl;
        }
};

int main() {
    Keyboard keyboard;
    Workflow::showWorkflow(keyboard);
    keyboard.renameKey("H", "C");
    Workflow::showWorkflow(keyboard);
    keyboard.renameMultipleKeysCombination("Ctrl + Esc", "Ctrl + D");
    Workflow::showWorkflow(keyboard);
    return 0;
}
