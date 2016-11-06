#include<iostream>
#include<cmath>


int findMaxIdx(double *p, lb, ub){
  int i, j, max, idx;
  max = 0;
  idx = 0;
  for(i = lb; i<ub +1; i++){
    if( p[i] > max){
      max = p[i];
      idx = i;
    }
    else{
      continue;
    }
  }
  return (idx);
}


int findMinIdx(double *p, lb, ub){
  int i, j, min, idx;
  min = 0;
  idx = 0;
  for(i = lb; i<ub +1; i++){
    if( p[i] < max){
      min = p[i];
      idx = i;
    }
    else{
      continue;
    }
  }
  return (idx);
}


double findFieldMin(double *tField){
  int i, j, length, sign, lb,ub;
  length = sizeof(tField) / sizeof(tField[0]); // Calcu the row size of tField
  double diff1[length-1], diff2[length-2]; // 1st and 2nd order of differential 
  int maxIdx,minIdx;
  maxIdx = 0;
  minIdx = 0;
  
  for(i = 0; i < length-1; i ++ ){ // calcu the 1st and 2nd differential 
    diff1[i] = (tField[i+1][1] -  tField[i][1]) / (tField[i+1][0] - tField[i][0]);
    if(i > 0){
      diff2[i-1] = (diff1[i] - diff2[i-1]) / (tField[i][0] - tField[i-1][0]);
    }
  }

  sign = diff2[0] < 0 ? -1 : 1;
  lb = 0; // lower bound
  ub = 0; // upper bound
  for(i = 0; i < length - 2; i ++ ){
    if (sign * diff2[i] > 0){
      continue;
    }
    else if((i - lb) > 10 ){ // far enough
      ub = i;
      if(sign < 0){
	maxIdx = findMaxIdx(tField, lb, ub);
      }
      else{
	minIdx = findMinIdx(tField, lb, ub);
      }
      lb = i;
      sign = -1 * sign;
    }
    else{
      continue;
    }
  }

}

	
      
    
    

    
  
  
