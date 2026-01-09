//
// Created by Pawan on 1/5/26.
//

#ifndef TETRIS_2_0_CREATEWINDOW_H
#define TETRIS_2_0_CREATEWINDOW_H


#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

class Window {

public:
    Window(int width, int height, const char* appName);
    ~Window();
    void processESC();
    GLFWwindow* getWindow() const;
    static void error_callback(int error, const char* description);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
    GLFWwindow* window;

};

#endif //TETRIS_2_0_CREATEWINDOW_H