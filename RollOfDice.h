#ifndef _ROLLOFDICE_H
#define _ROLLOFDICE_H

#include "Dice.h"
#include <vector>

/**
 * A RollOfDice is simply a container that has a certain amount
 * of die. When the method roll() is called, each dice is rolled
 * individually.
 */
struct RollOfDice {
	std::vector<Dice> allDices;
	
	//RollOfDice(int numberOfDice);
	RollOfDice(std::vector<Dice>);
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
