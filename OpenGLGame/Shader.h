#pragma once

#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Shader
{
    // Function to read the contents of a file into a string
    string readShaderFile(const string& filePath) {
        ifstream fileStream(filePath);

        if (!fileStream.is_open()) {
            cerr << "Failed to open file: " << filePath << endl;
            return "";
        }

        stringstream buffer;
        buffer << fileStream.rdbuf();
        return buffer.str();
    }

    // Function to compile a shader from a source file
    GLuint compileShaderFromFile(const string& filePath, GLenum shaderType) {
        // Read shader source code from the file
        string shaderSource = readShaderFile(filePath);
        if (shaderSource.empty()) {
            return 0; // Failed to read shader source
        }

        const GLchar* shaderSourcePtr = shaderSource.c_str();

        // Compile shader
        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderSourcePtr, nullptr);
        glCompileShader(shader);

        // Check for compilation errors
        GLint success;
        GLchar infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success) {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            cerr << "Shader compilation error in " << filePath << ":\n" << infoLog << endl;
            glDeleteShader(shader);
            return 0;
        }

        return shader;
    }

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

