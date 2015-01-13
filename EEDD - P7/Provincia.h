/* 
 * File:   provincia.h
 * Author: zackreynolt
 *
 * Created on 12 de enero de 2015, 17:45
 */

#ifndef PROVINCIA_H
#define	PROVINCIA_H

#include "Municipio.h"
#include <string>
#include <vector>

using namespace std;

class Provincia {   
public:
    string nombre;
    vector<Municipio*> lista_municipios;
    
    
    Provincia          (string nom): nombre(nom), lista_municipios() {};
    Provincia          (const Provincia& orig) {};
    virtual ~Provincia () {};
    int habitantes() {
        int total_habitantes=0;
        
        //Suma de los habitantes de cada municipio
        for (int i = 0; i < lista_municipios.size(); ++i) {
            total_habitantes += lista_municipios[i]->_habitantes;
        }
        
        return total_habitantes;
    };
    
    bool operator==(const Provincia &orig) {
        return nombre == orig.nombre;
    };
    
private:

};

#endif	/* PROVINCIA_H */

