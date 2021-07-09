//
//  Shader.hpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 30/01/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
private:
    GLuint programID;
    
    
public:
    Shader(const char *vertexShader , const char *fragmentShader);
    void Use();
    
    //UTITILITY
    void SetUniformVec4(const char * name, GLfloat x ,GLfloat y, GLfloat z, GLfloat w);
   
    
};


#endif /* Shader_hpp */
