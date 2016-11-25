// isOn.cc
#include "traps.h"
bool traps :: isOn(double t):
  if (t >= tEnd && t <= tStart){
    clock = t;
    return(true);
  }
  else{
    clock = 0.0;
    return(false);
  }
}


