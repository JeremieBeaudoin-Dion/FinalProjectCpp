#include "RollOfDice.h"
#include "Dice.h"
#include "Colour.h"

RollOfDice::RollOfDice(int numberOfDice){
	
	for (int i=0; i<numberOfDice; ++i) {
		
		Colour desiredColour;
		
		if (i == 5) {
			desiredColour = Colour::WHITE;
		} else {
			desiredColour = static_cast<Colour>(i);
		}
		
		allDices.push_back(Dice(desiredColour));
	}
	
}

RollOfDice::RollOfDice(Dice d1, Dice d2) {
	allDices.push_back(d1);
	allDices.push_back(d2);
}

void RollOfDice::roll(){
	for (int i=0; i<allDices.size(); ++i) {
		allDices[i].roll();
	}
}

RollOfDice& RollOfDice::pair(Dice d1, Dice d2) {
	return *(new RollOfDice(d1, d2));
}

std::ostream& operator<<(std::ostream& os, RollOfDice& rod) {
	
	for (int i=0; i<rod.allDices.size(); ++i) {
		os << rod.allDices[i];
	}
	
}
