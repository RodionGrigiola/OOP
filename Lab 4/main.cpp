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
        std::cout << "Pressed key: " << key << std::endl;
    }

    void undo() override {
        std::cout << "Undo last action: " << key << std::endl;
    }

    std::string prepareToShow() override {
        return key;
    }

    std::string key;
};

class MultipleKeysAction : public KeyboardAction {

public:
    MultipleKeysAction(std::vector<std::string> keys) : keys(keys) {}

    void run() override {
        std::cout << "Pressed combination: ";
        for (const auto& k : keys) {
            std::cout << k << " + ";
        }
        std::cout << "\b\b  " << std::endl;
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

class VirtualKeyboard {
private:
    std::vector<KeyboardAction*> history;
    std::unordered_map<std::string, KeyboardAction*> actions;

public:
    void pressKey(std::string key) {
        if (actions.find(key) != actions.end()) {
            actions[key]->run();
        } else {
            KeyPressAction* action = new KeyPressAction(key);
            actions[key] = action;
            actions[key]->run();
        }
        history.push_back(actions[key]);
    }

    void pressCombo(std::vector<std::string> keys) {
        std::string comboKey;
        for (const auto& k : keys) {
            comboKey += k + " + ";
        }
        comboKey.erase(comboKey.size() - 3); // Removing the last " + "

        if (actions.find(comboKey) != actions.end()) {
            actions[comboKey]->run();
        } else {
            MultipleKeysAction* action = new MultipleKeysAction(keys);
            actions[comboKey] = action;
            actions[comboKey]->run();
        }
        history.push_back(actions[comboKey]);
    }

    void undo() {
        if (!history.empty()) {
            KeyboardAction* action = history.back();
            action->undo();
            history.pop_back();
        }
    }

    void showHistory() {
        for (const auto& element : history) {
            std::cout << element->prepareToShow() << std::endl;
        }
    }

    void renameKey(std::string oldValue, std::string newValue) {
        bool isExists = false;
        std::cout << "Renaming " + oldValue + " to " + newValue << std::endl;
        for (const auto& element : history) {
            if (element->prepareToShow() == oldValue) {
                KeyPressAction* action = dynamic_cast<KeyPressAction*>(element);
                if (action) {
                    action->key = newValue;
                    isExists = true;
                }
            }
        }
        for (auto& pair : actions) {
            if (pair.first == oldValue) {
                actions[newValue] = pair.second;
                actions.erase(oldValue);
                isExists = true;
                break;
            }
        }
        if (!isExists) {
            std::cout << "The key doesn't exist!" << std::endl;
        }
    }

    void renameMultipleKeysCombination(std::string oldValue, std::string newValue) {
        bool isExists = false;
        std::cout << "Renaming combo " + oldValue + " to " + newValue << std::endl;
        std::vector<std::string> newCombo;
        size_t pos = 0;
        std::string delimiter = " + ";
        while ((pos = newValue.find(delimiter)) != std::string::npos) {
            std::string token = newValue.substr(0, pos);
            newCombo.push_back(token);
            newValue.erase(0, pos + delimiter.length());
        }
        newCombo.push_back(newValue);

        for (const auto& element : history) {
            if (element->prepareToShow() == oldValue) {
                MultipleKeysAction* action = dynamic_cast<MultipleKeysAction*>(element);
                if (action) {
                    action->keys = newCombo;
                    isExists = true;
                }
            }
        }
        for (auto& pair : actions) {
            if (pair.first == oldValue) {
                actions[newValue] = pair.second;
                actions.erase(oldValue);
                isExists = true;
                break;
            }
        }
        if (!isExists) {
            std::cout << "The combination doesn't exist!" << std::endl;
        }
    }
};

class Workflow {
public:
    static void showWorkflow(VirtualKeyboard& keyboard) {
        keyboard.pressKey("F");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        keyboard.pressKey("W");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        keyboard.pressCombo({"Ctrl", "Esc"});
        std::this_thread::sleep_for(std::chrono::seconds(1));
        keyboard.pressCombo({"Shift", "Alt"});
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "-----History----- " << std::endl;
        keyboard.showHistory();
        std::cout << "------End of History------- " << std::endl;
        keyboard.undo();
        std::cout << "-----History-----" << std::endl;
        keyboard.showHistory();
        std::cout << "------End of History------- " << std::endl;
    }
};

int main() {
    VirtualKeyboard keyboard;
    Workflow::showWorkflow(keyboard);
    keyboard.renameKey("Q", "E");
    Workflow::showWorkflow(keyboard);
    keyboard.renameMultipleKeysCombination("Ctrl + A", "Ctrl + D");
    Workflow::showWorkflow(keyboard);

    return 0;
}
