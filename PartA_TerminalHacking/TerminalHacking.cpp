// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 5;

/*
Get input from the user and check it is valid..
..then if it is convert each letter to uppercase and return the word.
*/
std::string getWord()
{
	std::cout << "Enter a word: ";
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
		std::cout << "Password is not the correct length.";
	}

}

// Calcualte the likeness between input word and secret word.
int getLikeness(std::string inputWord, std::string secretWord)
{
	int likeness = 0;
	
	for (int i = 0; i < secretWord.length(); i++)
	{
		if (secretWord[i] == inputWord[i])
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

	// Initialise ammount of lives
	int lives = 4;

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

	// Main game loop
	while (true) 
	{
		std::cout << "You have " << lives << " tries left." << std::endl;
		std::string inputWord = getWord();

		if (inputWord == secret)
		{
			std::cout << "CORRECT!" << std::endl;
			return 0;     //end the game loop when the asnwer is correct
		}

		
		else
		{
			std::cout << "Incorrect Password, Please Try Again." << std::endl;
			lives--;

			if (lives <= 0)
			{
				std::cout << "Too many incorrect tries." << std::endl;
				return 0;
			}
		}

	// Print the likeness
	int likeness = getLikeness(inputWord, secret);
	std::cout << "likeness = " << likeness << std::endl;
		
	}
    return 0;
}

