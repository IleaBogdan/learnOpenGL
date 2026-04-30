#!/bin/sh

g++ -o ./bin/exe -std=c++26 src/glad.c *.cpp -I./include -lGL -lGLU -lglut -lglfw -ldl -lX11 -lpthread -lXrandr -lXi
