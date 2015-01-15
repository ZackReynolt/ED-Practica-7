/* 
 * File:   Mallaregular.h
 * Author: alf
 *
 * Created on December 16, 2013, 3:44 PM
 */

#ifndef MALLAREGULAR_H
#define	MALLAREGULAR_H

#include <vector>
#include <list>

using namespace std;

template<class T>
class Casilla{
    list<T> puntos;
public:
    //friend class MallaRegular<T>;
    Casilla(): puntos() {};
    void inserta (T &dato) { puntos.push_back(dato); }
    bool busca (T &dato);
    bool borra (T &dato);
};

template<class T>
class MallaRegular {
    float xMin, yMin, xMax, yMax;       // tamaño real global
    float tamaCasillaX, tamaCasillaY;   // tamaño real de cada casilla
    
    vector<vector<Casilla<T> > > mr;    //vector 2D de casillas
    
    Casilla<T>* obtenerCasilla (float x, float y);
    
public:
    MallaRegular (float aXMin, float aYMin, float aXMax, float aYMax, int aNDiv): 
                    xMin(aXMin), yMin(aYMin), xMax(aXMax), yMax(aYMax),  mr(aNDiv, vector<Casilla<T> >(aNDiv)) {
        tamaCasillaX = (xMax - xMin) / aNDiv;
        tamaCasillaY = (yMax - yMin) / aNDiv;
    };
    
    void insertarDato (float x, float y, T &dato);
    Casilla<T> *buscarDato (float x, float y, T& dato);
    Casilla<T> *borrarDato (float x, float y, T& dato);
    
    vector<T> burcarRango(float rxmin, float rymin, float rxmax, float rymax);    
};

template<class T>
bool Casilla<T>::busca(T &dato) {
    typename list<T>::iterator it;
    it = puntos.begin();
    while (it != puntos.end()) {
        if (*it == dato)
            return true;
    }
    return false;
}

template<class T>
bool Casilla<T>::borra(T& dato) {
    typename list<T>::iterator it;
    it = puntos.begin();
    while (it != puntos.end()) {
        if (*it == dato) {
            puntos.erase(it);
            return true;
        }
    }
    return false;
}

template<class T>
Casilla<T> *MallaRegular<T>::obtenerCasilla (float x, float y) {
    int i = (x - xMin) / tamaCasillaX;
    int j = (y - yMin) / tamaCasillaY;
    return &mr[i][j];    
}

template<class T>
void MallaRegular<T>::insertarDato(float x, float y, T& dato) {
    Casilla<T> *c = obtenerCasilla (x, y);
    c->inserta(dato);
}

template<class T>
Casilla<T> *MallaRegular<T>::borrarDato(float x, float y, T& dato) {
    Casilla<T> *c = obtenerCasilla(x, y);
    if (c->borra(dato))
        return c;
    return 0;
}

template<class T>
Casilla<T> *MallaRegular<T>::buscarDato(float x, float y, T& dato) {
    Casilla<T> *c = obtenerCasilla(x, y);
    if (c->busca(dato))
        return c;
    return 0;
}
#endif	/* MALLAREGULAR_H */

