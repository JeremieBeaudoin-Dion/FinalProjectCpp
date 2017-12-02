#include "RollOfDice.h"
#include "Dice.h"

RollOfDice::int() {
	int total = 0;
	
	for (int i=0; i<allDices.size(); ++i) {
		total += allDices[0].face;
	}
}
