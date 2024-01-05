#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <vector>
#include <cstdlib> 

void printKeyTop(std::string keyColor) {
    std::cout << keyColor << " --- " << RESET;
}
void printKeyMiddle(char character, std::string keyColor) {
    std::cout << keyColor << "| " << character << " |" << RESET;
}
void printKeyBottom(std::string keyColor) {
    std::cout << keyColor << " --- " << RESET;
}

void displayWordleBoard(std::vector<std::string> playerGuesses, std::string correctAnswer, std::string gameStatus, std::vector<std::vector<std::string>> keyColors, int letterCount){
    std::system("cls");

    for (int guessIndex = 0; guessIndex < playerGuesses.size(); guessIndex++){ 
        for (int letterIndex = 0; letterIndex < letterCount; letterIndex++){
            printKeyTop(keyColors[guessIndex][letterIndex]); 
        }
        std::cout << std::endl;
        for (int letterIndex = 0; letterIndex < letterCount; letterIndex++){
            printKeyMiddle(playerGuesses[guessIndex][letterIndex], keyColors[guessIndex][letterIndex]); 
        }
        std::cout << std::endl; 
        for (int letterIndex = 0; letterIndex < letterCount; letterIndex++){
            printKeyBottom(keyColors[guessIndex][letterIndex]);
        }
        std::cout << std::endl;
    }   
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    if (gameStatus == "win"){
        std::cout << std::endl;
        std::cout << "Splendid!" << std::endl;
        std::cout << std::endl;
        std::cout << "Press [enter] to continue";
    }
    else if (gameStatus == "lose"){
        std::cout << std::endl;
        std::cout << "The word was: " << correctAnswer << std::endl;
        std::cout << std::endl;
        std::cout << "Better luck next time!" << std::endl;
        std::cout << std::endl;
        std::cout << "Press [enter] to continue";
    }
}
#endif