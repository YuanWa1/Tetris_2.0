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

    // gameObject.setVertices(vertices);
    m_object.setVertices(vertices);
    //
    // for (auto &v : gameObject.getVertices()) {
    //     cout << v << endl;
    // }
    scene.push_back(std::ref(m_object));
}



void Game::run() {
    while (!glfwWindowShouldClose(m_window.getWindow())) {

        m_input.beginFrame();
        glfwPollEvents();


        update();
        // m_shader.use();
        m_shader.draw(m_object, m_vao, m_vbo);
        render();


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
        cout << "W pressed : move forward" << endl;

    }

    if (m_input.held(GLFW_KEY_D)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 0; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] += dy;
        }
        m_object.setVertices(vert);
        cout << "W pressed : move forward" << endl;

    }

    if (m_input.held(GLFW_KEY_A)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 0; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] -= dy;
        }
        m_object.setVertices(vert);
        cout << "W pressed : move forward" << endl;

    }

    if (m_input.held(GLFW_KEY_S)) {
        std::vector<float> vert = m_object.getVertices();
        for (int i = 1; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] -= dy;
        }
        m_object.setVertices(vert);
        cout << "W pressed : move forward" << endl;

    }




    if (m_input.pressed(GLFW_KEY_S)) {
        cout << "S pressed : move backward" << endl;
    }


}

void Game::render() {
    // glClearColor(1.0f, 0.0f, 0.25, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT);

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