import numpy as np
import matplotlib.pylab as plt

Euler_1 = np.genfromtxt("Euler_0.005.txt",delimiter = ",")
Euler_2 = np.genfromtxt("Euler_0.0025.txt",delimiter = ",")
Euler_3 = np.genfromtxt("Euler_0.0005.txt",delimiter = ",")

Leap_1 = np.genfromtxt("Leap_0.005.txt",delimiter = ",")
Leap_2 = np.genfromtxt("Leap_0.0025.txt",delimiter = ",")
Leap_3 = np.genfromtxt("Leap_0.0005.txt",delimiter = ",")

RK_1 = np.genfromtxt("RK_0.005.txt",delimiter = ",")
RK_2 = np.genfromtxt("RK_0.0025.txt",delimiter = ",")
RK_3 = np.genfromtxt("RK_0.0005.txt",delimiter = ",")

plt.figure(figsize=(10,5))                     ####################### Grafica x contra y ########################
plt.subplot(3,3,1)
plt.plot(Euler_1[:,0],Euler_1[:,1])
plt.title("Euler_0.005")
plt.ylabel("y[UA]")

plt.subplot(3,3,2)
plt.plot(Leap_1[:,0],Leap_1[:,1])
plt.title("Leap_0.005")

plt.subplot(3,3,3)
plt.plot(RK_1[:,0],RK_1[:,1])
plt.title("RK_0.005")

plt.subplot(3,3,4)
plt.plot(Euler_2[:,0],Euler_2[:,1])
plt.title("Euler_0.0025")
plt.ylabel("y[UA]")

plt.subplot(3,3,5)
plt.plot(Leap_2[:,0],Leap_2[:,1])
plt.title("Leap_0.0025")

plt.subplot(3,3,6)
plt.plot(RK_2[:,0],RK_2[:,1])
plt.title("RK_0.0025")

plt.subplot(3,3,7)
plt.plot(Euler_3[:,0],Euler_3[:,1])
plt.xlabel("x[UA]")
plt.ylabel("y[UA]")
plt.title("Euler_0.0005")

plt.subplot(3,3,8)
plt.plot(Leap_3[:,0],Leap_3[:,1])
plt.xlabel("x[UA]")
plt.title("Leap_0.0005")

plt.subplot(3,3,9)
plt.plot(RK_3[:,0],RK_3[:,1])
plt.title("RK_0.0005")
plt.subplots_adjust(hspace=.5)
plt.xlabel("Vx[UA]")
plt.savefig("XY_met_dt.pdf")

plt.figure(figsize=(10,5))                     ####################### Grafica vx contra vy ########################
plt.subplot(3,3,1)
plt.plot(Euler_1[:,2],Euler_1[:,3])
plt.title("Euler_0.005")
plt.ylabel("Vy[UA/yr]")

plt.subplot(3,3,2)
plt.plot(Leap_1[:,2],Leap_1[:,3])
plt.title("Leap_0.005")

plt.subplot(3,3,3)
plt.plot(RK_1[:,2],RK_1[:,3])
plt.title("RK_0.005")

plt.subplot(3,3,4)
plt.plot(Euler_2[:,2],Euler_2[:,3])
plt.title("Euler_0.0025")
plt.ylabel("Vy[UA/yr]")

plt.subplot(3,3,5)
plt.plot(Leap_2[:,2],Leap_2[:,3])
plt.title("Leap_0.0025")

plt.subplot(3,3,6)
plt.plot(RK_2[:,2],RK_2[:,3])
plt.title("RK_0.0025")

plt.subplot(3,3,7)
plt.plot(Euler_3[:,2],Euler_3[:,3])
plt.xlabel("Vx[UA/yr]")
plt.ylabel("Vy[UA/yr]")
plt.title("Euler_0.0005")

plt.subplot(3,3,8)
plt.plot(Leap_3[:,2],Leap_3[:,3])
plt.xlabel("Vx[UA/yr]")
plt.title("Leap_0.0005")

plt.subplot(3,3,9)
plt.plot(RK_3[:,2],RK_3[:,3])
plt.title("RK_0.0005")
plt.subplots_adjust(hspace=.5)
plt.xlabel("Vx[UA/yr]")
plt.savefig("VxVy_met_dt.pdf")

plt.figure(figsize=(10,5))                     ####################### Grafica momento angular contra t ########################
plt.subplot(3,3,1)
plt.plot(Euler_1[:,6],Euler_1[:,4])
plt.title("Euler_0.005")
plt.ylabel("L[Kg*m^2/yr]")

plt.subplot(3,3,2)
plt.plot(Leap_1[:,6],Leap_1[:,4])
plt.title("Leap_0.005")

plt.subplot(3,3,3)
plt.plot(RK_1[:,6],RK_1[:,4])
plt.title("RK_0.005")

plt.subplot(3,3,4)
plt.plot(Euler_2[:,6],Euler_2[:,4])
plt.title("Euler_0.0025")
plt.ylabel("L[Kg*m^2/yr]")

plt.subplot(3,3,5)
plt.plot(Leap_2[:,6],Leap_2[:,4])
plt.title("Leap_0.0025")

plt.subplot(3,3,6)
plt.plot(RK_2[:,6],RK_2[:,4])
plt.title("RK_0.0025")

plt.subplot(3,3,7)
plt.plot(Euler_3[:,6],Euler_3[:,4])
plt.xlabel("t[yr]")
plt.ylabel("L[Kg*m^2/yr]")
plt.title("Euler_0.0005")

plt.subplot(3,3,8)
plt.plot(Leap_3[:,6],Leap_3[:,4])
plt.xlabel("t[yr]")
plt.title("Leap_0.0005")

plt.subplot(3,3,9)
plt.plot(RK_3[:,6],RK_3[:,4])
plt.title("RK_0.0005")
plt.subplots_adjust(hspace=.5)
plt.xlabel("t[yr]")
plt.savefig("Mome_met_dt.pdf")

plt.figure(figsize=(10,5))                     ####################### Grafica Energia mecanica contra t ########################
plt.subplot(3,3,1)
plt.plot(Euler_1[:,6],Euler_1[:,5])
plt.title("Euler_0.005")
plt.ylabel("E_mecanica[N]")

plt.subplot(3,3,2)
plt.plot(Leap_1[:,6],Leap_1[:,5])
plt.title("Leap_0.005")

plt.subplot(3,3,3)
plt.plot(RK_1[:,6],RK_1[:,5])
plt.title("RK_0.005")

plt.subplot(3,3,4)
plt.plot(Euler_2[:,6],Euler_2[:,5])
plt.title("Euler_0.0025")
plt.ylabel("E_mecanica[N]")

plt.subplot(3,3,5)
plt.plot(Leap_2[:,6],Leap_2[:,5])
plt.title("Leap_0.0025")

plt.subplot(3,3,6)
plt.plot(RK_2[:,6],RK_2[:,5])
plt.title("RK_0.0025")

plt.subplot(3,3,7)
plt.plot(Euler_3[:,6],Euler_3[:,5])
plt.xlabel("t[yr]")
plt.ylabel("E_mecanica[N]")
plt.title("Euler_0.0005")

plt.subplot(3,3,8)
plt.plot(Leap_3[:,6],Leap_3[:,5])
plt.xlabel("t[yr]")
plt.title("Leap_0.0005")

plt.subplot(3,3,9)
plt.plot(RK_3[:,6],RK_3[:,5])
plt.title("RK_0.0005")
plt.subplots_adjust(hspace=.5)
plt.xlabel("t[yr]")
plt.savefig("Ener_met_dt.pdf")