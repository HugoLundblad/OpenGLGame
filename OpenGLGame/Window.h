#pragma once

#include <iostream>
#include <windows.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

using namespace std;

class Window
{
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }


    static void error_callback(int error, const char* msg) {
        string s;
        s = " [" + to_string(error) + "] " + msg + '\n';
        cerr << s << endl;
    }

public:
    GLFWwindow* window;
    void swapBuffers() {
        glfwSwapBuffers(window);
    }
    bool success{};
    Window(int width, int height) {
        glfwSetErrorCallback(error_callback);

        // Initialize GLFW
        if (!glfwInit()) { // Exit, if it failed
            cout << "Failed to init GLFW" << endl;
            success = false;
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        // Request Window from Operating System
        GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
        if (window == nullptr)
        {
            cout << "Failed to create GLFW window" << endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(window);

        // Initialize GLAD (connects OpenGL Functions)
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            cout << "Failed to initialize GLAD" << endl;
            glfwTerminate();
            return;
        }
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // Initialization ends here
        success = true;
    }
};

