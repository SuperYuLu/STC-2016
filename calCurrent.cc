#include <cmath>
#include <iostream>
#include <string>
#define _USE_MATH_DEFINES

//using namespace std;
//double Imax = 500;
//double tPeriod = 10;

double calCurrent(string type, double t){
  /*
    Function used to genetrate the current according to
    given wave type and time;
    Imax and tPeriod will be given by global variable;
    Tested by Yu on 2016/11/20
  */
  double currI;
  double tt;
  tt = fmod(t, tPeriod);
  
  if(type == "sine"){
    currI = Imax * sin(tt);
  }
  
  else if (type == "triangle"){
    if(tt <= tPeriod / 2.0){
      currI = 2 * Imax / tPeriod * tt;
    }
    else{
      currI = 2 * Imax / tPeriod * (tPeriod - tt);
    }
  }

  else{
    cout << "Current wave type not found" << endl;
  }
  return(Imax);
}
