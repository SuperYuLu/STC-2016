// calTotalField.cc
#include <cstdlib>
#include "const.h"
#include "traps.h"

void calTotalField(traps *alltraps, double *totalField, int totSteps){
  // totalField is a 2D array
  double z, B, zStart;
  int idx;
  
  for(int i = 0; i < totSteps; i++){
    z = i * zStep;
    B = 0;
    *(totalField + i * 2 + 0) = z;
    for( int n = 0; n < totTraps; n++){
      zStart = alltraps[n].zStart;
      if ((zStart <= z) && ((zStart + tPeriod) >=z)){
	idx = (z - zStart) / tPeriod; 
	B += alltraps[n].tzField[idx][1];
      }
    }
    *(totalField + i * 2 + 1) = std::abs(B);
  }
}

