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
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include"QuickSort.h"

using namespace std;

//MAIN Utilizando QuickSort

int main() {
    vector<Estado> estados = { //creacion del vector de los Estados con nombre, indice, produccion economica (exportaciones por millones de US), poblacion, sector de actividad en numero
        {"Aguascalientes", 1, 31090, 1425607, 0}, //manufactura 5
        {"Baja California", 2, 52523, 3769020, 0}, // comercio al por menor
        {"Baja California Sur", 3, 519, 798447, 0}, //agricola
        {"Campeche", 4, 19074, 928363, 0}, //
        {"Chiapas", 5, 1462, 5543828, 0}, //
        {"Chihuahua", 6, 76580, 3741869, 0}, //
        {"CDMX", 7, 3518, 9209944, 0}, //
        {"Coahuila", 8, 60014, 3146771, 0}, //
        {"Colima", 9, 1111, 731391, 0}, //
        {"Durango", 10, 3027, 1832650, 0}, //
        {"Estado de Mexico", 11, 20457, 16992418, 0}, //
        {"Guanajuato", 12, 31754, 6166934, 0}, //
        {"Guerrero", 13, 1137, 3540685, 0}, //
        {"Hidalgo", 14, 3342, 3082841, 0}, //
        {"Jalisco", 15, 26862, 8348151, 0}, //
        {"Michoacan", 16, 6607, 4748846, 0}, //
        {"Morelos", 17, 2852, 1971520, 0}, //
        {"Nayarit", 18, 283, 1235456, 0}, //
        {"Nuevo Leon", 19, 53072, 5784442, 0}, //
        {"Oaxaca", 20, 1279, 4132148, 0}, //
        {"Puebla", 21, 19841, 6583278, 0}, //
        {"Queretaro", 22, 16713, 2368467, 0}, //
        {"Quintana Roo", 23, 65, 1857985, 0}, //exportaciones = 65.4
        {"San Luis Potosi", 24, 17801, 2822255, 0}, //
        {"Sinaloa", 25, 2949, 3026943, 0}, //
        {"Sonora", 26, 23866, 2944840, 0}, //
        {"Tabasco", 27, 11348, 2402598, 0}, //
        {"Tamaulipas", 28, 0, 3527735, 0}, //exportaciones no dadas (buscar)
        {"Tlaxcala", 29, 2177, 1342977, 0}, //
        {"Veracruz", 30, 8822, 8062579, 0}, //exportaciones no dadas
        {"Yucatan", 31, 1646, 2320898, 0}, //
        {"Zacatecas", 32, 3585, 1622138, 0} //
    };

    int opcion; //creacion de la var opcion para que el usuario seleccione el ordenamiento

    cout << "Selecciona el criterio para ordenar:\n"; //instrucciones
    cout << "1. Produccion Economica\n"; //PE
    cout << "2. Poblacion\n"; // Poblacion
    cout << "3. Sector\n"; //sectores
    cout << "Elige una opcion (1-3): "; //eleccion
    cin >> opcion; //se guarda la var opcion

//utilizando la funcion de QuickSort se acomodan los estados
    switch (opcion) { //utilizando switch para mas facil y la opcion dada por el usuario
        case 1: //caso 1 PE
            quickSort(estados, 0, estados.size() - 1, PE);
            break;
        case 2: //caso 2 poblacion
            quickSort(estados, 0, estados.size() - 1, Poblacion);
            break;
        case 3: //Sector
            quickSort(estados, 0, estados.size() - 1, Sector);
            break;
        default:
            cout << "Opción inválida." << endl;
            return 1;
    }

    //Se muestran los estados ordenados
    cout << "\nEstados ordenados:\n";
    for (const Estado& estado : estados) {
        estado.imprimir();
    }

    return 0;
}

#endif // ESTADOSQUICKSORT_H_INCLUDED
