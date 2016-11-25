#include "const.h"

class traps{
 Public:
  int trapNum;
 Private:
  int zStepNum = int(2*geoAspectRatio * geoR / zStep) + 1;
  double tStart, tEnd, zStart, clock;
  double centerPos, frontCoil, backCoil; // Center position of trap
  int currShape; // Current shape: 1 for sine, 2 for triangle
  double tzField[zStepNum][2];
  
  void initTrap(int num);
  bool isOn(double t);
  double calCurrent(double t, int shape);
  double calField(double currI);
  double genFieldMatix();
};


