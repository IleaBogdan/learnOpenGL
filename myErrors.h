#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>

void checkProgramError(const unsigned int&program);
void checkShaderError(const unsigned int&shader);

#define SUCCES 0
#define FAIL -1

void endprogram(int status_code);
void endprogram(int status_code,const char*message);
void endprogram(int status_code,const std::string&message);