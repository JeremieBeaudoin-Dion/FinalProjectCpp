#include "QwintoScoreSheet.h"
#include "ScoreSheet.h"

/**
 * Returns the total points accumultated in the QwintoScoreSheet
 */
int QwintoScoreSheet::calcTotal(){

//Premiere etape est de compter le nombre de case remplie dans les rangee
	int remplieR=0,remplieB=0,remplieJ=0;
	totalScore=0;

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

/**
 * Aide à déterminer si la partie est finie.
 */
bool QwintoScoreSheet::operator!(){

	int comp = 0;

	if(failedThrow==4) return false;

	int remplieR=0,remplieB=0,remplieJ=0;

	for(int i=0;i<9;i++){

		if(red[i]!=0)remplieR++;
		if(blue[i]!=0)remplieB++;
		if(yellow[i]!=0)remplieJ++;
	}

//Rangee complete?
	if (remplieR==9) comp++;

	if (remplieB==9) comp++;

	if (remplieJ==9) comp++;
	
	if(comp>=2) return false;
	else return true;

}

/**
 * Return false si il est possible d'effectuer une opération dans
 * une certaine position de la QwintoScoreSheet.
 */
bool QwintoScoreSheet::validate(const RollOfDice rOD, const Colour c, int position){

	bool goodColor = false;
	bool goodColumn = false;
	bool croissant = true;
	bool superposition = true;

	//Est-ce que la couleur choisie de la rangee est valide avec les des roules?
	for (auto i=0;i<=rOD.allDices.size();i++) {
		if(static_cast<int>(rOD.allDices[i].colour) == static_cast<int>(c)) goodColor = true;

	}

	switch(static_cast<int>(c)){

		case 0:
			goodColumn = red.validate(position);
			for(int i=0;i<=position;i++){
				if(red[i]>rOD){
					croissant = false;
					//break;
				}
			}
			for(int i=position;i<9;i++){
				if(red[i]<rOD && red[i]!=0){
					croissant = false;
					//break;
				}
			}
				switch(position){

					case 0:
						if(yellow[1] == rOD || blue[2] == rOD){
							superposition = false;
							break;
						}
					case 1:
						if(yellow[2] == rOD || blue[3] == rOD){
							superposition = false;
							break;
						}

					case 2:
						if(yellow[4] == rOD){
							superposition = false;
							break;
						}
					case 3:
						if(blue[5] == rOD){
							superposition = false;
							break;
						}
					default:
						if(yellow[position+1] == rOD || blue[position+2] == rOD){
							superposition = false;
							break;
						}
				

				}
			
			break;

		case 1:
			goodColumn = yellow.validate(position);
			for(int i=0;i<=position;i++){
				if(yellow[i]>rOD){
					croissant = false;
					//break;
				}
			}
			for(int i=position;i<9;i++){
				if(yellow[i]<rOD && yellow[i]!=0){
					croissant = false;
					//break;
				}
			}

			switch(position){

					case 0:
						if(blue[1] == rOD){
							superposition = false;
							break;
						}
					case 1:
						if(blue[2] == rOD || red[0] == rOD){
							superposition = false;
							break;
						}

					case 2:
						if(blue[3] == rOD || red[1] == rOD){
							superposition = false;
							break;
						}
					case 3:
						if(red[2] == rOD){
							superposition = false;
							break;
						}
					case 4:
						if(blue[4] == rOD){
							superposition = false;
							break;
						}
					default:
						if(blue[position+1] == rOD || red[position-1] == rOD){
							superposition = false;
							break;
						}
				

				}

			break;

		case 2:
			goodColumn = blue.validate(position);
			for(int i=0;i<=position;i++){
				if(blue[i]>rOD){
					croissant = false;
					//break;
				}
			}
			for(int i=position;i<9;i++){
				if(blue[i]<rOD && blue[i]!=0){
					croissant = false;
					//break;
				}
			}

			switch(position){

					case 0:
						break;

					case 1:
						if(yellow[0] == rOD){
							superposition = false;
							break;
						}

					case 2:
						if(yellow[1] == rOD || red[0] == rOD){
							superposition = false;
							break;
						}
					case 3:
						if(yellow[2] == rOD || red[1] == rOD){
							superposition = false;
							break;
						}
					case 4:
						if(yellow[4] == rOD){
							superposition = false;
							break;
						}

					case 5:
						if(red[3] == rOD){
							superposition = false;
							break;
						}
					default:
						if(yellow[position-1] == rOD || red[position-2] == rOD){
							superposition = false;
							break;
						}
				

				}
			break;
	}
	if (goodColumn && goodColor && superposition && croissant) return true;
	else return false;
}

/**
 * Essaie de scorer des points à une certaine position.
 * Return false si non-validé.
 */
bool QwintoScoreSheet::score(const RollOfDice rOD, const Colour c, int position){

	if(ScoreSheet::score(rOD,c,position)){

		switch(static_cast<int>(c)){

			case 0:
				red[position] = rOD;
				break;

			case 1:
				yellow[position] = rOD;
				break;

			case 2:
				blue[position] = rOD;
				break;
		}

		return true;
	}
	else{
		failedThrow++;
		return false;
	}
}

/**
 * Imprime la QwintoScoreSheet comme suit:
 *
  * Player name:
 *	 -------------------------------
 *	Red      | % % |XX| % % | | | |
 *	 ----------------------------------
 *	Yellow | | | | | |XX| % % | |
 *	 ----------------------------------
 *	Blue | | % % |XX| | | | % %
 *	 -------------------------------
 *	Failed throws: 
 */
std::ostream& operator<<(std::ostream& os, QwintoScoreSheet& qSS){

	os << "Player Name:" << qSS.name << "         Score:" << qSS.totalScore<< std::endl;
	os << "         --------------------------" << std::endl;
	os << qSS.red << std::endl;
	os << qSS.yellow <<std::endl;
	os << qSS.blue << std::endl;
	os << "Failed Throws:";
	if(qSS.failedThrow == 0) os<<std::endl;
	else{

		for(int i=1;i<=qSS.failedThrow;i++){
			os <<" "<<i;
		}
		os<<std::endl;
	}

	return os;

}