/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 2
	Description: This is the .cpp file for Orc. This class has a 
	constructor, destructor, update, attack, injure, and print method. 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Orc.h"

/*
	Orc - this is the constructor for the Orc class. This 
	method receives five integer parameters and calls the 
	initializer list from Enemy for some of the parameters 
	given. This method also calls the print method when 
	everything else is done.
*/
Orc::Orc(int hp, int str, int con, int xPos, int yPos):
Enemy::Enemy(hp, str, con, xPos, yPos)
{
	id = idGenerator;
	idGenerator++;
	print();
}

/*
	update - changes the Orcs current position to certain random 
	values. There are no parameters and returns void.
*/
void Orc::update()
{
	// random number between -5 and 5
	int random = rand() % 11 + (-5);
	xPosition += random;
	yPosition += random;
}

/*
	attack - sets a random damage value for Orc and adds Orcs 
	str to it. This method then prints the value of the 
	Orcs damage dealt to the passerby. There are no 
	parameters and returns void.
*/
void Orc::attack() const
{
	// random number between 1 and 6
	int damage = rand() % 6 + 1;
	damage += str;
	cout << "Orc " << id << " attacks a random passerby for " 
	<< damage << " damage!" << endl;
}

/*
	injure - receives an int parameter as the damage variable. 
	If damage is greater than 0, the damage is then subtracted 
	from the Orcs health and prints out how much damage the Orc 
	took and what his current health is. If the damage done is 
	0, this method prints something to that affect. If the 
	Orcs health reaches zero, alive is set to false 
	and a death message is printed. This method returns void.
*/
void Orc::injure(int damage)
{	
	if (damage > 0)
	{
		health -= damage;
		cout << "Orc " << id << " takes " 
		<< damage << " damage! Current hp = " << health << endl;
	}
	
	else
		cout << "The passerby tries to attack Orc " 
		<< id << ", but it's not very effective..." << endl;
		
	if (health <= 0)
	{
		alive = false;
		cout << "Orc " << id << " has been slain!" << endl;
	}
}

/*
	print - has no parameters and returns void. This method prints 
	the Orcs id, location, and current health.
*/
void Orc::print() const
{
	cout << "Orc " << id << " @ (" << xPosition << ", " 
	<< yPosition << ") hp = " << health << endl;
}

const char Orc::getDisplayChar() const
{
	if (alive == false)
		return 'o';
		
	return 'O';
}
