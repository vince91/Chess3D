#ifndef BOARD_H
#define BOARD_H

#include <glm/glm.hpp>
#include <vector>
#include <map>
#include "scene.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

class Board
{
public:
    Board();
    virtual ~Board();
    std::vector<std::vector <Piece *>> initClassic(Scene * _scene);
    std::vector<std::vector <Piece *>> initWithFile(Scene * _scene, std::string);
    ///retourne la position d'une case dans l'espace
    inline glm::vec3 getPosAt(int i, int j){return squares[i][j];}
    inline glm::vec3 getPosAt(std::vector<int> square){return squares[ square[0] ][ square[1] ];}
    ///calcule et stocke la position dans squares
    void computeAllSquares();
    Piece * getPieceByVao(int vao){return vaoIDsMap[vao];}
    void movePieceTo(int vao, int i, int j);
    const glm::vec3 getOut() { return outOfBound; }

private:
    ///Créer les 16 pièces d'un joueur
    std::vector<Piece *> initPieceFromFile(int side);
    std::vector<Piece *> initPiece(int side);
    Scene * scene;
    std::map<int, Piece *> vaoIDsMap;
    ///retourne la position réelle d'une case sur le plateau
    glm::vec3 computeRealPosition(int i, int j);
    ///Permet de maper un ensemble de 2 int en positions réelles dans l'espace
    std::vector<std::vector<glm::vec3> > squares;
    ///Liste de toutes les pièces
    const glm::vec3 centerToSquare0 = glm::vec3(-265.0f, 0.0f, -267.0f);
    const glm::vec3 outOfBound = glm::vec3(2000.0f, 0.0f, 2000.0f);
    const float squareOffset = 76.0f;
};

#endif // BOARD_H
