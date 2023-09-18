#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;
map<char, string> createEnglishToMorseMap() {
    map<char, string> englishToMorse;
    englishToMorse['A'] = ".-";
    englishToMorse['B'] = "-...";
    englishToMorse['C'] = "-.-.";
    englishToMorse['D'] = "-..";
    englishToMorse['E'] = ".";
    englishToMorse['F'] = "..-.";
    englishToMorse['G'] = "--.";
    englishToMorse['H'] = "....";
    englishToMorse['I'] = "..";
    englishToMorse['J'] = ".---";
    englishToMorse['K'] = "-.-";
    englishToMorse['L'] = ".-..";
    englishToMorse['M'] = "--";
    englishToMorse['N'] = "-.";
    englishToMorse['O'] = "---";
    englishToMorse['P'] = ".--.";
    englishToMorse['Q'] = "--.-";
    englishToMorse['R'] = ".-.";
    englishToMorse['S'] = "...";
    englishToMorse['T'] = "-";
    englishToMorse['U'] = "..-";
    englishToMorse['V'] = "...-";
    englishToMorse['W'] = ".--";
    englishToMorse['X'] = "-..-";
    englishToMorse['Y'] = "-.--";
    englishToMorse['Z'] = "--..";
    englishToMorse['0'] = "-----";
    englishToMorse['1'] = ".----";
    englishToMorse['2'] = "..---";
    englishToMorse['3'] = "...--";
    englishToMorse['4'] = "....-";
    englishToMorse['5'] = ".....";
    englishToMorse['6'] = "-....";
    englishToMorse['7'] = "--...";
    englishToMorse['8'] = "---..";
    englishToMorse['9'] = "----.";
    englishToMorse['.'] = ".-.-.-";
    englishToMorse[','] = "--..--";
    englishToMorse['?'] = "..--..";
    englishToMorse['!'] = "-.-.--";
    englishToMorse['\''] = ".----.";
    englishToMorse['\"'] = ".-..-.";
    englishToMorse['('] = "-.--.";
    englishToMorse[')'] = "-.--.-";
    englishToMorse['&'] = ".-...";
    englishToMorse[':'] = "---...";
    englishToMorse[';'] = "-.-.-.";
    englishToMorse['/'] = "-..-.";
    englishToMorse['_'] = "..--.-";
    englishToMorse['='] = "-...-";
    englishToMorse['+'] = ".-.-.";
    englishToMorse['-'] = "-....-";
    englishToMorse['$'] = "...-..-";
    englishToMorse['@'] = ".--.-.";
    englishToMorse[' '] = " ";
    return englishToMorse;
}
map<string, char> createMorseToEnglishMap() {
    map<string, char> morseToEnglish;
    map<char, string> englishToMorse = createEnglishToMorseMap();
    for (const auto& entry : englishToMorse) {
        morseToEnglish[entry.second] = entry.first;
    }
    return morseToEnglish;
}
void translateEnglishToMorse(map<char, string>& englishToMorse) {
    cout << "Enter English text: ";
    string englishText;
    getline(cin, englishText);
    stringstream morseCode;
    for (char c : englishText) {
        if (englishToMorse.find(toupper(c)) != englishToMorse.end()) {
            morseCode << englishToMorse[toupper(c)] << " ";
        }
    }
    cout << "Morse Code: " << morseCode.str() << endl;
}
void translateMorseToEnglish(map<string, char>& morseToEnglish) {
    cout << "Enter Morse code: ";
    string morseCode;
    getline(cin, morseCode);
    stringstream englishText;
    vector<string> morseWords;
    size_t start = 0, end = morseCode.find(" / ");
    while (end != string::npos) {
        morseWords.push_back(morseCode.substr(start, end - start));
        start = end + 3;
        end = morseCode.find(" / ", start);
    }
    morseWords.push_back(morseCode.substr(start));
    for (const string& morseWord : morseWords) {
        vector<string> morseChars;
        start = 0;
        end = morseWord.find(' ');
        while (end != string::npos) {
            morseChars.push_back(morseWord.substr(start, end - start));
            start = end + 1;
            end = morseWord.find(' ', start);
        }
        morseChars.push_back(morseWord.substr(start));
        for (const string& morseChar : morseChars) {
            if (morseToEnglish.find(morseChar) != morseToEnglish.end()) {
                englishText << morseToEnglish[morseChar];
            }
        }
        englishText << ' ';
    }
    cout << "English Text: " << englishText.str() << endl;
}
int main() {
    map<char, string> englishToMorse = createEnglishToMorseMap();
    map<string, char> morseToEnglish = createMorseToEnglishMap();
    bool continueTranslating = true;
    while (continueTranslating) {
        cout << "Enter '1' to translate English to Morse code" << endl;
        cout << "Enter '2' to translate Morse code to English" << endl;
        cout << "Enter '0' to exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 0:
                continueTranslating = false;
                break;
            case 1:
                translateEnglishToMorse(englishToMorse);
                break;
            case 2:
                translateMorseToEnglish(morseToEnglish);
                break;
            default:
                cout << "Invalid choice. Please enter '1', '2', or '0' to exit." << endl;
        }
    }
    return 0;
}