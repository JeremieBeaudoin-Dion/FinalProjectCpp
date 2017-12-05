#include "Player.h"
#include "RollOfDice.h"
#include "Dice.h"
#include<vector>
void QwintoPlayer::inputBeforeRoll(RollOfDice& rOD)
{

	//Premiere Etape est de demander au joueur de choisir ses des a rouler

	std::cout<<"C'est a votre tour de jouer. Lorsque demande, repondez <<oui>> si vous voulez jouer le de";
	std::cout<<" en question, et <non> pour ne pas le rouler" << endl;
	std::string rep;
	
	std::vector<Dice> d;

	std::cout<<"Voulez-vous jouer le de Rouge?" <<endl;
	while(rep!="oui" || rep!="non"){
	std::cin>>rep;
	if(rep=="oui") d.push_back(Dice(Colour::RED));
	}

	std::cout<<"Voulez-vous jouer le de Bleue?" <<endl;
    while(rep!="oui" || rep!="non"){
    std::cin >>rep;
    if(rep=="oui") d.push_back(Dice(Colour::BLUE));
	}

	std::cout<<"Voulez-vous jouer le de Jaune?" <<endl;
    while(rep!="oui" || rep!="non"){
    std::cin >>rep;
    if(rep=="oui") d.push_back(Dice(Colour::YELLOW));
	}
    rOD(d);
	std::cout<<rOD;
}

void QwintoPlayer::inputAfterRoll(RollOfDice& rOD){ }
