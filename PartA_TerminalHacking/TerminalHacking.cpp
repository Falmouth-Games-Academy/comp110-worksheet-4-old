// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

std::string getWord()
{ //Asks the user to enter a word and saves it to the varaible wordGuess, if no word is 
		std::cout << "Enter a word: ";
		std::string wordGuess;
		std::getline(std::cin, wordGuess);

		if (wordGuess.empty() == true)
		{
			std::cout << "Please enter a word." << std::endl;
			getWord();
		}//End if
		else
		{
			return wordGuess;
		}//End else
}

std::string checkGuess(std::string wordGuess, std::set<std::string> options)
{
	for each (std::string word in options)
	{
		if (word != wordGuess)
		{
			std::cout << "That's not a valid guess. Please enter another word: " << std::endl;
			getWord();
		}//End if
		else
		{
			return wordGuess;
		}
	}//End of far each
}

int getLikeness(std::string  wordGuess, std::string  secretWord)
{
	int likenessResult = 0;
	for (int i = 0; i < secretWord.length(); i++)
	{
		if (secretWord[i] = wordGuess[i])
		{
			likenessResult++;
		} //End of if statement

	}//End of for loop
	return likenessResult;
} //end of function



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
	int lives = 4;
	std::string playerGuess = getWord();
	if (playerGuess == secret)
	{
		std::cout << "You win" << std::endl;
		std::cout << "The secret word was " << secret << std::endl;
	}
	else 
	{
		std::cout << playerGuess << std::endl;
		int guessLikeness = getLikeness(playerGuess, secret);
		std::cout << guessLikeness << std::endl;
	}

	// TODO: implement the rest of the game

    return 0;
}

