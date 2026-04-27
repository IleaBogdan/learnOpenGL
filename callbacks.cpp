#include"callbacks.h"

// resize window function
void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}  

int render_triangle_number=1;
int render_fragment=1;
int max_frags=2;
bool render_the_same=true;

void key_callback(GLFWwindow*window,int key,int scancode,int action,int mods){
    if(key==GLFW_KEY_ESCAPE&&action==GLFW_PRESS){
        glfwSetWindowShouldClose(window,true);
    }
    if(key==GLFW_KEY_1&&action==GLFW_PRESS){
        render_triangle_number=1;
    }
    if(key==GLFW_KEY_2&&action==GLFW_PRESS){
        render_triangle_number=2;
    }
    if(key==GLFW_KEY_A&&action==GLFW_PRESS){
        ++render_fragment;
        render_fragment%=max_frags;
    }
    if(key==GLFW_KEY_SPACE&&action==GLFW_RELEASE){
        render_the_same=!render_the_same;
    }
}

// void processInput(GLFWwindow*window){
//     if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){ // close window on esc
//         glfwSetWindowShouldClose(window,true);
//     }
//     if(glfwGetKey(window,GLFW_KEY_1)==GLFW_PRESS){
//         render_triangle_number=1;
//     }
//     if(glfwGetKey(window,GLFW_KEY_2)==GLFW_PRESS){
//         render_triangle_number=2;
//     }
//     if(glfwGetKey(window,GLFW_KEY_A)==GLFW_PRESS){
//         ++render_fragment;
//         render_fragment%=max_frags;
//     }
//     if(glfwGetKey(window,GLFW_KEY_SPACE)==GLFW_RELEASE){
//         render_the_same=!render_the_same;
//     }
// }