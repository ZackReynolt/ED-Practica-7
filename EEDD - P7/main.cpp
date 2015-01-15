/* 
 * File:   main.cpp
 * Author: zackreynolt
 *
 * Created on 19 de diciembre de 2014, 16:34
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

#include "Municipio.h"
#include "Provincia.h"
#include "Mallaregular.h"
#include "ControlDemografico.h"

using namespace std;

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
                
                if (municipio->_nombre == "Agaete")
                    cout << "Allande" << endl;
                cout << municipio->_nombre << endl;
                it->second.lista_municipios.push_back(municipio);
                cd.malla_municipios.insertarDato(latitud, longitud, municipio);
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
    

    map<string, Provincia>::iterator it = cd.lista_provincias.find("Córdoba");
    
    cout << "Provincia: " << it->first << endl;
    cout << "Municipios: " << it->second.lista_municipios.size() << endl;
    cout << it->second.nombre << endl;
    
    cout << "Cantidad de habitantes: " 
            << cd.habitantesPorProvincia(it->first) << endl;
    
    cout << "Cantidad total de provincias: " 
            << cd.lista_provincias.size() << endl;

    return 0;
}

