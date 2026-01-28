//
// Created by jxmwa on 1/8/2026.
//

#include "Board.h"

void Board::setOccupied(int row, int col) {
    board[row][col] = true;
    boardHasChanged = true;
}

bool Board::shouldUpdate() const
{
    return boardHasChanged;
}
