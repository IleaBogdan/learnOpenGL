#include"main.h"

signed main(int argc,char*argv[]){
    init(main_window,"Learn OpenGL");
    glViewport(0,0,800,600); // where in the window will the program draw
    set_callbacks(main_window);
    glfwSetKeyCallback(main_window,key_callback);

    shader main_shader;
    // main_shader.init("shaders/vertex.glsl","shaders/fragment.glsl");
    // main_shader.add_vo(trig_1,trig_1_attribute_sizes);
    // main_shader.init("shaders/vertex_v2.glsl","shaders/fragment_v2.glsl");
    // main_shader.add_vo(trig_2,trig_2_attribute_sizes);
    main_shader.init("shaders/vertex_v3.glsl","shaders/fragment_v3.glsl");
    main_shader.add_vo(square_1,square_1_attribute_sizes);

    main_shader.init_texture(load_image_to_2d_texture("assets/wood_container.jpg"),GL_TEXTURE_2D);

    glfwMakeContextCurrent(main_window);
    while(!glfwWindowShouldClose(main_window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        float time=glfwGetTime();
        float blueVal=(sin(time)/2.f)+.5f;
        // main_shader.draw(0,
        //     // uniforms:
        //     // "ourColor",std::vector<float>{.0f,.0f,blueVal,.0f}
        //     "offsets",std::vector<float>{global_horizontal_offset,global_vertical_offset},
        //     "alpha",std::vector<float>{alpha}
        // );
        main_shader.draw_with_texture(0,
            "uColor",std::vector<float>{blueVal}
        );
        
        glBindVertexArray(0);
        // end of render stuff

        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }
    end_program:
    glfwTerminate();
    return 0;
}