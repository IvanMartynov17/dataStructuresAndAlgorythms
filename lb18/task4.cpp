#include <iostream>
#include <string>
#include <vector>

using namespace std;

char square[5][5] = {
    {'a','b','c','d','e'},
    {'f','g','h','i','k'},
    {'l','m','n','o','p'},
    {'q','r','s','t','u'},
    {'v','w','x','y','z'}
};

string polybiusEncrypt(string text) {
    string result = "";
    for (char c : text) {
        char l = (tolower(c) == 'j') ? 'i' : tolower(c);
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                if(square[i][j] == l) result += to_string(i+1) + to_string(j+1) + " ";
    }
    return result;
}

int main() {
    string text;
    cout << "-- Polybius Square --\nEnter text: "; getline(cin, text);
    cout << "Encrypted: " << polybiusEncrypt(text) << endl;
    return 0;
}