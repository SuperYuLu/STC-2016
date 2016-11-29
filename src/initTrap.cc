// initTrap.cc
#include "const.h"
#include "traps.h"

void traps :: initTrap(int num){
  /* Constructor goes here
     Based on given trap number, calculate the trap center position, 
     and front/back coil position
     no returns */
  trapNum = num;
  clock = 0.0;
  tStart = tPeriod * (trapNum - 1) - tOverlapRatio * (trapNum - 1) * tPeriod;
  tEnd = tStart + tPeriod;
  //centerPos =  0.5 * geoAspectRatio * geoR + 0.5 * trapNum * geoAspectRatio * geoR - (trapNum - 1) * geoOverlapRatio * geoAspectRatio * geoR; // offset + trap center position - overlap part
  centerPos = trapNum * geoAspectRatio * geoR - (trapNum - 1) * geoOverlapRatio * geoAspectRatio * geoR; 
  frontCoil = centerPos + geoAspectRatio * geoR * 0.5;
  backCoil = centerPos - geoAspectRatio * geoR * 0.5;
  zStart = backCoil - 0.5 * geoAspectRatio * geoR;
  currShape = 1;

  for(int i = 0; i < zStepNum; i++){
    tzField[i][0] = zStart  + i * zStep;
  }
  
}

