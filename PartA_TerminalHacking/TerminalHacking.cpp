// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

char getWord()
{
	while (true)
	{
		std::cout << "Enter a Word: ";
		std::string line;
		std::getline(std::cin, line);

		if (line.length() == 5 && isalpha(line[0]))
		{
			return toupper(line[0]);
		}
		else
		{
			std::cout << "That is incorrect!" << std::endl;
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

	std::string guessed;
	std::getline(std::cin, guessed);

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

	int lives = 4;

	while (true)
	{
		std::cout << secret << std::endl;
		std::cout << "You have " << lives << " lives left" << std::endl;

		char letter = getWord();
		std::cout << "You entered " << letter << std::endl;

		bool found = false;
		for (int i = 0; i < secret.length(); i++)
		{
			if (secret[i] == letter)
			{
				guessed[i] = letter;
				found = true;
			}
		}

		if (!found)
		{
			lives--;
			if (lives <= 0)
			{
				std::cout << "You lose :( The word was " << secret << std::endl;
				std::cin.ignore();
				break;
			}

		if (guessed == secret)
			{
				std::cout << "You win!!! The word was " << secret << std::endl;
				break;
			}
		}
	}
	// TODO: implement the rest of the game
	// Have the program recognize the word you imput
	// Have the program recognize how many leeters are similler between
	// the word you typed and the requested word
	// Give the player lives
	// Winning conditions
    return 0;
}