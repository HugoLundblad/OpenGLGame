#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "Triangle.h"

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

    float vertices[]{
           -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f,
           -1.0f, 0.5f, 0.0f
    };

    Mesh mesh1{vertices, size(vertices)};

    float vertices2[] = {
   -1.0f, -0.5f, 0.0f,
    0.0f, -0.5f, 0.0f,
   -0.5f,  0.5f, 0.0f
    };

    Mesh mesh2{ vertices2, size(vertices2) };

    // ----- Compile the Vertex Shader on the GPU -------

    Shader vertexShader{"vertexShader.glsl", GL_VERTEX_SHADER};

    Shader orangeShader{"orangeFragmentShader.glsl", GL_FRAGMENT_SHADER};

    Shader yellowShader{
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "} \0", GL_FRAGMENT_SHADER };

    // -------- Create Orange Shader Program (Render Pipeline) ---------

    Material orange{vertexShader, orangeShader};
    Material yellow{ vertexShader, yellowShader };

    Triangle a{ &mesh1, &orange };
    Triangle b{ &mesh2, &yellow };


    // clean up shaders after they've been linked into a program
    // glDeleteShader(orangeFragmentShader);
    // glDeleteShader(yellowFragmentShader);



    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose())
    {
        // process input (e.g. close window on Esc)

        // render (paint the current frame of the game)
        window.clear();

        a.render();
        b.render();

        // present (send the current frame to the computer screen)
        window.present(); // ??
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}

