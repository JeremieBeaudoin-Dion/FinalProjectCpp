#ifndef _QWINTOPLAYER_H
#define _QWINTOPLAYER_H

#include<RollOfDice.h>
#include<iostream>

class QwintoPlayer::Player{
	
	public:

		QwintoScoreSheet qSS;

		QwintoPlayer(string s):qSS(s);
		
		void inputBeforeRoll(RollOfDice& rOD);
		void inputAfterRoll(RollOfDice& rOD);

};

#endif
