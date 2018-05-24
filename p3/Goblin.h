#ifndef GOBLIN_H
#define GOBLIN_H

#include "Enemy.h"
#include "Goblin.h"
#include "Troll.h"
#include "Orc.h"

class Goblin: public Enemy {
	public:
		Goblin(int, int, int, int, int);
		void update();
		void print() const;
		void attack() const;
		void injure(int);
		const char getDisplayChar() const;
};//end of class

#endif
