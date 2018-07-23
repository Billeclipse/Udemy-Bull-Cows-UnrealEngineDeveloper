#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::IsGuessValid(FString)
{
	return false;
}

// receives a VALID guess, increments turn, and returns count
// counts bulls & cows, and increases try # assuming valid guess
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment turn number
	MyCurrentTry++;

	// seturp a return variable
	BullCowCount BullCowCount;
	// loop through all letters in the guess
		// compare letters against the hidden word

	return BullCowCount;
}
