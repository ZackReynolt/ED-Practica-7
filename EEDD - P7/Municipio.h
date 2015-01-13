/* 
 * File:   Municipio.h
 * Author: alf
 *
 * Created on 12 de enero de 2015, 17:47
 */

#ifndef MUNICIPIOS_H
#define	MUNICIPIOS_H

using namespace std;

class Municipio {    
public:
    string  _nombre;
    float   _lat;
    float   _long;
    float   _altitud;
    int     _habitantes;
    
  
    int habitantes() {
        return _habitantes;
    }
};

#endif	/* MUNICIPIO_H */

