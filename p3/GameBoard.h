/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 3
	Description: This is the class deifition for GameBoard.cpp. There 
	are 6 private data members and 5 public functions in this 
	class definition. The vector data type is of type Enemy* which 
	holds a collection of Enemy pointers that can be a Goblin, 
	Orc, or Troll.
*/

#ifndef GameBoard_H
#define GameBoard_H

#include "Enemy.h"
#include <vector>
using namespace std;

class GameBoard
{
	private:
		int xCoordinate;
		int yCoordinate;
		int row;
		int col;
		vector<Enemy*> collection;
		char ** board;

	public:
		GameBoard(int, int);
		~GameBoard();
		void addGamePiece(Enemy *);
		void resetBoard();
		void printBoard();
};

#endif
