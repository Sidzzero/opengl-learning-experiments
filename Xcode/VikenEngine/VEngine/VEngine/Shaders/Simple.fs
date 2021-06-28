//FRAGMENT SHADER

#version 330 core
in vec4 outCol;
out vec4 FRagColor;
uniform vec4 TimedColor;
void main()
{
 FragColor = TimedColor;
}