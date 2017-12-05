#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"
//#include "QwintoRow.h"
//#include "Colour.h"

//QwintoScoreSheet::QwintoScoreSheet(std::string n){
	
//	ScoreSheet(n);
//}

int QwintoScoreSheet::calcTotal(){

//Premiere etape est de compter le nombre de case remplie dans les rangee
	int remplieR=0,remplieB=0,remplieJ=0;

	for(int i=0;i<9;i++){

		if(red[i]!=0)remplieR++;
		if(blue[i]!=0)remplieB++;
		if(yellow[i]!=0)remplieJ++;
	}

//Rangee complete?
	if (remplieR==9) totalScore+=red[9];
	else totalScore+=remplieR;

	if (remplieB==9) totalScore+=blue[9];
	else totalScore+=remplieB;

	if (remplieJ==9) totalScore+=yellow[9];
	else totalScore+=remplieJ;

//Colonne Remplie

	if(red[0]!=0 && yellow[1]!=0 && blue[2]!=0)
		totalScore+=blue[2];

	if(red[1]!=0 && yellow[2]!=0 && blue[3]!=0)
		totalScore+=red[1];
	
	for(int i=4;i<7;i++){

		if(red[i]!=0 && yellow[i+1]!=0 && blue[i+2]!=0){
			switch(i){

				case 4:
				totalScore+=red[i];
				case 5:
				totalScore+=yellow[i+1];
				case 6:
				totalScore+=blue[i+2];

			}
		}

	}

	totalScore-=(5 * failedThrow);
	return totalScore;

}

bool QwintoScoreSheet::operator!(){


}

bool QwintoScoreSheet::validate(const RollOfDice* rOD, const Colour* c, int position = -1){


}

std::ostream& operator<<(std::ostream& os, QwintoScoreSheet& qSS){

	os << "Player Name:" << qSS.name << "         Score:" << qSS.totalScore<< std::endl;
	os << qSS.red << std::endl;
	os << qSS.yellow <<std::endl;
	os << qSS.blue << std::endl;


}