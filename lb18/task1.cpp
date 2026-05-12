#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cwctype>
using namespace std;

const wstring alphabet = L"абвгґдеєжзиіїйклмнопрстуфхцчшщьюя";

wstring caesarCipher(wstring text, int key) {
    wstring result = L"";
    int n = alphabet.length();

    for (wchar_t c : text) {
        wchar_t lower = towlower(c);
        size_t pos = alphabet.find(lower);

        if (pos != wstring::npos) {
            int newPos = (pos + key) % n;
            if (newPos < 0) {
                newPos += n;
            }
            if (isupper(c)) result += towupper(alphabet[newPos]);
            else result += alphabet[newPos];
        }
        else {
            result += c;
        }
    }
    return result;
}

int frequencyAttack(wstring cipherText) {
    int n = alphabet.length();
    vector<int> counts(n, 0);

    for (wchar_t c : cipherText) {
        size_t pos = alphabet.find(towlower(c));
        if (pos != wstring::npos) {
            counts[pos]++;
        }
    }

    int maxIndex = 0;
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        if (counts[i] > maxValue) {
            maxValue = counts[i];
            maxIndex = i;
        }
    }
    int targetIndex = alphabet.find(L'о');

    return maxIndex - targetIndex;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int choice, action;
    wstring text;

    cout << "\tCiphertext: \t" << endl;
    cout << "1.Enter text\n2.Read from file.\nChoice:" << endl;
    cin >> choice;
    cin.ignore();

    if (choice == 2) {
        wifstream fin("input.txt");
        if (!fin) { cerr << "File isnt found"; return 1; }
        getline(fin, text);
        fin.close();
    } else {
        cout << "Enter text: ";
        getline(wcin, text);
    }

    cout << "Do:\n 1.Cipher text\n 2.Decipher text\n";
    cin >> action;
    if (action == 1 || action == 2) {
        int shift;
        cout << "Enter key: ";
        cin >> shift;
        if (action == 2) shift = -shift;
        wcout << L"Result: " << caesarCipher(text, shift) << endl;
    }

    return 0;
}