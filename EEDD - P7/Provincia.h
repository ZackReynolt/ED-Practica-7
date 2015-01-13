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
    vector<Municipio*> lista_provincias;
    
    
    Provincia          ();
    Provincia          (const Provincia& orig);
    virtual ~Provincia ();
    int habitantes() {
        int total_habitantes=0;
        
        //Suma de los habitantes de cada municipio
        for (int i = 0; i < lista_provincias.size(); ++i) {
            total_habitantes+=lista_provincias[i]->_habitantes;
        }
        
        return total_habitantes;
    };
    
private:

};

#endif	/* PROVINCIA_H */

