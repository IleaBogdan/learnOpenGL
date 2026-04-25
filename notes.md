# My notes

## Hello-Window
1. glad must be included before glfw3
2. for some reason we need to init glad only after we do glfwMakeContextCurrent of windows or it will crash (idk, might have to check that)
3. all callback functions to our window must be set before the main loop
4. Whenever we call glClear and clear the color buffer, the entire color buffer will be filled with the color as configured by glClearColor.

## Hello-Triangle
1. load the shaders (fragment and vertex since opengl 3 and 4 have no default shaders)
2. make a program shader to do program shader stuff