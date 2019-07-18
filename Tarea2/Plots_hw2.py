import numpy as np
import matplotlib.pylab as plt

Euler = np.genfromtxt("Euler.txt",delimiter = ",")
plt.figure()
plt.plot(Euler[:,0],Euler[:,1])
plt.savefig("prueba")
