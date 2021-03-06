/*
	This is the console executable, that makes use of the BullCow class
	This acts as the view in a MVC pattern, and is responsible for all
	user interaction. For game logic see the FBullCowGame class.
*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
Ftext GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main()
{	
	do
	{			
		PrintIntro();
		PlayGame();
	}while(AskToPlayAgain());	
	return 0;
}

void PrintIntro()
{
	// introduce the game
	std::cout << "\nWelcome to Bull and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram i'm thiking of?" << std::endl << std::endl;
}

void PlayGame()
{
	// loop asking for guesses while the game
	// is NOT won and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries())
	{
		Ftext guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	PrintGameSummary();
	BCGame.Reset();
	return;
}

bool AskToPlayAgain()
{
	if (BCGame.HasMoreWords()) {
		std::cout << "Do you want to play again (y/n)?";
		Ftext Responce = "";
		getline(std::cin, Responce);
		return (Responce[0] == 'y' || Responce[0] == 'Y');
	}
	else {
		std::cout << "Congratulations! You found all the words available.";
		return false;
	}
	
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "You Won!" << std::endl << std::endl;
	}
	else {
		std::cout << "You Lost!" << std::endl << std::endl;
	}
}

// loop continually until the user gives a valid guess
Ftext GetValidGuess()
{
	EGuessStatus status = EGuessStatus::INVALID;
	Ftext guess = "";
	do {
		// get a guess from the player		
		std::cout << "Try " << BCGame.GetCurrentTry() << " out of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		getline(std::cin, guess);

		status = BCGame.IsGuessValid(guess);
		switch (status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "Please enter an isogram." << std::endl;
			break;
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "Please enter all lowercase letters." << std::endl;
			break;
		default:
			// assume the error is valid
			break;
		}
	} while ( status != EGuessStatus::OK);
	return guess;
}