#pragma once

#include "FBullCowGame.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <time.h>  // needed for the time function which is a parameter for the srand
#include <map>
#define TMap std::map

// default constructor
FBullCowGame::FBullCowGame() {
	srand(time(NULL));
	// The constant words has to be an isogram also has to to be max length 9 letters long
	HiddenWords[1] = "planet";
	HiddenWords[2] = "dog";
	HiddenWords[3] = "wolf";
	HiddenWords[4] = "isogram";
	HiddenWords[5] = "marvelous";
	for (int32 i = 1; i < HiddenWords.size() + 1; i++) {
		RandomNumbers.push_back(i);
	}
	std::iota(RandomNumbers.begin(), RandomNumbers.end(), 1);
	std::random_shuffle(RandomNumbers.begin(), RandomNumbers.end());

	bMoreWords = true;

	Reset();
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::HasMoreWords() const { return bMoreWords; }

int32 FBullCowGame::GetMaxTries() const {
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,14}, {7,20}, {8,28}, {9,38} };
	return WordLengthToMaxTries[GetHiddenWordLength()];
}

void FBullCowGame::Reset()
{
	if (!RandomNumbers.empty()) {
		// selecting a random hidden word from our TMap content
		MyHiddenWord = HiddenWords[RandomNumbers.back()];
		// removing that number from the list so it doesn't choose it again
		RandomNumbers.pop_back();	
	}
	else {
		bMoreWords = false;
	}

	MyCurrentTry = 1;
	bGameIsWon = false;
}

EGuessStatus FBullCowGame::IsGuessValid(FString guess) const
{
	if (!IsIsogram(guess)) { // if the guess isn't an isogram
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (!IsLowercase(guess)) { // if the guess isn't all lowercase TODO write function
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

bool FBullCowGame::IsLowercase(FString guess) const
{
	// handle 0 letter words as lower
	if (guess.length() < 1) { return true; }

	for (auto letter : guess) { // for all letters of the guess
		if (!islower(letter)) { // if the letter is in lowercase
			return false; // it is NOT a lowercase string
		}
	}

	return true; // for example in cases where \O is entered
}