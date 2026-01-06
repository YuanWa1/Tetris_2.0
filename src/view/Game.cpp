//
// Created by Pawan on 1/6/26.
//

#include "Game.h"
#include "model/GameObject.h"

Game::Game(): m_window(600, 600, "Tetris_2.0"), m_shader("assets/shaders/vshader.vert", "assets/shaders/fshader.frag"), m_input() {
init();
}

void Game::init() {
    m_input.init(m_window.getWindow());

    //Create new game object
    GameObject gameObject;
    std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    gameObject.setVertices(vertices);
    //
    // for (auto &v : gameObject.getVertices()) {
    //     cout << v << endl;
    // }


    m_shader.draw(gameObject);


    // glGenVertexArrays(1, &m_vao);
    // glBindVertexArray(m_vao);
    // // Now we have our vertex Array object, which is the rule for the vertex drawing
    //
    // glGenBuffers(1, &m_vbo);
    // glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
    // // Now we have pointed which is our vertex data using the m_vbo
    //
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    // glEnableVertexAttribArray(0);
}



void Game::run() {
    while (!glfwWindowShouldClose(m_window.getWindow())) {

        m_input.beginFrame();
        glfwPollEvents();

        update();
        render();

        glfwSwapBuffers(m_window.getWindow());
    }
}

void Game::fixedUpdate(float deltaTime) {
    cout<<"fixedUpdate"<<endl;
}

void Game::update() {

    // m_input.update(m_window.getWindow());
    if (m_input.pressed(GLFW_KEY_SPACE)) {
        cout << "Space pressed : jump" << endl;
    }
    if (m_input.pressed(GLFW_KEY_W)) {
        cout << "W pressed : move forward" << endl;

    }
    if (m_input.pressed(GLFW_KEY_S)) {
        cout << "S pressed : move backward" << endl;
    }


}

void Game::render() {
    glClearColor(1.0f, 0.0f, 0.25, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_shader.use();

    // we have our data binded, and we have set the rule for strides too
    // we have to bind the vertex array again;
    glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

Game::~Game() {
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}