/* 
 * File:   ControlDemografico.h
 * Author: zackreynolt
 *
 * Created on 13 de enero de 2015, 12:59
 */

#ifndef CONTROLDEMOGRAFICO_H
#define	CONTROLDEMOGRAFICO_H

#include <vector>
#include <string>

#include "Provincia.h"
#include "Municipio.h"
#include "Mallaregular.h"

using namespace std;

class ControlDemografico {
public:
    vector<Provincia> lista_provincias;
    MallaRegular<Municipio> malla_municipios;
    
    ControlDemografico          ();
    ControlDemografico          (const ControlDemografico& orig) {};
    virtual ~ControlDemografico () {};
    
    int habitantesPorZona       (float _lat, float _long) {};
    int habitantesPorZona       (string municipio) {};
    int habitantesPorProvincia  (string nombreProvincia) {
        int numHabitantes = 0;
        for (int i = 0; i < lista_provincias.size(); ++i) {
            if (lista_provincias[i].nombre == nombreProvincia)
                numHabitantes = lista_provincias[i].habitantes();
        }
        
        return numHabitantes;
    };
    
private:

};

#endif	/* CONTROLDEMOGRAFICO_H */

