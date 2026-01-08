// Created by Pawan on 1/5/26.

#include "CreateWindow.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

CreateWindow::CreateWindow(int width, int height, const char* appName) {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        std::cout << "Initialization of GLFW has failed\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // --- current primary monitor mode ---
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    if (!monitor || !mode) {
        std::cout << "Failed to get primary monitor / video mode\n";
        glfwTerminate();
        return;
    }

    glfwWindowHint(GLFW_RED_BITS,     mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS,   mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS,    mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

    // fullscreen:
    // window = glfwCreateWindow(mode->width, mode->height, appName, monitor, nullptr);
    //windowed fallback, you can do:
    window = glfwCreateWindow(width, height, appName, nullptr, nullptr);

    if (!window) {
        std::cout << "Failed to initialize the window\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        window = nullptr;
        return;
    }

    // VSync
    // glfwSwapInterval(1);

    // viewport size
    int fbW, fbH;
    glfwGetFramebufferSize(window, &fbW, &fbH);
    glViewport(0, 0, fbW, fbH);

    //background
    glClearColor(0.05f, 0.05f, 0.08f, 1.0f);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void CreateWindow::error_callback(int error, const char* description) {
    std::cerr << "GLFW Error (" << error << "): " << description << "\n";
}

GLFWwindow* CreateWindow::getWindow() const {
    return window;
}

void CreateWindow::processESC() {
    if (window && glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

CreateWindow::~CreateWindow() {
    if (window) glfwDestroyWindow(window);
    glfwTerminate();
}

void CreateWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
