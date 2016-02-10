// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;
// Changing the value of optionsLikeness changes how many letters the possible words have in common 
const int optionsLikeness = 1;

bool checkGuess(std::string wordGuess, std::set<std::string> options)
{//Checks to see if the users guess is in the list of possible options
	bool validGuess = false;
	for each (std::string word in options)
	{
		if (wordGuess != word)
		{
			validGuess = false;
		}
		else if (wordGuess == word)
		{
			validGuess = true;
			return validGuess;			
		}
	}//End of for each
	return validGuess;
}

std::string getWord(std::set<std::string> options)
{ //Asks the user to enter a word and saves it to the varaible wordGuess, if no word is entered it will ask for one
	std::string wordGuess;
	bool valid = false;

	while (wordGuess.empty() == true || wordGuess.length() != 5 || valid == false)
	{// While wordGuess is empty or isn't 5 characters in length 
			std::cout << "Enter a word: ";
			std::getline(std::cin, wordGuess);
			transform(wordGuess.begin(), wordGuess.end(), wordGuess.begin(), toupper);
			valid = checkGuess(wordGuess, options);
	}//End while
	
	return wordGuess;
}//End getWord


int getLikeness(std::string  wordGuess, std::string  secretWord)
{
	int likenessResult = 0;
	for (int i = 0; i < secretWord.length(); i++)
	{
			if (secretWord[i] == wordGuess[i])
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
	std::cout << secret << std::endl;
	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		int wordLikeness = getLikeness(word, secret);
		if (wordLikeness >= optionsLikeness)
		{
			options.insert(word);
		}
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	//Sets lives to equal 4
	int lives = 4;
	bool valid = false;
	std::string guessWord;
	
	
	while (true)
	{
		std::cout << "You have " << lives << " lives remaining." << std::endl;
		
		guessWord  = getWord(options);
		std::cout << guessWord << std::endl;

		if (guessWord == secret)
		{
			std::cout << "Access granted. The password was "<< secret << std::endl;
			break;
		}
		
		else if (lives == 0)
		{
			std::cout << lives << " lives left. Acces denied." << std::endl;
			break;
		}
		else if (lives > 0)
		{
			int likeness = getLikeness(guessWord, secret);
			std::cout << likeness << "  correct. Please try again." << std::endl;
			lives--;
		}
			
	}//End of while loop

	std::cout << "Game Over" << std::endl;

	system("pause"); //Window doesn't close until a key is pressed
	return 0;
}
