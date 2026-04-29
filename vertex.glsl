#version 460 core // version declaration
layout (location = 0) in vec3 aPos;

out vec4 vertexColor; // output for fragment.glsl

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    vertexColor=vec4(0.0,0.5,0.0,0.1);
}