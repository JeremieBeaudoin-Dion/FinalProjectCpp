#include "Player.h"
#include "QwintoPlayer.h"
#include "Dice.h"
#include <string>
#include<vector>

/**
 * Pose les questions au player avant de rouler des dés.
 */
void QwintoPlayer::inputBeforeRoll(RollOfDice& rOD) {

	//Premiere Etape est de demander au joueur de choisir ses des a rouler

	std::cout<<"C'est a votre tour de jouer " <<qSS.name<<". Lorsque demande, repondez <<oui>> si vous voulez jouer le de";
	std::cout<<" en question, et <non> pour ne pas le rouler" << std::endl;
	std::string rep="";
	bool done=true;
	std::cout<<"Voulez-vous jouer le de Rouge?" << std::endl;
	while(done){
	std::cin>>rep;
	if(rep =="oui") rOD.allDices.push_back(Dice(Colour::RED)); done=false;
	if(rep == "non") done=false;
	}
	done = true;
	std::cout<<"Voulez-vous jouer le de Bleue?" << std::endl;
    while(done){
	std::cin>>rep;
	if(rep =="oui") rOD.allDices.push_back(Dice(Colour::BLUE)); done=false;
	if(rep == "non") done=false;
	}
	done = true;
	std::cout<<"Voulez-vous jouer le de Jaune?" << std::endl;
    while(done){
	std::cin>>rep;
	if(rep =="oui") rOD.allDices.push_back(Dice(Colour::YELLOW)); done=false;
	if(rep == "non") done=false;
	}
	
}

/**
 * Pose les questions au player après avoir roulé des dés.
 */
void QwintoPlayer::inputAfterRoll(RollOfDice& rOD){

	std::string rep;
	Colour c;
	int pos;
	bool done = true;
	std::cout<<"Dans quelle couleure de range voulez-vous rentrer votre point? Repondez <<rouge>>, <<jaune>> ou <<bleu>>." << std::endl;
	while(done)
	{
		std::cin >> rep;
		if(rep.compare("bleu")==0) c = Colour::BLUE; done = false;
		if(rep.compare("jaune")==0) c = Colour::YELLOW; done = false;
		if(rep.compare("rouge")==0) c = Colour::RED; done = false;
	}

	done = true;
	std::cout<<"Dans quelle colonne voulez-vous rentrer votre point? Repondez un entier entre 1 et 9." << std::endl;
	while(done)
	{
		std::cin >> pos;
		if(pos>=1 && pos<=9) pos -= 1; done = false;
	}
	//std::cout<< "position: " << pos<<std::endl;
	//std::cout << "COLOUR " << static_cast<int>(c) << std::endl;
	if(!qSS.score(rOD,c,pos)) std::cout << "Vous avez echoue votre essai" << std::endl;

}
