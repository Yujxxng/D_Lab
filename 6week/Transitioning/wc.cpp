// Don't forget to include file-header and function-level Doxygen documentation blocks!!!
// A handout on documenting code using Doxygen is available on the course web page.

// Your definition of function wc can only rely on the following C++ Standard Library headers:

#include <iostream>
#include <iomanip>
#include <fstream>

// The use of functions declared in C Standard Library will be a violation of the Academic Integrity Policy ...
// If you are unsure about whether a function is declared in the Standard C library, use this reference: https://en.cppreference.com/w/c/header

// A text file consists of zero or more linesm, each line terminated by a line feed '\n' character.
// Watch out - don't use Windows OS programs [such as notepad.exe] to open and edit your text files.
// This is because Windows text files terminate each line by a carriage return '\r' character followed by a line feed '\n'.

// We don't want to deal with dynamic memory allocation/deallocation. Instead, we'll assume the longest length
// of a line [in any of the files that we'll process] is 2048 characters [including the null terminating character].

// This is an anonymous namespace - i.e., a namespace with no name.
// Anonymous namespaces are used by C++ programmers to make names declared at global scope private to this source file:
namespace {
  const size_t MAX_LINE_LEN {2048};
}

// In C++ [unlike in C], variable MAX_LINE_LEN is considered a constant expression [i.e. like a literal].
// Therefore, you can define a static char array with dimension MAX_LINE_LEN that can be used to store the
// characters of each line of text that you'll read in each of the source files that you'll process ...

// Helper functions must also be private to this source file and must therefore be declared/defined in
// an anonymous namespace ...
namespace {
  // Declare/define your helper functions here ...
  
  int isSpace(char c)
  {
	  if(c == ' ' || c == '\t' || c == '\n' || c == '\0' || c == '\r')
		  return 1;
	  
	  return 0;
  }
  
}

// Now, define function wc in namespace hlp2 ...
namespace hlp2 {
  // define function wc here ...
  void wc(int argc, char *argv[])
  {
	  int i = 1;
	  int tl = 0, tw = 0, tb = 0;
	  while(i < argc)
	  {  
		  //init variable
		  int totalLine = 0;
		  int word = 0;
		  int byte = 0;
		  
		  //file open & read
		  char const *fp = argv[i];
		  std::ifstream ifs{fp};
		
		  char pre, c;
		  while(!ifs.eof())
		  {
			c = ifs.get();
			if(ifs.eof()) break;
			
			if(c == '\n')
				totalLine++;
			
			if(isSpace(c) && !isSpace(pre))
				word++;
			
			
			byte++;
			
			pre = c;
		  }
		  if(!isSpace(pre))
			  word++;
		  
		  std::cout << std::right << std::setw(7) << totalLine << std::right << std::setw(8) << 
				word << std::right << std::setw(8) <<
				std::right << std::setw(8) << byte << " " << argv[i] << std::endl;
		 
		  ifs.close();
		  
		  tl += totalLine;
		  tw += word;
		  tb += byte;
		  
		  i++;
	  }
	  
	  std::cout << std::right << std::setw(7) << tl << std::right << std::setw(8) << 
				tw << std::right << std::setw(8) <<
				std::right << std::setw(8) << tb << " " << "total" << std::endl;
  }
} // end namespace hlp2
