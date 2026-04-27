#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main() {
    map<string, int> wordCount;
    string line, word;


    cout << "Enter the text: ";
    getline(cin, line);

    istringstream stream(line);
    while (stream >> word) {
        wordCount[word]++;
    }

    cout << "Word count: ";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
    return 0;
}