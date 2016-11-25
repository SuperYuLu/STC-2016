// main.cc 
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include "const.h"
#include "traps.h"
#include "main.h"

int mian(){
  traps alltraps[totTraps];
  double totTime = totTraps * tPeriod;
  double totDist = (totTraps+1) * geoAspectRatio * geoR - (totTraps - 1) * geoOverlapRatio * geoAspectRatio * geoR;
  double totalField[int(totDist / zStep) + 1][2]; // initialize 2D array with position and total field

  // init traps
  for(int i = 0; i < totTraps; i++){
    alltraps[i].initTrap(i+1);
  }

  
  for(int i=0; i < int(totTime / tStep); i++){
    t = i * tStep;
    for (int j = 0; j < totTraps; j++) if(alltraps[j].isOn(t)) alltraps[j].genFieldMatrix();
    calTotalField(traps *alltraps, double *totalField);
    
    

    
    for(int t = 0; t < sometime; t=t+tStep){
			/* loop through some amount of time, calculate the field for traps and find max/min info, save it into an array */
			for(int p = 0; p < maxPos; p+= zstep){
				/*loop through all the positions with 'zstep' increments to calculate the field for each position in the trap */
				field[i][t][p] = calField(t, p);
			}
		}
		
	}
	
	for(int t = 0; t < sometime; t=t+tStep){
		/* loop through time*/
		for(int p = 0; p < maxPos; p+= zstep){
			/*loop through all spatial position*/
			for(int i=1;i<totTraps;i++){
				// loop though all of the traps to generate totalField array
				totalField[t][p] += field[i][t][p];
			}
		}
	}
	
	
	/* further more, vary input parameters see how the result changes */
	
	ofstream totalFieldDatafile;
	totalFieldDatafile.open("totalFieldDatafile.csv")
	// for each row
	for (int i=0;i<maxTime;i++){
		// print first column's element
		totalFieldDatafile << totalField[i][0];

		// print remaining columns
		for (int j=1;j<maxPos;j++){
			totalFieldDatafile << ", " << totalField[i][j];
		}

		// print newline between rows
		totalFieldDatafile << endl;
	}
}
