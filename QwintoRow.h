#ifndef _QWINTOROW_H
#define _QWINTOROW_H

#include<ScoreSheet.h>
#include<Colour.h>
#include<iostream>

template <Colour T>
class QwintoRow{
	
	public:

		int qR[9] = {0};

		int& operator[] (int);

		bool validate(int)


};

std::ostream& operator<<(std::ostream&, const QwintoRow<T>&);

#endif