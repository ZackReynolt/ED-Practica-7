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
    
    Municipio           (string nombre, float lat, float longi, float alt, int habit) :
                        _nombre(nombre) , _lat(lat), _long(longi), _altitud(alt), _habitantes(habit) {};
    virtual ~Municipio  () {};
  
    int habitantes      () {
        return _habitantes;
    }
    
    bool operator== (const Municipio& orig) {
        if (_nombre == orig._nombre && _lat == orig._lat && _long == orig._long)
            return true;
        return false;
    }
};

#endif	/* MUNICIPIO_H */

