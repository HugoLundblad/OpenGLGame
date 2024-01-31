#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Window.h"
#include "Mesh.h"

using namespace std;

void processInput(GLFWwindow*);

int main() {

    Window window{ 800, 600 };

    // #500     #501
    int width, height, nrChannels;
    // unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);

    unsigned int textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    // glGenerateMipmap(GL_TEXTURE2D);

// ==================================================================
    // The Real Program starts here
    float red = 0;

    Mesh mesh1{};
    Mesh mesh2{};

    // ----- Compile the Vertex Shader on the GPU -------

    const char* vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // ------ Compile the Orange Fragment Shader on the GPU --------
    const char* orangeFragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "} \0";
    unsigned int orangeFragmentShader;
    orangeFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(orangeFragmentShader, 1, &orangeFragmentShaderSource, NULL);
    glCompileShader(orangeFragmentShader);

    // ------ Compile the Yellow Fragment Shader on the GPU --------
    const char* yellowFragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "} \0";
    unsigned int yellowFragmentShader;
    yellowFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(yellowFragmentShader, 1, &yellowFragmentShaderSource, NULL);
    glCompileShader(yellowFragmentShader);

    // -------- Create Orange Shader Program (Render Pipeline) ---------
    unsigned int orangeShaderProgram;
    orangeShaderProgram = glCreateProgram();
    glAttachShader(orangeShaderProgram, vertexShader);
    glAttachShader(orangeShaderProgram, orangeFragmentShader);
    glLinkProgram(orangeShaderProgram);

    // -------- Create Yellow Shader Program (Render Pipeline) ---------
    unsigned int yellowShaderProgram;
    yellowShaderProgram = glCreateProgram();
    glAttachShader(yellowShaderProgram, vertexShader);
    glAttachShader(yellowShaderProgram, yellowFragmentShader);
    glLinkProgram(yellowShaderProgram);

    // clean up shaders after they've been linked into a program
    glDeleteShader(vertexShader);
    glDeleteShader(orangeFragmentShader);
    glDeleteShader(yellowFragmentShader);



    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)
        window.processInput();
        red += 0.0001f;
        if (red > 1)
            red -= 1;

        // render (paint the current frame of the game)
        glClearColor(red, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(orangeShaderProgram);
        mesh1.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(yellowShaderProgram);
        mesh2.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // present (send the current frame to the computer screen)
        window.present(); // ??
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}

