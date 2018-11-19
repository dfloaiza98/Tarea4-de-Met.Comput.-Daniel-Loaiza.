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

