//
//  VAO.cpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 09/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#include "VAO.h"

VAO::VAO()
{
    glGenVertexArrays(1,&ID);
}

void VAO::LinkAttrib(VBO vboID , GLuint layout, GLuint compNum , GLenum type , GLsizei stride,void *offset)
{
    vboID.Bind();
    // X Y Z U V
    // components are x,yz or u,v
    //stride is lenght between a layout(same) first to start of next layout(same)
    //offset starting distance space
    glVertexAttribPointer(layout,compNum, type, GL_FALSE, stride, offset);//CHECK here the video says 0 and we have 6
  //  glVertexAttribPointer(layout,3, GL_FLOAT, GL_FALSE, 0, (GLvoid*) 0);//CHECK here the video says 0 and we have 6
    glEnableVertexAttribArray(layout);
    vboID.Unbind();
}

void VAO::Bind()
{
    glBindVertexArray(ID);
}
void VAO::Unbind()
{
    glBindVertexArray(0);
}
void VAO::Delete()
{
    glDeleteVertexArrays(1,&ID);
}
