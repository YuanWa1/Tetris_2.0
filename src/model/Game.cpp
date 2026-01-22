//
// Created by Pawan on 1/6/26.
//

#include "Game.h"

#include <algorithm>
#include <iostream>

#include "model/GameObject.h"

#include "model/Board.h"
#include "view/BoardGameObject.h"


Game::Game():
m_window(1200, 1200, "Tetris_2.0"),
m_shader("assets/shaders/vshader.vert", "assets/shaders/fshader.frag", &m_window),
m_input() {
    init();
}

void Game::init() {
    m_input.init(m_window.getWindow());

    glfwSetWindowUserPointer(m_window.getWindow(), this);
    std::cout << "C++ Window object @ " << (void*)this
      << " | GLFWwindow* @ " << m_window.getWindow() << "\n";
    //Create new board
    Board tetris_borad;

    tetris_borad.setOccupied(0,0);
    tetris_borad.setOccupied(1,1);
    tetris_borad.setOccupied(2,2);
    tetris_borad.setOccupied(3,3);
    tetris_borad.setOccupied(4,4);
    tetris_borad.setOccupied(5,5);

    //Create board game object
    BoardGameObject board_object(tetris_borad);


    //
    // for (const auto& row : tetris_borad.board) {
    //     // You can create GameObjects for each cell if needed
    //     for (const auto& cell : row) {
    //         std::cout << cell << " " << std::endl;
    //     }
    // }

    std::cout << "test here " << std::endl;
    std::cout << board_object.getVertices().size() << std::endl;

    // int i = 0;
    // for (const auto& test : board_object.getVertices()) {
    //     if (i%3 == 0) {
    //         std::cout << std::endl;
    //     }
    //     i++;
    //     std::cout << test << " " ;
    // }

    scene.push_back(board_object);



}



void Game::run() {

    while (!glfwWindowShouldClose(m_window.getWindow())) {

        m_input.beginFrame();
        glfwPollEvents();


        update();

        glClear(GL_COLOR_BUFFER_BIT);
        for (auto& object : scene) {
            m_shader.draw(object);
        }

        glfwSwapBuffers(m_window.getWindow());
    }
}

void Game::fixedUpdate(float deltaTime) {
    cout<<"fixedUpdate"<<endl;
}

void Game::update() {
    static float lastTime = (float)glfwGetTime();
    float currentTime = (float)glfwGetTime();
    float dt = currentTime - lastTime;
    lastTime = currentTime;
    float speed = 1.0f;      // units per second
    float dy = speed * dt;


    GameObject& m_object = scene[1];

    // m_input.update(m_window.getWindow());
    if (m_input.pressed(GLFW_KEY_SPACE)) {
        cout << "Space pressed : jump" << endl;
    }


    if (m_input.held(GLFW_KEY_W)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 1; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] += dy;
        }
        m_object.setVertices(vert);
        cout << "W held : move forward" << endl;

    }

    if (m_input.held(GLFW_KEY_D)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 0; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] += dy;
        }
        m_object.setVertices(vert);
        cout << "D held : move forward" << endl;

    }

    if (m_input.held(GLFW_KEY_A)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 0; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] -= dy;
        }
        m_object.setVertices(vert);
        cout << "A held : move forward" << endl;

    }

    if (m_input.pressed(GLFW_KEY_S)) {
        cout << "S pressed : move backward" << endl;
    }

    if (m_input.held(GLFW_KEY_S)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 1; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] -= dy;
        }
        m_object.setVertices(vert);
        cout << "S held : move forward" << endl;

    }


}