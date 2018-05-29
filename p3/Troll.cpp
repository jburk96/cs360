/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 2
	Description: This is the .cpp file for Troll. This class has a 
	constructor, destructor, update, attack, injure, and print method. 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#include "Troll.h"

/*
	Troll - this is the constructor for the Troll class. This 
	method receives five integer parameters and calls the 
	initializer list from Enemy for some of the parameters 
	given. This method also calls the print method when 
	everything else is done.
*/
Troll::Troll(int hp, int str, int con, int xPos, int yPos):
Enemy::Enemy(hp, str, con, xPos, yPos)
{
	id = idGenerator;
	idGenerator++;
	print();
}

/*
	update - changes the Trolls current position to certain random 
	values. There are no parameters and returns void. This method 
	also regenerates the Trolls current health by 
	the Trolls con. 
*/
void Troll::update()
{
	// random number between -10 and -7
	int random1 = rand() % 4 + (-10);
	// random number between 7 and 10
	int random2 = rand() % 4 + 7;
	
	if (-random1 >= random2)
		xPosition += random1;
		
	else
		xPosition += random2;
	
	health += con;
	
	if (health > 15)
	{
		int regenerate = health - 15;
		health = 15;
		cout << "Troll " << id << " regenerates " 
		<< (con-regenerate) << " health" << endl;
	}
		
	else
		cout << "Troll " << id << " regenerates " 
		<< con << " health" << endl;
}

/*
	attack - sets a random damage value for Troll and adds Trolls 
	str to it. This method then prints the value of the 
	Trolls damage dealt to the passerby. There are no 
	parameters and returns void.
*/
void Troll::attack() const
{
	// random number between 1 and 8
	int damage = rand() % 8 + 1;
	damage += str;
	cout << "Troll " << id << " attacks a random passerby for " 
	<< damage << " damage!" << endl;
}

/*
	injure - receives an int parameter and multiplies 1.5 of the 
	Trolls con to it. If damage is greater than 0, 
	the damage is then subtracted from the Trolls health and 
	prints out how much damage the Troll took and what his 
	current health is. If the damage done is 0, this method 
	prints something to that affect. If the Trolls health 
	reaches zero, alive is set to false and a death 
	message is printed. This method returns void.
*/
void Troll::injure(int damage)
{
	damage -= con*1.5;
	
	if (damage > 0)
	{
		health -= damage;
		cout << "Troll " << id << " takes " 
		<< damage << " damage! Current hp = " << health << endl;
	}
	
	else
		cout << "The passerby tries to attack Troll " 
		<< id << ", but it's not very effective..." << endl;
		
	if (health <= 0)
	{
		alive = false;
		cout << "Troll " << id << " has been slain!" << endl;
	}
}

/*
	print - has no parameters and returns void. This method prints 
	the Trolls id, location, and current health.
*/
void Troll::print() const
{
	cout << "Troll " << id << " @ (" << xPosition << ", " 
	<< yPosition << ") hp = " << health << endl;
}

/*
	getDisplayChar - this method has no parameters and returns a char 
	value. The char value returned will be 'T' or 't'. The 
	lower case 't' indicates that the Troll is dead.
*/
const char Troll::getDisplayChar() const
{
	if (alive == false)
		return 't';
		
	return 'T';
}
