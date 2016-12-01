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
  int totMinIdx;
  double minTZField[int( totTime / tStep) + 1][3]; // |time|min pos| min Field
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
    }
    
    // Calculate total field save to totalField (2D: pos | field) 
    calTotalField(alltraps,(double *)totalField, int(totDist / zStep) + 1);
    
    // Find total field minimium by return index
    totMinIdx = findFieldMin_V2((double *) totalField, totDist / zStep + 1);
    minTZField[i][0] = t;  // time
    minTZField[i][1] = totalField[totMinIdx][0]; // min position
    minTZField[i][2] = totalField[totMinIdx][1]; // min field
    std::cout << "totMinIdx: " << totMinIdx << std::endl;
    csvWriteAll(t, int(totDist / zStep) + 1, (double *) totalField);
  }
  csvWriteMin(totTime / tStep + 1, (double *) minTZField);
}
