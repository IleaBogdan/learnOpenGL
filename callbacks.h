#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>

extern int render_triangle_number;
extern int render_fragment;
extern bool render_the_same;

void framebuffer_size_callback(GLFWwindow*window,int width,int height);
void key_callback(GLFWwindow*window,int key,int scancode,int action,int mods);
// void processInput(GLFWwindow*window);