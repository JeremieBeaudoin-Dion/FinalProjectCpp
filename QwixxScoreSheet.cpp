#include "QwixxScoreSheet.h"

/**
 * Retourne les points totaux du ScoreSheet.
 */
int QwixxScoreSheet::calcTotal() {

    int total = 0;

    total += entriesToPoints(red.numberOfEntries());
    total += entriesToPoints(blue.numberOfEntries());
    total += entriesToPoints(green.numberOfEntries());
    total += entriesToPoints(yellow.numberOfEntries());

    total -= failedThrows * 5;

    return total;
}

/**
 * Helper method for calcTotal()
 */
int QwixxScoreSheet::entriesToPoints(int entries) {

    switch (entries) {
        case 0:
            return 0;

        case 1:
            return 1;

        case 2:
            return 3;

        case 3:
            return 6;

        case 4:
            return 10;

        case 5:
            return 15;

        case 6:
            return 21;

        case 7:
            return 28;

        case 8:
            return 36;

        case 9:
            return 45;

        case 10:
            return 55;

        case 11:
            return 66;

        default:
            return 78;

    }
}

/**
 * Score les points désirés dans la rangée désirée.
 *
 * Return false si cela donne un FAILEDTHROW
 */
bool QwixxScoreSheet::score(const RollOfDice rOD, const Colour c, int position) {

    if (validate(rOD, c)) {
        try {
            auto colorInt = static_cast<int>(c);

            switch (colorInt) {
                case 0:
                    red += rOD;
                    return true;

                case 1:
                    yellow += rOD;
                    return true;

                case 2:
                    blue += rOD;
                    return true;

                case 3:
                    green += rOD;
                    return true;
            }
        } catch (...) {
            failedThrows++;
            return false;
        }
    }
    failedThrows++;
    return false;
}

/**
 * Aide à définir si la partie est finie.
 */
bool QwixxScoreSheet::operator!() {

    int numberOfLockedRows = 0;

    if (red.locked) {
        numberOfLockedRows++;
    }

    if (blue.locked) {
        numberOfLockedRows++;
    }

    if (green.locked) {
        numberOfLockedRows++;
    }

    if (yellow.locked) {
        numberOfLockedRows++;
    }

    return (failedThrows < 3 || numberOfLockedRows < 1);
}

/**
 * Retourne false si il est impossible de scorer les points désirés.
 */
bool QwixxScoreSheet::validate(const RollOfDice rOD, const Colour c, int position) {
    return rOD.allDices.size() == 2;
}

/**
 * Imprime la scoresheet
 *
 * Exemple:
 *
 *
 * Player name:
 *  ------------------------------------
 * Red | 2| 3| 4| 5| 6| 7| 8| 9|10|11|12| U
 *  ------------------------------------
 * Yellow | 2| 3| 4| 5| 6| 7| 8| 9|10|11|12| U
 *  ------------------------------------
 * Green |12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| U
 *  ------------------------------------
 * Blue |12|11|10| 9| 8| 7| 6| 5| 4| 3| 2| U 
 *  ------------------------------------
 * Failed throws:
 */
std::ostream& operator<<(std::ostream& os, QwixxScoreSheet& qSS){

    os << "Player Name:" << qSS.name << "         Score:" << qSS.calcTotal()<< std::endl;
	os << "------------------------------------" << std::endl;
    os << qSS.red << std::endl;
	os << "------------------------------------" << std::endl;
    os << qSS.yellow <<std::endl;
	os << "------------------------------------" << std::endl;
    os << qSS.green << std::endl;
	os << "------------------------------------" << std::endl;
    os << qSS.blue << std::endl;
	os << "------------------------------------" << std::endl;

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