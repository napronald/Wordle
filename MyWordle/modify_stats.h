#ifndef MODIFY_STATS_H
#define MODIFY_STATS_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>

void readGameStats(GameStats& gameStats) {
    std::ifstream statsFile("stats.txt");
    if (statsFile) {
        gameStats.guessedWords.clear();
        gameStats.attemptCounts.clear();
        gameStats.winStatuses.clear();
        statsFile >> gameStats.state
             >> gameStats.totalPlays
             >> gameStats.avgAttempts
             >> gameStats.winRate
             >> gameStats.streakCurrent
             >> gameStats.streakLongest;
        std::string statsLine;
        getline(statsFile, statsLine);
        while (getline(statsFile, statsLine)) {
            std::istringstream iss(statsLine); 
            std::string guessedWord, winStatus;
            int attemptCount; 
            iss >> guessedWord >> attemptCount >> winStatus;
            
            gameStats.guessedWords.push_back(guessedWord);
            gameStats.attemptCounts.push_back(attemptCount);
            gameStats.winStatuses.push_back(winStatus);
        }
        gameStats.state = 1;
    } else {
        std::cerr << "Error: Could not open the stats file.\n";
    }
}

void updateGameStats(GameStats& gameStats){
    std::ofstream statsFile("stats.txt", std::ios::trunc); 
    if (statsFile.is_open()){
        int totalWins = 0, sumAttempts = 0, ongoingStreak = 0, maxStreak = 0;
        for (std::string win : gameStats.winStatuses) {
            if (win == "Yes"){
                totalWins++, ongoingStreak++;
                if (ongoingStreak > maxStreak) maxStreak = ongoingStreak;
            } else ongoingStreak = 0;
        }
    
        for (int attempt : gameStats.attemptCounts) sumAttempts += attempt; 
        gameStats.totalPlays = gameStats.guessedWords.size();
        gameStats.avgAttempts = gameStats.totalPlays ? sumAttempts/gameStats.attemptCounts.size() : 0; 
        gameStats.winRate = gameStats.totalPlays ? ((float)totalWins/gameStats.winStatuses.size()) * 100 : 0;
        gameStats.streakCurrent = ongoingStreak, gameStats.streakLongest = maxStreak;
        statsFile << gameStats.state << ' ' << gameStats.totalPlays << ' ' << gameStats.avgAttempts << ' ' << gameStats.winRate << ' ' << gameStats.streakCurrent << ' ' << gameStats.streakLongest << '\n';
        for (int i = 0; i < gameStats.guessedWords.size(); i++){
            statsFile << gameStats.guessedWords[i] << ' ' << gameStats.attemptCounts[i] << ' ' << gameStats.winStatuses[i] << '\n';
        }
        statsFile.close();
    } else std::cerr << "Error: Could not open the stats file." << std::endl;
}

void clearStatsFile() {
    std::ofstream statsFile("stats.txt", std::ios::trunc); 
    if(statsFile.is_open()){
        statsFile << "1 0 0 0 0 0"; 
        statsFile.close();
    } else std::cerr << "Error: Could not open the stats file." << std::endl;     
}
#endif