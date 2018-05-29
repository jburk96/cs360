/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 2
	Description: This is the .cpp file for Goblin. This class has a 
	constructor, destructor, update, attack, injure, and print method. 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Goblin.h"

/*
	Goblin - this is the constructor for the Goblin class. This 
	method receives five integer parameters and calls the 
	initializer list from Enemy for some of the parameters 
	given. This method also calls the print method when 
	everything else is done.
*/
Goblin::Goblin(int hp, int str, int con, int xPos, int yPos):
Enemy::Enemy(hp, str, con, xPos, yPos)
{
	id = idGenerator;
	idGenerator++;
	print();
}

/*
	update - changes the Goblins current position to certain random 
	values. There are no parameters and returns void.
*/
void Goblin::update()
{
	// random number between -3 and 3
	int randomX = rand() % 7 + (-3);
	// random number between -2 and 2
	int randomY = rand() % 5 + (-2);
	xPosition += randomX;
	yPosition += randomY;
}

/*
	attack - sets a random damage value for Goblin and adds Goblins 
	str to it. This method then prints the value of the 
	Goblins damage dealt to the passerby. There are no 
	parameters and returns void.
*/
void Goblin::attack() const
{
	// random value between 1 and 4
	int damage = rand() % 4 + 1;
	damage += str;
	cout << "Goblin " << id << " attacks a random passerby for " 
	<< damage << " damage!" << endl;
}

/*
	injure - receives an int parameter and subtract half of the 
	Goblins con from it. If the amount of damage the 
	enemy is greater than 0, the damage is then subtracted 
	from the Goblins health and prints out how much damage 
	the Goblin took and what his current health is. If the 
	damage done is 0, this method prints something to that 
	affect. If the Goblins health reaches zero, alive 
	is set to false and a death message is printed. This 
	method returns void.
*/
void Goblin::injure(int damage)
{
	damage -= con/2;
	
	if (damage > 0)
	{
		health -= damage;
		cout << "Goblin " << id << " takes " 
		<< damage << " damage! Current hp = " << health << endl;
	}
	
	else
		cout << "The passerby tries to attack Goblin " 
		<< id << ", but it's not very effective..." << endl;
		
	if (health <= 0)
	{
		alive = false;
		cout << "Goblin " << id << " has been slain!" << endl;
	}
}

/*
	print - has no parameters and returns void. This method prints 
	the Goblins id, location, and current health.
*/
void Goblin::print() const
{
	cout << "Goblin " << id << " @ (" << xPosition << ", " 
	<< yPosition << ") hp = " << health << endl;
}

/*
	getDisplayChar - this method has no parameters and returns a char 
	value. The char value returned will be 'G' or 'g'. The 
	lower case 'g' indicates that the goblin is dead.
*/
const char Goblin::getDisplayChar() const
{
	if (alive == false)
		return 'g';
		
	return 'G';
}
