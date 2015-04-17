#ifndef BOARD_H
#define BOARD_H

#include <glm/glm.hpp>
#include <vector>

class Board
{
    public:
        Board();
        virtual ~Board();
        void init();
    private:
        std::vector<std::vector<glm::vec3> > squares;
};

#endif // BOARD_H
