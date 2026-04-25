#include"myErrors.h"
#include<iostream>

void endprogram(int status_code){
    glfwTerminate();
    exit(status_code);
}
void endprogram(int status_code,const char*message){
    std::cerr<<"ERROR: "<<message<<"\n";
    endprogram(status_code);
}
void endprogram(int status_code,const std::string&message){
    std::cerr<<"ERROR: "+message<<"\n";
    endprogram(status_code);
}

void checkProgramError(const unsigned int&program){
    // program erro check
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr<<"ERROR::PROGRAM::FAILED\n"<<infoLog<<std::endl;
        endprogram(FAIL);
    }
}

void checkShaderError(const unsigned int&shader){
    // shader error checking
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr<<"ERROR::SHADER::COMPILATION_FAILED\n"<<infoLog<<std::endl;
        endprogram(FAIL);
    }
}