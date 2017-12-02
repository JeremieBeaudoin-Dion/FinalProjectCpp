#include <iostream>
#include "RandomDice.h"
#include "Dice.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Colour r = Colour::GREEN;
	Dice d(r);
	
	d.roll();
	
	std::cout << d << std::endl;
	
	return 0;
}
