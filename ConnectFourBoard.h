/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 1
	
	This file contains the class description for ConnectFourBoard.cpp. 
	This .h file also makes all necessary variables and fuctions either 
	public or private.
*/

#include <iostream>
#include <cstdlib>
class ConnectFourBoard
{
	public:
		ConnectFourBoard();
		~ConnectFourBoard();
		bool currentBoard();
	
	private:
		char board[6][7];
		int redTurn;
		int blackTurn;
		int newEntry;
		int invalid(int);
		bool winner;
		int redCount;
		int blackCount;
		int count;
};
