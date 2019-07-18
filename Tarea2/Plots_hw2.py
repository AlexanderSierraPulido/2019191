import numpy as np
import matplotlib.pylab as plt

Euler_1 = np.genfromtxt("Euler_0.005.txt",delimiter = ",")
Leap_1 = np.genfromtxt("Leap_frog.txt",delimiter = ",")

plt.figure()
plt.plot(Euler_1[:,0],Euler_1[:,1])
plt.savefig("prueba")

plt.figure()
plt.plot(Leap_1[:,0],Leap_1[:,1])
plt.savefig("prueba2")