# plotMin.py

import numpy as np
import os
import matplotlib.pyplot as plt

folder = '../dat/'
name = 'minField.csv' # 2D array:  Time | Pos | Field 
if os.path.exists(folder):
    if os.path.exists(folder + name):
        data2D = np.genfromtxt(folder + name, delimiter = ',')
        p = plt.figure()
        plt.subplot(211)
        plt.plot(data2D[:,0] * 1e6, data2D[:,1] * 1e3)
        plt.title('Magnetic field Minimium distribution')
        plt.ylabel('Min Field Position [mm]')
        plt.xlabel('Time [us]')
        plt.subplot(212)
        plt.plot(data2D[:,0] * 1e6, data2D[:,2] * 1e3)
        plt.ylabel('Min Field Value[T]')
        plt.xlabel('Time [us]')
        p.savefig(folder + 'minField.png', dpi=150)
        print("Plot saved in :" + folder + 'minField.png')
        plt.close(p)
    else:
        print("File: " + name + " not exist !")
else:
    print("Path: " + folder + " not exist !")

