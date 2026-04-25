#pragma once
#include<string>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"myErrors.h"

std::string load_shader(const char*shaderPath);
unsigned int load_default_shaders(void);