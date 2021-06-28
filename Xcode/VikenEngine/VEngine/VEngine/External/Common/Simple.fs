//FRAGMENT SHADER

#version 330 core
in vec3 outCol;
out vec4 FragColor;

uniform vec4 TimedColor;

void main()
{

FragColor = vec4(TimedColor.x , TimedColor.y ,TimedColor.z,TimedColor.w);

}