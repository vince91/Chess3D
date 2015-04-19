#include "game.h"

Game::Game() {

}

void Game::initClassicGame(Scene * _scene) {
    none.init(0);
    player1.init(1);
    player2.init(2);
    board.initClassic(_scene);

    turn = 1;
    computeAvailableMovements();

    //testDebug();
}

void Game::loadFromFile() {

}

void Game::saveToFile() {

}

Player Game::check() {
    for (unsigned int i = 0 ; i < player1.getPieces().size() ; i++) {
        for (unsigned int j = 0 ; j < player1.getPieces()[i]->getAvailableMovements().size() ; j++) {
            if (player1.getPieces()[i]->getAvailableMovements()[j] == player2.getKing()->getPosition()) {
                return player2;
            }
        }
    }

    for (unsigned int i = 0 ; i < player2.getPieces().size() ; i++) {
        for (unsigned int j = 0 ; j < player2.getPieces()[i]->getAvailableMovements().size() ; j++) {
            if (player2.getPieces()[i]->getAvailableMovements()[j] == player1.getKing()->getPosition()) {
                return player1;
            }
        }
    }

    return none;
}

Player Game::checkMate() { //trop compliqué
    /*int cM = 0;
    bool c = false;
    for (unsigned int k = 0 ; k < player2.getKing().getAvailableMovements().size() ; k++) {
        for (unsigned int i = 0 ; i < player1.getPieces().size() ; i++) {
            for (unsigned int j = 0 ; j < player1.getPieces()[i].getAvailableMovements().size() ; j++) {
                if (player1.getPieces()[i].getAvailableMovements()[j] == player2.getKing().getAvailableMovements()[k]) {
                    c = true;
                }
            }
        }
        if (c) {
            cM++;
        }
        c = false;
    }
    if (cM = )

    cM = 0;
    c = false;
    for (unsigned int k = 0 ; k < player1.getKing().getAvailableMovements().size() ; k++) {
        for (unsigned int i = 0 ; i < player2.getPieces().size() ; i++) {
            for (unsigned int j = 0 ; j < player2.getPieces()[i].getAvailableMovements().size() ; j++) {
                if (player2.getPieces()[i].getAvailableMovements()[j] == player1.getKing().getAvailableMovements()[k]) {
                    c = true;
                }
            }
        }
        if (c) {
            cM++;
        }
        c = false;
    }*/
    return none;
}

void Game::changeTurn() {
    if (turn == 1) {
        turn = 2;
    } else {
        turn = 1;
    }
    player1.computeAvailableMovements(player1.getPieces(), player2.getPieces());
    player2.computeAvailableMovements(player2.getPieces(), player1.getPieces());
}

void Game::computeAvailableMovements() {
    player1.computeAvailableMovements(player1.getPieces(), player2.getPieces());
    player2.computeAvailableMovements(player1.getPieces(), player2.getPieces());
}

void Game::testDebug() {
    std::vector<Piece*> pieces = player1.getPieces();
    std::vector<std::vector<int> > debugMovements = pieces[0]->getAvailableMovements();
    std::cout << std::endl << "AVAILABLE MOVEMENTS" << std::endl;
    for (unsigned int i = 0 ; i < debugMovements.size() ; i++) {
        std::cout << debugMovements[i][0] << " " << debugMovements[i][1] << std::endl;
    }
}
