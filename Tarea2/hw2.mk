Resultados.pdf: latex
    pdf latex

Latex : Fourier.py Plots_hw2.py
    python Fourier.py 
    python Plots_hw2.py
    
Plots_hw2.py : datos.txt

datos.txt : ODEs.cpp
    g++ ODEs.cpp
    ./a.out
