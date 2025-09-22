#include "game.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cctype>

// Constructor
RockPaperScissors::RockPaperScissors() : player1Score(0), player2Score(0), computerScore(0) {
    rng.seed(static_cast<unsigned int>(std::time(nullptr)));
}

// Helper method implementations
std::string RockPaperScissors::choiceToString(Choice choice) {
    switch(choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "Invalid";
    }
}

RockPaperScissors::Choice RockPaperScissors::getPlayerChoice(const std::string& playerName) {
    int choice;
    while(true) {
        std::cout << "\n" << playerName << ", enter your choice:\n";
        std::cout << "1. Rock\n";
        std::cout << "2. Paper\n";
        std::cout << "3. Scissors\n";
        std::cout << "Choice: ";
        
        if(std::cin >> choice && choice >= 1 && choice <= 3) {
            std::cin.ignore(); // Clear input buffer
            return static_cast<Choice>(choice);
        } else {
            std::cout << "Invalid input! Please enter 1, 2, or 3.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}

RockPaperScissors::Choice RockPaperScissors::getComputerChoice() {
    std::uniform_int_distribution<int> dist(1, 3);
    return static_cast<Choice>(dist(rng));
}

int RockPaperScissors::determineWinner(Choice choice1, Choice choice2) {
    if(choice1 == choice2) {
        return 0; // Tie
    }
    
    if((choice1 == ROCK && choice2 == SCISSORS) ||
       (choice1 == PAPER && choice2 == ROCK) ||
       (choice1 == SCISSORS && choice2 == PAPER)) {
        return 1; // Player 1 wins
    }
    
    return 2; // Player 2 wins
}

bool RockPaperScissors::playAgain() {
    std::string input;
    while(true) {
        std::cout << "Do you want to play another round? (y/n): ";
        std::getline(std::cin, input);
        
        // Convert to lowercase
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        
        if(input == "y" || input == "yes") {
            return true;
        } else if(input == "n" || input == "no") {
            return false;
        } else {
            std::cout << "Please enter 'y' for yes or 'n' for no.\n";
        }
    }
}

void RockPaperScissors::resetScores() {
    player1Score = 0;
    player2Score = 0;
    computerScore = 0;
}

void RockPaperScissors::playPlayerVsPlayer() {
    resetScores();
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "         PLAYER VS PLAYER MODE\n";
    std::cout << std::string(50, '=') << "\n";
    
    std::string player1Name, player2Name;
    std::cout << "Enter Player 1 name: ";
    std::getline(std::cin, player1Name);
    std::cout << "Enter Player 2 name: ";
    std::getline(std::cin, player2Name);
    
    if(player1Name.empty()) player1Name = "Player 1";
    if(player2Name.empty()) player2Name = "Player 2";
    
    do {
        Choice player1Choice = getPlayerChoice(player1Name);
        Choice player2Choice = getPlayerChoice(player2Name);
        
        int winner = determineWinner(player1Choice, player2Choice);
        
        if(winner == 1) player1Score++;
        else if(winner == 2) player2Score++;
        
        displayGameResult(player1Choice, player2Choice, winner, player1Name, player2Name);
        displayScore(player1Name, player2Name);
        
    } while(playAgain());
    
    displayFinalScore(player1Name, player2Name);
}

void RockPaperScissors::playPlayerVsComputer() {
    resetScores();
    std::cout << "\n" << std::string(50, '=') << "\n";
    std::cout << "        PLAYER VS COMPUTER MODE\n";
    std::cout << std::string(50, '=') << "\n";
    
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);
    
    if(playerName.empty()) playerName = "Player";
    
    do {
        Choice playerChoice = getPlayerChoice(playerName);
        Choice computerChoice = getComputerChoice();
        
        int winner = determineWinner(playerChoice, computerChoice);
        
        if(winner == 1) player1Score++;
        else if(winner == 2) computerScore++;
        
        displayGameResult(playerChoice, computerChoice, winner, playerName, "Computer");
        
        std::cout << "\nCurrent Score:\n";
        std::cout << playerName << ": " << player1Score << "\n";
        std::cout << "Computer: " << computerScore << "\n\n";
        
    } while(playAgain());
    
    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "         FINAL SCORE\n";
    std::cout << std::string(40, '-') << "\n";
    std::cout << playerName << ": " << player1Score << "\n";
    std::cout << "Computer: " << computerScore << "\n";
    
    if(player1Score > computerScore) {
        std::cout << "\nCongratulations " << playerName << "! You won overall!\n";
    } else if(computerScore > player1Score) {
        std::cout << "\nComputer wins overall! Better luck next time!\n";
    } else {
        std::cout << "\nIt's an overall tie! Great game!\n";
    }
    std::cout << std::string(40, '=') << "\n";
}

void RockPaperScissors::run() {
    int choice;
    
    std::cout << "Welcome to Rock Paper Scissors!\n";
    
    while(true) {
        displayMenu();
        
        if(std::cin >> choice) {
            std::cin.ignore(); // Clear input buffer
            
            switch(choice) {
                case 1:
                    playPlayerVsPlayer();
                    break;
                case 2:
                    playPlayerVsComputer();
                    break;
                case 3:
                    displayRules();
                    break;
                case 4:
                    std::cout << "\nThank you for playing Rock Paper Scissors!\n";
                    std::cout << "Goodbye! 👋\n\n";
                    return;
                default:
                    std::cout << "\nInvalid choice! Please enter a number between 1 and 4.\n";
                    break;
            }
        } else {
            std::cout << "\nInvalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}
