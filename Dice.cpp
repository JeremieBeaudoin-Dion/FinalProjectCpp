#include "Dice.h"
#include "RandomDice.h"
#include "Colour.h"
#include <iostream>

/**
 * Sets the face of the dice to a random value between
 * 1 and 6.
 */
void Dice::roll() {
	face = RandomDice::getValue();
}

std::ostream& operator<< (std::ostream& os, const Dice& d) {
	auto colour_as_integer = static_cast<int>(d.colour);
	
	switch(colour_as_integer) {
		
		case 0:
			os << "Red dice: ";
			break;
		
		case 1:
			os << "Yellow dice: ";
			break;
			
		case 2:
			os << "Blue dice: ";
			break;
			
		case 3:
			os << "Green dice: ";
			break;
			
		case 4:
			os << "White dice: ";
			break;
	}
	
	os << d.face;
	
    return os;
}
