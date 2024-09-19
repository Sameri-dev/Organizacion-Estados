#ifndef ESTADOSQUICKSORT_H_INCLUDED
#define ESTADOSQUICKSORT_H_INCLUDED

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

// Función particion
int particion(vector<Estado>& estados, int inicio, int fin, bool (*comparar)(const Estado&, const Estado&)) {
    Estado pivote = estados[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (comparar(estados[j], pivote)) {
            i++;
            swap(estados[i], estados[j]);
        }
    }
    swap(estados[i + 1], estados[fin]);
    return i + 1;
}

// Función QuickSort
void quickSort(vector<Estado>& estados, int inicio, int fin, bool (*comparar)(const Estado&, const Estado&)) {
    if (inicio < fin) {
        int pi = particion(estados, inicio, fin, comparar);
        quickSort(estados, inicio, pi - 1, comparar);
        quickSort(estados, pi + 1, fin, comparar);
    }
}

//funcion de comparacion de 2  estados (PE)
bool PE(const Estado& a, const Estado& b) { //creacion de funcion utilizando los parametros de Estado a y Estado b, devuelve true si el numero de a es menor que el b
    return a.produccionEconomica < b.produccionEconomica; //comparacion entre a y b y devuelve el resultado
}

//funcion de comparacion de 2  estados (poblacion)
bool Poblacion(const Estado& a, const Estado& b) { //creacion de funcion utilizando los parametros de Estado a y Estado b, devuelve true si el numero de a es menor que el b
    return a.poblacion < b.poblacion; //comparacion entre a y b y devuelve el resultado
}

//funcion de comparacion de 2  estados (sector)
bool Sector(const Estado& a, const Estado& b) { //creacion de funcion utilizando los parametros de Estado a y Estado b, devuelve true si el numero de a es menor que el b
    return a.sector < b.sector;//comparacion entre a y b y devuelve el resultado
}

#endif // ESTADOSQUICKSORT_H_INCLUDED
