/* 
 * File:   main.cpp
 * Author: zackreynolt
 *
 * Created on 19 de diciembre de 2014, 16:34
 */

#define DEG2RAD  57.29577951

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

#include "Municipio.h"
#include "Provincia.h"
#include "Mallaregular.h"
#include "ControlDemografico.h"

using namespace std;

float distancia(float latitud1, float longitud1, float latitud2, float longitud2) {
    double dist = sin(latitud1 / DEG2RAD) * sin(latitud2 / DEG2RAD)
            + cos(latitud1 / DEG2RAD) * cos(latitud2 / DEG2RAD)
            * cos(longitud2 / DEG2RAD - longitud1 / DEG2RAD);
    return (float) (acos(dist) * 6370.94690683);
}

void cargaFichero(ControlDemografico &cd) {
    try {
        // Opens a file
        fstream fi("municipios.txt");
        string line, atributo[8];
        int contador = 0;

        while (!fi.eof()) {
            getline(fi, line);
            if (contador > 0 && contador < 8)
                atributo[contador] = line;
            
            if (contador == 8) {
                map<string, Provincia>::iterator it = cd.lista_provincias.find(atributo[1]);
                if (it == cd.lista_provincias.end()) {
                    pair<string, Provincia> p(atributo[1], Provincia(atributo[1]));
                    cd.lista_provincias.insert(p);
                    it = cd.lista_provincias.find(atributo[1]);
                }
                
                float latitud   = atof(atributo[3].c_str());
                float longitud  = atof(atributo[4].c_str());
                float altitud   = atof(atributo[5].c_str());
                int habit       = atoi(atributo[6].c_str());
                Municipio *municipio = new Municipio(atributo[2], latitud, longitud, altitud, habit);
                it->second.lista_municipios.push_back(municipio);
                cd.malla_municipios.insertarDato(latitud, longitud, municipio);
                
                pair<string, Municipio*> q(atributo[2], municipio);
                cd.lista_municipios.insert(q);
                contador = 0;
            } else
                contador++;
        }
        fi.close();
    } catch (exception &e) {
        cout << "The file could not be open";
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    // 27.6254357, -18.3726917
    // 43.8321591, 4.3428536
    ControlDemografico cd(27.6254357, -18.3726917, 43.8321591, 4.3428536, 45);
    cargaFichero(cd);
    
    float coor1, coor2;
    
    // Coordenadas de Peal
    coor1 = 37.91332;
    coor2 = -3.121655;
    
    cout << "Número de habitantes para las coordinadas " << coor1 << ", "
            << coor2 << ": ";
    cout << cd.habitantesPorZona(coor1,coor2) << endl;
    
    cout << "Número de habitantes para el municipio Peal de Becerro: ";
    cout << cd.habitantesPorZona("Peal de Becerro");
    
    return 0;
}

