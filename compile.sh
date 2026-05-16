#!/bin/sh

echo "this script is old and maybe it wont run"

rm -r bin

if [ -e "bin" ]; then
    :
else
    mkdir bin
fi

cp -r ./assets ./bin
cp -r ./shaders ./bin

g++ -o ./bin/exe -std=c++26 src/glad.c src/*.cpp -I./include -lGL -lGLU -lglut -lglfw -ldl -lX11 -lpthread -lXrandr -lXi

echo "Compilation done!"