// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 5;

std::string getSecretWord()
{
	while (true)
	{
		std::cout << "Guess a word:";
		std::string line;
		std::getline(std::cin, line);

		if (line.length() == wordLength && isalpha(line[0]))
		{
			
			for (int i = 0; i < line.length(); i++)
			{
				line[i] = toupper(line[i]);
			}
			return line;
		}

		else
		{
			std::cout << "Thats not the word!" << std::endl;
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

	// set lives at 4
	int lives = 4;

	while (true)
	{
		std::cout << "You have " << lives << " lives left" << std::endl;

		//add bit at top for getWord
		std::string SecretWord = getSecretWord();
		std::cout << "You guessed" << SecretWord << std::endl;

		if (SecretWord == secret)
		{
			std::cout << "You Guessed The Word Congradulations!" << std::endl;
			return 0;
		}
		else
		{
			lives--;
			std::cout << "Wrong Try Again" << std::endl;
		}
	}






    return 0;
}

