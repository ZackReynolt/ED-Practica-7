/* 
 * File:   Mallaregular.h
 * Author: alf
 *
 * Created on December 16, 2013, 3:44 PM
 */

#ifndef MALLAREGULAR_H
#define	MALLAREGULAR_H

#include <stdexcept>
#include <vector>
#include <list>

using namespace std;

template<class T>
class Casilla{
public:
    list<T> puntos;
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
    int nDatos;
    
    vector<vector<Casilla<T> > > mr;    //vector 2D de casillas
    
    Casilla<T>* obtenerCasilla (float x, float y);
    
public:
    MallaRegular (float aXMin, float aYMin, float aXMax, float aYMax, int aNDiv): 
                    xMin(aXMin), yMin(aYMin), xMax(aXMax), yMax(aYMax), nDatos(0), mr(aNDiv, vector<Casilla<T> >(aNDiv)) {
        tamaCasillaX = (xMax - xMin) / aNDiv;
        tamaCasillaY = (yMax - yMin) / aNDiv;
    };
    
    void insertarDato (float x, float y, T &dato);
    Casilla<T> *buscarDato (float x, float y, T& dato);
    Casilla<T> *borrarDato (float x, float y, T& dato);
    
    vector<T> buscarRango(float rxmin, float rymin, float rxmax, float rymax);    
};

template<class T>
vector<T> MallaRegular<T>::buscarRango(float rxmin, float rymin, float rxmax, float rymax) {
    vector<T> vectorMun;
    int imin = (rxmin - xMin) / tamaCasillaX;
    int jmin = (rymin - yMin) / tamaCasillaY;
    int imax = (rxmax - xMin) / tamaCasillaX;
    int jmax = (rymax - yMin) / tamaCasillaY;
    if (imin < 0 || imin > mr.size()) throw std::out_of_range("Posición fuera de rango");
    if (jmin < 0 || jmin > mr.size()) throw std::out_of_range("Posición fuera de rango");
    if (imax < 0 || imax > mr.size()) throw std::out_of_range("Posición fuera de rango");
    if (jmax < 0 || jmax > mr.size()) throw std::out_of_range("Posición fuera de rango");
    int i = imin, j = jmin;
   
    while (i <= imax) {
        while (j <= jmax) {
            vectorMun.push_back(mr[i][j].puntos);
            j++;
        }
    j = jmin;
    i++;
    }
    return vectorMun;
}

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
    nDatos++;
}

template<class T>
Casilla<T> *MallaRegular<T>::borrarDato(float x, float y, T& dato) {
    Casilla<T> *c = obtenerCasilla(x, y);
    if (c->borra(dato)) {
        nDatos--;
        return c;
    }
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

