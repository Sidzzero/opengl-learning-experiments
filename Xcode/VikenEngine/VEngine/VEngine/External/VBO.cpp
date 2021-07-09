//
//  VBO.cpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 09/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#include "VBO.h"
VBO::VBO(GLfloat *vertices , GLsizeiptr size)
{
    glGenBuffers(1,&id);
    glBindBuffer(GL_ARRAY_BUFFER,id);
    glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_STATIC_DRAW);
}
void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER,id);
}

void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER , 0);
}
void VBO::Delete()
{
    glDeleteBuffers(1,&id);
}
