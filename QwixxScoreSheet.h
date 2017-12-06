//
// Created by Colocataire on 2017-12-05.
//

#ifndef UNTITLED2_QWIXXSCORESHEET_H
#define UNTITLED2_QWIXXSCORESHEET_H


#include "ScoreSheet.h"
#include "QwixxRow.h"
#include <list>
#include <vector>

class QwixxScoreSheet: public ScoreSheet{
    int failedThrows;

private:
    int entriesToPoints(int entries);

public:

    QwixxRow<std::vector<int>, Colour::RED> red;
    QwixxRow<std::vector<int>, Colour::YELLOW> yellow;
    QwixxRow<std::list<int>, Colour::BLUE> blue;
    QwixxRow<std::list<int>, Colour::GREEN> green;

    explicit QwixxScoreSheet(std::string n): ScoreSheet(n), failedThrows(0) {};

    int calcTotal() override;

    bool score(const RollOfDice rOD, const Colour c);

    bool operator !();

protected:

    bool validate(const RollOfDice rOD, const Colour c);



};


#endif //UNTITLED2_QWIXXSCORESHEET_H
