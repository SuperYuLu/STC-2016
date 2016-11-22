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



double findFieldMax(double *tField){
  int i, j, length, sign, lb,ub;
  length = sizeof(tField) / sizeof(tField[0]); // Calcu the row size of tField
  double diff1[length-1], diff2[length-2]; // 1st and 2nd order of differential 
  int maxIdx;
  double maxField, temp;
  maxIdx = 0;
  
  for(i = 0; i < length-1; i ++ ){ // calcu the 1st and 2nd differential 
    diff1[i] = (tField[i+1][1] -  tField[i][1]) / (tField[i+1][0] - tField[i][0]);
    if(i > 0){
      diff2[i-1] = (diff1[i] - diff2[i-1]) / (tField[i][0] - tField[i-1][0]);
    }
  }

  sign = diff2[0] < 0 ? -1 : 1;
  lb = 0; // lower bound
  ub = 0; // upper bound
  maxField = 0;
  
  for(i = 0; i < length - 2; i ++ ){
    if (sign * diff2[i] > 0){
      continue;
    }
    
    else{
      if((i - lb) > 10 && sign < 0){ // far enough
	ub = i;
	temp = findMaxIdx(tField, lb, ub);
	if (tField[temp][1] > maxField){
	  maxIdx = temp;
	  maxField = tField[temp][1];\
	  lb = i;
	  sign = -1 * sign;
	}
      }
    }
  }
}

return(maxIdx)
