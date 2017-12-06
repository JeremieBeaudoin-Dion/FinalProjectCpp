//
// Created by Colocataire on 2017-12-05.
//

#include "QwixxScoreSheet.h"

int QwixxScoreSheet::calcTotal() {

    int total = 0;

    total += entriesToPoints(red.numberOfEntries());
    total += entriesToPoints(blue.numberOfEntries());
    total += entriesToPoints(green.numberOfEntries());
    total += entriesToPoints(yellow.numberOfEntries());

    total -= failedThrows * 5;

    return total;
}

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

bool QwixxScoreSheet::score(const RollOfDice rOD, const Colour c) {

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
        } catch (std::string & s) {
            return false;
        }
    }

    return false;
}

bool QwixxScoreSheet::operator!() {
    return false;
}

bool QwixxScoreSheet::validate(const RollOfDice rOD, const Colour c) {
    return rOD.allDices.size() == 2;
}


