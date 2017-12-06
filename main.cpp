#include <iostream>
#include "RandomDice.h"
#include "RollOfDice.h"
#include "Colour.h"
#include "Dice.h"
//#include "QwintoRow.h"
#include "QwintoScoreSheet.h"
#include "QwintoPlayer.h"
//#include "Player.h"

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
	
	std::cout << "------QWINTO-------" << std::endl;
	std::cout << "SVP choisir le nombre de joueurs (1 a 3): " << std::endl;
	int nPlayer;
	while(true){
		std::cin >> nPlayer;
		if(nPlayer>=1 && nPlayer<=3) break;
	}

	std::string name;

	std::vector<QwintoPlayer> qP;
	for(int i=1;i<=nPlayer;i++)
	{

		std::cout << "Jouer " << i << ", svp rentrez votre nom: ";
		std::cin >> name;
		qP.push_back(QwintoPlayer(name));

	}
	qP[nPlayer-1].active = true;

	bool endcondition = true;
	while(endcondition){
	RollOfDice rOD;
	
	int nextP = 0;

	for (nextP;nextP<qP.size();nextP++) {
		if(qP[nextP].active){
			qP[nextP].active = false;
			qP[(nextP+1)%nPlayer].active = true;
			break;
		}
	}

	//std::cout << "C'est a votre tour de jouer "<< qP[(nextP+1)%nPlayer].qSS.name <<std::endl;
	qP[(nextP+1)%nPlayer].inputBeforeRoll(rOD);
	
	rOD.roll();
	std::cout << rOD << std::endl;
	std::cout << qP[(nextP+1)%nPlayer].qSS << std::endl;
	qP[(nextP+1)%nPlayer].inputAfterRoll(rOD);

	nextP = 0;
	for (nextP;nextP<qP.size();nextP++) {
		if(!(qP[nextP].active)){
			std::cout << qP[(nextP)].qSS << std::endl;
			qP[nextP].inputAfterRoll(rOD);
		}
	}
	for (auto i=0;i<qP.size();i++) {
		if(!(!(qP[i].qSS))) endcondition = false;
		}
	}
	int maxScore = -1;
    QwintoPlayer* winningPlayer = nullptr;
    for (QwintoPlayer p : qP) {

        std::cout << p.qSS << std::endl;

        if (p.qSS.totalScore > maxScore) {
            winningPlayer = &p;
            maxScore = p.qSS.totalScore;
        }

    }

    std::cout << winningPlayer->qSS.name << ", vous avez gagné!" << std::endl;
}

/**
 * Runs the Qwixx Game
 */
void runQwixx() {

	std::cout << "------QWIXX-------" << std::endl;
	std::cout << "SVP choisir le nombre de joueurs (1 a 3): " << std::endl;
	int nPlayer;
	while(true){
		std::cin >> nPlayer;
		if(nPlayer>=1 && nPlayer<=3) break;
	}

	std::string name;

	std::vector<QwixxPlayer> qP;
	for(int i=1;i<=nPlayer;i++)
	{

		std::cout << "Jouer " << i << ", svp rentrez votre nom: ";
		std::cin >> name;
		qP.push_back(QwintoPlayer(name));

	}
	qP[nPlayer-1].active = true;

	bool endcondition = true;
	while(endcondition){
	RollOfDice rOD;
	
	int nextP = 0;

	for (nextP;nextP<qP.size();nextP++) {
		if(qP[nextP].active){
			qP[nextP].active = false;
			qP[(nextP+1)%nPlayer].active = true;
			break;
		}
	}

	//std::cout << "C'est a votre tour de jouer "<< qP[(nextP+1)%nPlayer].qSS.name <<std::endl;
	qP[(nextP+1)%nPlayer].inputBeforeRoll(rOD);
	
	rOD.roll();
	std::cout << rOD << std::endl;
	std::cout << qP[(nextP+1)%nPlayer].qSS << std::endl;
	qP[(nextP+1)%nPlayer].inputAfterRoll(rOD);

	nextP = 0;
	for (nextP;nextP<qP.size();nextP++) {
		if(!(qP[nextP].active)){
			std::cout << qP[(nextP)].qSS << std::endl;
			qP[nextP].inputAfterRoll(rOD);
		}
	}
	for (auto i=0;i<qP.size();i++) {
		if(!(!(qP[i].qSS))) endcondition = false;
		}
	}
	int maxScore = -1;
    QwixxPlayer* winningPlayer = nullptr;
    for (QwixxPlayer p : qP) {

        std::cout << p.qSS << std::endl;

        if (p.qSS.totalScore > maxScore) {
            winningPlayer = &p;
            maxScore = p.qSS.totalScore;
        }

    }

    std::cout << winningPlayer->qSS.name << ", vous avez gagné!" << std::endl;
	
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

// void testQwixxPlayer() {
//     QwixxPlayer qA("Jer");
//     RollOfDice rd;
//     while(!(qA.qSS)){
//         RollOfDice rd;
//         qA.inputBeforeRoll(rd);
//         //std::cout<<"BEFOREROLLDONE"<<std::endl;
//         //std::cout<<"ROLLDONE"<<std::endl;
//         std::cout<<rd<<std::endl;
//         //std::cout<<"BEFOREROLLDONE"<<std::endl;
//         qA.qSS.setTotal();
//         //std::cout<<"BEFOREROLLDONE"<<std::endl;
//         std::cout<< qA.qSS <<std::endl;
//         qA.inputAfterRoll(rd);
//         std::cout<< qA.qSS <<std::endl;

//     }
// }

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
	
	else{

		bool cond = true;
		std::string rep;
		while(cond){
			std::cout << "SVP choisir la version du jeu(Qwinto ou Qwixx), en ecrivant <<qwinto>> ou <<qwixx>>" << std::endl;	
			std::cin >> rep;
			if(rep.compare("qwinto")==0) runQwinto();
			if(rep.compare("qwixx")==0) runQwixx();
		}
	}
}
