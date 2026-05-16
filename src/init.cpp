#include"main.h"

void init(GLFWwindow*&window){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
    window=glfwCreateWindow(800,600,"Learn OpenGL",nullptr,nullptr);
    if(!window){
        std::cerr<<"Failed to create window!\n";
        exit(-1);
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
        exit(-1);
    }
}