#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;


//Funktionen von u, bzw. v zur späteren Verwendung in den Algorithmen
double fu(double a, double u, double v){
    return a-u+u*u*v;
}

double fv(double b, double u, double v){
    return b-u*u*v;
}



int main()
{
    //Deklaration und Initialisierung der Variablen
    double a=0, b=0, u0=0, v0=0, two=2;
    double deltat = 0.001, endzeit = 100;
    double schrittzahl = endzeit/deltat;	//wenn schrittzahl>=1,000,000 gibt es einen Fehler, da zu wenig Speicherplatz für die folgenden Arrays
    double uEuler[(int)schrittzahl], vEuler[(int)schrittzahl], uRunge[(int)schrittzahl], vRunge[(int)schrittzahl];
    for(int i=0; i<schrittzahl; i++){
        uEuler[i] = 0;
        vEuler[i] = 0;
        uRunge[i] = 0;
        vRunge[i] = 0;
    }
    //Einlesen von Parametern und Anfangswerten
    //Wenn Nutzereingabe erwünscht: Schleife um Programm auskommentieren!

    while(a<=0){
    	cout << "Parameter a (>0): ";
    	cin  >> a;
    	if(a<=0)	//Klammern um einzeilige Schleifen sind Geschmackssache...
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
    //Wenn automatischer Schleifendurchlauf erwünscht: bis hier auskommentieren und den nächsten beiden Zeilen die Startwerte zuweisen
    /*
    u0=1;
    v0=1;
    */
    
    //Einsetzen der Startwerte in die erste Stelle des Arrays
    uEuler[0] = u0; 
    vEuler[0] = v0;
    uRunge[0] = u0;
    vRunge[0] = v0;
    
    /*
    //Schleife um verschiedene Parameter a und b automatisch zu bekommen
    //MUSS AUSKOMMENTIERT WERDEN, wenn Nutzereingabe erwünscht, da Parameter überschrieben werden!
    for(b=0.1;b<1;b+=0.1){
        for(a=0.1;a<1;a+=0.1){
    */        
            
            
            //Dateiname der Ausgabedatei aus Variablen zusammenbasteln
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
            
            //Datei öffnen und die ersten beiden Zeilen mit Beschriftungen und Parametern füllen
            ofstream out (dateiname.c_str());
            out << "#aktschritt \t uEuler \t vEuler \t uRunge \t vRunge" << endl;
            out << "# a=" << a << "\t b=" << b << "\t u0=" << u0 << "\t v0=" << v0 << endl;
            
            //Berechnung 
            for(int aktschritt=0; aktschritt<schrittzahl; aktschritt++){
                out << aktschritt*deltat << "\t";
                
                
                //Euler-Algorithmus
                uEuler[aktschritt+1]=uEuler[aktschritt]+(deltat*fu(a,uEuler[aktschritt],vEuler[aktschritt]));
                vEuler[aktschritt+1]=vEuler[aktschritt]+(deltat*fv(b,uEuler[aktschritt],vEuler[aktschritt]));
                out << uEuler[aktschritt] << "\t" << vEuler[aktschritt] << "\t";
                
                
                //Runge-Kutta 4. Ordnung
                double k1u = deltat*fu(a,uRunge[aktschritt],vRunge[aktschritt]);
                double k1v = deltat*fv(b,uRunge[aktschritt],vRunge[aktschritt]);
                double k2u = deltat*fu(a,uRunge[aktschritt]+k1u/two,vRunge[aktschritt]+k1v/two);
                double k2v = deltat*fv(b,uRunge[aktschritt]+k1u/two,vRunge[aktschritt]+k1v/two);
                double k3u = deltat*fu(a,uRunge[aktschritt]+k2u/two,vRunge[aktschritt]+k2v/two);
                double k3v = deltat*fv(b,uRunge[aktschritt]+k2u/two,vRunge[aktschritt]+k2v/two);
                double k4u = deltat*fu(a,uRunge[aktschritt]+k3u,vRunge[aktschritt]+k3v);
                double k4v = deltat*fv(b,uRunge[aktschritt]+k3u,vRunge[aktschritt]+k3v);
                uRunge[aktschritt+1]=uRunge[aktschritt]+(k1u+two*k2u+two*k3u+k4u)/6.;
                vRunge[aktschritt+1]=vRunge[aktschritt]+(k1v+two*k2v+two*k3v+k4v)/6.;
                
                out << uRunge[aktschritt] << "\t" << vRunge[aktschritt] << endl;
                //cout << uRunge[aktschritt+1]-uEuler[aktschritt+1] << "\t" << vRunge[aktschritt+1]-vEuler[aktschritt+1] << endl; // Ausgabe der Differenz von Runge zu Euler
                
                if(uRunge[aktschritt+1]<=0||vRunge[aktschritt+1]<=0){
                    cout << "Fehler im Runge-Kutta-Algorithmus! Negative u oder v" << endl << "Programm wird beendet" << endl;
                    aktschritt=schrittzahl;		//Unschöne Lösung, geht hübscher...
                }
                if(uEuler[aktschritt+1]<=0||vEuler[aktschritt+1]<=0)
                    cout << "Fehler im Euler-Algorithmus, negative u oder v" << endl;
                
            }
            out.close();
	    
	    //Automatisches erstellen einer Rahmendatei für Gnuplot und anschließendes plotten
            ofstream plot ("plot.gp");
            plot << "reset" << endl;
	    //plot << "set yrange [0:4]" << endl
	    plot<< "set title 'a" << a << " b=" << b << " u0=" << u0 << " v0=" << v0 << endl;
            plot << "p '" << dateiname.c_str() << "' u 1:4" << endl << "pause 10"; //Wenn das Fenster immer geöffnet bleiben soll, ist die 10 zu ersetzen mit -1
            plot.close();
            system("gnuplot plot.gp");
	    //Will man eine flüssigere "Animation" haben, empfiehlt es sich, erst nur die Berechnungen machen zu lassen und danach nur die Plots auszugeben
	
	/*
        } //Diese Klammern müssen beim automatischen Durchlauf einkommentiert sein
    }*/
 
    return 0;
}
