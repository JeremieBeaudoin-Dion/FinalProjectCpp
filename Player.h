#ifndef _PLAYER_H
#define _PLAYER_H

#include"RollOfDice.h"
#include<iostream>

class Player{
	
	public:
		bool active;
		//std::string name;
		virtual void inputBeforeRoll(RollOfDice&) = 0;
		virtual void inputAfterRoll(RollOfDice&) = 0;

};

#endif
