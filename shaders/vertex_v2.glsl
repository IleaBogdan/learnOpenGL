#version 430
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 vertexColor;
uniform float horizontal_offset;
uniform float vertical_offset;

void main(){
    gl_Position=vec4(aPos.x+horizontal_offset,-aPos.y+vertical_offset,aPos.z,1.0);
    // vertexColor=vec4(0.0,0.5,0.0,0.1);
    vertexColor=vec4(aColor,1.0);
}