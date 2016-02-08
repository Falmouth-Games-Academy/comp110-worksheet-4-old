// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 4;
const int numberOfWords = 10;

std::string getWord()
{
	std::cout << "Enter a word: ";
	std::string line;
	std::getline(std::cin, line);

	if (line.length() == wordLength && isalpha(line[0]))
	{
		return line;
	}
	else
	{
		std::cout << "Word is not the correct length.";
	}

}

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	//Initialise lives and
	int lives = 5;

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

	//Main game loop
	while (true) 
	{
		std::cout << "You have " << lives << " tries left." << std::endl;
		std::string inputWord = getWord();
		if (inputWord == secret)
		{
			lives--;
			if (lives <= 0)
			{
				std::cout << "Too many incorrect tries." << std::endl;
				return 0;
			}
		}
		else
		{
			std::cout << "wrong" << std::endl;
		}
	}
	

	

	

    return 0;
}

