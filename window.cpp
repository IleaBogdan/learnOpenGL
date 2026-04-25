#include"window.h"
#include<iostream>

void create_window(GLFWwindow*&window,int width,int height,const char*title,GLFWmonitor*monitor,GLFWwindow*share){
    window=glfwCreateWindow(width,height,title,monitor,share);
    if(window==nullptr){
        std::cerr<<"Failed to create GLFW window"<<std::endl;
        endprogram(FAIL);
    }
}
void set_callbacks(GLFWwindow*&window){
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); // resize window function set to window 
}