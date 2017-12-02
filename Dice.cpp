#include "Dice.h"
#include "RandomDice.h"
#include "Colour.h"
#include <iostream>

void Dice::Roll() {
	face = RandomDice::getValue();
}

std::ostream& operator<< (std::ostream& os, Dice& d) {
	os << d.face;
    return os;
}
