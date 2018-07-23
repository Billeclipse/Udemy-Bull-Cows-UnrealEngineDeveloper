// Main of BullCowGame.cpp

#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
std::string GetGuess();
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
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bull and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram i'm thiking of?" << std::endl;
}

std::string GetGuess()
{
	// get a guess from the player
	std::string Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";	
	getline(std::cin, Guess);
	return Guess;
}

void PlayGame()
{	
	for (int count = 0; count < BCGame.GetMaxTries(); count++)
	{		
		// repeat the guess back to them
		std::cout << "Your guess was: " << GetGuess() << std::endl << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?";
	std::string Responce = "";
	getline(std::cin, Responce);
	return (Responce[0] == 'y' || Responce[0] == 'Y');
}