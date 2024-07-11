
#include <cstring>
#include <iostream>
#include <fstream>


namespace hlp2 {
  // provide definition of q here ...
  void extract(char const *filename, char const **keywords)
  {
	  std::ifstream ifs{filename};
	  if(!ifs)
	  {
		  std::cerr << "File "<< filename << " not found." << std::endl;
		  return;
	  }
	  
	  std::string secret;
	  
	  bool flag = false;
	  while(ifs.good())
	  {
		  //read line
		  std::string str;
		  std::string tmp;
		  ifs >> str;
		  
		  if(flag)
		  {
			  secret += str + " ";
			  
			  for(int i = 0; *(keywords + i) != nullptr; i++)
			  {
				  if(str.compare(*(keywords + i)) == 0)
				  {
					  ifs >> str;
				  }
			  }
			  
			  flag = false;
		  }
		  
		  for(int i = 0; *(keywords + i) != nullptr; i++)
		  {
			  if(str.compare(*(keywords + i)) == 0)
			  {
				tmp = *(keywords + i);
				
				if(!flag)
					flag = true;
			  }
		  }
		  //std::cout << str << std::endl;  
	  }
	  
	  std::cout << secret << std::endl;
	  ifs.close();
  }
}
