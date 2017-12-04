#ifndef _QWINTOROW_H
#define _QWINTOROW_H

//#include "ScoreSheet.h" 
//#include "Colour.h" 
#include<iostream>

template <Colour T>
class QwintoRow{
	
	public:

		int qR[9];

		int& operator[](int index);

		bool validate(int value);


};

template <Colour T>
std::ostream& operator<<(std::ostream&, QwintoRow<T>&);

#endif


template<Colour T> 
int& QwintoRow<T>::operator[](int index){

        //if(validate(qR[index])){
        return qR[index];
        //}
	

}
template <Colour T>
bool QwintoRow<T>::validate(int value){

        if(value!=0) return true;
        else return false;

}
template <Colour T>
std::ostream& operator<<(std::ostream& os,QwintoRow<T>& qR){


        auto colour_as_integer = static_cast<int>(T);
        
        switch(colour_as_integer) {
                
                case 0:
                        os << "Red                 "<< ((qR[0]==0)?' ':qR[0]) << '|' << ((qR[1]==0)?' ':qR[1]) << '%' << ((qR[2]==0)?' ':qR[2]) << '%' << ((qR[3]==0)?' ':qR[3]); os << "|XX| "<< ((qR[4]==0)?' ':qR[4]) << '%' << ((qR[5]==0)?' ':qR[5]) << '%' << ((qR[6]==0)?' ':qR[6]) << '|' << ((qR[7]==0)?' ':qR[7]) << '|' << ((qR[8]==0)?' ':qR[8]);os << '|' << std::endl;
                        os <<"                      ----------------------------------" <<std::endl;
                        break;
                
                case 1:
                        os << "Yellow   "<< ((qR[0]==0)?' ':qR[0]) << '|' << ((qR[1]==0)?' ':qR[1]) << '|' << ((qR[2]==0)?' ':qR[2]) << '|' << ((qR[3]==0)?' ':qR[3]) << '|' << ((qR[4]==0)?' ':qR[4]);os << '|' << "|XX| "<< ((qR[5]==0)?' ':qR[5]) << '%' << ((qR[6]==0)?' ':qR[6]) << '%' << ((qR[7]==0)?' ':qR[7]) << '|' << ((qR[8]==0)?' ':qR[8]);os << '|' << std::endl;
                        os <<"                  ----------------------------------" <<std::endl;
                        break;
                        
                case 2:
                        os << "Blue     "<< ((qR[0]==0)?' ':qR[0]) << '|' << ((qR[1]==0)?' ':qR[1]) << '|' << ((qR[2]==0)?' ':qR[2]) << '%' << ((qR[3]==0)?' ':qR[3]) << '%' << ((qR[4]==0)?' ':qR[4]);os << "|XX| "<< ((qR[5]==0)?' ':qR[5]) << '|' << ((qR[6]==0)?' ':qR[6]) << '|' << ((qR[7]==0)?' ':qR[7]) << '%' << ((qR[8]==0)?' ':qR[8]);os << '%' << std::endl;
                        os <<"          ----------------------------------" <<std::endl;
                        break;
                        
                
        }

        return os;

}

