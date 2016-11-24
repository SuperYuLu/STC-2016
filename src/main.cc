#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include "const.h"
#include "main.h"

int mian(){
	traps alltraps[totTraps]; // asign arry alltraps to store all trap info
	field[totTraps][maxTime][maxPos] // initialize 3D field array with trap number, time and position
	totalField[maxTime][maxPos] // initialize 2D array with time and position by adding time and position for each trap
	
	for(i=1; i < totTraps; i++){
	  
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
