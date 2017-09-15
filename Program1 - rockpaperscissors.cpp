//Created by: Michael Homer
//Class: CS 201R
//Project 1: Rock Paper Scissors
#include <iostream>
using namespace std;

int Menu();
//Preconditions : None, function takes no arguments
//Post conditions: this function prompts the user to pick either rock paper or scissors
//that choice is then returned as an integer between 1 and 3 (inclusive)
bool playAgain();
//Preconditions: This function does not take in any arguments
//Post conditions: The user is asked if they want to continue playing the game. if yes, the function returns
//a boolean object as true, and false if the user does not want to keep playing.
void Winner(int, int);
//Preconditions: Expects two inputs, player 1's choice and player 2's choice, each of type int
//Post conditions: Compairs the users' choices and determines who won. Does not return, prints who won.

int main() {
	do {
		cout << "Let's start with the first player:" << endl;
		int player1Choice = Menu();

		cout << "\nNow the second player:" << endl;
		int player2Choice = Menu();

		Winner(player1Choice, player2Choice);
		cout << endl;
	} while (playAgain());
	return 0;
}

int Menu() {
	int choice;
	cout << "\nWelcome to our game\n"
		<< "Let's play rock, paper, scissors\n"
		<< "Enter your choice:\n"
		<< "1 : Rock\n"
		<< "2 : Paper\n"
		<< "3 : Scissors\n";

	//section will loop until a vaild input is entered. loop is exited with the return statements
	do {
		if (!(cin >> choice && choice <= 3 && choice >= 1)) {
			cout << "ERROR: INVALID INPUT\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			switch (choice) {
			case 1: cout << "You chose rock!\n"; break;
			case 2: cout << "You chose paper\n"; break;
			case 3: cout << "You chose scissors\n"; break;
			}
			return choice;
		}
	} while (true);
}

void Winner(int player1Choice, int player2Choice) {
	/*1 = rock
	2 = paper
	3 = scisors*/

	if (player1Choice == player2Choice)
		cout << "You Both Tied";
	//checks all possible ways for p1 to win
	else if ((player1Choice == 1 && player2Choice == 3) || (player1Choice == 2 && player2Choice == 1) || (player1Choice == 3 && player2Choice == 2))
		cout << "Player 1 Wins!!";
	else
		// if all the above conditions fail, then the only possibility left is that p2 won.
		cout << "Player 2 Wins!!";
}

bool playAgain() {
	char input;
	do {
		cout << "\nWould you like to play again? [Y/y/N/n]: ";
		cin >> input;
		switch(input){
		case 'y':
		case 'Y': return true;
		case 'n':
		case 'N': return false;
		default:
			cout << "ERROR: INVALID CHOICE\n";
			cin.clear();
			cin.ignore(10000, '\n');
		}
	} while (true);
}