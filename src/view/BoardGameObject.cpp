//
// Created by jxmwa on 1/8/2026.
//

#include "BoardGameObject.h"

#include <iostream>

BoardGameObject::BoardGameObject(Board& b) : m_board(b){
    build();
}

void BoardGameObject::build()
{
    // Initialize vertices based on the board state
    // Center is at (0,0) row/2 and col/2 assuming row and col are even
    std::vector<float> tmp_vertices;
    std::vector<unsigned int> tmp_indices;
    float cellSize = 0.1f; // Size of each cell

    //start point = (-col/2 * cellSize, row/2 * cellSize)
    float startX = - (Board::COLS / 2.0f) * cellSize;
    float startY = (Board::ROWS / 2.0f) * cellSize;

    unsigned int base = 0;

    for (int i = 0; i < Board::ROWS; ++i) {
        for (int j = 0; j < Board::COLS; ++j) {
            if (m_board.board[i][j]) {
                float x = startX + j * cellSize;
                float y = startY - i * cellSize;

                // Define the 4 corners of the cell (two triangles)
                tmp_vertices.insert(tmp_vertices.end(), {
                    x,y,0.0f,  // Top-left
                    x,y - cellSize, 0.0f,   // Bottom-left
                    x + cellSize, y - cellSize, 0.0f,  // Bottom-right
                    x + cellSize, y,0.0f  // Top-right
                });



                tmp_indices.insert(tmp_indices.end(), {
                    base + 0, base + 1, base + 3, base + 1, base + 2, base + 3,
                });

                base += 4;
            }
        }
    }

    setVertices(tmp_vertices);
    setIndices(tmp_indices);
}

void BoardGameObject::update()
{
    // if (m_board.shouldUpdate())
    if (m_board.boardHasChanged)
    {
        build();
        m_board.boardHasChanged = false;
    }
}
