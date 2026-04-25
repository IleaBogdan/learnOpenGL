#include"shaders.h"  
#include<iostream>
#include<fstream>

std::string load_shader(const char*shaderPath){
    std::ifstream file(shaderPath);
    if(!file){
        std::cerr<<"ERROR: Can't find: "<<shaderPath<<"\n";
        endprogram(FAIL);
    }
    return std::string((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
}

unsigned int load_default_shaders(void){
    // shader loading
    std::string vertexShaderSourceLoad=load_shader("vertex.glsl");
    const char*vertexShaderSource=vertexShaderSourceLoad.c_str();
    unsigned int vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkShaderError(vertexShader);

    std::string fragmentShaderSourceLoad=load_shader("fragment.glsl");
    const char*fragmentShaderSource=fragmentShaderSourceLoad.c_str();
    unsigned int fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderError(fragmentShader);


    unsigned int shaderProgram=glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramError(shaderProgram);

    glUseProgram(shaderProgram);

    // we no longer need the shaders now
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
    // end of shader loading (thank god)

    return shaderProgram;
}