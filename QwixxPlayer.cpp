#include "QwixxPlayer.h"

void QwixxPlayer::inputBeforeRoll(RollOfDice& rOD) {

    if (active) {
        std::cout << qSS.name << ", c'est à votre tour de jouer" << std::endl;

        rOD.allDices = std::vector<Dice>();

        rOD.allDices.push_back(Dice(Colour::RED));
        rOD.allDices.push_back(Dice(Colour::YELLOW));
        rOD.allDices.push_back(Dice(Colour::BLUE));
        rOD.allDices.push_back(Dice(Colour::GREEN));
        rOD.allDices.push_back(Dice(Colour::WHITE));
        rOD.allDices.push_back(Dice(Colour::WHITE));

        rOD.roll();

    }

}

void QwixxPlayer::inputAfterRoll(RollOfDice & rOD) {

    int numberOfTakenThrows = 0;

    if (active) {
        std::cout << "Voici les dés qui ont été joues" << std::endl;
        std::cout << rOD << std::endl;

        std::string rep = "";
        bool done = true;

        std::cout << "Voulez-vous combiner un dé de couleur avec un dé blanc?" << std::endl;

        while (done) {
            std::cin >> rep;
            if (rep == "oui" || rep == "non") done = false;
        }

        if (rep == "oui") {
            numberOfTakenThrows++;
            std::cout << "Quelle couleur voulez-vous combiner avec un dé blanc?" << std::endl;

            done = true;
            std::string color = "";

            while (done) {
                std::cin >> color;
                if (color == "red" || color == "yellow" || color == "blue" || color == "green") done = false;
            }

            std::cout << "Voulez-vous le premier dé blanc?" << std::endl;
            done = true;

            while (done) {
                std::cin >> rep;
                if (rep == "oui" || rep == "non") done = false;
            }

            Dice whiteDice = nullptr;

            if (rep == "oui") {
                whiteDice = rOD.allDices[4];
            } else {
                whiteDice = rOD.allDices[5];
            }

            Dice colorDice = nullptr;
            if (color == "red") {
                colorDice = rOD.allDices[0];

            } else if (color == "yellow") {
                colorDice = rOD.allDices[1];

            } else if (color == "blue") {
                colorDice = rOD.allDices[2];

            } else if (color == "green") {
                colorDice = rOD.allDices[3];
            }

            if (!qSS.score(rOD.pair(whiteDice, colorDice), colorDice.colour)) {
                std::cout << "Failed throw" << std::endl;
            }

        }

    } else {
        std::cout << "Voici les dés qui ont été joues" << std::endl;
        std::cout << rOD << std::endl;

        std::string rep = "";
        bool done = true;

        std::cout << "Voulez-vous prendre des points avec les dés blancs?" << std::endl;

        while (done) {
            std::cin >> rep;
            if (rep == "oui" || rep == "non") done = false;
        }

        if (rep == "oui") {

            numberOfTakenThrows++;
            std::cout << "Dans quelle couleur voulez-vous mettre les points?" << std::endl;

            done = true;
            std::string color = "";

            while (done) {
                std::cin >> color;
                if (color == "red" || color == "yellow" || color == "blue" || color == "green") done = false;
            }

            Dice colorDice = nullptr;
            if (color == "red") {
                colorDice = rOD.allDices[0];

            } else if (color == "yellow") {
                colorDice = rOD.allDices[1];

            } else if (color == "blue") {
                colorDice = rOD.allDices[2];

            } else if (color == "green") {
                colorDice = rOD.allDices[3];
            }

            qSS.score(rOD.pair(rOD.allDices[4], rOD.allDices[5]), colorDice.colour);
        }

    }

    if (active && numberOfTakenThrows == 0) {
        qSS.failedThrow++;
    }
}
