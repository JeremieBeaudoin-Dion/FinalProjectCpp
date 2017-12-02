#ifndef _QWINTOSORESHEET_H
#define _QWINTOSORESHEET_H

#include<ScoreSheet.h>
#include<iostream>

class QwintoScoreSheet{
	

	public:

		QwintoRow<RED> red; 
		QwintoRow<BLUE> blue;
		QwintoRow<YELLOW> yellow;

		bool validate();

		int calcTotal();

		std::ostream& operator<<(std::ostream&, const ScoreSheet&);

	public:

		ScoreSheet(string n):(name(n),failedThrow(0),totalScore(0));

		bool score(const RollOfDice*, const Colour*, int position = -1);

		int setTotal();

		bool operator not();

		std::ostream& operator<<(std::ostream&, const ScoreSheet&);
};

#endif