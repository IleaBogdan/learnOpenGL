#include"main.h"

void set_callbacks(GLFWwindow*&window){
    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); // resize window function set to window 
}

void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}  

void key_callback(GLFWwindow*window,int key,int scancode,int action,int mods){
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
}
