#include "iostream"
#include <vector>
#include <string>
#include <thread>
#include <map>

class Workflow {
private:
    std::vector <std::string> buffer;
    std::map <std::string, std::string> keyMap;
public:
    void KeyPress(const std::string &key) {
        buffer.push_back(key);
    }

    int getBufferLength() {
        return buffer.size();
    }

    void LongKeyPress(const std::string &key, int time) {
        std::this_thread::sleep_for(std::chrono::seconds(time));
        buffer.push_back(key);
    }

    void Undo() {
        if (!buffer.empty()) {
            buffer.pop_back();
        }
    }

    void Print() {
        for (std::string &bufferEl: buffer) {
            std::cout << GetCurrentKeyMap(bufferEl) << " ";
        }
        std::cout << std::endl;
    }

    void RemapKey(const std::string &originalKey, const std::string &newKey) {
        keyMap[originalKey] = newKey;
    }

   std::string GetCurrentKeyMap(const std::string &originalKey) {
        if (keyMap.count(originalKey) > 0) {
            return keyMap.at(originalKey);
        }
        return originalKey;
    }
};

int main() {
    Workflow workflow;

    workflow.KeyPress("Ctrl+Alt+Del");
    workflow.Print();

    workflow.KeyPress("Ctrl+X");
    workflow.Print();

    workflow.KeyPress("F12");
    workflow.Print();

    workflow.KeyPress("A");
    workflow.Print();

    workflow.LongKeyPress("fn",2);

    std::cout<< "Переобозначим теперь клавишу F12"<<std::endl;
    workflow.RemapKey("F12", "ctrl");
    workflow.Print();

    std::cout << "Теперь уберем все использованные комбинации клавиш в цикле"<< std::endl;
    while(workflow.getBufferLength() > 0) {
        std::cout << "--------" << std::endl;
        workflow.Undo();
        workflow.Print();
    }

    return 0;
}


