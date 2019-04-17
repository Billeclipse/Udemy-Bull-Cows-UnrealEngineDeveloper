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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	// seturp a return variable
	FBullCowCount FBullCowCount;
	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters against the hidden word	
		for (int32 j = 0; j < GuessLength; j++) {
			// if they match thenadfasdf
			if (MyHiddenWord[i] == Guess[j]) {
				// if they're in the same place	
				if (i == j) {
					// incriment bulls
					FBullCowCount.Bulls++;
				}
				// else
				else {
					// incriment cows
					FBullCowCount.Cows++;
				}
			}
		}
	}
	return FBullCowCount;
}
