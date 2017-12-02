#include <iostream>
#include "RandomDice.h"
#include "RollOfDice.h"
#include "Dice.h"

/**
 * PLAYING DICE
 *
 * A project by 
 * Alexandre Fawcett - 7011967
 * Jérémie Beaudoin-Dion - 8876521
 *
 * This program lets the player play a game of
 * Qwinto or Qwixx.
 */
 
/**
 * Runs the Qwinto Game
 */
void runQwinto() {
	
}

/**
 * Runs the Qwixx Game
 */
void runQwixx() {
	
}

/**
 * A test that prints and rolls dices
 */
void testDice() {
	Colour g = Colour::GREEN;
	Dice d(g);
	
	d.roll();
	
	std::cout << d << std::endl;
	
	Colour r = Colour::RED;
	Dice d1(r);
	
	d1.roll();
	
	std::cout << d1 << std::endl;
}

/**
 * A test that uses different rollOfDice
 */
void testRollOfDice() {
	RollOfDice rollOfDice(3);
	
	rollOfDice.roll();
	
	std::cout << rollOfDice << std::endl;
	
	RollOfDice rollOfDice1(5);
	
	rollOfDice1.roll();
	
	std::cout << rollOfDice1 << std::endl;
}
 
/**
 * Different available tests
 */
void doTestAccordingToStringValue(std::string testValue) {
	
	if (testValue == "TEST_DICE") {
		testDice();	
		return;
	}
	
	if (testValue == "TEST_ROLLOFDICE") {
		testRollOfDice();	
		return;
	}
};

int main(int argc, char** argv) {
	
	if (argc > 1) {
		doTestAccordingToStringValue(std::string(argv[1]));
	}
	
	return 0;
}
