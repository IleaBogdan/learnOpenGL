#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"vars.h"
#include"callbacks.h"
#include"shader_class/shader.h"
#include"shapes.h"
#include"stb_image.h"

void init(GLFWwindow*&window,const std::string&window_name,const bool&primariy_monitor=false);
unsigned int load_image_to_2d_texture(const std::string&image_path,const int&channels,const bool&flip=true);