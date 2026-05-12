#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;


const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const string key      = "phqgiumeaylnofdxjkrcvstzwb";

string subtitutionCipher(string text, string fromAlpha, string toAlpha) {
    string result = "";

    for (char c : text) {
        char lower = tolower(c);
        size_t pos = fromAlpha.find(lower);

        if (pos != string::npos) {
            char replaced = toAlpha[pos];

            if (isupper(c)){
                result += (char)toupper(replaced);
            }else {
                result += replaced;
            }
        }else {
            result += c;
        }
    }
    return result;
}

int main() {
    int choice, action;
    string text;

    cout << "\t--Substitution cipher--\n\n";
    cout << "Alphabet: " << alphabet << "\n";
    cout << "Key: " << key << "\n\n";

    cout << "\n1. Enter text manually\n2. Read from file (input.txt)\nChoice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 2) {
        ifstream file("input.txt");
        if (!file.is_open()) {
            cerr << "File not found!\n";
            return 1;
        }
        getline(file, text);
    }else {
        cout << "Enter text: ";
        getline(cin, text);
    }

    cout << "Choose the action:\n1.Encrypt\n2.Descrypt\nChoice: ";
    cin >> action;

    if (action == 1) {
        cout << "Encrypted text: " << subtitutionCipher(text, alphabet, key) << "\n";
    }else if (action == 2) {
        cout << "Decrypted text: " << subtitutionCipher(text, key, alphabet) << "\n";
    }
    return 0;
}