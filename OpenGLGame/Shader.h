#pragma once

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
    unsigned int shaderId;
	Shader(const char* source, short shaderType) {
        shaderId = glCreateShader(shaderType);
        glShaderSource(shaderId, 1, &source, NULL);
        glCompileShader(shaderId);
	}
    Shader(const Shader&) = delete;

    ~Shader() {
        glDeleteShader(shaderId);
    }
};

