#pragma once
// C/C++ libs:
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

// opengl libs:
#include<glad/glad.h> // this is for opengl 3 and 4
#include<GLFW/glfw3.h>
// #include<GL/glut.h> // this is for opengl 1 and 2

// local headers:
#include"callbacks.h"
#include"shaders.h"
#include"myErrors.h"
#include"init.h"
#include"window.h"


inline GLenum GLerr; // variable for openGL errors
// usage: while ((GLerr = glGetError()) != GL_NO_ERROR) { std::cerr << "OpenGL error: " << GLerr << std::endl; }

// program global variables:
inline GLFWwindow*main_window;