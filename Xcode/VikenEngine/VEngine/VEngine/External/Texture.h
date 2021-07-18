//
//  Texture.hpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 12/07/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <glad/glad.h>

#include "std_image.h"

#include "Shader.hpp"
class Texture
{
public:
    GLuint Id;
    Texture(const char *file , GLuint slot,GLenum texType, GLenum format ,GLenum byteType );
    
    void texunit(Shader shader,const char* uniformName,GLuint unit);
    void Bind();
    void Unbind();
    void Delete();
    
private:
    GLenum type;
};

#endif /* Texture_hpp */
