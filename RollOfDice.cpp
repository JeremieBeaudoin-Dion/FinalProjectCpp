#include "RollOfDice.h"
#include "Dice.h"
#include "Colour.h"
#include <iostream>
/**
 * Basic constructor for a RollOfDice that stores a number 
 * of die depending on a int value.
 */
// RollOfDice::RollOfDice(int numberOfDice){
	
// 	for (int i=0; i<numberOfDice; ++i) {
		
// 		Colour desiredColour;
		
// 		if (i == 5) {
// 			desiredColour = Colour::WHITE;
// 		} else {
// 			desiredColour = static_cast<Colour>(i);
// 		}
		
// 		allDices.push_back(Dice(desiredColour));
// 	}
	
// }


RollOfDice::RollOfDice(std::vector<Dice> d):allDices(d){};
/**
 * Helper constructor for the pair() method
 */
RollOfDice::RollOfDice(Dice d1, Dice d2) {
	allDices.push_back(d1);
	allDices.push_back(d2);
}

/**
 * Rolls each dice individually
 */
void RollOfDice::roll(){
	for (int i=0; i<allDices.size(); ++i) {
		allDices[i].roll();
	}
}

/**
 * Returns a RollOfDice consisting of the two desired dices.
 */
RollOfDice& RollOfDice::pair(Dice d1, Dice d2) {
	return *(new RollOfDice(d1, d2));
}

std::ostream& operator<<(std::ostream& os,const RollOfDice& rod) {

	for (auto i=0;i<rod.allDices.size();i++) {
		os << rod.allDices[i] << std::endl;
	}
	//os << std::endl;

	return os;
}
