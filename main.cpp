#include <iostream>
#include "RandomDice.h"
#include "RollOfDice.h"
#include "Colour.h"
#include "Dice.h"
#include "QwintoRow.h"

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
	Colour r = Colour::BLUE;
        QwintoRow<Colour::RED> row; 
 	RollOfDice rd0(3),rd1(3),rd2(2),rd3(1),rd4(3),rd5(3),rd6(2),rd7(1),rd8(3),rd9(2);	
 	rd0.roll();
	row[0]=rd0;
	row[1]=rd1;
	row[2]=rd2;
	row[3]=rd3;
	row[4]=rd4;
	row[5]=rd5;
	row[6]=rd6;
	row[7]=rd7;
	row[8]=rd8;
	std::cout<<row<<std::endl;
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

       if (testValue == "TEST_ROW"){
		testQwintoRow();
		return;
	}
};

int main(int argc, char** argv) {
	
	if (argc > 1) {
		doTestAccordingToStringValue(std::string(argv[1]));
	}
	
	return 0;
}
