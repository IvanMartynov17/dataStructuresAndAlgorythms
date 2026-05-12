#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct Position {
    int r, c;
};

void generateMatrix(string key, char matrix[5][5]) {
    string alphabet = "abcdefghiklmnopqrstuvwxyz";
    string combined = "";

    for (char c : key) {
        c = (char)tolower(c);
        if (c == 'j')
            c = 'i';

        if (isalpha(c) && combined.find(c) == string::npos) {
            combined += c;
        }
    }

    for (char c : alphabet) {
        if (combined.find(c) == string::npos) {
            combined += c;
        }
    }

    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = combined[k++];
        }
    }
}

void printMatrix(char matrix[5][5]) {
    cout << "\tMatrix: \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

Position findPosition(char matrix[5][5], char c) {
    if (c == 'j') c = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == c)
                return {i, j};
        }
    }
    return {-1, 1};
}

string processText (string text, char matrix[5][5], bool encrypt) {
    string preparedText = "";
    for (char c : text) {
        if (isalpha(c)) preparedText += (char)tolower(c);
    }

    string bi = "";
    for (size_t i = 0; i < preparedText.size(); i += 2) {
        bi += preparedText[i];
        if (i + 1 < preparedText.size() && preparedText[i] == preparedText[i + 1]) {
            bi = 'x';
        }else if (i + 1 < preparedText.size()) {
            bi += preparedText[i++];
        }else {
            bi += 'x';
        }
    }
    string result = "";
    int shift = encrypt ? 1 : -1;

    for (size_t i = 0; i < bi.length(); i += 2) {
        Position p1 = findPosition(matrix, bi[i]);
        Position p2 = findPosition(matrix, bi[i+1]);

        if (p1.r == p2.r) {
            result += matrix[p1.r][(p1.c + shift + 5) % 5];
            result += matrix[p2.r][(p2.c + shift + 5) % 5];
        } else if (p1.c == p2.c) {
            result += matrix[(p1.r + shift + 5) % 5][p1.c];
            result += matrix[(p2.r + shift + 5) % 5][p2.c];
        } else {
            result += matrix[p1.r][p2.c];
            result += matrix[p2.r][p1.c];
        }
    }
    return result;
}

int main() {
    char matrix[5][5];
    string text, key;
    int choice, action;

    cout << "\t-- Playfair Cipher (English) --\n\n";
    cout << "1. Manual input\n2. Read from file (input.txt)\nChoice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 2) {
        ifstream fin("input.txt");
        if (!fin.is_open()) {
            cerr << "File not found!" << endl;
            return 1;
        }
        getline(fin, text, '\0');
        fin.close();
    } else {
        cout << "Enter text: ";
        getline(cin, text);
    }

    cout << "Enter keyword: ";
    getline(cin, key);

    generateMatrix(key, matrix);
    printMatrix(matrix);

    cout << "\nChoose action:\n1. Encrypt\n2. Decrypt\nChoice: ";
    cin >> action;

    bool isEncrypt = (action == 1);
    string result = processText(text, matrix, isEncrypt);

    cout << "\nResult: " << result << endl;

    return 0;
}