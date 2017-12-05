#include "ScoreSheet.h"

int ScoreSheet::setTotal(){
	return calcTotal();
}

bool ScoreSheet::score(const RollOfDice rOD, const Colour c, int position ) {
	return validate(rOD, c, position);
}