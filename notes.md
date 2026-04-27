# My notes

## Hello-Window
1. glad must be included before glfw3
2. for some reason we need to init glad only after we do glfwMakeContextCurrent of windows or it will crash (idk, might have to check that)
3. all callback functions to our window must be set before the main loop
4. Whenever we call glClear and clear the color buffer, the entire color buffer will be filled with the color as configured by glClearColor.

## Hello-Triangle
1. load the shaders (fragment and vertex since opengl 3 and 4 have no default shaders)
2. make a program shader to do program shader stuff


## Shaders
1. The maximum number of vertex attributes on your gpu from your asus tuff gaming is 16.
```C++
int nrAttributes;
glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
```
2. glsl types: int, float, double, uint, bool, vec
```
Vectors (n represents the number of components, from 2 to 4):
 - vecn: the default vector of n floats.
 - bvecn: a vector of n booleans.
 - ivecn: a vector of n integers.
 - uvecn: a vector of n unsigned integers.
 - dvecn: a vector of n double components.
```
3. we can use a vec with vec_name.x vec_name.y vec_name.z vec_name.w (GLSL also allows you to use rgba for colors or stpq for texture coordinates, accessing the same components.)
4. swizzling is allowed. swizzling is something like this:
```glsl
vec2 someVec;
vec4 differentVec = someVec.xyxx;
vec3 anotherVec = differentVec.zyw;
vec4 otherVec = someVec.xxxx + anotherVec.yxzy;
```
5. there also is a constructor like function that takes in values and other vecs:
```glsl
vec2 vect = vec2(0.5, 0.7);
vec4 result = vec4(vect, 0.0, 0.0);
vec4 otherResult = vec4(result.xyz, 1.0);
``` 