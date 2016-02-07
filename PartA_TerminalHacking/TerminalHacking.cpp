// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

char getLetter()
{
	while (true)
	{
		std::cout << "Welcome to the game. Choose a word: ";
		std::string line;
		std::getline(std::cin, line);
		if (line.length() == 1 && isalpha(line[0]))
		{
			return
				toupper(line[0]);
		}
		else
		{
			std::cout << "That's not a letter!" << std::endl;
		}
	}
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

	std::string partialWord(secret.length(), '-');

	int lives = 3;
	char symbol = '*';
	//std::string livesRemaining(lives, symbol);

	while (true)
	{
		std::cout << partialWord << std::endl;
		std::cout << "Attempts remaining: " << std::string(lives, symbol) << std::endl;

		char letter = getLetter();
		std::cout << "You entered " << letter << std::endl;

		bool found = false;
		for (int i = 0; i < secret.length(); i++)
		{
			if (secret[i] == letter)
			{
				partialWord[i] = letter;
				found = true;
			}

		}
		if (!found)
		{
			lives--;
			if (lives <= 0)
			{
				std::cout << "You lose :( The word was " << secret << std::endl;
				gameOver = true;
				//break;
			}
		}

		if (partialWord == secret)
		{
			std::cout << "You win! The word was " << secret << std::endl;
			//break;
		}
	}


    return 0;
}

