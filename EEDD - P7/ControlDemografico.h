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
    map<string, Municipio*> lista_municipios;
    MallaRegular<Municipio*> malla_municipios;
    
    ControlDemografico          (float lat_min, float long_min, float lat_max, float long_max, int division ) : 
                                malla_municipios(lat_min, long_min, lat_max, long_max, division) {};
    //ControlDemografico          (const ControlDemografico& orig) {};
    virtual ~ControlDemografico () {};
    
    int habitantesPorZona       (float _lat, float _long) {
        // 30 Km = 0,269978402
        float rango = 0.269978402;
        int numHabitantes = 0;
        vector<Municipio*> listaMuni;
        
        // Obtener los municipios que están a menos de 30 Km
//        listaMuni = malla_municipios.burcarRango(_lat-rango, _long-rango, 
//                                                 _lat+rango, _long+rango);
        
        for (int i = 0; i < listaMuni.size(); ++i )
            numHabitantes+= listaMuni[i]->habitantes();
        
        return numHabitantes;
    };
    int habitantesPorZona       (string municipio) {
        float _lat, _long;
        map<string, Municipio*>::iterator it = this->lista_municipios.find(municipio);
        
        _lat = it->second->_lat;
        _long = it->second->_long;
        
        return habitantesPorZona(_lat, _long);
    };
    int habitantesPorProvincia  (string nombreProvincia) {
        int numHabitantes = 0;
        
        map<string, Provincia>::iterator it = this->lista_provincias.find(nombreProvincia);
        numHabitantes = it->second.habitantes();
        
        return numHabitantes;
    };
    
private:

};

#endif	/* CONTROLDEMOGRAFICO_H */

