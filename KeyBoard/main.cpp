#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <fstream>
#include <vector>
#include "keyboardprint.h"

using namespace std;

int main(int argc, char* argv[]) {
    int currentGameState = 0;
    int previousGameState;
    string keyboardLine;
    vector <string> colorCodes = {BLACK, YELLOW, GREEN, RESET};
    vector <vector<string>> currentColors;
    vector <vector<string>> previousColors = {{RESET}};
    vector <vector<char>> keyboardLayout = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}, {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'}, {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};

    while(true) {
        ifstream gameStateFile("../wordle/stats.txt");
        if (gameStateFile.is_open()){
            gameStateFile >> currentGameState;
        if (currentGameState == 0){ 
            if (previousGameState != currentGameState){
                system("cls");
                cout << "Please launch the Wordle game." << endl;
                ofstream keyboardFile("../wordle/keyboard.txt", ios::trunc);
                keyboardFile.close();
                previousGameState = currentGameState;
                previousColors = {{RESET}};
            }
        }
        else if (currentGameState == 1){ 
            if (previousGameState != currentGameState){
                system("cls");
                cout << "Waiting for Wordle game round to start." << endl;
                ofstream keyboardFile("../wordle/keyboard.txt", ios::trunc);
                keyboardFile.close();
                previousGameState = currentGameState;
                previousColors = {{RESET}};

            }
        }
        else {
            previousGameState = currentGameState;
            currentColors.clear();
            for (vector<char> keyboardRow : keyboardLayout){
                currentColors.push_back({});
                for (char key : keyboardRow){
                    ifstream colorFile("../wordle/keyboard.txt");
                    currentColors.back().push_back(colorCodes[3]);
                    if (colorFile.is_open()){ 
                        for (int i = 0; i<3; i++){ 
                            getline(colorFile, keyboardLine);
                            if (keyboardLine.find(key) != string::npos) currentColors.back().back() = colorCodes[i];
                        }
                    }
                    else cerr<< "Color file could not be opened." << endl;
                }
            }
            if (previousColors != currentColors) {
                system("cls");
                printKeyboard(keyboardLayout, currentColors);
                previousColors = currentColors;
            }
        }
    }
            else cerr<< "Game state file could not be opened." << endl;
                gameStateFile.close();
    }
    return 0;
}
