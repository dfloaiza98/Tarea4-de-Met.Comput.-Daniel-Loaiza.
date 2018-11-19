###--- Archivo makefile. Daniel Loaiza cod=201615258. Tarea4 Metodos Computacionales 2018-2 ---##


#Se espera que la siguiente orden genere un archivo pdf basado en el archivo.txt
Resultados_hw4.pdf: Resultados_hw4.tex
	pdflatex Resultados_hw4.tex
#Este archivo.txt guarda las posiciones en x,y para un angulo de 45 grados. 
datostrayectoria.txt: ODE.cpp
	g++ ODE.cpp
	./a.out
#Este archivo.txt contiene los pares de coordenadas x,y (posiciones) para angulos de 10,20,30,...,70 grados.
datosangulo.txt: ODE.cpp
	g++ ODE.cpp
	./a.out
#Este archivo.txt guarda todo lo necesario para graficar la barra de calcita.
datosPDE.txt: PDE.cpp
	g++ PDE.cpp
	./a.out
