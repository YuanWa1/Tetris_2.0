//
// Created by jxmwa on 1/8/2026.
//

#include "Board.h"

bool Board::isRowFull(int rowNumber) const {
    for (int j = 0; j < COLS; ++j) {
        if (!board[rowNumber][j]) {
            return false;
        }
    }
    return true;
}

void Board::removeFullRow() {
    for (int i = 0; i < ROWS; ++i) {
        if (isRowFull(i)) {
            for (int j = 0; j < COLS; ++j) {
                board[i][j] = false;
            }
            boardHasChanged = true;
        }
    }

}

void Board::setOccupied(int row, int col) {
    board[row][col] = true;
    boardHasChanged = true;
}

bool Board::shouldUpdate() const
{
    return boardHasChanged;
}
