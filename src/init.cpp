#include"main.h"

void init(GLFWwindow*&window,const std::string&window_name){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    
    window=glfwCreateWindow(800,600,window_name.c_str(),nullptr,nullptr);
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

unsigned int load_image_to_2d_texture(const std::string&image_path){
    // load image data and generate texture
    unsigned int texture;
    glGenTextures(1,&texture);  
    glBindTexture(GL_TEXTURE_2D,texture);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    int width,height,nrChannels;
    unsigned char*data=stbi_load(image_path.c_str(),&width,&height,&nrChannels,0); 
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

    return texture;
}