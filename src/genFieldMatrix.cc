// genFieldMatrix.cc
#include "traps.h"
#include "const.h"

void traps :: genFieldMatrix(){
  I = calCurrent(clock, 1);
  for (int j = 0; j <= zStepNum; z++){
    z = zStart + j + zStep;
    tzField [j][1] = calField(I, z);
  }
}
