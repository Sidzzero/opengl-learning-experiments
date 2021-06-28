//
//  Shader.cpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 30/01/21.
//  Copyright © 2021 SrikathSiddhu. All rights reserved.
//

#include "Shader.hpp"


Shader:: Shader(const char *vertexShader , const char *fragmentShader)
{
    
    //Load the File contents<For reading the file>
    std::ifstream vertexFile;
    std::ifstream fragmentFile;
    
    vertexFile.exceptions(std::ifstream::failbit   |std::ifstream::badbit);
    fragmentFile.exceptions(std::ifstream::failbit |std::ifstream::badbit);
    
    std::string vertexContent;
    std::string fragmentContent;
    //Compile
    try
    {
        vertexFile.open(vertexShader);
        fragmentFile.open(fragmentShader);
        
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream<<vertexFile.rdbuf();
        fShaderStream<<fragmentFile.rdbuf();
        
        vertexFile.close();
        fragmentFile.close();
        vertexContent = vShaderStream.str();
        fragmentContent = fShaderStream.str();
        
    }
    catch(std::ifstream::failure exp)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << exp.code().message()<<std::endl;
        return;
    }
    
    //Compiling Shader
    const char *vertexCode  = vertexContent.c_str();
    const char *fragmentCode  = fragmentContent.c_str();
    unsigned int iVertID,iFragID;
    
    int sucess =0;
    char infoLog[512];
    
    iVertID = glCreateShader(GL_VERTEX_SHADER);
    iFragID = glCreateShader(GL_FRAGMENT_SHADER);
    
    glShaderSource(iVertID,1,&vertexCode,NULL);
    glShaderSource(iFragID,1,&fragmentCode,NULL);
    
    //Compile Vertex Shader
    glCompileShader(iVertID);
    glGetShaderiv(iVertID,GL_COMPILE_STATUS,&sucess);
    if(sucess == false)
    {
        glGetShaderInfoLog(iVertID,512,NULL,infoLog);
        std::cout<<"Error:Compile Vertex Shader:"<<vertexShader<<"\n Message:"<<infoLog<<std::endl;
        return ;
    }
    
    //Compile Fragment Shader
    glCompileShader(iFragID);
    glGetShaderiv(iFragID,GL_COMPILE_STATUS,&sucess);
    if(sucess == false)
    {
        glGetShaderInfoLog(iFragID,512,NULL, infoLog);
          std::cout<<"Error:Compile Fragment Shader:"<<fragmentShader<<"\n Message:"<<infoLog<<std::endl;
        return ;
    }
 
    
    //Error
    if(sucess == true)
     {
         std::cout<<"Succesfull Compile Vertex and Fragment Shader"<<std::endl;
     }
     else
     {
         return;
     }
    
    
    //Link
    programID = glCreateProgram();
    glAttachShader(programID,iVertID);
    glAttachShader(programID,iFragID);
    glLinkProgram(programID);
    
    glGetProgramiv(programID, GL_LINK_STATUS,&sucess);
   
    //Error
    if(sucess == false)
       {
           glGetProgramInfoLog(programID,512,NULL,infoLog);
               std::cout<<"Error:Linking Failed:"<<fragmentShader<<"\n Message:"<<infoLog<<std::endl;
           
       }
      else
        {
            std::cout<<"Succesfull Linked Vertex and Fragment Shader"<<std::endl;
        }
    glDeleteShader(iVertID);
    glDeleteShader(iFragID);
    
      
}

void Shader::SetUniformVec4(const char * name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    GLuint uniformTimedColorLocation = glGetUniformLocation(programID,name);
    glUniform4f(uniformTimedColorLocation,x,y,z,w);
    
}

void Shader ::Use()
{
    glUseProgram(programID);
}
