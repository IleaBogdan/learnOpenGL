#include"callbacks.h"

// resize window function
void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}  

int render_triangle_number=1;
int render_fragment=1;
int max_frags=2;
void processInput(GLFWwindow*window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){ // close window on esc
        glfwSetWindowShouldClose(window,true);
    }
    if(glfwGetKey(window,GLFW_KEY_1)==GLFW_PRESS){
        render_triangle_number=1;
    }
    if(glfwGetKey(window,GLFW_KEY_2)==GLFW_PRESS){
        render_triangle_number=2;
    }
    if(glfwGetKey(window,GLFW_KEY_A)==GLFW_PRESS){
        ++render_fragment;
        render_fragment%=max_frags;
    }
}