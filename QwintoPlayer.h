#ifndef _QWINTOPLAYER_H
#define _QWINTOPLAYER_H

#include "RollOfDice.h"
#include "QwintoScoreSheet.h"
#include "Player.h"
#include<iostream>

/**
 * Une implémentation de Player pour un jeu de Qwinto.
 */
class QwintoPlayer: public Player{
	
	public:

		QwintoScoreSheet qSS;

		QwintoPlayer(std::string s):qSS(s){};
		
		void inputBeforeRoll(RollOfDice&);
		void inputAfterRoll(RollOfDice&);

};

#endif
