#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main()
{
    //Daklaration der Variablen
    double a, b, uAnfang, vAnfang, u0, v0;
    double deltat = 0.001, endzeit = 100;
    double schrittzahl = endzeit/deltat;
    double uEuler[(int)schrittzahl], vEuler[(int)schrittzahl];
    for(int i=0;i<schrittzahl;i++){
	    uEuler[i]=0;
	    vEuler[i]=0;
    }
    //Einlesen von Parametern und Anfangswerten
    cout << "Parameter a: ";
    cin  >> a;
    cout << "Parameter b: ";
    cin  >> b;
    cout << "Anfangswert u: ";
    cin  >> u0;
    while(u0<=0){
	cout << "u muss immer Positiv sein" << endl;
	cout << "Anfangswert u: ";
        cin  >> u0;
    }
    cout << "Anfangswert v: ";
    cin  >> v0;
    while(v0<=0){
        cout << "v muss immer Positiv sein" << endl;
        cout << "Anfangswert v: ";
        cin  >> v0;
    }
    uEuler[0] = u0;
    vEuler[0] = v0;
    //Euler-Cauchy-Algorithmus
    for(double aktzeit=0; aktzeit<endzeit; aktzeit += deltat){
        
    } 

    return 0;
}
