#include "RollOfDice.h"
#include "Dice.h"
#include "Colour.h"

RollOfDice::RollOfDice(int numberOfDice){
	
	for (int i=0; i<numberOfDice; ++i) {
		allDices.push_back(Dice(static_cast<Colour>(i)));
	}
	
}

void RollOfDice::roll() {
	for (int i=0; i<allDices.size(); ++i) {
		allDices[i].roll();
	}
}
