// #include<string>
// #include "const.h"

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

