#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"myErrors.h"
#include"callbacks.h"

void create_window(GLFWwindow*&window,int width,int height,const char*title,GLFWmonitor*monitor,GLFWwindow*share);
void set_callbacks(GLFWwindow*&window);