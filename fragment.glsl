#version 460 core // version declaration
out vec4 FragColor;

// in vec4 vertexColor; // input from the vertex.glsl
// uniform vec4 ourColor; // input from the C++ code to the shader. 
in vec3 ourColor;

void main()
{
    // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    // FragColor = vertexColor;
    FragColor=vec4(ourColor,1.0);
} 