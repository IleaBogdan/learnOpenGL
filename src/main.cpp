#include"main.h"

signed main(int argc,char*argv[]){
    init(main_window,"Learn OpenGL");
    glViewport(0,0,800,600); // where in the window will the program draw
    set_callbacks(main_window);
    glfwSetKeyCallback(main_window,key_callback);

    shader main_shader;
    // main_shader.init("shaders/vertex.glsl","shaders/fragment.glsl");
    // main_shader.init("shaders/vertex_v2.glsl","shaders/fragment_v2.glsl");
    main_shader.init("shaders/vertex_v3.glsl","shaders/fragment_v3.glsl");
    
    vertex_object vo;
    vo.init(square_1,square_1_attribute_sizes);

    unsigned int texture=load_image_to_2d_texture("assets/wood_container.jpg");

    glfwMakeContextCurrent(main_window);
    while(!glfwWindowShouldClose(main_window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        float time=glfwGetTime();
        float blueVal=(sin(time)/2.f)+.5f;

        glUseProgram(main_shader.get_program());

        
        int uColorIdx=glGetUniformLocation(main_shader.get_program(),"uColor");
        glUniform1f(uColorIdx,blueVal);
        
        // int ourColorIdx=glGetUniformLocation(main_shader.get_program(),"ourColor");
        // glUniform4f(ourColorIdx,.0f,.0f,blueVal,.0f);
        
        // int offsetsIdx=glGetUniformLocation(main_shader.get_program(),"offsets");
        // glUniform2f(offsetsIdx,global_horizontal_offset,global_vertical_offset);

        // int alphaIdx=glGetUniformLocation(main_shader.get_program(),"alpha");
        // glUniform1f(alphaIdx,alpha);
        
        glBindTexture(GL_TEXTURE_2D,texture);
        glBindVertexArray(vo.get_VAO());
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines

        // this only takes sets of 3 from the vector and draws traingles with each one of them and then moves to the next set of 3 from the vector
        // glDrawArrays(GL_TRIANGLES,0,this->vo[vo_index].shape_size());
        // this draws everything as a single shape (note: use it for convex polygons, idk what happes in a non convex polygon)
        glDrawArrays(GL_TRIANGLE_FAN,0,vo.shape_size());

        glBindVertexArray(0);
        // end of render stuff

        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }
    end_program:
    glfwTerminate();
    return 0;
}