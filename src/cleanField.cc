// cleanField.cc
#include "traps.h"
#include "const.h"

void traps :: cleanField(){
  for(int i = 0; i < zStepNum; i++){
    tzField[i][1] = 0.0;
  }
}
