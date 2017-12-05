#ifndef _DICE_H
#define _DICE_H

#include"Colour.h"
#include<iostream>

/**
 * A Dice object has a colour and a FACE value.
 * when the roll() method is called, the face value
 * is set randomly to a number between 1 and 6
 */
struct Dice {
	const Colour colour;
	int face;
	
	Dice(Colour c) : colour(c), face(0) {};
	void roll();
};

std::ostream& operator<<(std::ostream&, const Dice&);

#endif
