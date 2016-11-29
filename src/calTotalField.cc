// calTotalField.cc
#include <cmath>
#include "const.h"
#include "traps.h"
#include <iostream>

void calTotalField(traps alltraps[], double *totalField, int totSteps){
  // totalField is a 2D array
  double z, B, zStart;
  int idx;
  
  for(int i = 0; i < totSteps; i++){ // Loop through absolute positions
    z = i * zStep;
    B = 0.0;
    
    *(totalField + i * 2 + 0) = z; // can be optimized 
    for( int n = 0; n < totTraps; n++){ // Loop through all traps 
      zStart = alltraps[n].zStart;

      if ((zStart <= z) && ((zStart + 2 * geoAspectRatio * geoR) >=z)){
      	idx = (z - zStart) / zStep; 
      	B += alltraps[n].tzField[idx][1];
      }
      
      if (z == 5e-3) std::cout << "Middle B: " << alltraps[n].tzField[idx][1] <<std::endl;
    }
    
    // std::cout << "z = " << z << "Btot = " << B << std::endl;
    *(totalField + i * 2 + 1) = B;// std::abs(B);
  }
}

