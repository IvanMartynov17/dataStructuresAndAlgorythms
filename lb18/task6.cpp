#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;


map<wstring, wstring> createMorseMap() {
    return {
        {L"А", L".-"},    {L"Б", L"-..."},  {L"В", L".--"},   {L"Г", L"...."},
        {L"Ґ", L"--."},   {L"Д", L"-.."},   {L"Е", L"."},     {L"Є", L"..-.."},
        {L"Ж", L"...-"},  {L"З", L"--.."},  {L"И", L"---."},  {L"І", L".."},
        {L"Ї", L".---."}, {L"Й", L".---"},  {L"К", L"-.-"},   {L"Л", L".-.."},
        {L"М", L"--"},    {L"Н", L"-."},    {L"О", L"---"},   {L"П", L".--."},
        {L"Р", L".-."},   {L"С", L"..."},   {L"Т", L"-"},     {L"У", L"..-"},
        {L"Ф", L"..-."},  {L"Х", L"...."},  {L"Ц", L"-.-."},  {L"Ч", L"---."},
        {L"Ш", L"----"},  {L"Щ", L"--.-"},  {L"Ь", L"-..-"},  {L"Ю", L"..--"},
        {L"Я", L".-.-"}
    };
}


void playMorseSound(const wstring& morseCode) {
    for (wchar_t c : morseCode) {
        if (c == L'.') Beep(800, 200);
        else if (c == L'-') Beep(800, 600);
        Sleep(100);
    }
    Sleep(300);
}


wstring encryptToMorse(const wstring& text, map<wstring, wstring>& morseMap) {
    wstring result = L"";
    for (wchar_t c : text) {
        wstring letter(1, towupper(c));
        if (morseMap.count(letter)) {
            result += morseMap[letter] + L" ";
        } else if (c == L' ') {
            result += L"/ ";
        }
    }
    return result;
}


wstring decryptFromMorse(const wstring& morse, map<wstring, wstring>& morseMap) {
    map<wstring, wstring> reverseMap;
    for (auto const& [key, val] : morseMap) reverseMap[val] = key;

    wstring result = L"", code;
    wstringstream ss(morse);
    while (ss >> code) {
        if (code == L"/") result += L" ";
        else if (reverseMap.count(code)) result += reverseMap[code];
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    auto morseMap = createMorseMap();
    int choice, action;
    wstring text, result;

    cout << "--- Morse Code ---\n";
    cout << "1. Console input\n2. Read from file (input.txt)\nChoice: ";
    cin >> choice; cin.ignore();

    if (choice == 2) {
        wifstream fin("C:/Users/User/Desktop/СДтаА/дз/шифрування");
        fin.imbue(locale("Ukrainian"));
        getline(fin, text, (wchar_t)EOF);
        fin.close();
    } else {
        cout << "Enter text: ";
        getline(wcin, text);
    }

    cout << "\n1. Encrypt (Text -> Morse)\n2. Decrypt (Morse -> Text)\nAction: ";
    cin >> action; cin.ignore();

    if (action == 1) {
        result = encryptToMorse(text, morseMap);
        wcout << L"\nMorse Code: " << result << endl;

        wofstream fout("output.txt");
        fout.imbue(locale("Ukrainian"));
        fout << result; fout.close();

        cout << "Sound playback starting..." << endl;
        playMorseSound(result);
    } else {
        result = decryptFromMorse(text, morseMap);
        wcout << L"\nDecrypted: " << result << endl;

        wofstream fout("output.txt");
        fout.imbue(locale("Ukrainian"));
        fout << result; fout.close();
    }

    cout << "\nResults saved to output.txt" << endl;
    return 0;
}