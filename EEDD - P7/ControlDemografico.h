/* 
 * File:   ControlDemografico.h
 * Author: zackreynolt
 *
 * Created on 13 de enero de 2015, 12:59
 */

#ifndef CONTROLDEMOGRAFICO_H
#define	CONTROLDEMOGRAFICO_H

#include <map>
#include <string>

#include "Provincia.h"
#include "Municipio.h"
#include "Mallaregular.h"

using namespace std;

class ControlDemografico {
public:
    map<string, Provincia> lista_provincias;
    MallaRegular<Municipio*> malla_municipios;
    
    ControlDemografico          (float lat_min, float long_min, float lat_max, float long_max, int division ) : 
                                malla_municipios(lat_min, long_min, lat_max, long_max, division) {};
    //ControlDemografico          (const ControlDemografico& orig) {};
    virtual ~ControlDemografico () {};
    
    int habitantesPorZona       (float _lat, float _long) {
        int numHabitantes = 0;
        float distance;
        
        // Comprobar casillas que están a menos de 20Km
        
            // Sumar número de habitantes de municipios 
            // DENTRO de esas casillas, y a menos de 20Km
        
        return numHabitantes;
    };
    int habitantesPorZona       (string municipio) {};
    int habitantesPorProvincia  (string nombreProvincia) {
        int numHabitantes = 0;
        
        map<string, Provincia>::iterator it = this->lista_provincias.find(nombreProvincia);
        numHabitantes = it->second.habitantes();
        
        return numHabitantes;
    };
    
private:

};

#endif	/* CONTROLDEMOGRAFICO_H */

