#ifndef GAME_H
#define GAME_H

#include <string>
#include <random>

class RockPaperScissors {
public:
    enum Choice {
        ROCK = 1,
        PAPER = 2,
        SCISSORS = 3
    };

private:
    int player1Score;
    int player2Score;
    int computerScore;
    std::mt19937 rng;
    
    // Helper methods for game logic
    std::string choiceToString(Choice choice);
    Choice getPlayerChoice(const std::string& playerName);
    Choice getComputerChoice();
    int determineWinner(Choice choice1, Choice choice2);
    bool playAgain();
    
    // Display methods
    void displayGameResult(Choice choice1, Choice choice2, int winner, 
                          const std::string& player1Name, const std::string& player2Name);
    void displayScore(const std::string& player1Name, const std::string& player2Name);
    void displayFinalScore(const std::string& player1Name, const std::string& player2Name);
    void displayMenu();
    void displayRules();

public:
    // Constructor
    RockPaperScissors();
    
    // Main game methods
    void resetScores();
    void playPlayerVsPlayer();
    void playPlayerVsComputer();
    void run();
};

#endif // GAME_H
