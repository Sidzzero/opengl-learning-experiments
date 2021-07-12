//
//  VAO.hpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 09/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#ifndef VAO_hpp
#define VAO_hpp

#include "VBO.h"

class VAO
{
public:
    VAO();
    GLuint ID;
    
    void LinkAttrib(VBO &vboID , GLuint layout, GLuint compNum , GLenum type , GLsizei stride,void *offset);
    void Bind();
    void Unbind();
    void Delete();
    
};
#endif /* VAO_hpp */
