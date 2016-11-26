// findFieldMin.cc
/* Find the field minimium based on giving 2D array of field distribution
   return the index minimium field in the array */

int findMinIdx(double *p, int lb, int ub){
  int i, j, min, idx;
  min = 1000;
  idx = 0;
  for(i = lb; i<ub +1; i++){
    if( p[i] < min){
      min = p[i];
      idx = i;
    }
    else{
      continue;
    }
  }
  return (idx);
}


int findMaxIdx(double *p, int lb, int ub){
  int i, j, max, idx;
  max = -1000;
  idx = 0;
  for(i = lb; i<ub +1; i++){
    if( p[i] < min){
      min = p[i];
      idx = i;
    }
    else{
      continue;
    }
  }
  return (idx);
}


int findFieldMin(double *tField){ 
  int i, j, length, sign, lb,ub;//
  length = sizeof(tField) / sizeof(*tField + *(tField +1)); // Calcu the row size of tField
  double diff1[length-1], diff2[length-2]; // 1st and 2nd order of differential 
  int minIdx, temp;
  double minField;
  minIdx = 0;
  
  for(i = 0; i < length-1; i ++ ){ // calcu the 1st and 2nd differential 
    diff1[i] = (*(tField + (i+1) * 2 + 1) - *(tField + (i) * 2 + 1))  / (*(tField + (i+1) * 2 + 0) - *(tField + (i) * 2 + 0)); // 1st order diff
    if(i > 0)
      diff2[i-1] = (diff1[i] - diff2[i-1]) / (*(tField + (i) * 2 + 0) - *(tField + (i-1) * 2 + 0));
  }

	      

  sign = diff2[0] < 0 ? -1 : 1;
  lb = 0; // lower bound
  ub = 0; // upper bound
  minField = 1000; 

  for(i = 0; i < length - 2; i ++ ){
    if (sign * diff2[i] > 0){
      continue;
    }
    
    else{
      if((i - lb) > 2 && sign < 0){ // 2:far enough
	ub = i;
	temp = findMinIdx(tField, lb, ub);
	if (*(tField + temp * 2 + 1)< minField){
	  minIdx = findMinIdx(tField, lb, ub);
	  minField = *(tField + temp * 2 + 1);
	  lb = i;
	  sign = -1 * sign;
	}
      }
    }
  }

  return(minIdx);
}		      
