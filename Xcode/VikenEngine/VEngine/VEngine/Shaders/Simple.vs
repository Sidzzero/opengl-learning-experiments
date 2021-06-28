//VERTEX SHADER

#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aCol;
out vec4 outCol;
void main()
{
outCol = vec4(aCol.x , aCol.y ,aCol.z,0.0);
gl_Position  = vec4(aPos.x , aPos.y, aPos.z,1.0);
}