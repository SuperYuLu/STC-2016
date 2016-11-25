// initTrap.cc
#include "const.h"
#include "traps.h"

void traps :: initTrap(int num){
  /* Constructor goes here
     Based on given trap number, calculate the trap center position, 
     and front/back coil position
     no returns */
  trapNum = num;
  tStart = tPeriod * (trapNum - 1);
  tEnd = tStart + tPeriod;
  centerPos =  trapNum * (1 - geoOverlapRatio) * geoAspectRatio * geoR; // trap center 
  frontCoil = centerPos + geoAspectRatio * geoR * 0.5;
  backCoil = centerPos - geoAspectRatio * geoR * 0.5;
  zStart = backCoil - 0.5 * centerPos;
  currShape = 1;

  for(i = 0; i < zStepNum; i++){
    tzField[i][0] = backCoil - 0.5 * centerPos + i * zStep;
  }
  
}

