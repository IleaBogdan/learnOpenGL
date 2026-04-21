#pragma once
// C/C++ libs:
#include<iostream>

// opengl libs:
#include<glad/glad.h> // this is for opengl 3 and 4
#include<GLFW/glfw3.h>
// #include<GL/glut.h> // this is for opengl 1 and 2

inline GLenum err; // variable for errors
// usage: while ((err = glGetError()) != GL_NO_ERROR) { std::cerr << "OpenGL error: " << err << std::endl; }