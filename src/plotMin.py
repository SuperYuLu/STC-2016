# plotMin.py

import numpy as np
import os
import matplotlib.pyplot as plt

folder = '../dat/'
name = 'minField.csv' # 2D array:  Time | Pos | Field
labelFontSize = 8
if os.path.exists(folder):
    if os.path.exists(folder + name):
        data2D = np.genfromtxt(folder + name, delimiter = ',')
        dt = data2D[2,0] - data2D[1,0]; # Get the fixed time interval
        diff = np.gradient(data2D[:,1], dt)
        
        p = plt.figure()
        plt.subplot(311)
        plt.plot(data2D[:,0] * 1e6, data2D[:,1] * 1e3)
        plt.title('Magnetic field Minimium distribution')
        plt.ylabel('Min Field Position [mm]', fontsize = labelFontSize)
        #plt.xlabel('Time [us]',fontsize = labelFontSize)

        plt.subplot(312)
        plt.plot(data2D[:,0] * 1e6, diff)
        #plt.xlabel('Time [us]',fontsize = labelFontSize)
        plt.ylabel('Acceleration [m/s^2]',fontsize = labelFontSize)
        
        plt.subplot(313)
        plt.plot(data2D[:,0] * 1e6, data2D[:,2])
        plt.ylabel('Min Field Value[T]',fontsize = labelFontSize)
        plt.xlabel('Time [us]',fontsize = labelFontSize)
        p.savefig(folder + 'minField.jpg', dpi=150)
        
        print("Plot saved in :" + folder + 'minField.png')
        plt.close(p)
    else:
        print("File: " + name + " not exist !")
else:
    print("Path: " + folder + " not exist !")

