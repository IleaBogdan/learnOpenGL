#version 460 core // version declaration
out vec4 FragColor;

in vec4 vertexColor; // input from the vertex.glsl

void main()
{
    FragColor = vec4(1.0f, 0.0f, 0.2f, 1.0f);
    // FragColor = vertexColor;
} 