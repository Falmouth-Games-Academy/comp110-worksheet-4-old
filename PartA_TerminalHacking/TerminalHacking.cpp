// PartA_TerminalHacking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "WordList.h"

const int wordLength = 5;
const int numberOfWords = 15;

/*
char getGuess()
{
	while (true)
	{
		std::cout << "Welcome to the game. Choose a word: ";
		std::string line;
		std::getline(std::cin, line);
		if (line.length() == 5 && isalpha(line[0]))
		{
			int i = 0;
			while (line[i])
			{
				return
					toupper(line[i]);
				i++;
			}
		}
		else
		{
			std::cout << "That's an invalid word!" << std::endl;
		}
	}
*/
std::string getGuess()
{
	while (true)
	{
		// Get player choice word
		std::string guess;
		//std::string newGuess;
		std::cout << "Guess the word: ";
		std::getline(std::cin, guess);

		if (guess.length() == 5)
		{
			for (int i = 0; i < guess.length(); i++)
			{
				if (isalpha(guess[i]))
				{
					guess[i] = toupper(guess[i]);
				}
				else
				{
					std::cout << "That's not a letter!" << std::endl;
				}

				return guess;
			}
			/*
			for each (char c in guess)
			{
				newGuess.append(.append(toupper(c));
				
				if (!isalpha(c))
				{
					std::cout << "That's not a letter!" << std::endl;
				}
				
			}
			return newGuess;
			*/
		}
		else
		{
			std::cout << "That's not 5 letters!" << std::endl;
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

	//std::string partialWord(secret.length(), '-');
	std::string attemptWord(secret.length(), '-');

	int lives = 3;
	char symbol = '*';
	int l = 0;
	//std::string livesRemaining(lives, symbol);

	//bool gameOver = false;
	//while (!gameOver)
	while (true)
	{

		//std::cout << partialWord << std::endl;
		std::cout << attemptWord << std::endl;

		// make a string from the guess
		std::string guess = getGuess();

		std::cout << "You entered " << guess << std::endl;
		std::cout << "Attempts remaining: " << std::string(lives, symbol) << std::endl;
		std::cout << "Likeness: " << l << std::endl;

		bool found = false;
		//bool similar = false;

		for (int i = 0; i < secret.length(); i++)
		{
			for (int c = 0; c < guess.length(); c++)
			{
				char secretletter = secret[i];
				//std::cout << secretletter << std::endl;
				std::cout << secret[i] << std::endl;
				char guessletter = guess[c];
				//std::cout << guessletter << std::endl;
				std::cout << guess[c] << std::endl;
				//if (guessletter == secretletter)
				if (guess[c] == secret[i])
				{
					l++;
					if (l > 4)
					{
						std::cout << "You win! The word was " << secret << std::endl;
						found = true;
					}
				}
				
			}
		}

		//}
		/*
		if (l = 5)
		{
			std::cout << "You win! The word was " << secret << std::endl;
			found = true;
			//break;
		}
		
		*/
		if (!found)
		{
			lives--;
			if (lives <= 0)
			{
				std::cout << "You lose :( The word was " << secret << std::endl;
				//gameOver = true;
				//break;
			}
		}
	}

    return 0;
}

