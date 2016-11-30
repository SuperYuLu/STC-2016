# This scirpt is for python3
# This script is to calculate the real time dependent of the mag. field change
# when swhich between two neiboring trap, all parameters are the real ones

import numpy as np
import matplotlib.pyplot as plt

# Define coil parameters

r = 5.1e-3 # Bore diameter of coils, in meter
u0 = 1.256637e-6 # Magnetic constant
space = 5e-3 # Center to Center dist. in meters
WireDia = 0.405e-3 # Wire diameter


pos_back = 4*space # Define the position of back coil center 
pos_front = pos_back+2*space-3*WireDia # Define the position of front coil center
t_sampling=100
I_max = 100 # Current in Coils, Amps

# Current signal, half sin wave
def I(t_start):
    global t_sampling, I_max
    t=np.linspace(t_start,t_start+np.pi,t_sampling)
    I=I_max*np.sin(t)
    return I

 
def Magfield(pos_back,I,z):
    '''
    Calculate the magnetic field in coils with the accurate geometry,at
    current I and position z

    pos_back: back peak position of the anti helmholtz coil
    pos_front: front peak position of the  anti helmholtz coil
    I: Current in the coil 
    '''
    global WireDia,u0
    Magfield = 0
    pos_front = pos_back+2*space-3*WireDia
    for j in np.linspace(0,3,4):
        R = r+j*WireDia
        for k in np.linspace(0,3,4):
            p1 = pos_front-1.5*WireDia+k*WireDia
            Magfield += u0*I*r**2/2/(((z-p1)**2+R**2)**(3/2))
        for s in np.linspace(0,1,2):
            p2 = pos_back-0.5*WireDia*s*WireDia
            Magfield -= u0*I*r**2/2/(((z-p2)**2+R**2)**(3/2))
    #Magfield=abs(Magfield)
    return Magfield


z1=np.linspace(0,10*space,100)
z2 = np.linspace(space,10*space+space,100)

B1=abs(Magfield(pos_back,I_max,z1))
B2=abs(Magfield(pos_back+space,I_max,z2))


plt.figure(1)
plt.plot(z1*10**3,B1,'bs',z2*10**3,B2,'r^')
plt.ylabel('Field Magnitude (T)')
plt.xlabel('Position (mm)')
plt.title('Mag. field distribution for two neighboring traps')
plt.show()


I1=np.concatenate((I(0),np.zeros(np.int(t_sampling/2))),0)
I2=np.concatenate((np.zeros(np.int(t_sampling/2)),I(0)),0)
Bt1=Magfield(pos_back,I1,pos_front)
Bt2=Magfield(pos_back+space,I2,pos_front)
Btot=Bt1-Bt2
T=np.linspace(0,np.pi/2+np.pi,1.5*t_sampling)
plt.figure(2)
plt.subplot(211)
plt.plot(T,I1,'b-',T,I2,'g-')
plt.title('Current V.S. time for neiboring pulses')
plt.xlabel('time')
plt.ylabel('Current (A)')
plt.subplot(212)
plt.plot(T,abs(Bt1),'b-', T,abs(Bt2),'g-',T,abs(Btot),'r*')
plt.title('Field change with time for two neighboring pulse')
plt.xlabel('time')
plt.ylabel('Field(T)')
plt.show()



    # z = np.linspace(0,10*space,100)
    # Magfield=np.
    # for j in np.linspace(0,3,4):
    #     R = r+j*WireDia
    #     for k in np.linspace(0,3,4):
    #         p1=pos_front-1.5*WireDia+k*WireDia
    #         Magfield+=u*I*r**2/2/(((z-p1)**2+R**2)**(3/2))
    #         for s in np.linspace(0,1,2):
    #             p2=pos_back-0.5*WireDia*s*WireDia
    #             Magfield-=u*I*r**2/2/(((z-p2)**2+R**2)**(3/2))
    # Magfield=abs(Magfield)
    # return Magfield
