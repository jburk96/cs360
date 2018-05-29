/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 2
	Description: This is the .cpp file for Enemy. This class has a 
	constructor, destructor, and an isAlive method.
*/

#include "Enemy.h"
int Enemy::idGenerator = 1;
/*
	Enemy - has an initializer list for any const variables needing to 
	be set from inherited classes. These variables include the health, 
	strength, constitution, xPosition, and yPosition. The constructor 
	the sets alive to true when the Enemy is created.
*/
Enemy::Enemy(int hp, int strength, int constitution, int xPos, int yPos): 
	health(hp), 
	str(strength), 
	con(constitution),
	xPosition(xPos),
	yPosition(yPos)
{
	alive = true;
}

/*
	isAlive - this is a test to determine whether the Enemy is 
	currently alive or dead. If the Enemy is alive, it returns 
	true. If it is dead, it returns false.
*/
bool Enemy::isAlive() const
{
	if (alive == true)
		return true;
		
	return false;
}

int Enemy::getId() const
{
	return id;
}

int Enemy::getHealth() const
{
	return health;
}

int Enemy::getStr() const
{
	return str;
}

int Enemy::getCon() const
{
	return con;
}
int Enemy::getX() const
{
	return xPosition;
}

int Enemy::getY() const
{
	return yPosition;
}
