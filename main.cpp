#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#define _USE_MATH_DEFINES

double geoR = 5e-3; // Radius of coil, 5 mm
double geoAspectRatio = 2; // Space of the two coils for a single trap, with respect to geoR
double geoOverlapRatio = 0.5; // geoOverlapRatio 0~1, 0 for not overlap, 1 for totally overlap, 0.5 for half overlap
double zStep = 0.2 * geoR;  // Spatial step(resolution)
double tPeriod = 50e-6; // Current pulse period, 50 us
double tStep = tPeriod / 20.0; // Time step(resolution)
double tOverlapRatio = 0.5; // The time overlap = tOverlapRatio * tPeriod
double Imax = 500; // Current maxmium = 500 A
int geoWindings = 8;
int totTraps = 3;

// =============== Declare all fuctions (this will go seperate file later)==============
double calCurrent(string type, double t);
double calField(double currI, double pos);
double findFieldMin(double tField[]);
double findFieldMax(double tField[]);



// ======================== Define class traps here ====================================
class traps{
  int trapNum;
  double centerPos, frontCoil, backCoil;		// Center position of trap
  traps();
  double calCurrent(double t, char shape);
  double calField(double currI);
};

traps :: traps(int num){
  /* Constructor goes here
     Based on given trap number, calculate the trap center position, 
     and front/back coil position
     no returns */
  trapNum = num; // the 1st trap num = 0
  centerPos = geoOverlapRatio * geoR * num;
  frontCoil = centerPos + geoAspectRatio * geoR * 0.5;
  backCoil = centerPos - geoAspectRatio * geoR * 0.5;
  
}


double traps :: calCurrent(string type, double t) = calCurrent(string type, double t);
  /* Calculate current value (currI)  in the coil at time t
     with the sape given is 'shape': shape = "sin" or shape="triangle"
     one has to consider the on time of a specific trap, which can be 
     calculated from trapNum, tPeriod, tOverlapRatio.
     return(currI) */


double traps :: calField(double currI, double pos) = calField(double currI, double pos);
  /* Calculate the magnemtic field based on trap geometry 
     return a 2D [Nx2]array tField: 
     the 1st column is for position(absolute position)
     the 2nd column is for calculated field.
  */


// ==================== Functions to be used ==========================================

double findFieldMin(double tField[]) = findFieldMin(double tField[]);
  /* Find the trap minimun and corresponding position
     return a 2D[Nx3] array fieldMin:
     the 1st column is time;
     the 2nd column is position of min field 
     the 3rd column is field min
     return(fieldMin)
  */

double findFieldMax(double tField[]) = findFieldMax(double tField[]);
  /* Same as above, may be we could combine these two equations into one
     return(fieldMax)
  */


// ============================== main part of program =================================

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