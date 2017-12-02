#ifndef _ROLLOFDICE_H
#define _ROLLOFDICE_H

#include "Dice.h"
#include <vector>

struct RollOfDice {
	std::vector<Dice> allDices;
	
	RollOfDice(int numberOfDice);
	void roll();
	
	operator int() const{
		int total = 0;
	
		for (int i=0; i<allDices.size(); ++i) {
			total += allDices[i].face;
		}
		
		return total;
	}
};

#endif
