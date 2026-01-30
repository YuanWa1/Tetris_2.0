//
// Created by Pawan on 1/6/26.
//

#ifndef TETRIS_2_0_GAME_H
#define TETRIS_2_0_GAME_H
#include "../view/Window.h"
#include "../view/Renderer.h"
#include "controller/Input.h"
#include <vector>

#include "Board.h"
#include  "GameObject.h"
#include "view/BoardGameObject.h"

class Game {
public:
    Game();
    ~Game() = default;
    void run();

private:
    void init();
    void fixedUpdate(float FIXED_DT);
    void update();
    void render();

    // Engine
    Input m_input;
    Window m_window;
    Renderer m_shader;


    // Game part
    Board m_board;
    BoardGameObject m_boardGameObject;
    std::vector<GameObject*> scene;

};


#endif //TETRIS_2_0_GAME_H