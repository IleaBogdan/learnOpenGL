#version 430
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec4 vertexColor;
uniform vec2 offsets;
uniform float alpha;

void main(){
    // rotation:
    float rx=aPos.x*cos(alpha)-aPos.y*sin(alpha);
    float ry=aPos.x*sin(alpha)+aPos.y*cos(alpha);
    gl_Position=vec4(rx+offsets.x,-ry+offsets.y,aPos.z,1.0);
    // vertexColor=vec4(0.0,0.5,0.0,0.1);
    vertexColor=vec4(aColor,1.0);
}