//main.h
#ifndef __MAIN_H_INCLUDED__
#define __MAIN_H_INCLUDED__


void calTotalField(traps alltraps[],double *totalField, int totSteps);
void cleanTrapsField(traps tp[]);
int findFieldMin_V2(double *tField, int rowNum);
void csvWriteAll(double t, int rowNum, double *field2D);
void csvWriteMin(int tNum, int *idx, double *field2D);
//double findFieldMax(double tField[]);

#endif

