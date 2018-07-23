#pragma once
#include <string>

class FBullCowGame {
public:	
	int GetMaxTries();
	int GetCurrentTry();
	void Reset(); // TODO make a more rich return value
	bool IsGameWon();
	bool IsGuessValid(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};
