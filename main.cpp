/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 1
	
	This file is the test client for the ConnectFourBoard files. This 
	file allows the users to quit the program or start a new Connect 
	4 game. The users may play as many games as they desire. This 
	file will ensure any input data is valid.
*/

#include "ConnectFourBoard.h"
using namespace std;


/*
	choice - ensures input validation from the user. The input must 
	be either a 1 or a 2. If the input is incorrect, this function 
	will continue to ask the user for correct input.
	
	Parameters: None
	
	Returns: int (either a 1 or a 2)
*/
int choice ()
{
	string input;
	cout << "\n1: quit\n2: new game\nEnter Choice: ";
	cin >> input;
	cin.clear();
	cin.ignore();
	
	//	converts string to integer
	int test = atoi(input.c_str());
	
	while (test != 1 && test != 2)
	{
		cout << "\nI'm Sorry, but that's not a valid " << 
		"choice. Please try again." << endl;
		cout << "1: quit\n2:new game\nEnter Choice: ";
		cin >> input;
		cin.clear();
		cin.ignore();
		test = atoi(input.c_str());
	}
	
	return test;
}

int main ()
{
	bool gameOver;
	int input;
	cout << "\n\n~*~*~* Welcome to Connect Four! *~*~*~" << endl;
	input = choice();
	
	while (input != 1)
	{
		ConnectFourBoard game = ConnectFourBoard();
		gameOver = game.currentBoard();
		
		//	continues until the game is over
		while(!gameOver)
		{
			gameOver = game.currentBoard();
		}
		
		input = choice();
	}
}
