#include"shader.h"


void shader::set_uniforms(void){/*Base case - do nothing*/}

/// @brief 
/// @param name == string (name of the uniform)
/// @param value == vector (of size 1, 2, 3 or 4) 
/// @param ...args == again and again 
template<typename T,typename...Args>
void shader::set_uniforms(const std::string&name,const std::vector<T>&value,Args&&...args) {
    switch(value.size()){
    case 1ull:this->set_uniform1(name,value);break;
    case 2ull:this->set_uniform2(name,value);break;
    case 3ull:this->set_uniform3(name,value);break;
    case 4ull:this->set_uniform4(name,value);break;
    default:
        throw("What? How did you give me a vector that is not of size 1,2,3 or 4?");
        break;
    }
    this->set_uniforms(std::forward<Args>(args)...);
}

template<typename T>void shader::set_uniform1(const std::string&name,const std::vector<T>&value){
    int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
    switch(typeid(T)){
    case typeid(float):
        glUniform1f(uniform_index,value[0]);
        break;
    default:
        throw("Unimplemented or unsuported type!");
        break;
    }
}
template<typename T>void shader::set_uniform2(const std::string&name,const std::vector<T>&value){
    int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
    switch(typeid(T)){
    case typeid(float):
        glUniform4f(uniform_index,value[0],value[1]);
        break;
    default:
        throw("Unimplemented or unsuported type!");
        break;
    }
}
template<typename T>void shader::set_uniform3(const std::string&name,const std::vector<T>&value){
    int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
    switch(typeid(T)){
    case typeid(float):
        glUniform4f(uniform_index,value[0],value[1],value[2]);
        break;
    default:
        throw("Unimplemented or unsuported type!");
        break;
    }
}
template<typename T>void shader::set_uniform4(const std::string&name,const std::vector<T>&value){
    int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
    switch(typeid(T)){
    case typeid(float):
        glUniform4f(uniform_index,value[0],value[1],value[2],value[3]);
        break;
    default:
        throw("Unimplemented or unsuported type!");
        break;
    }
}