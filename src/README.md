# Source code for STC-2016
***
### Main program  
---
main.cc  

### List of functions   
---
+ calCurrent: Calculate current in the coil at a given time, peridic boundry condition
	- input: string type, double t
	- output: double currI 
+ calField: Calculate magnetic field at a single position and single time
	- input: double currI, double pos 
	- output: double field 
+ calTotalField: Generate 2D array with the magnetic fields for all positions and times 
	- input: traps alltraps[], double *totalField, int totSteps 
	- output: double tfield, 2D array 
+ func\_findFieldMin: Find the magnetic field minimum given a magnetic field distribution 
	- input: double tField, 2D array
	- output: int minIdx, the index of field minimum
+ func\_findFieldMin: Find the magnetic field minimum given a magnetic field distribution 
	- input: double tField, 2D array
	- output: int minIdx, the index of field minimum

	

	
