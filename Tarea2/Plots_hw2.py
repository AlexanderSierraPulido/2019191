import numpy as np
import matplotlib.pylab as plt

Euler = np.genfromtxt("Euler.txt",delimiter = ",")
Leap = np.genfromtxt("Leap_frog.txt",delimiter = ",")

plt.figure()
plt.plot(Euler[:,0],Euler[:,1])
plt.savefig("prueba")

plt.figure()
plt.plot(Leap[:,0],Leap[:,1])
plt.savefig("prueba2")