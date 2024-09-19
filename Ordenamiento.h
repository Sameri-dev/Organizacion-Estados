#ifndef ORDENAMIENTO_H_INCLUDED
#define ORDENAMIENTO_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//estructura para datos del estado
struct Estado {
    string nombre;       //name
    int numeroEntidad;        //num indice
    int produccionEconomica;  //produccion economica
    int poblacion;            //poblacion
    int sector;               //sector de actividad en numero

    //imprimir datos
    void imprimir() const {
        cout << "Estado: " << nombre //name
                  << ", Num. Entidad: " << numeroEntidad //num
                  << ", Produccion Economica: " << produccionEconomica //PE
                  << ", Poblacion: " << poblacion //poblacion
                  << ", Sector: " << sector << endl; //sector
    }
};

//funcion de comparacion de 2  estados (PE)
bool compararProduccionEconomica(const Estado& a, const Estado& b) { //creacion de funcion utilizando los parametros de Estado a y Estado b, devuelve true si el numero de a es menor que el b
    return a.produccionEconomica < b.produccionEconomica; //comparacion entre a y b y devuelve el resultado
}

//funcion de comparacion de 2  estados (poblacion)
bool compararPoblacion(const Estado& a, const Estado& b) { //creacion de funcion utilizando los parametros de Estado a y Estado b, devuelve true si el numero de a es menor que el b
    return a.poblacion < b.poblacion; //comparacion entre a y b y devuelve el resultado
}

//funcion de comparacion de 2  estados (sector)
bool compararSector(const Estado& a, const Estado& b) { //creacion de funcion utilizando los parametros de Estado a y Estado b, devuelve true si el numero de a es menor que el b
    return a.sector < b.sector;//comparacion entre a y b y devuelve el resultado
}


#endif // ORDENAMIENTO_H_INCLUDED
