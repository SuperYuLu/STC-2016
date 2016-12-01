// csvWriteMin.cc
#include<iostream>
#include<fstream>
#include<cmath>
#include "const.h"



void csvWriteMin(int tNum, double *field2D){ // |time|min pos|min Field|
  std::string path="../dat/";
  std::string filename;
  filename = "minField";
  filename = path + filename + ".csv";

  std::ofstream minFieldDatafile;
  minFieldDatafile.open(filename);

  for(int i = 0; i < tNum; i++){
    minFieldDatafile << *(field2D + i * 3 + 0)<< ","; // 1st column, time
    minFieldDatafile << std::abs(*(field2D + i * 3 + 1))<<","; // 2nd column, min pos
    minFieldDatafile << std::abs(*(field2D + i * 3 + 2))<< std::endl; // 3rd column, min field
  }
  
  minFieldDatafile.close();
  std::cout << filename << " SAVED" << std::endl;
}
