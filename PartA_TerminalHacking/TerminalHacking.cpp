// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;
const int guaranteedNumberOfLikeWords = 5;

int getSimilarity(std::string guessedWord, std::string secretWord)
{
	int similarity = 0;
	for (int i = 0; i < secretWord.length(); i++)
	{
		if (secretWord[i] == guessedWord[i])
		{
			similarity++;
		}

	}
	return similarity;
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

	//set up the attempt count
	int attempts = 4;
	bool valid = false;
	while (valid == false)

	{
		//Ask the player for a word
		std::cout << "Enter a Word: ";
		std::string guess;
		std::cin >> guess;

		for (int i = 0; i < guess.length(); i++)
		{
			if (isalpha(guess[i]))
			{
				//Changes the input to capitals
				guess[i] = toupper(guess[i]);
			}
			else
			{
				std::cout << "Invalid Input" << std::endl;
			}
		}
		
		//Pull in the similarity function to check for similar characters
		int similarity = getSimilarity(guess, secret);
		
		std::cout << "You Entered:  " << guess << std::endl;
		
		std::cout << "With a Similarity of: " << similarity << std::endl;
		
		attempts--;
		std::cout << "You have " << attempts << " Attempts left" << std::endl;

		//For each guess a check is made for winning or loosing
		for (int i = 0; i < secret.length(); i++)
		{
			if (guess == secret)
			{
				std::cout << "Access Granted" << secret << std::endl;
				std::cin.ignore();
				bool valid = true;
			}

		}
			if (attempts <= 0)
			{
				std::cout << "Attempts Failed Self Destruct Iminent" << secret << std::endl;
				std::cin.ignore();
				break;
			}

	}
	// TODO: implement the rest of the game
}