//
//  main.cpp
//  VEngine
//
//  Created by Srikanth_Siddhu on 23/12/20.
//  Copyright © 2020 SrikathSiddhu. All rights reserved.
//

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "std_image.h"

#include "Shader.hpp"
//Math declaration
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VBO.h"
#include "EBO.h"
#include "VAO.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window );
void initIMGUI(GLFWwindow* window);
//Range between -1 to 1
/*
float vertices [] =
{
   -0.5f,-0.5f,0.0f,
    0.5f,-0.5f,0.0f,
    0.0f,0.5f,0.0f,
   // 1.0f,1.0f,0.0f,
};*/

float vertices [] =
{
   -0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f,
    0.5f,-0.5f,0.0f,1.0f,0.0f,0.0f,
    0.0f,0.5f,0.0f,1.0f,0.0f,0.0f,
   // 1.0f,1.0f,0.0f,
};

/*
float rectVertices[] = {
    // first triangle
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
};*/

GLfloat rectVertices[] = {
    // first triangle
    // X , Y ,Z          //R , G , B
     0.5f,  0.5f, 0.0f,  1.0f ,0.0f, 0.0f,  // top right
    // X , Y ,Z          //R , G , B
    0.5f, -0.5f, 0.0f,  0.0f ,0.0f, 1.0f,  // bottom left
    // X , Y ,Z          //R , G , B
    -0.5f, -0.5f, 0.0f,  0.0f ,0.0f, 1.0f,  // bottom right
     // X , Y ,Z          //R , G , B
    -0.5f,  0.5f, 0.0f,  1.0f ,0.0f, 0.0f,   // top left
};

GLfloat rectVerticesWithTexture[] = {
    // first triangle
    // X , Y ,Z           //u   //v
     0.5f,  0.5f, 0.0f,  1.0f ,1.0f, // top right
    // X , Y ,Z
    0.5f, -0.5f, 0.0f,   1.0f  , 0.0f,// bottom right
    // X , Y ,Z
    -0.5f, -0.5f, 0.0f,  0.0f,0.0f, // bottom right
     // X , Y ,Z
    -0.5f,  0.5f, 0.0f,  0.0f , 1.0f  // top left
};


//HOW Should the indexs be?
unsigned int rectIndices[]=
{
    0,1,2,
    2,3,0
};




int main(int argc, const char * argv[])
{
       GLFWwindow* window;

       // Initialize the library
       if(!glfwInit())
           return -1;
    
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // Create a windowed mode window and its OpenGL context
      window = glfwCreateWindow(800, 600, "VikEngine", NULL, NULL);
      if (!window)
      {
          std::cout << "Failed to create GLFW window" << std::endl;
          glfwTerminate();
          return -1;
      }
    
    std::cout << "Welcome to VikEngine!\n";
    // Mathe the window's context current
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize the OpenGL API with GLAD
   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) )
        
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    //IMGUI DECLARATIONS
    initIMGUI(window);

  
    

    
  // REFEREMCE :https://stackoverflow.com/questions/48787190/how-to-color-triangles-with-indexed-vertices
   
    
    // Texture Setup
 //   glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(GL_FLOAT),(GLvoid*)(3*sizeof(GL_FLOAT)));
//    glEnableVertexAttribArray(1);
    
//    glGenBuffers(1,&eboTexRectangle);
 //   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboTexRectangle);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER , sizeof(rectIndices),rectIndices,GL_STATIC_DRAW);
    
   
    
    unsigned int texContainer;
    glGenTextures(1,&texContainer);
    glBindTexture(GL_TEXTURE_2D,texContainer);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    
    int iWidth , iHeight,nChannels;
   stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load("/Users/Srikanth_Siddhu/UnityProjects/Self/VikEngine/Xcode/VikenEngine/VEngine/VEngine/External/container.jpg",&iWidth,&iHeight,&nChannels,0);
    
    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,iWidth,iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,data);//THIS HAS TO BE BYTE!!!!
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout<<"Image not loaded!"<<stbi_failure_reason()<<std::endl;
        return -1;
    }
    stbi_image_free(data);
        //Shader Program
 //REFACTORED place
    Shader simpleUniformShader("//Users//Srikanth_Siddhu//UnityProjects//Self/VikEngine//Xcode//VikenEngine//VEngine//VEngine//External//Common//Simple.vs","//Users//Srikanth_Siddhu//UnityProjects//Self/VikEngine//Xcode//VikenEngine//VEngine//VEngine//External//Common//Simple.fs");
    ///
        Shader simpleTextureShader("//Users//Srikanth_Siddhu//UnityProjects//Opengl_ngu//SourceControlled//Xcode//VikenEngine//VEngine//VEngine//External//Common//Simple_Tex.vs","//Users//Srikanth_Siddhu//UnityProjects//Opengl_ngu//SourceControlled//Xcode//VikenEngine//VEngine//VEngine//External//Common//Simple_Tex.fs");
    
    Shader simpleShader("//Users//Srikanth_Siddhu//UnityProjects//Opengl_ngu//SourceControlled//Xcode//VikenEngine//VEngine//VEngine//External//Common//Simple.vs","//Users//Srikanth_Siddhu//UnityProjects//Opengl_ngu//SourceControlled//Xcode//VikenEngine//VEngine//VEngine//External//Common//Simple.fs");
    
    VAO vao;
    vao.Bind();
    VBO vbo(rectVertices,sizeof(rectVertices));
    EBO ebo(rectIndices,sizeof(rectIndices));
    
  
    vao.LinkAttrib(vbo,0, 3, GL_FLOAT, 6*sizeof(GLfloat),(void*) 0);
    vao.LinkAttrib(vbo,1, 3, GL_FLOAT, 6*sizeof(GLfloat),(void*) (sizeof(GLfloat)*3));
    ebo.Bind();
    vao.Unbind();
    
    VAO vaoText;
    vaoText.Bind();
    VBO vboTex(rectVerticesWithTexture,sizeof((rectVerticesWithTexture)));
    EBO eboText(rectIndices,sizeof(rectIndices));
    
    vao.LinkAttrib(vboTex, 0, 3, GL_FLOAT, 5*sizeof((GL_FLOAT)), 0);
    vao.LinkAttrib(vboTex, 1, 2, GL_FLOAT, 5*sizeof((GL_FLOAT)), (void*)(sizeof(GLfloat)*3));
    vaoText.Unbind();
    
    
    //IMGUI

      ImVec4 ObjectColor = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    vec = trans * vec;
    std::cout <<"Values:"<< vec.x << vec.y << vec.z << ":END"<<std::endl;
    
    // Loop until the user closes the window
       while(!glfwWindowShouldClose(window))
       {
           
           processInput(window);
           glClearColor(0.1f,0.4f,0.4f,1.0f);
           // glClearColor(clear_color.x,clear_color.y,clear_color.z,clear_color.w);
           // Render here!
           glClear(GL_COLOR_BUFFER_BIT);
           
           
           //IMGUI
                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();
           
          auto time = glfwGetTime();
           
     
         
          glActiveTexture(GL_TEXTURE0);
          glBindTexture(GL_TEXTURE_2D, texContainer);
          simpleTextureShader.Use();
        
           vaoText.Bind();
           glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
           
           //glBindTexture(GL_TEXTURE_2D,0);
           
         /*
           simpleShader.Use();
           vao.Bind();
           glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
           //glDrawArrays(GL_TRIANGLES,0,6);
           vao.Unbind();
           
           */
           
           //IMGUI
           // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
                  {
                      static float f = 0.0f;
                      static int counter = 0;

                      ImGui::Begin("VikiEngine:ToolBox");                          // Create a window called "Hello, world!" and append into it.

                     // ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
                    //  ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
                    //  ImGui::Checkbox("Another Window", &show_another_window);

                     // ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                      ImGui::ColorEdit3("Object Color", (float*)&ObjectColor); // Edit 3 floats representing a color

                      if (ImGui::Button("Close Window"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                      {
                          std::cout<<" Closing Window";
                          break;
                          counter++;
                      }
                      ImGui::SameLine();
                     // ImGui::Text("counter = %d", counter);

                      ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                      ImGui::End();
                  }
           
           
           
           
           ImGui::Render();
           ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
           
           glfwSwapBuffers(window);
           glfwPollEvents();
        
       }
       ImGui_ImplGlfw_Shutdown();
       ImGui::DestroyContext();
    
       glfwTerminate();
       return 0;
    
    return 0;
}
void processInput(GLFWwindow* window )
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width
    // and height will be significantly larger than specified on retina displays
    glViewport(0, 0, width, height);
}
void initIMGUI(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
      ImGui::CreateContext();
      ImGuiIO& io = ImGui::GetIO(); (void)io;
  

       // Setup Platform/Renderer backends
     
     ImGui::StyleColorsDark();
      ImGui_ImplGlfw_InitForOpenGL(window, true);
     ImGui_ImplOpenGL3_Init();
}
