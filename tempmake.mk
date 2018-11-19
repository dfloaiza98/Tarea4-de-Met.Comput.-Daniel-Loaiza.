trayectoria.dat: ODE.cpp
	g++ ODE.cpp
	./a.out

datosPDE.dat: PDE.cpp
	g++ PDE.cpp
	./a.out
