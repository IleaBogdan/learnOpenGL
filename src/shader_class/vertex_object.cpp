#include"shader.h"

void vertex_object::init(std::vector<float>_verts){
    inited=true;
    std::copy(_verts.begin(),_verts.end(),back_inserter(this->verts));
    
    // float*vertices=verts.data();
    float vertices[verts.size()];
    std::copy(verts.begin(),verts.end(),vertices);
    
    glGenBuffers(1,&this->VBO);
    glGenVertexArrays(1,&this->VAO);

    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER,this->VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    // this assignee a region of memory of specific size and tipe on the gpu where I can render stuff with the VAO
    // first arg is set to 0 because we have in vertex.glsl layout=0
    // the last arg is a void* and must be a void* of the offset from where the data starts
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

size_t vertex_object::shape_size(void){
    return this->verts.size()/3; // a triangle has three sides
}