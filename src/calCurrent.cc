// calCurrent.cc
#include <cmath>
#include "const.h"
#include "traps.h"
#include <iostream>
#define pi 3.1415926



double traps :: calCurrent(double t, int shape){
  /*
    Function used to genetrate the current according to
    given wave type and time;
    Imax and tPeriod will be given by global variable;
    Tested by Yu on 2016/11/20
  */
  double currI;
 
  double tt;
  tt = fmod(t - tStart, tPeriod);
  
  if(shape == 1) currI = Imax * sin( pi * tt / tPeriod);
  
  else if (shape == 2){
    if(tt <= tPeriod / 2.0){
      currI = 2 * Imax / tPeriod * tt;
    }
    else{
      currI = 2 * Imax / tPeriod * (tPeriod - tt);
    }
  }
  //if(tt = 50e-6) std::cout << "tStart: " << tStart*1e6 << " us" << " 50us current: " << currI << std::endl;
  return(currI);
}
