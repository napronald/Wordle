#ifndef STATS_SCREEN_H
#define STATS_SCREEN_H

#include <iostream>
#include <vector>
#include <iomanip>

void print_stats_screen(
    int timesPlayed,
    int averageAttempts,
    int winPercentage,
    int currentStreak,
    int longestStreak,
    std::vector<std::string> Words,
    std::vector<int> Attempts,
    std::vector<std::string> Wins,
    int Number_of_Letters
) {
    std::cout << "==========================" << std::endl;
    std::cout << "   STATISTICS SUMMARY     " << std::endl;
    std::cout << "==========================" << std::endl;
    std::cout << "Times Played:" << std::setw(13) << std::right << timesPlayed << std::endl;
    std::cout << "Average Attempts:" << std::setw(9) << std::right << averageAttempts << std::endl;
    std::cout << "Win Percentage:" << std::setw(10) << std::right << winPercentage << "%" << std::endl;
    std::cout << "Current Streak:" << std::setw(11) << std::right << currentStreak << std::endl;
    std::cout << "Longest Streak:" << std::setw(11) << std::right << longestStreak << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
    std::cout << "--------------------------" << std::endl;
    for (int i = 0; i < Words.size(); i++) {
        std::cout << Words[i] << std::setw(17 - Words[i].length()) << std::right << Attempts[i] << std::setw(9) << std::right << Wins[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Press [enter] to continue" << std::endl;
}

#endif