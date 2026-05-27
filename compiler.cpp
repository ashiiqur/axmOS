#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 

using namespace std;

int main() {

    string RESET  = "\033[0m";  
    string RED    = "\033[1;31m"; 
    string GREEN  = "\033[1;32m"; 
    string CYAN   = "\033[1;36m"; 
    string YELLOW = "\033[1;33m"; 

    cout << CYAN << "--- axmOS Shell v0.8 (Full Calculator!) ---" << RESET << endl;
    cout << "Bhasha: Assamese" << endl;
    cout << "Commands: dekha \"[text]\", hishab [num] [+ - * /] [num], safaa, bondho" << endl << endl;

    string axmos_code;

    while (true) {
        cout << GREEN << "axmOS> " << RESET;
        getline(cin, axmos_code);

        if (axmos_code == "bondho") {
            cout << CYAN << "axmOS bondho kori ase... (Shutting down axmOS)" << RESET << endl;
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
                    cout << RED << "[Bhul/Error]: Ki dekhabo? (What should I show?)" << RESET << endl;
                } else {
                    cout << data << endl;
                }
            } 

            else if (command == "hishab") {
                int num1, num2;
                char math_sign; 
                
                if (ss >> num1 >> math_sign >> num2) {
                    if (math_sign == '+') {
                        cout << YELLOW << "Uttor (Result): " << (num1 + num2) << RESET << endl;
                    } 
                    else if (math_sign == '-') {
                        cout << YELLOW << "Uttor (Result): " << (num1 - num2) << RESET << endl;
                    }
                    else if (math_sign == '*') {
                        cout << YELLOW << "Uttor (Result): " << (num1 * num2) << RESET << endl;
                    }
                    else if (math_sign == '/') {

                        if (num2 == 0) {
                            cout << RED << "[Bhul/Error]: Shunyo (0) di horon koribo nuwari! (Cannot divide by zero!)" << RESET << endl;
                        } else {
                            cout << YELLOW << "Uttor (Result): " << (num1 / num2) << RESET << endl;
                        }
                    }
                    else {
                        cout << RED << "[Bhul/Error]: Ei chin tu buji napalo (Unknown math symbol). Use +, -, *, /" << RESET << endl;
                    }
                } else {
                    cout << RED << "[Bhul/Error]: Sothik format nai! Nirdesh: hishab 5 + 5" << RESET << endl;
                }
            }

            else if (command == "safaa") {
                system("clear"); 
            }
            else {
                cout << RED << "[Bhul/Error]: Ei nirdesh buji napalo (Unknown command): " << command << RESET << endl;
            }
        }
    }

    return 0;
}