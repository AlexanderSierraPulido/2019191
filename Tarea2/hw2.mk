Resultados_hw2.pdf : Resultados_hw2.tex 
    pdflatex Resultados_hw2.tex
    
Resultados_hw2.tex : Fourier.py Plots_hw2.py
    python Fourier.py 
    python Plots_hw2.py
    
Plots_hw2.py : ODEs.cpp
    g++ ODEs.cpp
    ./a.out
