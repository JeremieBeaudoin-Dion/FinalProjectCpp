#ifndef _QWIXXSCORESHEET_H
#define _QWIXXSCORESHEET_H

#include "ScoreSheet.h"
#include "QwixxRow.h"
#include <list>
#include <vector>

class QwixxScoreSheet: public ScoreSheet{

private:
    int entriesToPoints(int entries);

public:
    int failedThrows;
    QwixxRow<std::vector<int>, Colour::RED> red;
    QwixxRow<std::vector<int>, Colour::YELLOW> yellow;
    QwixxRow<std::list<int>, Colour::BLUE> blue;
    QwixxRow<std::list<int>, Colour::GREEN> green;

    explicit QwixxScoreSheet(std::string n): ScoreSheet(n), failedThrows(0) {};

    int calcTotal();

    bool score(const RollOfDice rOD, const Colour c, int position = -1);

    bool operator !();

protected:

    bool validate(const RollOfDice rOD, const Colour c, int position = -1);

};

std::ostream& operator<<(std::ostream& os, QwixxScoreSheet& qSS);

#endif //_QWIXXSCORESHEET_H
