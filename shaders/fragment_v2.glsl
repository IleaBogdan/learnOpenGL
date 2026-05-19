#version 460 core // version declaration
out vec4 FragColor;

in vec4 vertexColor; // input from the vertex.glsl

void main()
{
    FragColor=vertexColor;
} 