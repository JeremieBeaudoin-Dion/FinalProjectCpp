#include<QwintoRow.h>
template <Colour T>
int& QwintoRow<T>::operator[](int index){
	
	if(validate(qR[index])){
	return qR[index];
	}

}

bool QwintoRow::validate(int value){
	
	if(value!=0) return true;
	else return false;

}

std::ostream& operator<<(std::ostream& os, const QwintoRow<T>& qwin)_{

	auto colour_as_integer = static_cast<int>(T);
	
	switch(colour_as_integer) {
		
		case 0:
			os << "Red		   "<< (qR[0]==0)?" ":qR[0] << "|" << (qR[1]==0)?" ":qR[1] << "%" << (qR[2]==0)?" ":qR[2] << "%" << (qR[3]==0)?" ":qR[3] << "|XX| "<< (qR[4]==0)?" ":qR[4] << "%" << (qR[5]==0)?" ":qR[5] << "%" << (qR[6]==0)?" ":qR[6] << "|" << (qR[7]==0)?" ":qR[7] << "|" << (qR[8]==0)?" ":qR[8] << "|" << std::endl;
			os <<"			    ----------------------------------" <<std::endl;
			break;
		
		case 1:
			os << "Yellow	"<< (qR[0]==0)?" ":qR[0] << "|" << (qR[1]==0)?" ":qR[1] << "|" << (qR[2]==0)?" ":qR[2] << "|" << (qR[3]==0)?" ":qR[3] << "|" << (qR[4]==0)?" ":qR[4] << "|" << "|XX| "<< (qR[5]==0)?" ":qR[5] << "%" << (qR[6]==0)?" ":qR[6] << "%" << (qR[7]==0)?" ":qR[7] << "|" << (qR[8]==0)?" ":qR[8] << "|" << std::endl;
			os <<"			----------------------------------" <<std::endl;
			break;
			
		case 2:
			os << "Blue	"<< (qR[0]==0)?" ":qR[0] << "|" << (qR[1]==0)?" ":qR[1] << "|" << (qR[2]==0)?" ":qR[2] << "%" << (qR[3]==0)?" ":qR[3] << "%" << (qR[4]==0)?" ":qR[4] << "|XX| "<< (qR[5]==0)?" ":qR[5] << "|" << (qR[6]==0)?" ":qR[6] << "|" << (qR[7]==0)?" ":qR[7] << "%" << (qR[8]==0)?" ":qR[8] << "%" << std::endl;
			os <<"		----------------------------------" <<std::endl;
			break;
			
		
	}

}
