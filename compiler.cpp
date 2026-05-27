#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    cout << "--- axmOS Shell Compiler v0.1 ---" << endl;
    cout << "Bhasha (Language): Assamese" << endl << endl;

    string axmos_code = "dekha axmOS_Nirman_Arambho;"; 
    
    cout << "Reading code: " << axmos_code << endl;
    cout << "Analyzing..." << endl;
    cout << "-----------------------------------" << endl;

    stringstream ss(axmos_code);
    string word;
    
    while (ss >> word) {
        if (word == "dekha") {
            cout << "[Nirdesh/Command]: Screen-ot dekhaba (Print command found)" << endl;
        } else if (word == "axmOS_Nirman_Arambho;") {
            cout << "[Tothyo/Data]: 'axmOS_Nirman_Arambho'" << endl;
        } else {
            cout << "[Bhul/Error]: Ei shobdoto buji napalo (Unknown word): " << word << endl;
        }
    }

    return 0;
}