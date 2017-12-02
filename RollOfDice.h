#ifndef _ROLLOFDICE_H
#define _ROLLOFDICE_H

#include "Dice.h"

struct RollOfDice {
	Dice[] allDices;
	
	RollOfDice(int numberOfDice);
	void Roll();
	operator int() const;
	
};

#endif
