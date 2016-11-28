// genFieldMatrix.cc
#include "traps.h"
#include "const.h"
#include <iostream>

void traps :: genFieldMatrix(){
  double I, z;
  I = calCurrent(clock, 1);
  for (int j = 0; j < zStepNum; j++){
    z = zStart + j * zStep;
    // std::cout << "z= " << z << std::endl;
    tzField [j][1] = calField(I, z);
  }
}
