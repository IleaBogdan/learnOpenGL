#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform float uColor;

void main(){
    gl_Position=vec4(aPos,1.0);
    ourColor=aColor;
    ourColor.y=uColor;
    // ourColor=vec3(uColor,uColor,uColor);
    TexCoord=aTexCoord;
}