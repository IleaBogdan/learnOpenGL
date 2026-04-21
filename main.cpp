#include"main.h"

// resize window function
void framebuffer_size_callback(GLFWwindow*window,int width,int height){
    glViewport(0,0,width,height);
}  
void processInput(GLFWwindow*window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS){ // close window on esc
        glfwSetWindowShouldClose(window,true);
    }
}

signed main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
    
    GLFWwindow*window=glfwCreateWindow(800,600,"LearnOpenGL",nullptr,nullptr);
    // GLFWwindow*window=glfwCreateWindow(800,600,"LearnOpenGL",glfwGetPrimaryMonitor(),nullptr);
    if(window==nullptr){
        std::cerr<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr<<"Failed to initialize GLAD"<<std::endl;
        return -1;
    }  

    glViewport(0,0,800,600);

    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback); // resize window function set to window 


    // render loop
    glfwMakeContextCurrent(window);
    while(!glfwWindowShouldClose(window)){
        processInput(window);

        // render stuff here:
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // end of render stuff
        
        glfwSwapBuffers(window); // double buffer magic function
        glfwPollEvents(); // checks for events like keyboard, mouse or window close
    }

    glfwTerminate();
    return 0;
}