#ifndef _DICE_H
#define _DICE_H

#include"Colour.h"
#include<iostream>

struct Dice {
	const Colour colour;
	int face;
	
	Dice(Colour c) : colour(c), face(0) {};
	void roll();
};

std::ostream& operator<<(std::ostream&, Dice&);


#endif
