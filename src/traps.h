// traps.h
#include "const.h"
#ifndef __TRAPS_H_INCLUDED__
#define __TRAPS_H_INCLUDED__
class traps{
 public:
  int trapNum;
  double tStart, tEnd, zStart, clock;
  double centerPos, frontCoil, backCoil; // Center position of trap
  int currShape; // Current shape: 1 for sine, 2 for triangle
  double tzField[zStepNum][2];
  void initTrap(int num);
  bool isOn(double t);
  double calCurrent(double t, int shape);
  double calField(double currI, double pos);
  void genFieldMatrix();
  void cleanField();
   
};
#endif

