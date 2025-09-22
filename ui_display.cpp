#include "game.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

void RockPaperScissors::displayGameResult(Choice choice1, Choice choice2, int winner, 
                      const std::string& player1Name, const std::string& player2Name) {
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << player1Name << " chose: " << choiceToString(choice1) << "\n";
    std::cout << player2Name << " chose: " << choiceToString(choice2) << "\n";
    std::cout << std::string(40, '-') << "\n";
    
    if(winner == 0) {
        std::cout << "It's a tie!\n";
    } else if(winner == 1) {
        std::cout << player1Name << " wins this round!\n";
    } else {
        std::cout << player2Name << " wins this round!\n";
    }
    std::cout << std::string(40, '=') << "\n";
}

void RockPaperScissors::displayScore(const std::string& player1Name, const std::string& player2Name) {
    std::cout << "\nCurrent Score:\n";
    std::cout << player1Name << ": " << player1Score << "\n";
    std::cout << player2Name << ": " << player2Score << "\n\n";
}

void RockPaperScissors::displayFinalScore(const std::string& player1Name, const std::string& player2Name) {
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "         FINAL SCORE\n";
    std::cout << std::string(40, '-') << "\n";
    std::cout << player1Name << ": " << player1Score << "\n";
    std::cout << player2Name << ": " << player2Score << "\n";
    
    if(player1Score > player2Score) {
        std::cout << "\nCongratulations " << player1Name << "! You won overall!\n";
    } else if(player2Score > player1Score) {
        std::cout << "\nCongratulations " << player2Name << "! You won overall!\n";
    } else {
        std::cout << "\nIt's an overall tie! Great game!\n";
    }
    std::cout << std::string(40, '=') << "\n";
}

void RockPaperScissors::displayMenu() {
    std::cout << "\n" << std::string(50, '*') << "\n";
    std::cout << "        ROCK PAPER SCISSORS GAME\n";
    std::cout << std::string(50, '*') << "\n";
    std::cout << "1. Player vs Player\n";
    std::cout << "2. Player vs Computer\n";
    std::cout << "3. Game Rules\n";
    std::cout << "4. Exit\n";
    std::cout << std::string(50, '-') << "\n";
    std::cout << "Enter your choice (1-4): ";
}

void RockPaperScissors::displayRules() {
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "                 GAME RULES\n";
    std::cout << std::string(50, '=') << "\n";
    std::cout << "Rock Paper Scissors is a classic hand game played between\n";
    std::cout << "two players. Each player simultaneously forms one of three\n";
    std::cout << "shapes with their hand:\n\n";
    std::cout << "ROCK     - Crushes Scissors\n";
    std::cout << "PAPER    - Covers Rock\n";
    std::cout << "SCISSORS - Cuts Paper\n\n";
    std::cout << "WINNING CONDITIONS:\n";
    std::cout << "Rock beats Scissors\n";
    std::cout << "Paper beats Rock\n";
    std::cout << "Scissors beats Paper\n";
    std::cout << "Same choice = Tie\n\n";
    std::cout << "GAME MODES:\n";
    std::cout << "Player vs Player: Two human players compete\n";
    std::cout << "Player vs Computer: Play against the computer\n";
    std::cout << std::string(50, '=') << "\n";
    
    std::cout << "\nPress Enter to return to main menu...";
    std::cin.ignore();
    std::string dummy;
    std::getline(std::cin, dummy);
}
