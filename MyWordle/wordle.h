#ifndef WORDLE_H
#define WORDLE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
#include <cstdlib>
#include <bits/stdc++.h>
#include <cmath>
#include "main_screen.h"
#include <cctype> 
#include <random>
#include <vector>
#include <fstream>
#include <iostream>

std::string randomWordle(const std::string& wordlistFilename) {
    std::vector<std::string> words;
    std::string word;
    std::ifstream file(wordlistFilename);

    while (file >> word) {
        words.push_back(word);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, words.size() - 1);

    int randomIndex = distr(gen);
    return words[randomIndex];
}

std::vector<std::string> guessColors(std::string guess_upper, std::string answer_upper, int Number_of_Letters) {
    std::vector<std::string> color(Number_of_Letters, BLACK);
  
    for (int i = 0; i < Number_of_Letters*2; i++) {
        size_t index = answer_upper.find(guess_upper[(i % Number_of_Letters)]); 

        if (std::floor((float)i/float(Number_of_Letters)) == 0) {
            if (index != std::string::npos && index == (i % Number_of_Letters)) {
                color[index] = GREEN;
                answer_upper[index] = ' ';
            }
        
        } else {
            if (index != std::string::npos) {
                color[i % Number_of_Letters] = YELLOW;
                answer_upper[index] = ' ';
            }
        }
    }
    return color;
}
  

void updateKeyboard(std::vector<std::vector<std::string>> colors, std::string guess_upper, int Number_of_Letters) {
    std::string black_keys;
    std::string yellow_keys;
    std::string green_keys;

    std::ifstream keyboard_file_in("keyboard.txt");

    if (keyboard_file_in.is_open()) {
        std::string line;
        std::getline(keyboard_file_in, line);
        black_keys = line + std::string(Number_of_Letters, ' ');
        std::getline(keyboard_file_in, line);
        yellow_keys = line + std::string(Number_of_Letters, ' ');
        std::getline(keyboard_file_in, line);
        green_keys = line + std::string(Number_of_Letters, ' ');
    } else std::cerr << "Error: File could not be opened" << std::endl;
    keyboard_file_in.close();

    std::ofstream keyboard_file_out("keyboard.txt", std::ios::trunc);
    if (keyboard_file_out.is_open()) {
        for (int i = 0; i < Number_of_Letters; i++) {
            if (colors.back()[i] == BLACK) {
                black_keys[black_keys.size()-Number_of_Letters+i] = guess_upper[i];
            } else if (colors.back()[i] == YELLOW) {
                yellow_keys[yellow_keys.size()-Number_of_Letters+i] = guess_upper[i];
            } else if (colors.back()[i] == GREEN) {
                green_keys[green_keys.size()-Number_of_Letters+i] = guess_upper[i];
            }
        }
        keyboard_file_out << black_keys << '\n' << yellow_keys << '\n' << green_keys;
    } else std::cerr << "Error: File could not be opened" << std::endl;
    keyboard_file_out.close();
}


void startGame(GameStats& stats, const std::string& Possible_words_file_name, const std::string& AllowedGuesses_words_file_name, int Number_of_Letters, const std::vector<int>& listOfNumbers_in_Texts) {
    std::vector<std::string> guesses;
    std::vector<std::vector<std::string>> colors;
    std::string gameState = "active";
    bool valid_guess = false; 
    std::string answer = randomWordle(Possible_words_file_name);
    std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

    while (gameState == "active") {
        valid_guess = false;  
        std::string guess;
        std::string line;

        while (!valid_guess) {
            std::ifstream allowed_words_file(AllowedGuesses_words_file_name);
            std::ifstream answer_words_file(Possible_words_file_name);
            std::cout << "Enter guess: ";
            std::cin >> guess;
            while (std::getline(allowed_words_file, line) || std::getline(answer_words_file, line)) {
                if (guess == line) {
                    valid_guess = true;
                    break;
                }
            }
            allowed_words_file.close();
            answer_words_file.close();
        }

        std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        guesses.push_back(guess);
        colors.push_back(guessColors(guess, answer, Number_of_Letters));
        updateKeyboard(colors, guess, Number_of_Letters);

        if (guess == answer) {
            gameState = "win";
        } else if (guesses.size() == 6) {  
            gameState = "lose";
        }
        displayWordleBoard(guesses, answer, gameState, colors, Number_of_Letters);
    }
    stats.guessedWords.push_back(answer);
    stats.attemptCounts.push_back(guesses.size());
    stats.winStatuses.push_back((gameState == "win" ? "Yes" : "No"));
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
    while (!gameState.empty()) std::getline(std::cin, gameState);
}
#endif