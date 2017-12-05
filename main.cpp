#include <iostream>
#include "RandomDice.h"
#include "RollOfDice.h"
#include "Colour.h"
#include "Dice.h"
//#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"

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
    d.push_back(Dice(Colour::BLUE));
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

	//std::cout << not(qss);

	std::vector<Dice> d;
    d.push_back(Dice(Colour::YELLOW));
    d.push_back(Dice(Colour::BLUE));
 	RollOfDice rd(d);
 	rd.roll();
 	if (qss.score(rd,Colour::BLUE,2))
 		qss.setTotal();

 	std::vector<Dice> d1;
 	d1.push_back(Dice(Colour::RED));
    d1.push_back(Dice(Colour::BLUE));
 	RollOfDice rd1(d1);
 	rd1.roll();
 	if (qss.score(rd1,Colour::RED,0))
 		qss.setTotal();

 	std::vector<Dice> d2;
 	d2.push_back(Dice(Colour::YELLOW));
    d2.push_back(Dice(Colour::BLUE));
 	RollOfDice rd2(d2);
 	rd2.roll();
 	if (qss.score(rd2,Colour::YELLOW,1))
 		qss.setTotal();
	std::cout<< qss << std::endl;

}

void testQwintoPlayer(){

	QwintoPlayer qA("Alex");
 	RollOfDice rd;
 	while(!(qA.qSS)){
 		RollOfDice rd;
 		qA.inputBeforeRoll(rd);
 		//std::cout<<"BEFOREROLLDONE"<<std::endl;
 		rd.roll();
 		//std::cout<<"ROLLDONE"<<std::endl;
 		std::cout<<rd<<std::endl;
 		//std::cout<<"BEFOREROLLDONE"<<std::endl;
 		qA.qSS.setTotal();
 		//std::cout<<"BEFOREROLLDONE"<<std::endl;
 		std::cout<<qA.qSS<<std::endl;
 		qA.inputAfterRoll(rd);
 		std::cout<<qA.qSS<<std::endl;

 	}

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

	if (testValue == "TEST_QWINTOPLAYER"){
		testQwintoPlayer();
		return;
	}


};

int main(int argc, char** argv) {
	
	if (argc > 1) {
		doTestAccordingToStringValue(std::string(argv[1]));
	}
	
	return 0;
}
