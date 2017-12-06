#ifndef _QWINTOROW_H
#define _QWINTOROW_H

#include<iostream>

/**
 * A QwintowRow is a row of points that will be used in a
 * Qwinto Game.
 */
template <Colour T>
class QwintoRow{
	
	public:

		int qR[9]={0};

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
        //else return(int x=0);
	

}
template <Colour T>
bool QwintoRow<T>::validate(int value){

        if(qR[value]==0) return true;
        else return false;

}
template <Colour T>
std::ostream& operator<<(std::ostream& os,QwintoRow<T>& qR){


        auto colour_as_integer = static_cast<int>(T);
        
        switch(colour_as_integer) {
                
                case 0:
                os << "Red          |";
                for(int i=0;i<9;i++){

                        if(qR[i]==0) os<<" ";
                        else {
                                if(qR[i]>10) os<<qR[i];
                                else os<<" "<<qR[i];
                        }

                        switch ( i ) {

                                case 0:
                                os << '%';
                                break;
                                case 1:
                                os << '%';
                                break;
                                case 2:
                                os << "|XX|";
                                break;
                                case 3:
                                os << '%';
                                break;
                                case 4:
                                os << '%';
                                break;
                                default:
                                os <<'|';
                                break;

                        }


                }
                os <<std::endl<<"          -------------------------" <<std::endl;
                        break;

                        //os << "Red                 "<< ((qR[0]==0)?' ':qR[0]) << '|' << char((qR[1]==0)?' ':qR[1]) << '%' << ((qR[2]==0)?' ':qR[2]) << '%' << ((qR[3]==0)?' ':qR[3]); os << "|XX| "<< ((qR[4]==0)?' ':qR[4]) << '%' << ((qR[5]==0)?' ':qR[5]) << '%' << ((qR[6]==0)?' ':qR[6]) << '|' << ((qR[7]==0)?' ':qR[7]) << '|' << ((qR[8]==0)?' ':qR[8]);os << '|' << std::endl;
                        //os <<"                      ----------------------------------" <<std::endl;
                        //break;
                
                case 1:

                os << "Yellow     |";
                for(int i=0;i<9;i++){

                        if(qR[i]==0) os<<" ";
                        else {
                                if(qR[i]>10) os<<qR[i];
                                else os<<" "<<qR[i];
                        }

                        switch ( i ) {

                                case 4:
                                os << "|XX|";
                                break;
                                case 5:
                                os << '%';
                                break;

                                case 6:
                                os << '%';
                                break;

                                default:
                                os <<'|';
                                break;

                        }


                }
                os <<std::endl<<"         ------------------------" <<std::endl;
                        break;
                        // os << "Yellow   "<< ((qR[0]==0)?' ':qR[0]) << '|' << ((qR[1]==0)?' ':qR[1]) << '|' << ((qR[2]==0)?' ':qR[2]) << '|' << ((qR[3]==0)?' ':qR[3]) << '|' << ((qR[4]==0)?' ':qR[4]);os << '|' << "|XX| "<< ((qR[5]==0)?' ':qR[5]) << '%' << ((qR[6]==0)?' ':qR[6]) << '%' << ((qR[7]==0)?' ':qR[7]) << '|' << ((qR[8]==0)?' ':qR[8]);os << '|' << std::endl;
                        // os <<"                  ----------------------------------" <<std::endl;
                        // break;
                        
                case 2:
                os << "Blue     |";
                for(int i=0;i<9;i++){

                        if(qR[i]==0) os<<" ";
                        else {
                                if(qR[i]>10) os<<qR[i];
                                else os<<" "<<qR[i];
                        }

                        switch ( i ) {

                                case 1:
                                os << '%';
                                break;
                                case 2:
                                os << '%';
                                break;
                                case 3:
                                os << "|XX|";
                                break;
                                case 7:
                                os << '%';
                                break;
                                case 8:
                                os << '%';
                                break;
                                default:
                                os <<'|';
                                break;

                        }


                }
                os <<std::endl<<"         ----------------------" <<std::endl;
                        break;
                        // os << "Blue     "<< ((qR[0]==0)?' ':qR[0]) << '|' << ((qR[1]==0)?' ':qR[1]) << '|' << ((qR[2]==0)?' ':qR[2]) << '%' << ((qR[3]==0)?' ':qR[3]) << '%' << ((qR[4]==0)?' ':qR[4]);os << "|XX| "<< ((qR[5]==0)?' ':qR[5]) << '|' << ((qR[6]==0)?' ':qR[6]) << '|' << ((qR[7]==0)?' ':qR[7]) << '%' << ((qR[8]==0)?' ':qR[8]);os << '%' << std::endl;
                        // os <<"          ----------------------------------" <<std::endl;
                        // break;
                  
                
        }


        return os;

}

