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

void cargaFichero() {
    try {
        // Opens a file
        fstream fi("municipios.txt");
        string line, atributo[6];
        int contador = 1;

        while (!fi.eof()) {
            if (contador > 1 && contador < 8) {
                atributo[contador] = line;
            }
            
            if (contador == 9) {
                
                contador = 1;
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
    
    ControlDemografico cd;
    cargaFichero();

    return 0;
}

