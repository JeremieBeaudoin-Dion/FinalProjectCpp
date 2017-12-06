#ifndef _QWIXXPLAYER_H
#define _QWIXXPLAYER_H


#include "Player.h"
#include "QwixxScoreSheet.h"

class QwixxPlayer: public Player{

public:

    QwixxScoreSheet qSS;

    explicit QwixxPlayer(const std::string s): qSS(s){};

    void inputBeforeRoll(RollOfDice&);
    void inputAfterRoll(RollOfDice&);

};


#endif //_QWIXXPLAYER_H
