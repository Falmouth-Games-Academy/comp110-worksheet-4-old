// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15; 
const int guaranteedNumberOfLikeWords = 5;


int checkLikeness(std::string guessedWord, std::string secretWord)
{
	int likeness = 0;
	for (int i = 0; i < secretWord.length(); i++)
	{
		if (secretWord[i] == guessedWord[i])
		{
			likeness++;
		}
	}
	return likeness;
}


std::string getGuess(std::set<std::string> validOptions)
{
	bool validGuess = false;

	while (true)
	{
		std::cout << "\nEnter your guess!" << std::endl;
		std::string guess;
		std::getline(std::cin, guess);
		
		// Convert guess to upper case
		std::transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

		// Compare the guess with the options
		for each (std::string word in validOptions)
		{
			if (word == guess)
			{
				return guess;
			}
		}
		std::cout << "Invalid guess!" << std::endl;
	}
}


std::set<std::string> chooseWords(std::string secret)
{
	// Initialise word list
	WordList words(wordLength);

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	int likeWords = 0;
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();

		// Ensure that the minimum number of words are like
		if (likeWords < guaranteedNumberOfLikeWords)
		{
			int likeness = checkLikeness(word, secret);

			// They are like if more than half of the letters match the secret
			if (likeness > wordLength / 2)
			{
				options.insert(word);
				likeWords++;
			}

		}
		else
			options.insert(word);
	}

	return options;
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

	// Get list of word options
	std::set<std::string> options = chooseWords(secret);

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	int lives = 4;
	// Main game loop
	do
	{
		std::string guess = getGuess(options);
		if (guess == secret)
		{
			std::cout << "You win!" << std::endl;
			break;
		}
		else
		{
			int likeness = checkLikeness(guess, secret);
			std::cout << "Likeness: " << likeness << std::endl;
			lives--;
			std::cout << lives << " lives remaining!" << std::endl;
		}
	} while (lives > 0);
	
	if (lives <= 0)
		std::cout << "You lose!" << std::endl;

    return 0;
}

