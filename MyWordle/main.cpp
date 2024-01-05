#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <vector>
#include <cstdlib>  

struct GameStats {
    int state, totalPlays, avgAttempts, winRate, streakCurrent, streakLongest;
    std::vector<std::string> guessedWords, winStatuses;
    std::vector<int> attemptCounts;
};

#include "wordle.h"
#include "modify_stats.h"
#include "menu_screen.h"
#include "stats_screen.h"
#include "tutorial_screen.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Invalid number of arguments." << std::endl;
        exit(0);
    }
    std::vector<int> validWordCounts = {2267, 3937, 6881, 8913, 9023};
    GameStats gameStats;
    std::string playerChoice;
    int wordLength = std::stoi(argv[1]);
    std::string guessesFilename = argv[3];
    std::string wordlistFilename = argv[2];

    std::system(CLEAR_SCREEN);
    readGameStats(gameStats); 
    updateGameStats(gameStats); 

    displayMainMenu();

    while (std::cin >> playerChoice) {
        std::cin.ignore();
        if (playerChoice == "5") {
            gameStats.state = 0;
            updateGameStats(gameStats);
            std::system(CLEAR_SCREEN);
            break;
        } else if (playerChoice == "1") {
            std::system(CLEAR_SCREEN);
            gameStats.state = 2;
            updateGameStats(gameStats);
            startGame(gameStats, wordlistFilename, guessesFilename, wordLength, validWordCounts);
            gameStats.state = 1;
            updateGameStats(gameStats);
        } else if (playerChoice == "2") {
            while (!playerChoice.empty()) {
                std::system(CLEAR_SCREEN);
                print_Tutorial_screen();
                std::getline(std::cin, playerChoice);
            }
        } else if (playerChoice == "3") {
            while (!playerChoice.empty()) {
                std::system(CLEAR_SCREEN);
                print_stats_screen(
                    gameStats.totalPlays, 
                    gameStats.avgAttempts, 
                    gameStats.winRate, 
                    gameStats.streakCurrent, 
                    gameStats.streakLongest, 
                    gameStats.guessedWords, 
                    gameStats.attemptCounts, 
                    gameStats.winStatuses,
                    wordLength);
                std::getline(std::cin, playerChoice);
            }
        } else if (playerChoice == "4") {
            clearStatsFile();
            readGameStats(gameStats);
            while (!playerChoice.empty()) {
                std::system(CLEAR_SCREEN);
                print_stats_screen(
                    gameStats.totalPlays, 
                    gameStats.avgAttempts, 
                    gameStats.winRate, 
                    gameStats.streakCurrent, 
                    gameStats.streakLongest, 
                    gameStats.guessedWords, 
                    gameStats.attemptCounts, 
                    gameStats.winStatuses,
                    wordLength);
                std::getline(std::cin, playerChoice);
            }
        }

        std::system(CLEAR_SCREEN);
        displayMainMenu();
    }

    return 0;
}
