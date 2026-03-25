//
// Created by jxmwa on 1/8/2026.
//

#ifndef TETRIS_2_0_BOARDGAMEOBJECT_H
#define TETRIS_2_0_BOARDGAMEOBJECT_H

#include "model/Board.h"
#include "../model/GameObject.h"

class BoardGameObject : public GameObject{
public:
    BoardGameObject(Board& b);
    void update() override;
    void build();

private:
    Board& m_board;
};


#endif //TETRIS_2_0_BOARDGAMEOBJECT_H