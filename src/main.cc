// main.cc
#include<fstream>
#include "const.h"
#include "traps.h"
#include "main.h"
#include <iostream>
int main(){
  
  traps alltraps[totTraps]; //Array of class traps
  double totTime = totTraps * tPeriod; //Total time for simulation
  double totDist = (totTraps+1) * geoAspectRatio * geoR - (totTraps - 1) * geoOverlapRatio * geoAspectRatio * geoR; // Total space distance for simulation
  double totalField[int(totDist / zStep) + 1][2]; // 2D array with position and total field
  int tMinIdx[int(totTime / tStep) + 1]; //Field minimium index at different time
  
  // init traps
  for(int i = 0; i < totTraps; i++){
    alltraps[i].initTrap(i+1);
  }

  // Simulation
  double t; // time
  for(int i=0; i < int(totTime / tStep) + 1; i++){ // Loop through time
    t = i * tStep;
    
    for (int j = 0; j < totTraps; j++) // Loop through traps
      if(alltraps[j].isOn(t) == true) // Calculate field if trap is on
	alltraps[j].genFieldMatrix();
    
    // Calculate total field by direct adding up
    calTotalField(alltraps,(double *)totalField, int(totDist / zStep) + 1);
    
    // Find total field minimium by return index
    tMinIdx[i] = findFieldMin((double *) totalField);
    cleanTrapsField(alltraps);
  }

  for( int m = 0; m < int(totTime / tStep) + 1; m ++){
    std::cout << tMinIdx[m] << std::endl;
  }
  
	// /* further more, vary input parameters see how the result changes */
	
	// ofstream totalFieldDatafile;
	// totalFieldDatafile.open("totalFieldDatafile.csv")
	// // for each row
	// for (int i=0;i<maxTime;i++){
	// 	// print first column's element
	// 	totalFieldDatafile << totalField[i][0];

	// 	// print remaining columns
	// 	for (int j=1;j<maxPos;j++){
	// 		totalFieldDatafile << ", " << totalField[i][j];
	// 	}

	// 	// print newline between rows
	// 	totalFieldDatafile << endl;
	// }
}
