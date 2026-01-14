//
// Created by jxmwa on 1/8/2026.
//

#include "BoardGameObject.h"

#include <iostream>

BoardGameObject::BoardGameObject(const Board& b) : m_board(b){
    // Initialize vertices based on the board state
    // Center is at (0,0) row/2 and col/2 assuming row and col are even
    std::vector<float> tmp_vertices;
    float cellSize = 0.1f; // Size of each cell

    //start point = (-col/2 * cellSize, row/2 * cellSize)
    float startX = - (Board::COLS / 2.0f) * cellSize;
    float startY = (Board::ROWS / 2.0f) * cellSize;

    for (int i = 0; i < Board::ROWS; ++i) {
        for (int j = 0; j < Board::COLS; ++j) {
            if (m_board.board[i][j]) {
                float x = startX + j * cellSize;
                float y = startY - i * cellSize;

                // Define the 4 corners of the cell (two triangles)
                tmp_vertices.insert(tmp_vertices.end(), {
                    x,y,0.0f,  // Top-left
                    x + cellSize, y,0.0f,  // Top-right
                    x + cellSize, y - cellSize, 0.0f,  // Bottom-right

                    x,y,0.0f,  // Top-left
                    x + cellSize, y - cellSize, 0.0f,  // Bottom-right
                    x,y - cellSize, 0.0f   // Bottom-left
                });
            }
        }
    }

    setVertices(tmp_vertices);
}
