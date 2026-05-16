#include"main.h"

signed main(int argc,char*argv[]){
    init(main_window);
    glViewport(0,0,800,600); // where in the window will the program draw
    set_callbacks(main_window);
    glfwSetKeyCallback(main_window,key_callback);

    shader main_shader;
    main_shader.init("shaders/vertex.glsl","shaders/fragment.glsl");
    main_shader.add_vo(trig_1);

    glfwMakeContextCurrent(main_window);
    while(!glfwWindowShouldClose(main_window)){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float time=glfwGetTime();
        float greenVal=(sin(time)/2.f)+.5f;
        main_shader.draw(0,"ourColor",std::vector<float>{.0f,greenVal,.0f,1.f});
        
        glBindVertexArray(0);
        // end of render stuff

        glfwSwapBuffers(main_window);
        glfwPollEvents();
    }
    return 0;
}