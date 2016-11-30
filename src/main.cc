// main.cc
#include<fstream>
#include "const.h"
#include "traps.h"
#include "main.h"
#include <iostream>
int main(){
  
  traps alltraps[totTraps]; //Array of class traps
  double totTime = totTraps * tPeriod - (totTraps - 1) * tOverlapRatio * tPeriod; //Total time for simulation
  double totDist = (totTraps+3) * geoAspectRatio * geoR - (totTraps - 1) * geoOverlapRatio * geoAspectRatio * geoR; // Total space distance for simulation
  double totalField[int(totDist / zStep) + 1][2]; // 2D array with position and total field
  int totMinIdx[int(totDist / zStep) + 1];
  std:: cout << "totDist" << totDist<< std::endl;
  // init traps
  for(int i = 0; i < totTraps; i++){
    alltraps[i].initTrap(i+1);
  }

  // Simulation
  double t; // time
  for(int i=0; i < (int(totTime / tStep) +1 ); i++){ // Loop through time
    t = i * tStep;
    std::cout<<"=== "<< t * 1e6 << " us /"<< totTime * 1e6 << " us ===" << std::endl;
    cleanTrapsField(alltraps); // zero field value before calculate
    for (int j = 0; j < totTraps; j++){ // Loop through traps
      if(alltraps[j].isOn(t) == true){ // Calculate field if trap is on
	std::cout << "trapNum: " << alltraps[j].trapNum << " is On " << std::endl;
	alltraps[j].genFieldMatrix();
      }
      //alltraps[j].genFieldMatrix();
    }

    
    for( int k = 0; k < zStepNum; k++){
      //std::cout << "P= " << alltraps[1].tzField[k][0] << " B= " << alltraps[1].tzField[k][1] << "   " << std::endl;
      //std::cout << "P= " << alltraps[0].tzField[k][0] << " B= " << alltraps[0].tzField[k][1] << "   " << std::endl;
    }
    
    // Calculate total field by direct adding up
    calTotalField(alltraps,(double *)totalField, int(totDist / zStep) + 1);
    
    // Find total field minimium by return index
    totMinIdx[i] = findFieldMin_V2((double *) totalField, totDist / zStep + 1);
    std::cout << "totMinIdx: " << totMinIdx[i] << std::endl;
    csvWrite(t, int(totDist / zStep) + 1, (double *) totalField);
  }

}
