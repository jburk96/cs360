/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 3
	Description: This class creates a 2d array that is representative 
	of a gameboard for all classes that inherit from Enemy. This 
	class also creates a vector collection of Enemy pointers that 
	can call public functions on those same classes without having 
	to address a specific Enemy type. The functions in this class 
	are GameBoard, ~GameBoard, addGamePiece, resetBoard, and 
	printBoard. 
*/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "GameBoard.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"

/*
	GameBoard - this is the constructor for the GameBoard class. 
	This function dynamically allocates memory for a 2d array and 
	calls the resetBoard function upon completion.
*/
GameBoard::GameBoard(int x, int y)
{
	row = (2*x) + 1;
	col = (2*y) + 1;
	
	board = new char *[row];
	for(int i = 0; i < row; i++)
    	board[i] = new char [col];
    		
	GameBoard::resetBoard();
}

/*
	~GameBoard - this is the destructor for the GameBoard class. 
	This function cleans up any dynamically allocated memory the 
	2d array. 
*/
GameBoard::~GameBoard()
{
	for(int i = 0; i < row; i++)
    	delete[] board[i];
	delete[] board;
}

/*
	addGamePiece - this function accepts a Enemy * called monster 
	and pushes it onto the vector collection of Enemy*'s. The 
	function does not return anything.
*/
void GameBoard::addGamePiece(Enemy * monster)
{ 
	collection.push_back(monster);
}

/*
	resetBoard - this function has no parameters and does not 
	return anything. All it does is assign every member of the 
	array to represent a cartesian coordinate system. If the 
	gameboard has game pieces on the board already, the 
	function will remove them from the array.
*/
void GameBoard::resetBoard()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == (row-1)/2)
				board[i][j] = '_';
			
			else if (j == (row-1)/2)
				board[i][j] = '|';
			
			else
				board[i][j] = '.';
		}
	}
}

/*
	printBoard - this function has no parameters and does not 
	return anything. For every Enemy* in the vector, it will get 
	the char character from the enemy in question to be represented 
	as a gamepiece on the gameboard. If the position the gamepiece 
	is supposed to be on the grid is out of bounds, this function 
	will set the game piece to the very edge of the grid. If an 
	enemy needs to be placed at the same position as a different 
	enemy, this function will randomly choose a position not to 
	far from its intended position.
*/
void GameBoard::printBoard()
{
	for (vector<Enemy*>::iterator it = collection.begin() ; it != collection.end(); it++)
	{
    	char enemyChar = (*it)->getDisplayChar();
    	int enemyY = ((row-1)/2) + (*it)->getX();
    	int enemyX = ((col-1)/2) - (*it)->getY();
    	
    	
    	if (enemyY > row)
    		enemyY = row-1;
    		
    	if (enemyY < 0)
    		enemyY = 0;
    		
    	if (enemyX > col)
    		enemyX = col-1;
    	
    	if (enemyX < 0)
    		enemyX = 0;
    		
    	if (board[enemyX][enemyY] != '|' && 
    	board[enemyX][enemyY] != '_' && 
    	board[enemyX][enemyY] != '.' && 
    	board[enemyX][enemyY] != enemyChar)
    	{
    		while (board[enemyX][enemyY] != '|' && 
    		board[enemyX][enemyY] != '_' && 
    		board[enemyX][enemyY] != '.' && 
    		board[enemyX][enemyY] != enemyChar)
    		{
    			enemyY -= rand() % 3;
    			enemyX += rand() % 2;
    			
    			if (enemyY > row)
    				enemyY = row-1;
    		
    			if (enemyY < 0)
    				enemyY = 0;
    		
    			if (enemyX > col)
    				enemyX = col-1;
    	
    			if (enemyX < 0)
    				enemyX = 0;
    		}
    	}
    	
    	board[enemyX][enemyY] = enemyChar;
	}
	
	cout << "\n" << endl;
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << board[i][j];
			
			if (j == row-1)
				cout << endl;
		}
	}
}
