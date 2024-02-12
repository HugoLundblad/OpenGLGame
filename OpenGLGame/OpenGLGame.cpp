
#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Material.h"
#include "GameObject.h"
#include "stb_image.h"
#include "Texture.h"

using namespace std;

void processInput(GLFWwindow*);

int main() {

    Window window{ 800,600 };

    Texture container{ "container.jpg", GL_TEXTURE0 };
    Texture wall{ "wall.jpg", GL_TEXTURE1 };

    int width, height, nrChannels;

    Vertex vertices[]{
           Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
           Vertex{Vector3{ 0.0f, -0.5f, 0.0f}},
           Vertex{Vector3{-0.5f,  0.5f, 0.0f}},
           Vertex{Vector3{-1.0f, -0.5f, 0.0f}},
           Vertex{Vector3{-0.5f,  0.5f, 0.0f}},
           Vertex{Vector3{-1.0f, 0.5f, 0.0f}}
    };


    Mesh mesh1{ vertices, size(vertices) };

    Vertex vertices2[]{
        Vertex{Vector3{0.0f, -0.5f, 0.0f},Color::red},
        Vertex{Vector3{1.0f, -0.5f, 0.0f},Color::green},
        Vertex{Vector3{0.5f,  0.5f, 0.0f},Color::blue}
    };

    Mesh mesh2{ vertices2, size(vertices2) };

    Vertex vertices3[]{
        // positions                           // colors        // texture coords
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},  Color::red,     Vector2{ 1.0f, 1.0f }},   // top right
        Vertex{Vector3{ 0.5f, -0.5f, 0.0f},  Color::green,   Vector2{ 1.0f, 0.0f }},   // bottom right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},  Color::blue,    Vector2{ 0.0f, 0.0f }},   // bottom left
        Vertex{Vector3{-0.5f,  0.5f, 0.0f},  Color::yellow,  Vector2{ 0.0f, 1.0f }},    // top left
        Vertex{Vector3{ 0.5f,  0.5f, 0.0f},  Color::red,     Vector2{ 1.0f, 1.0f }},   // top right
        Vertex{Vector3{-0.5f, -0.5f, 0.0f},  Color::blue,    Vector2{ 0.0f, 0.0f }},   // bottom left
    };

    Mesh mesh3{ vertices3, size(vertices3) };

    Shader vertexShader{ "vertexShader.glsl", GL_VERTEX_SHADER };

    Shader orangeShader{
        "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER
    };

    Shader yellowShader{
        "orangeFragmentShader.glsl", GL_FRAGMENT_SHADER
    };

    Shader textureShader{
        "textureFragmentShader.glsl", GL_FRAGMENT_SHADER
    };


    // -------- Create Orange Shader Program (Render Pipeline) ---------
    Material orange{ vertexShader, orangeShader };
    Material yellow{ vertexShader, yellowShader };
    Material textured{ vertexShader, textureShader };

    GameObject a{ &orange, &mesh1 };
    a.red = 1;
/*  GameObject b{&orange, Mesh::createTriangle()};
    b.red = 0.5f;
    GameObject c{ &textured, Mesh::createQuad(), &wall};
    c.horizontalOffset = -0.5f;
    GameObject d{ &textured, Mesh::createQuad(), &container };
    d.horizontalOffset = +0.5f; */

    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    vector<GameObject*> gameObjects{};
    for (size_t i = 0; i < size(cubePosition); i++)
    {
        GameObject* newCube = new GameObject{ &textured, Mesh::createCube(), &wall };
        newCube->rotation.z = i * 0.1f;
        newCube->rotation.x = i * 0.1f + 0.5f;
        newCube->position = cubePosition[i];
        gameObjects.push_back(newCube);
    }

    // While the User doesn't want to Quit (X Button, Alt+F4)
    while (!window.shouldClose()) // window -> window.window
    {
        window.processInput();

        window.clear();

        d.rotation.x = glfwGetTime();
        c.rotation.x = glfwGetTime();

        a.render();
        //a.horizontalOffset = cos(glfwGetTime());
        b.render();

        //c.horizontalOffset = cos(glfwGetTime());

        c.render();
        d.render();

        window.present();
    }
    // Cleans up all the GLFW stuff
    glfwTerminate();
    return 0;
}
