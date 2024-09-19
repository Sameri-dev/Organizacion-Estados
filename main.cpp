#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include"Ordenamiento.h"

using namespace std;

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

