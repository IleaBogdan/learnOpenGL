#include"shader.h"

shader::shader(const std::string&vertexShaderPath,const std::string&fragmentShaderPath){
    this->load_shaders(vertexShaderPath,fragmentShaderPath);
}
unsigned int shader::get_program(void){
    return this->program;
}
std::string load_shader(const std::string&shaderPath){
    std::ifstream file(shaderPath);
    if(!file){
        std::cerr<<"ERROR: Can't find: "<<shaderPath<<"\n";
        exit(-1);
    }
    return std::string((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
}

void shader::load_shaders(const std::string&vertexShaderPath,const std::string&fragmentShaderPath){
    // shader loading
    std::string vertexShaderSourceLoad=load_shader(vertexShaderPath);
    const char*vertexShaderSource=vertexShaderSourceLoad.c_str();
    unsigned int vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    check_shader_error(vertexShader);

    std::string fragmentShaderSourceLoad=load_shader(fragmentShaderPath);
    const char*fragmentShaderSource=fragmentShaderSourceLoad.c_str();
    unsigned int fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    check_shader_error(fragmentShader);


    this->program=glCreateProgram();
    glAttachShader(this->program, vertexShader);
    glAttachShader(this->program, fragmentShader);
    glLinkProgram(this->program);
    check_program_error(this->program);

    glUseProgram(this->program);

    // we no longer need the shaders now
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
    // end of shader loading (thank god)
}
void shader::activate(void){
    glUseProgram(this->program);
}


void shader::check_program_error(const unsigned int&program){
    // program error check
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cerr<<"ERROR::PROGRAM::FAILED\n"<<infoLog<<std::endl;
        exit(-1);
    }
}

void shader::check_shader_error(const unsigned int&shader){
    // shader error checking
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr<<"ERROR::SHADER::COMPILATION_FAILED\n"<<infoLog<<std::endl;
        exit(-1);
    }
}