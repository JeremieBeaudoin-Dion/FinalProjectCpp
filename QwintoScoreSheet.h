#ifndef _QWINTOSORESHEET_H
#define _QWINTOSORESHEET_H
#include "ScoreSheet.h"
#include "QwintoRow.h"
#include "Colour.h"
#include<iostream>

class QwintoScoreSheet: public ScoreSheet{
	public:

		QwintoRow<Colour::RED> red; 
		QwintoRow<Colour::BLUE> blue;
		QwintoRow<Colour::YELLOW> yellow;

		QwintoScoreSheet(std::string n):ScoreSheet(n){};

		int calcTotal();

		bool operator !();

	protected:

		bool validate(const RollOfDice*, const Colour*, int position);

};

	std::ostream& operator<<(std::ostream& os, QwintoScoreSheet& qSS);

#endif