#include "Header/shader.h"

std::string get_file_contents(const char* a_cfileName)
{

    std::ifstream in(a_cfileName, std::ios::binary);
	if (in)
	{
		std::string contents;
		//Going to end of file
        in.seekg(0, std::ios::end);
        //Resize the string to size of file but getting last positions
		contents.resize(in.tellg());

        //Setting to starting of file
		in.seekg(0, std::ios::beg);
        //Reading contents of IN into the content string
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* a_vertexShader, const char* a_fragmentShader)
{
      std::string strVertexFile , strFragFile;   
      try
      {
        strVertexFile = get_file_contents(a_vertexShader);
        strFragFile = get_file_contents(a_fragmentShader);
      }
      catch(const std::exception& e)
      {
          std::cerr << e.what() << '\n';
          return;
      }
      
      const char *vertexSource = strVertexFile.c_str();
      const char *FragmentSource = strFragFile.c_str();

}
