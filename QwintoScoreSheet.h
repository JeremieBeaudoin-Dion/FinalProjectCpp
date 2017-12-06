#ifndef _QWINTOSORESHEET_H
#define _QWINTOSORESHEET_H
#include "ScoreSheet.h"
#include "QwintoRow.h"
#include "Colour.h"
#include<iostream>

/**
 * Implémente une ScoreSheet pour un jeu de Qwinto.
 */
class QwintoScoreSheet: public ScoreSheet{
	public:

		QwintoRow<Colour::RED> red; 
		QwintoRow<Colour::BLUE> blue;
		QwintoRow<Colour::YELLOW> yellow;

		QwintoScoreSheet(std::string n):ScoreSheet(n){};

		int calcTotal();

		bool score(const RollOfDice rOD, const Colour c, int position);

		bool operator not();

	protected:

		bool validate(const RollOfDice rOD, const Colour c, int position);



};

	std::ostream& operator<<(std::ostream& os, QwintoScoreSheet& qSS);

#endif