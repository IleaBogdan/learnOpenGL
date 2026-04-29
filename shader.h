#pragma once
#include<iostream>
#include<fstream>
#include<string>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

class shader{
private:
    unsigned int program;
    void check_shader_error(const unsigned int&shader);
    void check_program_error(const unsigned int&program);
public:
    shader(const std::string&vertexShaderPath,const std::string&fragmentShaderPath);
    unsigned int get_program(void);
    void load_shaders(const std::string&vertexShaderPath,const std::string&fragmentShaderPath);
    void activate(void);
};