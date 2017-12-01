#ifndef _SCORESHEET_H
#define _SCORESHEET_H

#include<RollOfDice.h>
#include<iostream>

class ScoreSheet{
	
	protected:
		string name; //Nom du joueur
		int failedThrow, totalScore; //Donnes pour les lancers echouers et son score total

		virtual bool validate() = 0;

		virtual int calcTotal() = 0;

	public:

		ScoreSheet(string n):(name(n),failedThrow(0),totalScore(0));

		virtual bool score(const RollOfDice*, const Colour*, int position = -1);

		virtual int setTotal();

		virtual bool operator not();

		virtual std::stream& operator<<(std::ostream&, const ScoreSheet&);
};

#endif