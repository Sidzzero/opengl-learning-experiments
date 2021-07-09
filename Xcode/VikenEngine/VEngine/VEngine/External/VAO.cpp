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

void VAO::LinkVBO(VBO vboID, GLuint layout)
{
    vboID.Bind();
    
    glVertexAttribPointer(layout,3, GL_FLOAT, GL_FALSE, 6*sizeof(GLfloat), (GLvoid*) 0);//CHECK here the video says 0 and we have 6
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
