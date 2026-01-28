//
// Created by jxmwa on 1/8/2026.
//

#ifndef TETRIS_2_0_BOARDGAMEOBJECT_H
#define TETRIS_2_0_BOARDGAMEOBJECT_H

#include "model/Board.h"

class BoardGameObject : public GameObject{
public:
    BoardGameObject(const Board& b);
    void update() override;
    void build();

private:
    const Board& m_board;
};


#endif //TETRIS_2_0_BOARDGAMEOBJECT_H