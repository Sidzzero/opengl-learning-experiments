//
//  Texture.cpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 12/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#include "Texture.h"

Texture::Texture(const char *file , GLuint slot,GLenum texType,GLenum format ,GLenum byteType )
{
   //File Loading Done HERE !
    int iWidth , iHeight,nChannels;
    stbi_set_flip_vertically_on_load(true);
    this->type = texType;
    unsigned char *imageData = stbi_load(file,&iWidth,&iHeight,&nChannels,0);
    
    //ACtivating the slot to be accessed !
    glGenTextures(1,&Id);
    glActiveTexture(slot);
    glBindTexture(texType,Id);
    
    glTexParameteri(texType,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(texType , GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(texType , GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    
    glTexImage2D(texType,0,format,iWidth,iHeight,0,format,byteType,imageData);//THIS HAS TO BE BYTE!!!!
    glGenerateMipmap(texType);
    stbi_image_free(imageData);
    
    glBindTexture(texType, 0);
}

void Texture:: texunit(Shader &shader,const char* uniformName,GLuint unit)
{
 //Uniform tells opengl which texture to use !
    GLuint uniLoc = glGetUniformLocation(shader.programID , uniformName);
    shader.Use();
    glUniform1i(uniLoc , 0);
}
void Texture::Bind()
{
    glBindTexture(type,Id);
}
void Texture::Unbind()
{
    glBindTexture(type,0);
}

void Texture::Delete()
{
    
}
