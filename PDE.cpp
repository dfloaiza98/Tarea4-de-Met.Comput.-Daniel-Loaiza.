//

#include <vector>
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
float c=820, k=1.62,p=2.71,d=10;
int static n=1024;
float h=50/n;
float v=k/(c*p);
float T[1024][1024][500];
float dt=0.1;
vector <vector <float> > coords1[4];
vector <vector <float> > coords2[4];
vector <vector <float> > coords3[4];
vector <vector <float> > coords4[4];
/*
 * 
 */
void Tn(int i,int  j,int  k){
    float pond=T[i][j-1][k]+T[i-1][j][k]-4*T[i][j][k]+T[i+1][j][k]+T[i][j+1][k];
    pond=pond/pow(h,2);
    T[i][j][k+1]=(T[i][j][k]+dt*v*(pond));
}
/*vector <float> postime(int i, int j, int k){
    int m=n/2;
    float t=dt*k;
    vector <float> coord[4]={t,(i-m)*h,(j-m)*h};
    return (coord);
}*/

//Esta funcion es para saber si el punto esta dentro o fuera del circulo.
bool isin(float x, float y){
    return((pow(x,2)+pow(y,2))<=25);
}
float Temp(float x, float y,float t){
    int i=x/h+n/2, j=y/h+n/2, k=t/dt;
    return (T[i][j][k]);
}
int main(int argc, char** argv) {

//El siguiente ciclo con ayuda de la funcion isin llena el arreglo t con 100 grados centigrados si el punto se encuentra dentro del circulo o con 10 grados centigrados si el punto se encuentra por fuera del circulo.
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(isin((i-n/2)*h,(j-n/2)*h))T[i][j][0]=100;
            else T[i][j][0]=10;
        }
    }
    int l=n-1;
    for(int k=0;k<l;k++){
        for(int i=1;i<l;i++){
            for (int j=1;j<l;j++){
                if(isin((i-n/2)*h,(j-n/2)*h)){
                    T[i][j][k]=100;
                }
                else {
                    Tn(i,j,k);
                }
            }
        }
    }
    
    return 0;
}

