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


//Esta lista guardara las coordenadas x y en y.
double listatxy[3001][3];
//Esta es la funcion que calculara 3000 coordenadas con la funcion que itera haciendo un promedio ponderado de las derivadas.
void runge_kutta1(float teta){
    int n=3000;
    
    listatxy[0][0]=0;
    listatxy[0][1]=v*cos(teta*(M_PI/180));
    listatxy[0][2]=v*sin(teta*(M_PI/180));
    for(int i=1;i<n;i++){
        listatxy[i][0]=i*h;
        listatxy[i][1]=iter((i-1)*h,listatxy[i-1][1], listatxy[i-1][2],true);
        listatxy[i][2]=iter((i-1)*h,listatxy[i-1][1], listatxy[i-1][2],false);
    }
    
}
int main(int argc, char** argv){
    runge_kutta1(45);
    ofstream datostrayectoria;
    datostrayectoria.open("datostrayectoria.txt");
    datostrayectoria << "t   vx   vy  x   y" << endl;
    float distancia45=0;
    double x=0,y=0;
    for(int i=0;i<3000;i++){
	datostrayectoria <<listatxy[i][0]<<","<<listatxy[i][1]<<","<<listatxy[i][2]<<","<<x<<","<<y<< endl;
	float xtemp = x;
	float ytemp=y;
        x=x+listatxy[i][1]*h;
	
        y=y+listatxy[i][2]*h;
	distancia45 += sqrt(pow((x-xtemp),2) + pow((y-ytemp),2));
	
	if(y<0){
	break;}     
	

    }

	cout << "La distancia recorrida para teta=45 es: " << distancia45 << " metros " << endl;
	datostrayectoria.close();
//Aqui se abre un archivo.txt que tendra los datos para distintos valores de teta.
    ofstream datosangulos;
    datosangulos.open("datosangulos.txt");
 
    int contador[7];
    float distancias[7];
    for(int i=0;i<7;i++){
	datosangulos << "EL, angulo,  es,  :," << (i+1)*10 << endl; 
	runge_kutta1((i+1)*10);
	double x=0,y=0;
	float distancia=0;
    	for(int k=0;k<3000;k++){
	datosangulos <<listatxy[k][0]<<","<<listatxy[k][1]<<","<<listatxy[k][2]<<","<<x<<","<<y<< endl;
	float xtemp = x;
	float ytemp=y;
        x=x+listatxy[k][1]*h;
	
	
        y=y+listatxy[k][2]*h;

	distancia += sqrt(pow((x-xtemp),2) + pow((y-ytemp),2));


	
	if(y<0){
	contador[i] = k;
	distancias[i] = distancia;
	break;}     
    }
    
  

	}
	//Las siguientes variables guardan un valor inicial para la mayor distancia y para el angulo. Que despues seran modificadas en el for subsiguiente.

        float mayor=0;
	int angulomayor=10;

   for(int i=0;i<7;i++){

	if(distancias[i]>mayor){
	
		mayor = distancias[i];
	        angulomayor = (i+1)*10;

	}

	
	}

	cout << "La distancia mayor recorrida es:" << mayor << " y se da para el angulo de: " << angulomayor<< endl;
	
	datosangulos << contador[0] <<"," << contador[1] <<"," << contador[2] <<"," << contador[3] <<"," << contador[4] <<","<< contador[5] <<"," << contador[6] <<"," << contador[7] <<"," << endl;

	datosangulos.close();
   

	
	

return 0;
}
