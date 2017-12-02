#ifndef _ROLLOFDICE_H
#define _ROLLOFDICE_H

#include "Dice.h"
#include <vector>

struct RollOfDice {
	std::vector<Dice> allDices;
	
	RollOfDice(int numberOfDice);
	RollOfDice(Dice, Dice);
	void roll();
	RollOfDice& pair(Dice, Dice);
	
	operator int() const{
		int total = 0;
	
		for (int i=0; i<allDices.size(); ++i) {
			total += allDices[i].face;
		}
		
		return total;
	}
};

std::ostream& operator<<(std::ostream&, RollOfDice&);

#endif
