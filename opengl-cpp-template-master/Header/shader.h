#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string get_file_contents(const char* a_cfileName);

class Shader
{
    public:
    GLuint ID;
    Shader(const char* a_vertexShader, const char* a_fragmentShader);

    void Activate();
    void Delete();
};
#endif  