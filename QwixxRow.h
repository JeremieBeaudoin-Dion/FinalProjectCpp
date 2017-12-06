#ifndef _QWIXXROW_H
#define _QWIXXROW_H

#include "RollOfDice.h"
#include "Colour.h"
#include<iostream>

template<class t, Colour c>
class QwixxRow {

public:
    t holder;
    bool locked;

    QwixxRow();

    QwixxRow& operator+=(const RollOfDice& rd);

    int numberOfEntries();
};

template <class t, Colour c>
std::ostream& operator<<(std::ostream&, QwixxRow<t, c>&);

#endif


template <class t, Colour c>
int QwixxRow<t, c>::numberOfEntries() {

    int number = 0;

    for (auto n : holder) {
        if (n < 0) {
            number++;
        }
    }

    if (locked) {
        number++;
    }

    return number;
}

template<class t, Colour c>
QwixxRow<t, c>::QwixxRow() : holder() {
    locked = false;

    auto colour_as_integer = static_cast<int>(c);

    switch(colour_as_integer) {

        case 0:

        case 1:
            for (int i=0; i<13; i++) {
                holder.push_back(i);
            }
            break;

        default:
            for (int i=12; i<-1; i--) {
                holder.push_back(i);
            }
            break;
    }

}

template<class t, Colour c>
QwixxRow<t, c>& QwixxRow<t, c>::operator+=(const RollOfDice &rd) {

    int point = static_cast<int>(rd);

    for (auto& number : holder) {

        if (number == point) {
            number = -1;
            break;
        }

        if (number == -1) {
            throw "Illegal number, a smaller number has already been used";
        }

    }

    if (numberOfEntries() > 4 && (point == 2 || point == 12)) {
        locked = true;
    }

    return *this;
}

template <class t, Colour c>
std::ostream& operator<<(std::ostream& os, QwixxRow<t, c>& qr) {

    auto colour_as_integer = static_cast<int>(c);

    switch(colour_as_integer) {

        case 0:
            os << "Red     ";
            break;

        case 1:
            os << "Yellow  ";
            break;

        case 2:
            os << "Blue    ";
            break;

        case 3:
            os << "Green   ";
            break;
    }

    for (auto number : qr.holder) {
        os << "|";
        if (number > -1) {
            if (number < 10) {
                os << " ";
            }
            os << number;
        } else {
            os << "XX";
        }

    }

    if (qr.locked) {
        os << " L";
    } else {
        os << " U";
    }

    os << std::endl;

    return os;

}