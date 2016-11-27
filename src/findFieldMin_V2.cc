// findFieldMin.cc
/* Find the field minimium based on giving 2D array of field distribution
   return the index minimium field in the array */
#include<cmath>
#include<iostream>
int findMinIdx(double *p, int len){
  int i, idx;
  double min;
  min = 1000;
  idx = 0;
  for(i = 0; i<len; i++){
    if( p[i] < min){
      min = p[i];
      idx = i;
    }
  }
  return (idx);
}


int findMaxIdx(double *p, int len){
  int i, idx;
  double max;
  max = -1000;
  idx = 0;
  for(i = 0; i<len; i++){
    if( p[i] > max){
      max = p[i];
      idx = i;
    }
  }
  return (idx);
}

int findFieldZero(double *p, int len,int lb, int ub){
  int i, idx;
  double min;
  min = 100;
  for (i = lb; i < ub; i++){
    if(std::abs(p[i]) < min){
      min = p[i];
      idx = i;
    }
  }
  return(idx);
}

int findFieldMin(double *tField){ 
  int i, len;
  len = sizeof(tField) / sizeof(*tField + *(tField +1)); // Calcu the row size of tField
  double field1D[len];
  int minIdx, maxIdx, zeroIdx;
  //std::cout << len << std::endl;
  for(i = 0; i < len; i++){
    field1D[i] = *(tField + i * 2 + 1);
  }

  minIdx = findMinIdx(field1D, len);
  maxIdx = findMaxIdx(field1D, len);
  zeroIdx = findFieldZero(field1D, len, minIdx, maxIdx);
  return(zeroIdx);
}		      
