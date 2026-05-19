#pragma once
#include<vector>

/*
we have a std::vector<float> for the shape
the vector can have any number of attribute placed one after the other
so we will keep track of the attribute with another std::vector<int> named like the first vector with attribute_sizes at the end
this vector will keep the exact offsets for each attribute (count of how many values are asigned to it)
*/

inline std::vector<int>trig_1_attribute_sizes={3};
inline std::vector<float>trig_1={
0.5f, -0.5f, 0.0f,
-0.5f, -0.5f, 0.0f,
0.0f, 0.5f, 0.0f,
};

inline std::vector<int>trig_2_attribute_sizes={3,3};
inline std::vector<float>trig_2={
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
};