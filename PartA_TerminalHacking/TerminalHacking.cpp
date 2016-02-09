// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

// Gets the likeness value between the word guessed and the secret word
int getLikeness(std::string guessedWord, std::string secretWord)
{
	int likeness = 0;
	for (int i = 0; i != secretWord.length() - 1; i++)
	{
		if (secretWord[i] == guessedWord[i])
		{
			likeness++;
		}
	}
	return likeness;
}

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(wordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game
	
	int lives = 4;
	std::string guess;
	bool endState = false;
	while (endState == false)
	{
		// tell the user to make a guess
		std::cout << "Please enter a guess." << std::endl;
		std::cin >> guess;
		// convert guess to upper case
		for (int i = 0; i < guess.length(); i++)
		{
			if (isalpha(guess[i]))
			{
				guess[i] = toupper(guess[i]);
			}
		}
		// check if word exists
		bool wordexistance = false;
		for each (std::string word in options)
		{
			if (guess == word)
			{
				wordexistance = true;
				// Detect win state
				if (guess == secret)
				{
					std::cout << guess << " Accepted" << std::endl;
					endState = true;
					break;
				}
				// Wrong guess
				else
				{
					int likeness = getLikeness(guess, secret);
					std::cout << "Wrong " << guess << std::endl << "Likeness " << likeness << std::endl;
					lives--;
					std::cout << "You have " << lives << " left." << std::endl;
					// Out of lives
					if (lives <= 0)
					{
						std::cout << "Locked out" << std::endl;
						endState = true;
						break;
					}
				}
			}
		}
		if (wordexistance == false)
		{
			std::cout << "Invalid guess" << std::endl;
		}
	}


    return 0;
}
