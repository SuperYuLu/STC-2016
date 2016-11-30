// genFieldMatrix.cc
#include "traps.h"
#include "const.h"
#include <iostream>

void traps :: genFieldMatrix(){
  double I, z;
  I = calCurrent(clock, 1);
  //std::cout << "I = " << I << std::endl;
  for (int j = 0; j < zStepNum; j++){
    z = zStart + j * zStep;
    tzField [j][1] = calField(I, z);
    //std::cout << "z: " << z << " Field " << tzField[j][1] << std::endl;
  }
}
