//Punto2 de la tarea4 de metodos computacionales  2018-2. Daniel Francisco Loaiza Saavedra, cod= 201615258.

//Importacion de librerias.
#include <cstdlib>
#include <math.h>
#include <iostream>

//Constantes a ser utilizadas durante la solucion.
double g=10,m=0.2,c=0.2, v=300,h=0.01;

using namespace std;

//Metodo que calcula la norma de un vector dadas dos componentes que son la coordenada de x y y.
double norm(double ux,double uy){
    return (sqrt(ux*ux+uy*uy));
}


//Funcion para definir la ecuacion diferencial ordinaria. 
double f(double t, double ux,double uy, bool xx){
    double x=-c*norm(ux,uy)*ux/m, y=-g-c*norm(ux,uy)/m*uy;
    if(xx)return (x);
    return (y);
}

//Funcion que itera a la cual le entra por parametro el tiempo, velocidad en x , velocidad en y un booleano para saber si la funcion calculara la funcion anterior f en la coordenada x o en coordenada y.
double iter(double t, double ux,double uy,bool xx){
    double kx=f(t,ux,uy,true);
    double ky=f(t,ux,uy,false);
    double k2x= f(t+h/2,ux+1/2*h*kx,uy+1/2*h*ky ,true);
    double k2y= f(t+h/2,ux+1/2*h*kx,uy+1/2*h*ky ,false);
    double k3x= f(t+h/2,ux+1/2*h*k2x,uy+1/2*h*k2y ,true);
    double k3y= f(t+h/2,ux+1/2*h*k2x,uy+1/2*h*k2y ,false);
    double k4x= f(t+h/2,ux+1/2*h*k3x,uy+1/2*h*k3y ,true);
    double k4y= f(t+h/2,ux+1/2*h*k3x,uy+1/2*h*k3y ,false);
    if(xx) return (ux+h/6*(kx+2*k2x+2*k3x+k4x));
    return (uy+h/6*(ky+2*k2y+2*k3y+k4y));
}
int main(){


return 0;
}
