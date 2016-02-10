#include <iostream>
#include <string>
#include <windows.h> 
//Imports above are needed to make this program work
using namespace std;





int main()
{
	
		SetConsoleTitle("Terminal Station"); //This sets the title of the program
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //declaring a handlee so programmer can change appearance of game
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //Changin the color of text
		
	int Guesses = 5; //Declaring the ammount of Guesses function 
	string Guess; //declared users guess as string since its letters only
	string Answer; //The Predefined answer is declared
	int i; //This is needed for the below loop

	Answer = "BORED"; //Answer

	cout << "MILLYCO INDUSTRIES (TM) TERMLINK PROTOCOL" << endl;
	cout << "PASSWORD REQUIRED - ENTER NOW" << endl;
	cout << endl;
	cout << "ATTEMPTS: " << Guesses << endl;
	cout << endl;

	cout << ":×^%;+=&.ßSNE!1" << endl;
	cout << "AKING.(',{:IA&£" << endl;
	cout << "<÷'LOCKPICK/*<;" << endl;
	cout << "'&^>...?>./THRO" << endl;
	cout << "WING></..;00SME" << endl;
	cout << "LLING/..?:AOIWD" << endl;
	cout << "BORED-01*23..>;" << endl;

	//Text above is what is displayed on launch of program so user understands

do { if (Guesses > 0) { //The Loop for likeness of characters
cout << " > ";
cin >> Guess; //user inputting function
if (Guess != "BORED") {
if (Guess == "SNEAKING" || Guess == "THROWING" || Guess == "SMELLING" || Guess == "LOCKPICK" ) { 
cout << "Incorrect! " << "1/5 Characters Right" << endl;}
else { cout << "Incorrect! " << "2/5 Characters Right" << endl;}}
} 
Guesses = Guesses - 1;
cout << Guesses << " ATTEMPT(S) LEFT: "; 
for (i=0; i<Guesses; i++) {
cout << "?"; } cout << endl;
} while (Guess != "BORED" && Guesses != 0); 

//loop ran after users guess is inputted determing if Pass or Failed
if ( Guess == "BORED" ) {
cout << "ACCESS GRANTED" << endl; }
else {
cout << "YOU HAVE BEEN TEMPORARILY LOCKED OUT! CONTACT THE ADMINISTRATOR!" << endl; }

return 0;
} 
