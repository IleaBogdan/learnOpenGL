#include"main.h"

signed main(){
    init_glfw();

    create_window(main_window,800,600,"The Main Window",nullptr,nullptr);
    glfwMakeContextCurrent(main_window);
    init_glad();  

    glViewport(0,0,800,600); // where in the window will the program draw
    set_callbacks(main_window);
    
    unsigned int shaderProgram=load_default_shaders();
    unsigned int nondefault_shaderProgram=load_default_shaders("fragment_2.glsl");

    // fun stuff (it is not fun)
    float vertices1[] = {
        0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f, 
        -0.5f, -0.5f, 0.0f,
        // -0.5f,  0.5f, 0.0f  
    };  
    unsigned int vertices_numbers1=3; // 3 * nr_of_triangles
    float vertices2[] = {
        // 0.5f, -0.5f, 0.0f,
        0.5f,  0.5f, 0.0f, 
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f  
    };  
    unsigned int vertices_numbers2=3;
    
    // generate a vertex array object
    unsigned int VBO1,VAO1,VBO2,VAO2;
    glGenBuffers(1,&VBO1);
    glGenVertexArrays(1,&VAO1);

    glBindVertexArray(VAO1);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO1);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices1),vertices1,GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    

    glGenBuffers(1,&VBO2);
    glGenVertexArrays(1,&VAO2);

    glBindVertexArray(VAO2);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO2);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices2),vertices2,GL_STATIC_DRAW);
    
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
        
        if(render_fragment==0){
            glUseProgram(shaderProgram);
        }else if(render_fragment==1){
            glUseProgram(nondefault_shaderProgram);
        }
        if(render_triangle_number==1){
            glBindVertexArray(VAO1);
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
            // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines

            glDrawArrays(GL_TRIANGLES,0,vertices_numbers1);        
        }else if(render_triangle_number==2){
            glBindVertexArray(VAO2);
            // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines

            glDrawArrays(GL_TRIANGLES,0,vertices_numbers2);
        }
        glBindVertexArray(0);    
        // end of render stuff
        
        glfwSwapBuffers(main_window); // double buffer magic function
        glfwPollEvents(); // checks for events like keyboard, mouse or window close
    }
    endprogram(SUCCES);
    return 0;
}