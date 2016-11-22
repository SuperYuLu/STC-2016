#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

class traps{
  int trapNum;
  double centerPos, frontCoil, backCoil;		// Center position of trap
  traps();
  double calCurrent(double t, char shape);
  double calField(double currI);
};

traps :: traps(void){
  /* Constructor goes here
   no returns */
   cout << "Traps are being created" << endl;
}

double traps :: calCurrent( double t){
  /* Calculate current value (currI)  in the coil at time t
     with the shape given is 'shape': shape = "sin" or shape="triangle"
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