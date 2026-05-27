#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 

using namespace std;

int main() {
    cout << "--- axmOS Shell v0.6 ---" << endl;
    cout << "Bhasha: Assamese" << endl;
    cout << "Commands: dekha \"[text]\", jog [num] + [num], safaa, bondho" << endl << endl;

    string axmos_code;

    while (true) {
        cout << "axmOS> ";
        getline(cin, axmos_code);

        if (axmos_code == "bondho") {
            cout << "axmOS bondho kori ase... (Shutting down axmOS)" << endl;
            break; 
        }

        stringstream ss(axmos_code);
        string command;

        if (ss >> command) {
            if (command == "dekha") {
                string data;
                getline(ss, data); 
                
                if (data.length() > 0 && data[0] == ' ') {
                    data = data.substr(1);
                }

                if (data.length() >= 2 && data[0] == '"' && data[data.length() - 1] == '"') {
                    data = data.substr(1, data.length() - 2);
                }

                if (data.empty()) {
                    cout << "[Bhul/Error]: Ki dekhabo? (What should I show?)" << endl;
                } else {
                    cout << data << endl;
                }
            } 
            else if (command == "jog") {
                int num1, num2;
                char math_sign; 
                
                if (ss >> num1 >> math_sign >> num2) {
                    if (math_sign == '+') {
                        cout << "Utor (Result): " << (num1 + num2) << endl;
                    } else {
                        cout << "[Bhul/Error]: Jog koriboloi '+' chin byobohar korok (Use '+' for addition!)" << endl;
                    }
                } else {
                    cout << "[Bhul/Error]: Sothik format nai! Nirdesh (Example): jog 5 + 5" << endl;
                }
            }
            else if (command == "safaa") {
                system("clear"); 
            }
            else {
                cout << "[Bhul/Error]: Ei nirdesh buji napalo (Unknown command): " << command << endl;
            }
        }
    }

    return 0;
}