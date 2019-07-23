import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

x = np.genfromtxt("Canal_ionico.txt",delimiter = "\t",usecols = 0)
y = np.genfromtxt("Canal_ionico.txt",delimiter = "\t",usecols = 1)

rad_max = []
centro_x = []
centro_y = []
for i in range(1000):
    c_x = np.random.uniform(-5,15)
    c_y = np.random.uniform(-5,15)
    centro_x.append(c_x)
    centro_y.append(c_y)
    mejor = 50
    for j in range(len(x)):
        distancia = (abs(np.sqrt((x[j]-c_x)**2 + (y[j]-c_y)**2)))
        if(distancia<mejor):
            mejor = distancia
    rad_max.append(mejor)

pos = np.argmax(rad_max)

plt.figure()
fig, ax = plt.subplots()
plt.axis('equal')
circle1 = plt.Circle((centro_x[pos],centro_y[pos]), rad_max[pos] , color='r',fill=False)
ax.add_artist(circle1)
plt.scatter(x,y)
plt.savefig("Canal.png")


#plt.savefig("lalalalalalala.png")
#plt.close()