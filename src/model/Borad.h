//
// Created by jxmwa on 1/8/2026.
//

#ifndef TETRIS_2_0_BORAD_H
#define TETRIS_2_0_BORAD_H

#include "GameObject.h"

class Borad{
public:
    Borad() = default;
    ~Borad() = default;

    bool isRowFull();

    void removeRow();

private:
    bool board[20][10];
};


#endif //TETRIS_2_0_BORAD_H