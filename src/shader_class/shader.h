#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<type_traits>
#include<numeric>

#include<glad/glad.h>
#include<GLFW/glfw3.h>

class vertex_object{
private:
    bool inited=false;
    std::vector<int>attribute_sizes;
    std::vector<float>verts;
public:
    unsigned int VAO,VBO;
    vertex_object()=default;
    void init(const std::vector<float>&_verts,const std::vector<int>&_attribute_sizes);
    int get_stride(void)const;
    int get_offset(int attribute_index)const;
    size_t shape_size(void)const;
};

class shader{
private:
    unsigned int program_id,texture;
    size_t texture_type;
    const std::string load_shader(const std::string&shader_path);
    std::vector<vertex_object>vo;
public:
    shader()=default;
    unsigned int get_program(void);
    void init(const std::string&vertex_shader_path,const std::string&fragment_shader_path);\

    void init_texture(const unsigned int&_texture,const size_t&_type);

    // vo stuff
    void add_vo(const std::vector<float>&shape,const std::vector<int>&attribute_sizes);
    void remove_last_vo();
    
    // draw
    void draw(size_t vo_index);
    template<typename...UniformPairs>
    void draw(size_t vo_index,UniformPairs&&...uniform_pairs){
        glUseProgram(this->program_id);

        if(vo_index>=vo.size()){
            std::cerr<<"Invalid vertex object index!\n";
            return;
        }

        set_uniforms(std::forward<UniformPairs>(uniform_pairs)...);

        glBindVertexArray(this->vo[vo_index].VAO);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        // this only takes sets of 3 from the vector and draws traingles with each one of them and then moves to the next set of 3 from the vector
        // glDrawArrays(GL_TRIANGLES,0,this->vo[vo_index].shape_size());
        // this draws everything as a single shape (note: use it for convex polygons, idk what happes in a non convex polygon)
        glDrawArrays(GL_TRIANGLE_FAN,0,this->vo[vo_index].shape_size());
    }
    void draw_with_texture(size_t vo_index);
    template<typename...UniformPairs>
    void draw_with_texture(size_t vo_index,UniformPairs&&...uniform_pairs){
        glUseProgram(this->program_id);

        if(vo_index>=vo.size()){
            std::cerr<<"Invalid vertex object index!\n";
            return;
        }

        set_uniforms(std::forward<UniformPairs>(uniform_pairs)...);

        glBindTexture(this->texture_type,this->texture);
        glBindVertexArray(this->vo[vo_index].VAO);
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        // this only takes sets of 3 from the vector and draws traingles with each one of them and then moves to the next set of 3 from the vector
        // glDrawArrays(GL_TRIANGLES,0,this->vo[vo_index].shape_size());
        // this draws everything as a single shape (note: use it for convex polygons, idk what happes in a non convex polygon)
        glDrawArrays(GL_TRIANGLE_FAN,0,this->vo[vo_index].shape_size());
    }

    // templates
    void set_uniforms(void){}    
    template<typename T,typename...Args>
    void set_uniforms(const std::string&name,const std::vector<T>&value,Args&&...args){
        switch(value.size()){
        case 1ull:this->set_uniform1(name,value);break;
        case 2ull:this->set_uniform2(name,value);break;
        case 3ull:this->set_uniform3(name,value);break;
        case 4ull:this->set_uniform4(name,value);break;
        default:
            throw std::runtime_error("Vector size must be 1,2,3 or 4");
        }
        this->set_uniforms(std::forward<Args>(args)...);
    }
    
    template<typename T>void set_uniform1(const std::string&name,const std::vector<T>&value){
        int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
        if constexpr(std::is_same_v<T,float>){
            glUniform1f(uniform_index,value[0]);
        }else{
            throw("Unimplemented or unsuported type!");
        }
    }
    template<typename T>void set_uniform2(const std::string&name,const std::vector<T>&value){
        int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
        if constexpr(std::is_same_v<T,float>){
            glUniform2f(uniform_index,value[0],value[1]);
        }else{
            throw("Unimplemented or unsuported type!");
        }
    }
    template<typename T>void set_uniform3(const std::string&name,const std::vector<T>&value){
        int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
        if constexpr(std::is_same_v<T,float>){
            glUniform3f(uniform_index,value[0],value[1],value[2]);
        }else{
            throw("Unimplemented or unsuported type!");
        }
    }
    template<typename T>void set_uniform4(const std::string&name,const std::vector<T>&value){
        int uniform_index=glGetUniformLocation(this->program_id,name.c_str());
        if constexpr(std::is_same_v<T,float>){
            glUniform4f(uniform_index,value[0],value[1],value[2],value[3]);
        }else{
            throw("Unimplemented or unsuported type!");
        }
    }
};

namespace check{
    void checkShaderError(const unsigned int&shader);
    void checkProgramError(const unsigned int&program);
}