/*
	This is the console executable, that makes use of the BullCow class
	This acts as the view in a MVC pattern, and is responsible for all
	user interaction. For game logic see the FBullCowGame class.

*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
Ftext GetGuess();
void PlayGame();
bool AskToPlayAgain();

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
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bull and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram i'm thiking of?" << std::endl;
}

Ftext GetGuess()
{
	// get a guess from the player
	Ftext Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";	
	getline(std::cin, Guess);
	return Guess;
}

void PlayGame()
{	
	BCGame.Reset();

	// loop for the number of turns asking for guesses
	// TODO change from for to while loop once we are validation tries
	for (int32 count = 0; count < BCGame.GetMaxTries(); count++)
	{
		Ftext guess = GetGuess(); // TODO make loop checking valid
		
		// submit valid guess to the game
		// print number of bulls and cows
		std::cout << "Your guess was: " << guess << std::endl << std::endl;
	}

	// TODO summarise game
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	Ftext Responce = "";
	getline(std::cin, Responce);
	return (Responce[0] == 'y' || Responce[0] == 'Y');
}