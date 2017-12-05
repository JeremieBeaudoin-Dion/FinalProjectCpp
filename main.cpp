#include <iostream>
#include "RandomDice.h"
#include "RollOfDice.h"
#include "Colour.h"
#include "Dice.h"
//#include "QwintoRow.h"
#include "QwintoScoreSheet.h"

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
 * A test that tests QwintoRow
 */
void testQwintoRow() {
    QwintoRow<Colour::BLUE> row; 
    std::vector<Dice> d;
    d.push_back(Dice(Colour::YELLOW));
 	RollOfDice rd(d);
 	rd.roll();	
	row[0]=rd;
	std::cout<<row<<std::endl;
}


/**
 * A test that uses different rollOfDice
 */
void testRollOfDice() {
	std::vector<Dice> d;
    d.push_back(Dice(Colour::YELLOW));
 	RollOfDice rollOfDice(d);	
	
	rollOfDice.roll();
	
	std::cout << rollOfDice << std::endl;
	
	// RollOfDice rollOfDice(5);
	
	// rollOfDice1.roll();
	
	// std::cout << rollOfDice1 << std::endl;
}

void testQwintoScoreSheet(){

	QwintoScoreSheet qss("Alex");

	std::cout<< qss << std::endl;

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

       if (testValue == "TEST_ROW"){
		testQwintoRow();
		return;
	}

	 if (testValue == "TEST_SCORESHEET"){
		testQwintoScoreSheet();
		return;
	}


};

int main(int argc, char** argv) {
	
	if (argc > 1) {
		doTestAccordingToStringValue(std::string(argv[1]));
	}
	
	return 0;
}
