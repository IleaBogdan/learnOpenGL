#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

extern int render_triangle_number;
extern int render_fragment;

void framebuffer_size_callback(GLFWwindow*window,int width,int height);
void processInput(GLFWwindow*window);