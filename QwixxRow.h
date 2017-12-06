#ifndef _QWIXXROW_H
#define _QWIXXROW_H

#include "RollOfDice.h" 
#include "Colour.h" 
#include<iostream>

template<class t, Colour c>
class QwixxRow {
	
	t holder;
	
	public:

		QwixxRow(); 

		QwixxRow& operator+=(const RollOfDice& rd);

};

template <class t, Colour c>
std::ostream& operator<<(std::ostream&, QwixxRow<t, c>&);

#endif

template<class t, Colour c>
QwixxRow<t, c>::QwixxRow() : holder() {
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
			os << number;
		} else {
			os << "XX";
		}
		
	}
	
}

template<class t, Colour c>
QwixxRow<t, c>::QwixxRow& operator+=(const RollOfDice& rd) {
	for (auto& number : qr.holder) {
		
		if (number == rd.int()) {
			number = -1;
			break;
		}
		
		if (number == -1) {
			throw "Illegal number, a smaller number has already been used";
		}
		
	}
}
