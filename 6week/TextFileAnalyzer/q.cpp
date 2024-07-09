// You must only include the following header files ...
#include <iostream>
#include <iomanip>
#include <fstream>

// an anonymous namespace ...
namespace
{
	// Declare/define your helper functions here ...
	
	bool isCharacter(char c)
	{
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
			return true;
		
		return false;
	}
	bool isWhiteSpace(char c)
	{
		if(c == ' ' || c == '\t' || c == '\n' || c == '\0' || c == '\r')
		  return true;
	  
		return false;
	}
	bool isDigits(char c)
	{
		if(c >= '0' && c <= '9')
			return true;
		
		return false;
	}
	bool isOthers(char c) //else if
	{
		if(isCharacter(c)) return false;
		if(isWhiteSpace(c)) return false;
		if(isDigits(c)) return false;
		
		return true;
	}
	
	float getPercentage(int total, int category)
	{
		float res = 0.0;
		res = (float)((float)category / (float)total) * 100.0;
		
		return res;
	}
	
	bool isUpper(char c)
	{
		if(c >= 'A' && c <= 'Z')
			return true;
		
		return false;
	}
	
	bool isLower(char c)
	{
		if(c >= 'a' && c <= 'z')
			return true;
		
		return false;
	}
	
	int a[26];
	void isAlpabet(char c)
	{
		int idx;
		
		if(isUpper(c))
			idx = (int)(c - 'A');
		else if(isLower(c))
			idx = (int)(c - 'a');
		
		a[idx]++;
	}
	
	void wout(std::ofstream& os, const char* categories, int i_val, float f_val)
	{
		os << std::setw(16) << std::left << categories << std::setw(20) << std::right << i_val
			<< std::setw(20) << std::right << std::setprecision(2) << std::fixed << f_val << " %\n";
	}
	
}

namespace hlp2 {
  void q(char const *input_filename, char const *analysis_file)
  {
	  //input file open
	  std::ifstream ifs(input_filename);
	  if(!ifs) //if(!ifs.is_open())
		  std::cout << "File " << input_filename << " not found." << std::endl;
	  
	  //create output file
	  std::ofstream ofs(analysis_file);
	  if(!ofs) //if(!ofs.is_open())
		  std::cout << "Unable to create output file" << analysis_file << "." << std::endl;
	  
	  //variable we need
	  int totalOfChar = 0;
	  int letter = 0, space = 0, digits = 0, others = 0;
	  int upper = 0, lower = 0;
	  
	  int numberInt = 0, sumInt = 0;
	  float avgInt = 0.0;
	  int d = 0;
	  char pre, c;
	  while(ifs.good())
	  {
		  c = ifs.get();
		  if(ifs.eof()) break;
		  
		  if(isCharacter(c))
		  {
			  letter++;
			  if(isUpper(c)) upper++;
			  else if(isLower(c)) lower++;
			  
			  isAlpabet(c);
		  }
		  if(isWhiteSpace(c)) space++;
		  if(isDigits(c))
		  {
				d = (d * 10) + (c - '0');
				digits++;
		  }
		  else
		  {
			  if(isDigits(pre) && !isDigits(c))
			  {
				  //std::cout << d << std::endl;
				  numberInt++;
				  sumInt += d;
				  d = 0;
			  }
		  }
		  
		  if(isOthers(c)) others++;

		  totalOfChar++;
		  
		  pre = c;
	  }
	  if(numberInt)
		avgInt = (float)((float)sumInt / (float)numberInt);
	  
	  ofs << "Statistics for file: " << input_filename << '\n';
	  ofs << "---------------------------------------------------------------------\n\n";
	  ofs << "Total # of characters in file: " << totalOfChar << "\n\n";
	  ofs << std::setw(20) << std::left << "Category" << std::setw(20) << std::left << "How many in file" << std::setw(19) << std::right << "% of file\n";
	  ofs << "---------------------------------------------------------------------\n";
	  
	  wout(ofs, "Letters", letter, getPercentage(totalOfChar, letter));
	  wout(ofs, "White space", space, getPercentage(totalOfChar, space));
	  wout(ofs, "Digits", digits, getPercentage(totalOfChar, digits));
	  wout(ofs, "Other characters", others, getPercentage(totalOfChar, others));
	  
	  ofs << "\n\nLETTER STATISTICS\n\n";
	  ofs << std::setw(20) << std::left << "Category" << std::setw(20) << std::left << "How many in file" << std::setw(19) << std::right << "% of all letters\n"; // *
	  ofs << "---------------------------------------------------------------------\n";
	  
	  wout(ofs, "Uppercase", upper, getPercentage(letter, upper));
	  wout(ofs, "Lowercase", lower, getPercentage(letter, lower));
	  
	  
	  for(int i = 0; i < 26; i++)
	  {
		  ofs << std::setw(16) << std::left << (char)('a' + i) << std::setw(20) << std::right << a[i]
			<< std::setw(20) << std::right << std::setprecision(2) << std::fixed << getPercentage(letter, a[i]) << " %\n";
	  }
	  
	  ofs << "\n\nNUMBER ANALYSIS\n\n";
	  ofs << std::setw(37) << std::left << "Number of integers in file:" << numberInt << '\n'; // *
	  ofs << std::setw(37) << std::left << "Sum of integers:" << sumInt << '\n';
	  ofs << std::setw(37) << std::left << "Average of integers:" << avgInt << '\n';
	  ofs << "_____________________________________________________________________\n";
	  
	  
	  ifs.close();
	  ofs.close();
  }
}