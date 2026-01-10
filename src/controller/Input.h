//
// Created by Pawan on 1/6/26.
//

#ifndef TETRIS_2_0_INPUT_H
#define TETRIS_2_0_INPUT_H

#include <array>
#include <GLFW/glfw3.h>

class Input {
public:
    Input ();
    void init(GLFWwindow* window);
    void update(GLFWwindow* window);
    bool pressed(int key) const;
    bool released(int key) const;
    bool held(int key) const;
    void beginFrame();

private:
    GLFWwindow* m_window = nullptr;
    static constexpr int MAX_KEYS = GLFW_KEY_LAST + 1;
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

    std::array<bool, MAX_KEYS>  m_current{};
    std::array<bool, MAX_KEYS>  m_previous{};
};


#endif //TETRIS_2_0_INPUT_H