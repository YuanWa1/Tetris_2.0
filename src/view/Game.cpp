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
    GameObject gameObject1;
    std::vector<float> vertices1 = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f,


    };

    GameObject gameObject2;
    std::vector<float> vertices2 = {
        -0.1f, -0.1f, 0.0f,
         0.1f, -0.1f, 0.0f,
         0.0f,  0.1f, 0.0f
    };

    gameObject1.setVertices(vertices1);

    gameObject2.setVertices(vertices2);

    scene.push_back(gameObject1);
    scene.push_back(gameObject2);


}



void Game::run() {
    while (!glfwWindowShouldClose(m_window.getWindow())) {

        m_input.beginFrame();
        glfwPollEvents();


        update();
        // m_shader.use();
        // m_shader.draw(m_object, m_vao, m_vbo);
        glClear(GL_COLOR_BUFFER_BIT);
        for (auto& object : scene) {
            m_shader.draw(object,m_vao,m_vbo);
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
        for (int i = 0; i < (int)vert.size(); i += 3) { // y is index 1 of each vec3
            vert[i] -= dy;
        }
        m_object.setVertices(vert);
        cout << "S held : move forward" << endl;

    }


}

Game::~Game() {
    glDeleteVertexArrays(1, &m_vao);
    glDeleteBuffers(1, &m_vbo);
}