/* 
 * File:   Municipio.h
 * Author: alf
 *
 * Created on 12 de enero de 2015, 17:47
 */

#ifndef MUNICIPIO_H
#define	MUNICIPIO_H

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
    
    bool operator== (const Municipio& orig) {
        if (_nombre == orig._nombre && _lat == orig._lat && _long == orig._long)
            return true;
        return false;
    }
};

#endif	/* MUNICIPIO_H */

