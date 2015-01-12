/* 
 * File:   provincia.h
 * Author: zackreynolt
 *
 * Created on 12 de enero de 2015, 17:45
 */

#ifndef PROVINCIA_H
#define	PROVINCIA_H

#include <string>
#include <vector>

using namespace std;

class provincia {   
public:
    string nombre;
    vector<Municipios*> lista_provincias;
    provincia();
    provincia(const provincia& orig);
    virtual ~provincia();
    int habitantes() {
        int total_habitantes=0;
        
        //Suma de los habitantes de cada municipio
        for (int i = 0; i < lista_provincias.end(); ++i) {
            total_habitantes+=lista_provincias[i].habitantes;
        }
        
        return total_habitantes;
    };
    
private:

};

#endif	/* PROVINCIA_H */

