#include <iostream>
#include <string>
#include <windows.h>
using namespace std;





int main()
{
	
		SetConsoleTitle("Terminal Station");
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
	int Guesses = 5;
	string Guess;
	string Answer;
	int i;

	Answer = "BORED";

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

do { if (Guesses > 0) {
cout << " > ";
cin >> Guess; 
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

if ( Guess == "BORED" ) {
cout << "ACCESS GRANTED" << endl; }
else {
cout << "YOU HAVE BEEN TEMPORARILY LOCKED OUT! CONTACT THE ADMINISTRATOR!" << endl; }

return 0;
} 
