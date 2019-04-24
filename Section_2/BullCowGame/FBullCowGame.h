/* 
	The game logic (no view code or direct user interaction)
	The game is a simple guess the word game based on Mastermind 
*/
#pragma once

#include <string>
#include <vector>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

// all values intialised to zero
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	INVALID,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE
};

class FBullCowGame {
public:	
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	bool HasMoreWords() const;
	EGuessStatus IsGuessValid(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);


private:
	TMap<int32, FString> HiddenWords;
	std::vector<int32> RandomNumbers;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool bMoreWords;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
