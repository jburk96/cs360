#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "GameBoard.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
//hi there
GameBoard::GameBoard(int x, int y)
{
	row = (2*x) + 1;
	col = (2*y) + 1;
	
	board = new char *[row];
	for(int i = 0; i < row; i++)
    	board[i] = new char [col];
    		
	GameBoard::resetBoard();
}

GameBoard::~GameBoard()
{
	for(int i = 0; i < row; i++)
    	delete[] board[i];
	delete[] board;
}

void GameBoard::addGamePiece(Enemy * monster)
{ 
	collection.push_back(monster);
}

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
