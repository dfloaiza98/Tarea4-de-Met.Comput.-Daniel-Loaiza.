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
int main(){


return 0;
}
