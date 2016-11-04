# STC-2016

***
Project for class of Sci &amp; Tech Computing(STC)  
Dept. of Statistics & Data Science  
Texas Advanced Computing Center(TACC)  
The University of Texas at Austin.  

## Magnetic field oscillation in 3D adiabatic slower system for cold atom physics
***
### About

---
Adiabatic slower is a facility that consist of hundreds of overlapping Anti-Helmholtz coils, which is used to slow atoms from ~500 m/s down to ~0 m/s to create ultra bright cold atom source in atomic physics.  
It is realized by activating spatially overlapped magnetic traps with a overlapping time sequence, thus create an effective co-moving trap to slow down atoms.As shown in: 
![coil](https://github.com/SuperYuLu/STC-2016/tree/master/img/AntiHelmhotzSym.png)  
While its performance has been highly evaluated in the experiment [^1], the optimization hasn't been well discussed in any published articles. One of the key feature is the magnetic field oscillation during the trasition of traps, which is related to the lose rate, temperature, density of atoms being slowd.  
Here we propose a simulation approach to this problem, we will discuss the oscillation of magnetic field in adiabatic slower under different conditions, and try to find the optimized operating parameters for a given adiabatic slower setup.  

### Github links

---
Project Wiki: <https://github.com/SuperYuLu/STC-2016/wiki>  
Project weekly plan: <https://github.com/SuperYuLu/STC-2016/projects/1>

### Folders

---
**/src**: source code folder.  
**/bin**: executable code folder.  
**/doc**: docs such proposal, report, etc.  


### How to contribute

---
Each members please create your own branch for your own part of work,   **We will merge branches to master branch only after discussion**. So please make sure you're pushing to your own branch when updating the repo!

### Contributers:

---
[Yu Lu](https://github.com/SuperYuLu)  
[Xingyao Wang](https://github.com/xingyaowang)  
[Nitish Mittal](https://github.com/niimits)  


### About STC(Scientific and Technical Computing

---
* Basics of computing architectures,Microprocessors,Shared Memory Machines,and Clusters. 
* Important tools for developing software and working in an STC environment.  
These include Unix (beyond beginning), compilers,building software packages(make),repositories(git),debuggers,profilers,etc. 
* Machine arithmetic,basics of common numerical methods (FD, FFT,Linear Algebra, ...). How to usescientific libraries. 
* Data Intensive Computing:basic efficient IO,parallel file systems,advanced data formats(HDF5,NetCDF), etc.
* Visualiza&on:Introduction to data structures,formats and visualization tool(Gnuplot,ParaView,etc.)

[^1]: [U Even, M. G. Raizen, et. al., New Journal of Physics, Volume 9, 2007](http://iopscience.iop.org/article/10.1088/1367-2630/9/4/096)http://iopscience.iop.org/article/10.1088/1367-2630/9/4/096
