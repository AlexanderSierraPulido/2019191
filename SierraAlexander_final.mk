all : Canal.png filtro.pdf
 

Canal.png :  SierraAlexander_canal_ionico.py
    python SierraAlexander_canal_ionico.py

filtro.pdf : SierraAlexander_Fourier.py
    python SierraAlexander_Fourier.py
    
