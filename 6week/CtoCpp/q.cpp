// This file can only have these 5 files included and therefore you should not
// remove the following include directives nor provide additional include directives!!!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "q.hpp" // compiler needs definition of type Tsunami

// anonymous namespace for any helper functions that you wish to implement
namespace {
  // ...
  double getMaxWave(hlp2::Tsunami const *arr, int size)
  {
	  double res = -1;
	  for(int i = 0; i < size; i++)
		  res = res < arr[i].wave ? arr[i].wave : res;
	  
	  return res;
  }
  
  double getAvgWave(hlp2::Tsunami const *arr, int size)
  {
	  double sum = 0;
	  for(int i = 0; i < size; i++)
		  sum += arr[i].wave;
	  
	  return (double)(sum / (double)size);
  }
  
  bool getGreaterThanAvg(hlp2::Tsunami const arr, double avg)
  {
	  if(arr.wave > avg)
		  return true;
	  
	  return false;
  }
}

namespace hlp2 {
  // provide definitions of functions declared in q.hpp here ...
  Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt)
  {
	  max_cnt = 0;
	  std::ifstream ifs{file_name};
	  if(!ifs)
		  return nullptr;
	  
	  while(ifs.good())
	  {
		  std::string str;
		  getline(ifs, str);
		  max_cnt++;
	  }
	  max_cnt--;
	  
	  Tsunami* tnami = new Tsunami[max_cnt];
	  
	  if(ifs.fail())
		ifs.clear();
	
	  ifs.seekg(0, std::ios::beg);
	  
	  int idx = 0;
	  while(ifs.good())
	  {
		  std::string str;
		  getline(ifs, str);
		  //std::cout << str << std::endl;
		  
		  std::string tmp;
		  int i = 0;
		  for(char c : str)
		  {
			  if( c != ' ')
				  tmp += c;
			  
			  if(tmp != "" && c == ' ')
			  {
				  if(i == 0)
					  tnami[idx].month = stoi(tmp);
				  else if(i == 1)
					  tnami[idx].day = stoi(tmp);
				  else if(i == 2)
					  tnami[idx].year = stoi(tmp);
				  else if(i == 3)
					  tnami[idx].fatalities = stoi(tmp);
				  else if(i == 4)
					  tnami[idx].wave = stod(tmp);
				  else
				  {
					  if(tnami[idx].location == "")
						  tnami[idx].location = tmp;
					  else
						  tnami[idx].location += " " + tmp;
				  }
				  tmp = "";
				  i++;
			  }  
		  }
		  idx++;
	  }
	  ifs.close();
	  
	  return tnami;
  }
  
  void print_tsunami_data(Tsunami const *arr, int size, std::string const& file_name)
  {
	  
	  std::ofstream ofs{file_name};
	  
	  if(!ofs)
		  return;
	  
	  
	  ofs << "List of tsunamis:\n-----------------\n";
	  for(int i = 0; i < size; i++)
	  {
		  //ofs << std::setw(2) << std::left << arr[i].month << " " <<
		  ofs << std::right << std::setfill('0') << std::setw(2) << arr[i].month << " ";
		  ofs << std::setw(2) << arr[i].day << " ";
		  
		  ofs << std::setfill(' ') << std::setw(4) << std::left << arr[i].year << " " <<
				 std::setw(6) << std::right << arr[i].fatalities << " " <<
				 std::setw(10) << std::setprecision(2) << std::fixed << std::right << arr[i].wave << "     " <<
				 std::left << arr[i].location << "\n";		 
	  }
	  
	  double avg = getAvgWave(arr, size);
	  ofs << "\nSummary information for tsunamis\n--------------------------------\n\n";
	  ofs << "Maximum wave height (in meters): " << std::setprecision(2) << std::fixed << getMaxWave(arr, size) << "\n\n";
	  ofs << "Average wave height (in meters): " << std::right << std::setw(5) << std::setprecision(2) << std::fixed << avg << "\n\n";
	  ofs << "Tsunamis with greater than average height " << std::setprecision(2) << std::fixed << avg << ":\n";
	  
	  for(int i = 0; i < size; i++)
	  {
		  if(getGreaterThanAvg(arr[i], avg))
			  ofs << std::setprecision(2) << std::fixed << arr[i].wave << "     " << arr[i].location << '\n';
	  }
	  
	  ofs.close();
	  
  }

}
