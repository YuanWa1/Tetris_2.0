//
// Created by Pawan on 1/5/26.
//

#include "CreateWindow.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

CreateWindow::CreateWindow(int width, int height, const char* appName) {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        cout << "Initialization of GLFW has failed" << endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(width, height, appName, nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        cout << "Failed to initalize the window" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Window initializing" << endl;

    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
    }
    // glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

}

void CreateWindow::error_callback(int error, const char *description) {
    fprintf(stderr, "Error occured %s\n", description);
}

GLFWwindow* CreateWindow::getWindow() const {
    return this->window;
}

void CreateWindow::processESC() {
    if (glfwGetKey(this->window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(this->window, GLFW_TRUE);
    }
}
CreateWindow::~CreateWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}


void CreateWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}