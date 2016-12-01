// csvWriteMin.cc
#include<iostream>
#include<fstream>
#include<cmath>
#include "const.h"
//#include<sstream>


void csvWriteMin(int tNum, int *idx, double *field2D){
  std::string path="../dat/";
  std::string filename;
  //std::ostringstream convert;
  //convert << t*1e6;
  filename = "minField";
  filename = path + filename + ".csv";

  std::ofstream minFieldDatafile;
  minFieldDatafile.open(filename);

  for(int i = 0; i < tNum; i++){
    minFieldDatafile << i * tStep << ","; // 1st column, time
    minFieldDatafile << std::abs(*(field2D + idx[i] * 2 + 0))<<","; // 2nd column, min pos
    minFieldDatafile << std::abs(*(field2D + idx[i] * 2 + 1))<< std::endl; // 2nd column, min field
  }
  
  minFieldDatafile.close();
  std::cout << filename << " SAVED" << std::endl;
}
