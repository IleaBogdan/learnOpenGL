#include"callbacks.h"

// resize window function
void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}  
void processInput(GLFWwindow*window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){ // close window on esc
        glfwSetWindowShouldClose(window,true);
    }
}