#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{	
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
}

EGuessStatus FBullCowGame::IsGuessValid(FString guess) const
{
	if (!IsIsogram(guess)) { // if the guess isn't an isogram
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (false) { // if the guess isn't all lowercase TODO write function
		return EGuessStatus::NOT_LOWERCASE;
	}
	else if (guess.length() != GetHiddenWordLength()) { // if the guesss length is wrong
		return EGuessStatus::WRONG_LENGTH;
	}
	else {
		return EGuessStatus::OK;
	}
}

// receives a VALID guess, increments turn, and returns count
// counts bulls & cows, and increases try # assuming valid guess
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowCount FBullCowCount;
	// loop through all letters in the hidden word
	for (int32 i = 0; i < GetHiddenWordLength(); i++) {
		// compare letters against the guess word	
		for (int32 j = 0; j < Guess.length(); j++) {
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
	if (FBullCowCount.Bulls == GetHiddenWordLength()) {
		bGameIsWon = true;
	}
	return FBullCowCount;
}

bool FBullCowGame::IsIsogram(FString guess) const
{
	// handle 0 and 1 letter words as isograms
	if (guess.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : guess) { // for all letters of the guess
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we do NOT have an isogram
		}
		else { // otherwise
			LetterSeen[Letter] = true; //add the letter to the map as seen
		}		
	}

	return true; // for example in cases where \O is entered
}