/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 1
	
	This file is the ConnectFourBoard class and has three functions. 
	These functions include a constructor, destructor, and currentBoard. 
	All together this file creates the Connect 4 board and does the 
	necessary testing to determine which player is the winner or if 
	there is a tie. This file also ensures input validation.
*/

#include "ConnectFourBoard.h"
using namespace std;


/*
	ConnectFourBoard - this is the constructor for the class. It 
	assigns values to all the instance variables and all the 
	slots within the instance array.
	
	Parameters: None
	
	Returns: None
*/
ConnectFourBoard::ConnectFourBoard()
{
	redTurn = 0;
	blackTurn = 0;
	redCount = 0;
	blackCount = 0;
	count = 0;
	
	//	creates the board
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			board[i][j] = '_';
		}
	}
}

/*
	currentBoard - This function displays the current progress of the 
	board. It also determines whose tern it is and ensures input 
	validation of which column to insert their letter. This function 
	also determines which player has gotten four in a row or if 
	there is a tie in the game.
	
	Parameters: None
	
	Returns: bool (If the game is over or not)
*/
bool ConnectFourBoard::currentBoard()
{
	redCount = 0;
	blackCount = 0;
	string input;
	bool place = false;
	int placementTest = 5;
	cout << "\nCurrent Board Status:\n\n1 2 3 4 5 6 7" << endl;
	
	//displays the board
	for (int i = 0; i<6; i++)
	{
		for (int j = 0; j<7; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	// if it is red's turn
	if (redTurn == blackTurn)
	{
		cout << "\nIt is red's turn.\nEnter column (1-7): ";
		cin >> input;
		cin.clear();
		cin.ignore();
		newEntry = atoi(input.c_str());
		newEntry = invalid(newEntry) - 1;
		
		while (!place)
		{
			if (board[placementTest][newEntry] == '_')
			{
				board[placementTest][newEntry] = 'r';
				place = true;
			}
				
			else
			{
				if (placementTest > 0)
					placementTest--;
					
				else
				{
					cout << "\n\n\n\n\n\n\n\n\nNo more available " << 
					"space in this column. Please try again.\n" << endl;
					redTurn--;
					count--;
					place = true;
				}
			}
		}
		
		if (newEntry-1 >=0 && board[placementTest][newEntry-1] == 'r')
		{
			redCount++;
			
			if (newEntry-2 >=0 && 
			board[placementTest][newEntry-2] == 'r')
			{
				redCount++;
				
				if (newEntry-3 >=0 && 
				board[placementTest][newEntry-3] == 'r')
					redCount++;
			}
		}
		
		if (newEntry+1 <=6 && board[placementTest][newEntry+1] == 'r')
		{
			redCount++;
			
			if (newEntry+2 <=6 && 
			board[placementTest][newEntry+2] == 'r')
			{
				redCount++;
				
				if (newEntry+3 <=6 && 
				board[placementTest][newEntry+3] == 'r')
					redCount++;
			}
			
		}
		
		if (redCount != 3)
		{
			redCount = 0;
		
			if (placementTest+1 <= 5 && 
			board[placementTest+1][newEntry] == 'r')
			{
				redCount++;
			
				if (placementTest+2 <= 5 && 
				board[placementTest+2][newEntry] == 'r')
				{
					redCount++;
				
					if (placementTest+3 <= 5 && 
					board[placementTest+3][newEntry] == 'r')
						redCount++;
				}
			
				if (redCount != 3)
					redCount = 0;
			}
		
			if (placementTest-1 > 0 && newEntry-1 >=0 && 
			board[placementTest-1][newEntry-1] == 'r')
			{
				redCount++;
			
				if (placementTest-2 > 0 && newEntry-2 >=0 && 
				board[placementTest-2][newEntry-2] == 'r')
				{
					redCount++;
				
					if (placementTest-3 > 0 && newEntry-3 >=0 && 
					board[placementTest-3][newEntry-3] == 'r')
						redCount++;
				}
			}
		
			if (placementTest+1 <= 5 && newEntry+1 <= 6 && 
			board[placementTest+1][newEntry+1] == 'r')
			{
				redCount++;
			
				if (placementTest+2 <= 5 && newEntry+2 <= 6 && 
				board[placementTest+2][newEntry+2] == 'r')
				{
					redCount++;
				
					if (placementTest+3 <= 5 && newEntry+3 <= 6 && 
					board[placementTest+3][newEntry+3] == 'r')
						redCount++;
				}
			}
			
			if (redCount != 3)
			{
				redCount = 0;
		
				if (placementTest-1 >0 && newEntry+1 <= 6 && 
				board[placementTest-1][newEntry+1] == 'r')
				{
					redCount++;
			
					if (placementTest-2 >0 && newEntry+2 <= 6 && 
					board[placementTest-2][newEntry+2] == 'r')
					{
						redCount++;
				
						if (placementTest-3 >0 && newEntry+3 <= 6 && 
						board[placementTest-3][newEntry+3] == 'r')
							redCount++;
					}
				}
		
				if (placementTest+1 <= 5 && newEntry-1 >= 0 && 
				board[placementTest+1][newEntry-1] == 'r')
				{
					redCount++;
			
					if (placementTest+2 <= 5 && newEntry-2 >= 0 && 
					board[placementTest+2][newEntry-2] == 'r')
					{
						redCount++;
				
						if (placementTest+3 <= 5 && newEntry-3 >= 0 && 
						board[placementTest+3][newEntry-3] == 'r')
							redCount++;
					}
			
					if (redCount != 3)
						redCount = 0;
				}
			}
		}
		
		redTurn++;
		count++;
	}
	
	else
	{
		cout << "\nIt is black's turn.\nEnter column (1-7): ";
		cin >> input;
		cin.clear();
		cin.ignore();
		newEntry = atoi(input.c_str());
		newEntry = invalid(newEntry) - 1;
		
		while (!place)
		{
			if (board[placementTest][newEntry] == '_')
			{
				board[placementTest][newEntry] = 'b';
				place = true;
			}
				
			else
			{
				if (placementTest > 0)
					placementTest--;
					
				else
				{
					cout << "\n\n\n\n\n\n\n\n\nNo more available" << 
					" space in this column. Please try again.\n" << endl;
					blackTurn--;
					count--;
					place = true;
				}
			}
		}
		
		if (newEntry-1 >=0 && board[placementTest][newEntry-1] == 'b')
		{
			blackCount++;
			
			if (newEntry-2 >=0 && 
			board[placementTest][newEntry-2] == 'b')
			{
				blackCount++;
				
				if (newEntry-3 >=0 && 
				board[placementTest][newEntry-3] == 'b')
					blackCount++;
			}
		}
		
		if (newEntry+1 <=6 && board[placementTest][newEntry+1] == 'b')
		{
			blackCount++;
			
			if (newEntry+2 <=6 && 
			board[placementTest][newEntry+2] == 'b')
			{
				blackCount++;
				
				if (newEntry+3 <=6 && 
				board[placementTest][newEntry+3] == 'b')
					blackCount++;
			}
			
		}
		
		if (blackCount != 3)
		{
			blackCount = 0;
		
			if (placementTest+1 <= 5 && 
			board[placementTest+1][newEntry] == 'b')
			{
				blackCount++;
			
				if (placementTest+2 <= 5 && 
				board[placementTest+2][newEntry] == 'b')
				{
					blackCount++;
				
					if (placementTest+3 <= 5 && 
					board[placementTest+3][newEntry] == 'b')
						blackCount++;
				}
			
				if (blackCount != 3)
					blackCount = 0;
			}
		
			if (placementTest-1 > 0 && newEntry-1 >=0 && 
			board[placementTest-1][newEntry-1] == 'b')
			{
				blackCount++;
			
				if (placementTest-2 > 0 && newEntry-2 >=0 && 
				board[placementTest-2][newEntry-2] == 'b')
				{
					blackCount++;
				
					if (placementTest-3 > 0 && newEntry-3 >=0 && 
					board[placementTest-3][newEntry-3] == 'b')
						blackCount++;
				}
			}
		
			if (placementTest+1 <= 5 && newEntry+1 <= 6 && 
			board[placementTest+1][newEntry+1] == 'b')
			{
				blackCount++;
			
				if (placementTest+2 <= 5 && newEntry+2 <= 6 && 
				board[placementTest+2][newEntry+2] == 'b')
				{
					blackCount++;
				
					if (placementTest+3 <= 5 && newEntry+3 <= 6 && 
					board[placementTest+3][newEntry+3] == 'b')
						blackCount++;
				}
			}
			
			if (blackCount != 3)
			{
				blackCount = 0;
		
				if (placementTest-1 >0 && newEntry+1 <= 6 && 
				board[placementTest-1][newEntry+1] == 'b')
				{
					blackCount++;
			
					if (placementTest-2 >0 && newEntry+2 <= 6 && 
					board[placementTest-2][newEntry+2] == 'b')
					{
						blackCount++;
				
						if (placementTest-3 >0 && newEntry+3 <= 6 && 
						board[placementTest-3][newEntry+3] == 'b')
							blackCount++;
					}
				}
		
				if (placementTest+1 <= 5 && newEntry-1 >= 0 && 
				board[placementTest+1][newEntry-1] == 'b')
				{
					blackCount++;
			
					if (placementTest+2 <= 5 && newEntry-2 >= 0 && 
					board[placementTest+2][newEntry-2] == 'b')
					{
						blackCount++;
				
						if (placementTest+3 <= 5 && newEntry-3 >= 0 && 
						board[placementTest+3][newEntry-3] == 'b')
							blackCount++;
					}
			
					if (blackCount != 3)
						blackCount = 0;
				}
			}
		}
		blackTurn++;
		count++;
	}
	
	// if red has four in a row
	if (redCount == 3)
	{
		
		cout << "\nCurrent Board Status:\n\n1 2 3 4 5 6 7" << endl;
		
		//prints the board
		for (int i = 0; i<6; i++)
		{
			for (int j = 0; j<7; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		
		cout << "\n~*~*~* Red Wins! *~*~*~" << endl;
		return true;
	}
	
	//	if black has four in a row
	if (blackCount == 3)
	{
		cout << "\nCurrent Board Status:\n\n1 2 3 4 5 6 7" << endl;
		
		//prints the board
		for (int i = 0; i<6; i++)
		{
			for (int j = 0; j<7; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	
		cout << "\n~*~*~* Black Wins! *~*~*~" << endl;
		return true;
	}
	
	//	if it is a tie
	if (count == 42)
	{
		cout << "\nCurrent Board Status:\n\n1 2 3 4 5 6 7" << endl;
	
		//prints the board
		for (int i = 0; i<6; i++)
		{
			for (int j = 0; j<7; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	
		cout << "\n ~*~*~* It's a tie! *~*~*~" << endl;
		return true;
	}
	
	else
		return false;
}

/*
	invalid - this is the method that ensures input validation.
	
	Parameters: integer
	
	Returns: integer
*/
int ConnectFourBoard::invalid (int newEntry)
{
	string input;
	while (newEntry < 1 || newEntry > 7)
	{
		cout << "\nI'm Sorry, but that's not a valid choice." << 
		" Please try again.\nEnter column (1-7): ";
		cin >> input;
		cin.clear();
		cin.ignore();
		newEntry = atoi(input.c_str());
	}
	
	return newEntry;
}

/*
	~ConnectFourBoard - this is the destructor for the class. 
	It does absolutely nothing at this time.
	
	Parameters: None
	
	Returns: None
*/
ConnectFourBoard::~ConnectFourBoard()
{

}
