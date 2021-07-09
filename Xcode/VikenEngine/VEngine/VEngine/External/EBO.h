//
//  EBO.hpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 09/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#ifndef EBO_hpp
#define EBO_hpp
#include <glad/glad.h>
class EBO
{
public:
    GLuint ID;
    EBO(GLfloat *indices , GLsizeiptr size);
    
    void Bind();
    void Unbind();
    void Delete();
    
};

#endif /* EBO_hpp */
