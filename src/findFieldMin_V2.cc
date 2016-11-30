// findFieldMin_V2.cc
/* Find the field minimium based on giving 2D array of field distribution
   return the index minimium field in the array */
#include<cmath>
#include<iostream>

int findMinIdx(double *p, int len){
  int i, idx;
  double min;
  min = 1000.0;
  idx = 0;
  for(i = 0; i<len; i++){
    
    if( p[i] < min){
      min = p[i];
      idx = i;
    }
    //std::cout << p[i]<< ","<<min<< "," << idx << std::endl;
  }
  
  return (idx);
}


int findMaxIdx(double *p, int len){
  int i, idx;
  double max;
  max = -1000.0;
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
  idx =  0;
  min = 100.0;
  for (i = lb; i < ub; i++){
    // std::cout << "i number" << i << std::endl;
    if(std::abs(p[i]) < min){
      //std::cout << "p[i]: " << p[i] << " min" << min << std::endl;
      min = std::abs(p[i]);
      idx = i;
    }
  }
  //std::cout << "idx: " << idx << " lb: " << lb << std::endl;
  return(idx);
}

int findFieldMin_V2(double *tField, int rowNum){ 
  int i;
  double field1D[rowNum];
  int minIdx, maxIdx, zeroIdx;
  //std::cout << "rowNum: " << rowNum << std::endl;
  zeroIdx = 0;
  for(i = 0; i < rowNum; i++){
    field1D[i] = *(tField + i * 2 + 1);
  }
  
  minIdx = findMinIdx(field1D, rowNum);
  maxIdx = findMaxIdx(field1D, rowNum);
  std::cout << "minIdx: " << minIdx << " value: " << field1D[minIdx] << std::endl;
  std::cout << "maxIdx: " << maxIdx << " value: " << field1D[maxIdx] << std::endl;
  zeroIdx = findFieldZero(field1D, rowNum, minIdx, maxIdx);
  //std::cout << "zeroIdx: " << zeroIdx << std::endl;
  return(zeroIdx);
}		      
