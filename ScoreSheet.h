#ifndef _SCORESHEET_H
#define _SCORESHEET_H

#include "RollOfDice.h" 
#include "Colour.h"
#include<iostream>

class ScoreSheet{
	
	public:
		std::string name; //Nom du joueur
		int failedThrow, totalScore; //Donnes pour les lancers echouers et son score total

		ScoreSheet(std::string n):name(n),failedThrow(0),totalScore(0){};

		virtual int calcTotal() = 0;

		bool score(const RollOfDice rOD, const Colour c, int position = -1);

		int setTotal();

		virtual bool operator not(){};

	protected:

		virtual bool validate(const RollOfDice, const Colour, int position) = 0;

};
	//std::ostream& operator<<(std::ostream&, ScoreSheet);

#endif
