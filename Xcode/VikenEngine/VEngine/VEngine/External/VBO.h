//
//  VBO.h
//  VEngine
//
//  Created by Srikanth_Siddhu on 09/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#ifndef VBO_h
#define VBO_h
#include <glad/glad.h>
class VBO
{
public:
    VBO(GLfloat *vertices , GLsizeiptr size);
    GLuint id;
    
    void Bind();
    void Unbind();
    void Delete();
};

#endif /* VBO_h */
