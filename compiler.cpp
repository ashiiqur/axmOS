#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    cout << "--- axmOS Shell v0.2 ---" << endl;
    cout << "Bhasha: Assamese" << endl;
    cout << "Type 'bondho' to exit." << endl << endl;

    string axmos_code;

    // The REPL Loop:
    while (true) {
        cout << "axmOS> ";
        getline(cin, axmos_code); 

        if (axmos_code == "bondho") {
            cout << "axmOS bondho kori ase... (Shutting down axmOS)" << endl;
            break; 
        }

        stringstream ss(axmos_code);
        string command;
        string data;

        if (ss >> command) {
            if (command == "dekha") {
                
                if (ss >> data) {
                    cout << data << endl;
                } else {
                    cout << "[Bhul/Error]: Ki dekhabo? (What should I show?)" << endl;
                }
            } else {
                cout << "[Bhul/Error]: Ei nirdesh buji napalo (Unknown command): " << command << endl;
            }
        }
    }

    return 0;
}