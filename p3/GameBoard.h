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
