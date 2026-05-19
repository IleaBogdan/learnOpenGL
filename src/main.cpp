#include"main.h"

signed main(int argc,char*argv[]){
    init(main_window,"Random Triangle");
    glViewport(0,0,800,600); // where in the window will the program draw
    set_callbacks(main_window);
    glfwSetKeyCallback(main_window,key_callback);

    shader main_shader;
    main_shader.init("shaders/vertex_v2.glsl","shaders/fragment_v2.glsl");
    main_shader.add_vo(trig_2,trig_2_attribute_sizes);
    // main_shader.init("shaders/vertex.glsl","shaders/fragment.glsl");
    // main_shader.add_vo(trig_1,trig_1_attribute_sizes);

    int frame_count=0;
    glfwMakeContextCurrent(main_window);
    while(!glfwWindowShouldClose(main_window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        float time=glfwGetTime();
        float greenVal=(sin(time)/2.f)+.5f;
        main_shader.draw(0,
            // uniforms:
            "offsets",std::vector<float>{global_horizontal_offset,global_vertical_offset},
            "alpha",std::vector<float>{alpha}
        );
        
        glBindVertexArray(0);
        // end of render stuff

        ++frame_count;
        if(frame_count==5)alpha+=PI/6.f;
        frame_count%=5;

        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }
    return 0;
}