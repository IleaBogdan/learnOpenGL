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

    // load image data and generate texture
    unsigned int texture;
    glGenTextures(1,&texture);  
    glBindTexture(GL_TEXTURE_2D,texture);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    int width,height,nrChannels;
    unsigned char*data=stbi_load("assets/wood_container.jpg",&width,&height,&nrChannels,0); 
    if(data){}else{
        std::cerr<<"Failed to load texture\n";
        exit(-1);
    }

    // the 6th argument must always be 0 (some legacy crap)
    // the 7th and 8th is how we will pass the image data
    // the first agrument is what type of texture we have (it can be 1D, 2D or 3D)
    // the second argument has something to do with the mipmap level
    // the 3rd argument is what type of data is in our image (i.e. RGB data)
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    // end of texture generation

    main_shader.init_texture(texture,GL_TEXTURE_2D);

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
    return 0;
}