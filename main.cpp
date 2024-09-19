#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include"Ordenamiento.h"

using namespace std;

int main() {
    vector<Estado> estados = { //creacion del vector de los Estados con nombre, indice, produccion economica, poblacion, sector de actividad en numero
        {"CDMX", 1, 5000000, 9209944, 2},
        {"Jalisco", 2, 4500000, 8341680, 1},
        {"Nuevo Leon", 3, 4000000, 5917744, 3},
        {"Guanajuato", 4, 3500000, 6166317, 4},
        {"Puebla", 5, 3000000, 5479680, 5}
    };

    int opcion; //creacion de la var opcion para que el usuario seleccione el ordenamiento

    cout << "Selecciona el criterio para ordenar:\n"; //instrucciones
    cout << "1. Produccion Economica\n"; //PE
    cout << "2. Poblacion\n"; // Poblacion
    cout << "3. Sector\n"; //sectores
    cout << "Elige una opcion (1-3): "; //eleccion
    cin >> opcion; //se guarda la var opcion

    //para ordenar de acuerdo a opcion seleccionada
    switch (opcion) { //utilizamos switch para que sea mas rapido
        case 1: //caso 1 PE
            sort(estados.begin(), estados.end(), compararProduccionEconomica); //utilizando sort y la funcion de compararPorProduccionEconomica
            break;
        case 2: //caso 3 poblacion
            sort(estados.begin(), estados.end(), compararPoblacion); //utilizando sort y la funcion de compararPorPoblacion
            break;
        case 3://caso 2 sector
            sort(estados.begin(), estados.end(), compararSector);//utilizando sort y la funcion de compararPorSector
            break;
        default: //sino
            cout << "Opcion no valida." << std::endl; //opcion no valida
            return 1;
    }

    //mostrar los datos ya ordenados
    cout << "\nDatos ordenados:\n\n";
    for (const auto& estado : estados) {
        estado.imprimir();
        }
}
