//
// Created by Pawan on 1/6/26.
//

#ifndef TETRIS_2_0_GAME_H
#define TETRIS_2_0_GAME_H
#include  "CreateWindow.h"
#include  "Render.h"
#include "controller/Input.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void init();
    void fixedUpdate(float FIXED_DT);
    void update();
    void render();

    CreateWindow m_window;
    Render m_shader;
    Input m_input;

    unsigned int m_vao;
    unsigned int m_vbo;

};


#endif //TETRIS_2_0_GAME_H