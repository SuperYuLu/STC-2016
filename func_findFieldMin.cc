#include<iostream>
#include<cmath>

double findFieldMin(double *tField){
  
  int i, j, length;
  length = sizeof(tField) / sizeof(tField[0]); // Calcu the row size of tField
  double diff1[length-1], diff2[length-2]; // 1st and 2nd order of differential 
  
  for(i = 0; i < length-1; i ++ ){ // calcu the 1st and 2nd differential 
    diff1[i] = (tField[i+1][1] -  tField[i][1]) / (tField[i+1][0] - tField[i][0]);
    if(i > 0){
      diff2[i-1] = (diff1[i] - diff2[i-1]) / (tField[i][0] - tField[i-1][0]);
    }
  }


  
  
