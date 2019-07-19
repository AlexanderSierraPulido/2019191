import numpy as np
from matplotlib.colors import LogNorm
import matplotlib.pylab as plt

seria = plt.imread("cara_02_grisesMF.png")      ####### Se leen los datos
sonrie = plt.imread("cara_03_grisesMF.png")

FFT_seria = np.fft.fft2(seria)                  ####### Realizamos transformada y arreglo de frecuencias
FFT_sonrie = np.fft.fft2(sonrie)
Seria_freq = np.fft.fftshift(FFT_seria)
Sonrie_freq = np.fft.fftshift(FFT_sonrie)

plt.figure()
plt.subplot(1,2,1)
plt.imshow(abs(FFT_seria),plt.cm.gray, norm = LogNorm() )
plt.colorbar()
plt.title("Seria transformada")

plt.subplot(1,2,2)
plt.imshow(abs(FFT_sonrie),plt.cm.gray, norm = LogNorm() )
plt.colorbar()
plt.title("Sonrie transformada")
plt.savefig("FFtIm")


for i in range(254):
    for j in range(170):
        if(abs(FFT_seria[i,j]) <= 110 ):
            Seria_freq[i,j] = 0

for i in range(254):
    for j in range(170):
        if(abs(FFT_sonrie[i,j]) >= 45 ):
            Sonrie_freq[i,j] = 0          

Filtro_seria = np.fft.ifft2(FFT_seria)
Filtro_sonrie = np.fft.ifft2(FFT_sonrie)

plt.figure()
plt.subplot(2,2,1)
plt.imshow(abs(Filtro_seria),norm= LogNorm(),cmap='Greys')
plt.title("Seria Filtrada")

plt.subplot(2,2,2)
plt.imshow(abs(Filtro_sonrie),norm= LogNorm(),cmap='Greys')
plt.title("Sonrie Filtrada")

Filtro_seria_shift = np.fft.fftshift(Filtro_seria)
Filtro_sonrie_shift = np.fft.fftshift(Filtro_sonrie)

plt.subplot(2,2,3)
plt.imshow(abs(Filtro_seria_shift),norm= LogNorm())
plt.title("Espacio de amplitudes filtro seria")

plt.subplot(2,2,4)
plt.imshow(abs(Filtro_sonrie_shift),norm= LogNorm())
plt.title("Espacio de amplitudes filtro sonrie")
plt.savefig("ImProceso")

#Creando la imagen hibrida a partir de las imagenes filtradas anteriormente

Total = 0.75*Sonrie_freq + 2.5*Seria_freq

#Recuperando la imagen hibrida usando la transformada de Fourier inversa

Imag_hib = np.fft.ifft2(Total)

#Graficando la imagen hibrida 

plt.figure()
plt.imshow(-Imag_hib.real,cmap='Greys')
plt.title("Imagen Hibrida")
plt.savefig("Hibrida")