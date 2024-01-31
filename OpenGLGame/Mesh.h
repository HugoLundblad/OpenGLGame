#pragma once

#include <glad/glad.h>


class Mesh
{
    unsigned int playerMesh;
public:

    void use() {
        glBindVertexArray(playerMesh);
    }

    struct Vertex {

    };

	Mesh() {

        // ----- Create Vertex Array Object, which makes changing between VBOs easier -----
        glGenVertexArrays(1, &playerMesh);
        glBindVertexArray(playerMesh);

        // ----- Create Array Buffer on the GPU and copy our vertices to GPU -------
        float vertices[] = {
           -1.0f, -0.5f, 0.0f,
            0.0f, -0.5f, 0.0f,
           -0.5f,  0.5f, 0.0f
        };
        unsigned int VBO; // variable to store buffer id
        glGenBuffers(1, &VBO); // ask open gl to create a buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO); // tell gl to use this buffer
        glBufferData(GL_ARRAY_BUFFER, // copy our vertices to the buffer
            sizeof(vertices), vertices, GL_STATIC_DRAW);

        // ------ configure vertex attribute(s) (currently it's just one, the position) -----
        // so the vertex shader understands, where to find the input attributes, in this case position
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
	}
};

