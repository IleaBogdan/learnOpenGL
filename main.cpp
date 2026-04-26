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
        0.5f, -0.5f, 0.0f,  // bottom right
        0.5f,  0.5f, 0.0f,  // top right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };  
    unsigned int indices[]{
        0,1,2,
        1,2,3
    };
    unsigned int vertices_numbers=3*2; // 3 * nr_of_triangles
    
    // generate a vertex array object
    unsigned int VBO,VAO,EBO;
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);  
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 
    
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
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
        // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines

        // actuall draw part:
        // glDrawArrays(GL_TRIANGLES,0,vertices_numbers);        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);    
        // end of render stuff
        
        glfwSwapBuffers(main_window); // double buffer magic function
        glfwPollEvents(); // checks for events like keyboard, mouse or window close
    }
    endprogram(SUCCES);
    return 0;
}