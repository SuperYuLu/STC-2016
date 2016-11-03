#include<whatever>

double geoR, geoAspectRatio,geoOverlapRatio;
double zStep;  // Spatial step(resolution)
double tStep;  // Time step(resolution)
double tPeirod; // Current pulse period
double tOverlapRatio; // The time overlap = tOverlapRatio * tPeriod
int geoWindings, totTraps;	


// ======================== Define class traps here ====================================
class traps{
  int trapNum;
  double centerPos, frontCoil, backCoil;		// Center position of trap
  traps();
  double calCurrent(double t, char shape);
  double calField(double currI);
};

traps :: traps(){
  /* Constructor goes here
   no returns */
}

double traps :: calCurrent( double t){
  /* Calculate current value (currI)  in the coil at time t
     with the sape given is 'shape': shape = "sin" or shape="triangle"
     one has to consider the on time of a specific trap, which can be 
     calculated from trapNum, tPeriod, tOverlapRatio.
     return(currI) */
}

double traps :: calField(double currI){
  /* Calculate the magnemtic field based on trap geometry 
     return a 2D [Nx2]array tField: 
     the 1st column is for position(absolute position)
     the 2nd column is for calculated field.
  */
}

// ==================== Functions to be used ==========================================

double findFieldMin(double tField[]){
  /* Find the trap minimun and corresponding position
     return a 2D[Nx3] array fieldMin:
     the 1st column is time;
     the 2nd column is position of min field 
     the 3rd column is field min
     return(fieldMin)
  */
}

double findFieldMax(double tField[]){
  /* Same as above, may be we could combine these two equations into one
     return(fieldMax)
  */
}

// ============================== main part of program =================================

int mian(){
  traps alltraps[totTraps]; // asign arry alltraps to store all trap info
  
  for(int i = 0; i < totTraps; i ++){
    /* initialize the trap, eg. trapNum, centerPos, etc */
  }
  
  for(int t = 0; t < sometime; t=t+tStep){
    /* loop through some amount of time, calculate the field for traps and find max/min info, save it into an array */
  }

  /* further more, vary input parameters see how the result changes */

}
    
