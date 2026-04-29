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
    if(action==GLFW_PRESS){
        switch(key){
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window,true);
            break;
            case GLFW_KEY_1:
                render_triangle_number=1;
            break;
            case GLFW_KEY_2:
                render_triangle_number=2;
            break;
            case GLFW_KEY_A:
                ++render_fragment;
                render_fragment%=max_frags;
            break;
        }
    }
    if(action==GLFW_RELEASE){
        switch(key){
            case GLFW_KEY_SPACE:
                render_the_same=!render_the_same;
            break;
        }
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