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
