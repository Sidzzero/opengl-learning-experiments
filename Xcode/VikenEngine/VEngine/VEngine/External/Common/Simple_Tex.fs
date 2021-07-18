//FRAGMENT SHADER

#version 330 core
in vec2 texCord;
out vec4 FragColor;

uniform sampler2D tex0;
void main()
{

//FragColor = vec4(texCord.x ,texCord.y ,0,1.0);
 FragColor = texture(tex0, texCord);

}
