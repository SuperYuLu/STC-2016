#include<iostream>
#include<cmath>
#include<fstream>
#include <cstdlib>

using namespace std;
int main(){
	int n = 10;
	int totalField[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			totalField[i][j] = rand()%100;
		}
	}
	
	ofstream totalFieldDatafile;
	totalFieldDatafile.open("totalFieldDatafile.csv");
	
	for(int k = 0; k<n;k++){
		for (int i=0;i<n;i++){
			// print first column's element
			totalFieldDatafile << k << ", " << totalField[i][0];

			// print remaining columns
			for (int j=1;j<n;j++){
				totalFieldDatafile << ", " << totalField[i][j];
			}

			// print newline between rows
			totalFieldDatafile << endl;
		}
	}	
	return 0;
}


