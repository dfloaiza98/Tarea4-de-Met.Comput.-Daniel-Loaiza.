##Daniel Loaiza, cod= 201615258.
##Script de python que recibe dos archivos.txt generados por ODE.cpp para plotear la trayectoria para teta=45 y para teta=10,20,30,...,70.

##Importacion de librerias
import numpy as np
import matplotlib.pyplot as plt

#Obtencion y clasificacion de datos para los valores de movimiento de proyecto de los angulo 45 
datos = np.genfromtxt("datostrayectoria.txt",dtype=None,delimiter=",",skip_header=1)
datosTi= datos[:,0]
datosDx= datos[:,3]
datosDy= datos[:,4]
datosVx= datos[:,1]
datosVy= datos[:,2]


##Figura que contiene el movimiento del proyectil para el angulo de 45 grados.
plt.figure()
plt.plot(datosDx,datosDy,color="red",label="Angulo = 45 grados")
plt.title("Movimiento del proyectil")
plt.ylabel("Posicion en y[m]")
plt.xlabel("Posicion en x[m]")
plt.legend()
plt.show()
plt.savefig("Movimientoparaangulode45grados.pdf")

##Variable para guardar los valores para distintos angulos  y luego graficar.
datosangulos = np.genfromtxt("datosangulos.txt",dtype=None,delimiter=",",skip_footer=1)
contadores= np.genfromtxt("datosangulos.txt",dtype=None,delimiter=",",skip_header=len(datosangulos))[0:-1]

##Las siguientes listas vacias seran usadas para guardar los valores de distancia en x y distancia en y asociados a los distintos valores de teta.
datosDx10= []
datosDy10= []
datosDx20= []
datosDy20= []
datosDx30= []
datosDy30= []
datosDx40= []
datosDy40= []
datosDx50= []
datosDy50= []
datosDx60= []
datosDy60= []
datosDx70= []
datosDy70= []

k=1
l= contadores[0]+2
for j in range(k,l):
	datosDx10.append(float(datosangulos[j][3]))
	datosDy10.append(float(datosangulos[j][4]))
k=1 +l
l= contadores[1]+contadores[0]+4
for j in range(k,l):
	datosDx20.append(float(datosangulos[j][3]))
	datosDy20.append(float(datosangulos[j][4]))
k=1 + l
l= contadores[0]+ contadores[1] + contadores[2]+6
for j in range(k,l):
	datosDx30.append(float(datosangulos[j][3]))
	datosDy30.append(float(datosangulos[j][4]))
k=1 + l
l= contadores[0]+ contadores[1] + contadores[2]+  contadores[3]+8
for j in range(k,l):
	datosDx40.append(float(datosangulos[j][3]))
	datosDy40.append(float(datosangulos[j][4]))
k=1 + l
l= contadores[0]+ contadores[1] + contadores[2]+ contadores[3]+contadores[4]+ 10
for j in range(k,l):
	datosDx50.append(float(datosangulos[j][3]))
	datosDy50.append(float(datosangulos[j][4]))
k=1 + l
l= contadores[0]+ contadores[1] + contadores[2]+ contadores[3]+contadores[4]+ contadores[5]+12
for j in range(k,l):
	datosDx60.append(float(datosangulos[j][3]))
	datosDy60.append(float(datosangulos[j][4]))
k=1+l
l= contadores[0]+ contadores[1] + contadores[2]+ contadores[3]+contadores[4]+ contadores[5]+contadores[6]+14
for j in range(k,l):
	datosDx70.append(float(datosangulos[j][3]))
	datosDy70.append(float(datosangulos[j][4]))


plt.figure()
plt.title("Movimiento del proyectil para distintos angulos")
plt.plot(datosDx10,datosDy10,label="10")
plt.plot(datosDx20,datosDy20,label="20")
plt.plot(datosDx30,datosDy30,label="30")
plt.plot(datosDx40,datosDy40,label="40")
plt.plot(datosDx50,datosDy50,label="50")
plt.plot(datosDx60,datosDy60,label="60")
plt.plot(datosDx70,datosDy70,label="70")
plt.ylabel("Posicion en y[m]")
plt.xlabel("Posicion en x[m]")
plt.legend(loc="best")
plt.savefig("Desplazamientoproyectilvariosangulos.pdf")

