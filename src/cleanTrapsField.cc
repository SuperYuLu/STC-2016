// cleanTrapsField.cc
#include "traps.h"
#include "const.h"
void cleanTrapsField(traps tp[]){
  for(int i = 0; i < totTraps; i++){
    tp[i].cleanField();
  }
}

