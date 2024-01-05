#ifndef KEYBOARDPRINT_H
#define KEYBOARDPRINT_H
#define RESET "\033[0m"

#include <iostream>
#include <vector>

using namespace std;

void printKeyTop(string colorCode) { 
    cout << colorCode << " --- " << RESET; 
}

void printKeyMiddle(char keyCharacter, string colorCode) { 
    cout << colorCode << "| " << keyCharacter << " |" << RESET; 
}

void printKeyBottom(string colorCode) { 
    cout << colorCode << " --- " << RESET; 
}

void printKeyboard(vector<vector<char>> keyboardLayout, vector<vector<string>> keyColors) 
{
    for (int row = 0; row < keyboardLayout.size(); row++){
        string paddingSpaces((50-(keyboardLayout[row].size() * 5))/2, ' '); 
        cout << paddingSpaces;
        for(int key = 0; key < keyboardLayout[row].size(); key++){
            printKeyTop(keyColors[row][key]);
        }
        cout << endl << paddingSpaces;
        for (int key = 0; key < keyboardLayout[row].size(); key++) {
            printKeyMiddle(keyboardLayout[row][key], keyColors[row][key]);
        }
        cout << endl << paddingSpaces;
        for (int key = 0; key < keyboardLayout[row].size(); key++) {
            printKeyBottom(keyColors[row][key]);
        }
        cout << endl;
    }
}

#endif