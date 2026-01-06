//
// Created by Pawan on 1/6/26.
//

#include <iostream>
#include "Input.h"
#include <cstring>

using namespace std;

Input::Input() {
    m_current.fill(false);
    m_previous.fill(false);
}

void Input::init(GLFWwindow* window) {
    m_window = window;
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, &Input::keyCallback);
}


void Input::beginFrame() {
    m_previous = m_current; // fast copy
}

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    auto* self = static_cast<Input*>(glfwGetWindowUserPointer(window));
    if (!self) return;

    if (key < 0 || key >= MAX_KEYS) return;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if (action == GLFW_PRESS)
    {
        self->m_current[key] = true;
    }else if (action == GLFW_RELEASE) {
        self->m_current[key] = false;
    }

}

bool Input::pressed(int key) const {
    return m_current[key] && !m_previous[key];
}

bool Input::held(int key) const {
    return m_current[key];
}

bool Input::released(int key) const {
    return !m_current[key] && m_previous[key];
}