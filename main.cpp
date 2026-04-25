#include"main.h"

signed main(){
    init_glfw();

    create_window(main_window,800,600,"The Main Window",nullptr,nullptr);
    glfwMakeContextCurrent(main_window);
    init_glad();  

    glViewport(0,0,800,600); // where in the window will the program draw
    set_callbacks(main_window);
    
    unsigned int shaderProgram=load_default_shaders();

    // fun stuff (it is not fun)
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };  
    
    // generate a vertex array object
    unsigned int VBO,VAO;
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);  
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    // first arg is set to 0 because we have in vertex.glsl layout=0
    // the last arg is a void* and must be a void* of the offset from where the data starts
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    
    // render loop
    glfwMakeContextCurrent(main_window);
    while(!glfwWindowShouldClose(main_window)){
        processInput(main_window);
        
        // render stuff here:
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,3);
        // end of render stuff
        
        glfwSwapBuffers(main_window); // double buffer magic function
        glfwPollEvents(); // checks for events like keyboard, mouse or window close
    }
    endprogram(SUCCES);
    return 0;
}