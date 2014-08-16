#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;


//Funktionen von u, bzw. v
double fu(double a, double u, double v){
	return a-u+u*u*v;
}

double fv(double b, double u, double v){
	return b-u*u*v;
}



int main()
{
    //Deklaration und Initialisierung der Variablen
    double a=0, b=0, u0=0, v0=0;
    double deltat = 0.001, endzeit = 100;
    double schrittzahl = endzeit/deltat;
    double uEuler[(int)schrittzahl], vEuler[(int)schrittzahl], uRunge[(int)schrittzahl], vRunge[(int)schrittzahl];
    for(int i=0; i<schrittzahl; i++){
	    uEuler[i] = 0;
	    vEuler[i] = 0;
	    uRunge[i] = 0;
	    vRunge[i] = 0;
    }
    //Einlesen von Parametern und Anfangswerten
    while(a<=0){
	cout << "Parameter a (>0): ";
	cin  >> a;
	if(a<=0)
		cout << "a muss immer Positiv sein!" << endl;
    }
    while(b<=0){
	cout << "Parameter b (>0): ";
	cin  >> b;
	if(b<=0)
		cout << "b muss immer Positiv sein!" << endl;
    }
    while(u0<=0){
	cout << "Anfangswert u (>0): ";
	cin  >> u0;
	if(u0<=0)
		cout << "u muss immer positiv sein!" << endl;
    }
    while(v0<=0){
        cout << "Anfangswert v (>0): ";
        cin  >> v0;
	if(v0<=0)
		cout << "v muss immer Positiv sein!" << endl;
    }
    uEuler[0] = u0;
    vEuler[0] = v0;
    uRunge[0] = u0;
    vRunge[0] = v0;

    b=0.7;
    for(a=0.1;a<1;a+=0.1){


    string dateiname, as, bs, us, vs;
    stringstream ass, bss, uss, vss;
    ass << a;
    bss << b;
    uss << u0;
    vss << v0;
    as= ass.str();
    bs = bss.str();
    us= uss.str();
    vs = vss.str();
    dateiname = "a" + as + "b" + bs + "u" + us + "v" + vs + ".dat";

    ofstream out (dateiname.c_str());
    out << "#aktschritt \t uEuler \t vEuler \t uRunge \t vRunge" << endl;
    out << "# a=" << a << "\t b=" << b << "\t u0=" << u0 << "\t v0=" << v0 << endl; 
    for(int aktschritt=0; aktschritt<schrittzahl; aktschritt++){
        out << aktschritt*deltat << "\t";


		//Euler-Cauchy-Algorithmus
	uEuler[aktschritt+1]=uEuler[aktschritt]+(deltat*fu(a,uEuler[aktschritt],vEuler[aktschritt]));
	vEuler[aktschritt+1]=vEuler[aktschritt]+(deltat*fv(b,uEuler[aktschritt],vEuler[aktschritt]));
	out << uEuler[aktschritt] << "\t" << vEuler[aktschritt] << "\t";
    	

		//Runge-Kutta 4. Ordnung
	double k1u = deltat*fu(a,uRunge[aktschritt],vRunge[aktschritt]);
	double k1v = deltat*fv(b,uRunge[aktschritt],vRunge[aktschritt]);
	double k2u = deltat*fu(a,uRunge[aktschritt]+k1u/2.,vRunge[aktschritt]+k1v/2.);
	double k2v = deltat*fv(b,uRunge[aktschritt]+k1u/2.,vRunge[aktschritt]+k1v/2.);
	double k3u = deltat*fu(a,uRunge[aktschritt]+k2u/2.,vRunge[aktschritt]+k2v/2.);
	double k3v = deltat*fv(b,uRunge[aktschritt]+k2u/2.,vRunge[aktschritt]+k2v/2.);
	double k4u = deltat*fu(a,uRunge[aktschritt]+k3u,vRunge[aktschritt]+k3v);
	double k4v = deltat*fv(b,uRunge[aktschritt]+k3u,vRunge[aktschritt]+k3v);
	uRunge[aktschritt+1]=uRunge[aktschritt]+(k1u+2*k2u+2*k3u+k4u)/6.;
	vRunge[aktschritt+1]=vRunge[aktschritt]+(k1v+2*k2v+2*k3v+k4v)/6.;
	
	out << uRunge[aktschritt] << "\t" << vRunge[aktschritt] << endl;
   	//cout << uRunge[aktschritt+1]-uEuler[aktschritt+1] << "\t" << vRunge[aktschritt+1]-vEuler[aktschritt+1] << endl; 
    }
    } 

    return 0;
}
