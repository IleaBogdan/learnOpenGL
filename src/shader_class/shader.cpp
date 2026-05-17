#include"shader.h"

unsigned int shader::get_program(void){
    return this->program_id;
}

void shader::init(const std::string&vertex_shader_path,const std::string&fragment_shader_path){
    const std::string vertex_shader_code_loader=this->load_shader(vertex_shader_path);
    const char*vertex_shader_code=vertex_shader_code_loader.c_str();
    unsigned int vertex_shader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader,1,&vertex_shader_code, NULL);
    glCompileShader(vertex_shader);
    check::checkShaderError(vertex_shader);

    const std::string fragment_shader_code_loader=this->load_shader(fragment_shader_path);
    const char*fragment_shader_code=fragment_shader_code_loader.c_str();
    unsigned int fragment_shader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader,1,&fragment_shader_code, NULL);
    glCompileShader(fragment_shader);
    check::checkShaderError(fragment_shader);

    this->program_id=glCreateProgram();
    glAttachShader(this->program_id, vertex_shader);
    glAttachShader(this->program_id, fragment_shader);
    glLinkProgram(this->program_id);
    check::checkProgramError(this->program_id);

    glUseProgram(this->program_id);

    // we no longer need the shaders now
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);  
    // end of shader loading (thank god)
}

const std::string shader::load_shader(const std::string&shader_path){
    std::ifstream file;
    file.open(shader_path);
    if(!file){
        std::cerr<<"Failed to open file or file not found!\n";
        exit(-1);
    }
    return std::string((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>()); // oneliner to read the file
}

void shader::add_vo(const std::vector<float>&shape){
    vertex_object new_vo;
    new_vo.init(shape);
    this->vo.push_back(new_vo);
}

void shader::remove_last_vo(){
    this->vo.pop_back();
}

void shader::draw(size_t vo_index){
    glUseProgram(this->program_id);

    if(vo_index>=vo.size()){
        std::cerr<<"Invalid vertex object index!\n";
        return;
    }

    glBindVertexArray(this->vo[vo_index].VAO);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines
    
    // this only takes sets of 3 from the vector and draws traingles with each one of them and then moves to the next set of 3 from the vector
    glDrawArrays(GL_TRIANGLES,0,this->vo[vo_index].shape_size());
    // this draws everything as a single shape (note: use it for convex polygons, idk what happes in a non convex polygon)
    // glDrawArrays(GL_TRIANGLE_FAN,0,this->vo[vo_index].shape_size());
}

// template<typename...UniformPairs>
// void shader::draw(size_t vo_index,UniformPairs&&...uniform_pairs){
//     glUseProgram(this->program_id);

//     if(vo_index>=vo.size()){
//         std::cerr<<"Invalid vertex object index!\n";
//         return;
//     }

//     (set_uniforms(std::forward<UniformPairs>(uniform_pairs)), ...);

//     glBindVertexArray(this->vo[vo_index].VAO);
//     // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // just the lines
//     glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // fill inside the lines

//     // this only takes sets of 3 from the vector and draws traingles with each one of them and then moves to the next set of 3 from the vector
//     glDrawArrays(GL_TRIANGLES,0,this->vo[vo_index].shape_size());
//     // this draws everything as a single shape (note: use it for convex polygons, idk what happes in a non convex polygon)
//     glDrawArrays(GL_TRIANGLE_FAN,0,this->vo[vo_index].shape_size());
// }