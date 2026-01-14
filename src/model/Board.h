//
// Created by jxmwa on 1/8/2026.
//

#ifndef TETRIS_2_0_BORAD_H
#define TETRIS_2_0_BORAD_H

#include "GameObject.h"

class Board{
public:
    static constexpr int ROWS = 20;
    static constexpr int COLS = 10;

    Board(): board{false} {};
    ~Board() = default;

    bool isRowFull();

    void removeRow();

    void setOccupied(int row, int col);

    // bool board[20][10];
    bool board[ROWS][COLS];

private:
    // bool board[20][10] = {false};
};


#endif //TETRIS_2_0_BORAD_H