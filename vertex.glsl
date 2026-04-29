#version 460 core // version declaration
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

// out vec4 vertexColor; // output for fragment.glsl
out vec3 ourColor;

void main()
{
    gl_Position = vec4(aPos, 1.0);
    // vertexColor=vec4(0.0,0.5,0.0,0.1);
    ourColor=aColor;
}