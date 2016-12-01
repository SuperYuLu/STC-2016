// csvWriteAll.cc
#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>

void csvWriteAll(double t, int rowNum, double *field2D){
  std::string path="../dat/";
  std::string filename;
  std::ostringstream convert;
  convert << t*1e6;
  filename = convert.str();
  if(fmod(t * 1e6,1) < 0.001){
    filename = filename + ".0";
  }
  filename = path + filename + ".csv";

  std::ofstream totalFieldDatafile;
  totalFieldDatafile.open(filename);
  
  for(int k = 0; k < rowNum;k++){
    
    // print first column's element
    totalFieldDatafile << *(field2D + k * 2 + 0)<< ", ";
    totalFieldDatafile << *(field2D + k * 2 + 1)<< std::endl;
    
  }
  totalFieldDatafile.close();
  std::cout << filename << " SAVED" << std::endl;
}
