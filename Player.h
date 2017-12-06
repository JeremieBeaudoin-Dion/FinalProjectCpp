#ifndef _PLAYER_H
#define _PLAYER_H

#include"RollOfDice.h"
#include<iostream>

/**
 * The Player is an abstract class that ensures that
 * the methods inputBeforeRoll() and inputAfterRoll()
 * will be implemented in QwixxPlayer and QwintoPlayer
 */
class Player{
	
	public:
		bool active = false;
		//std::string name;
		virtual void inputBeforeRoll(RollOfDice&) = 0;
		virtual void inputAfterRoll(RollOfDice&) = 0;

};

#endif
