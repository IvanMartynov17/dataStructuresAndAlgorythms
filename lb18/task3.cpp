#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <vector>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

void printVenegereTable() {
    int n = alphabet.length();
    cout << "\t --Venegere table--" << endl;
    for (char c : alphabet) {
        cout << c << " ";
    }
        cout << endl;

    for (int i = 0; i < n; i++) {
        cout << alphabet[i] << " |";
        for (int j = 0; j < n; j++) {
            cout << alphabet[(i + j) % n] << " ";
        }
        cout << endl;
    }
    cout << "==============================" << endl;
}

string vinegereCipher(string text, string key, bool isEncrypt) {
    string result = "";
    int n = alphabet.length();
    int keyIndex = 0;

    for (char c : text) {
        char lowerC = tolower(c);
        size_t pos = alphabet.find(lowerC);

        if (pos != string::npos) {
            char keyChar = key[keyIndex % key.length()];
            int shift = alphabet.find(keyChar);

            if (!isEncrypt) {
                shift = -shift;
            }

            int newPos = (pos + shift) % n;
            if (newPos < 0) {
                newPos += n;
            }

            char processedChar = alphabet[newPos];
            result += isupper(c) ? (char)toupper(processedChar) : processedChar;

            keyIndex++;
        }else {
            result += c;
        }
    }
    return result;
}
int main() {
    string text, key;
    int action;

    cout << "\t---Venegere cipher---" << endl;
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter key: ";
    getline(cin, key);

    if (key.empty()) {
        cerr << "Key cannot be empty!" << endl;
        return 1;
    }

    cout << "Choose action: 1.Encrypt 2.Decrypt\n Choice:";
    cin >> action;

    if (action == 1) {
        string encrypted = vinegereCipher(text, key, true);
        cout << "\nEncrypted text: " << encrypted << endl;
    } else if (action == 2) {
        string decrypted = vinegereCipher(text, key, false);
        cout << "\nDecrypted text: " << decrypted << endl;
    } else {
        cout << "Invalid choice." << endl;
        return 0;
    }
    char showTable;
    cout << "Show table? (y/n): ";
    cin >> showTable;
    if (showTable == 'y') {
        printVenegereTable();
    }
}