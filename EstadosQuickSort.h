#ifndef ESTADOSQUICKSORT_H_INCLUDED
#define ESTADOSQUICKSORT_H_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Estructura para datos del estado
struct Estado {
    string nombre;       // Nombre del estado
    int numeroEntidad;   // Número de entidad
    int produccionEconomica; // Producción económica
    int poblacion;       // Población
    int sector;          // Sector de actividad

    // Imprimir datos
    void imprimir() const {
        cout << "Estado: " << nombre 
             << ", Num. Entidad: " << numeroEntidad 
             << ", Producción Económica: " << produccionEconomica 
             << ", Población: " << poblacion 
             << ", Sector: " << sector << endl;
    }
};

// Función partición
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

// Funciones de comparación
bool PE(const Estado& a, const Estado& b) {
    return a.produccionEconomica < b.produccionEconomica;
}

bool Poblacion(const Estado& a, const Estado& b) {
    return a.poblacion < b.poblacion;
}

bool Sector(const Estado& a, const Estado& b) {
    return a.sector < b.sector;
}

// Función para cargar los estados desde un archivo
vector<Estado> cargarEstadosDesdeArchivo(const string& nombreArchivo) {
    vector<Estado> estados;
    ifstream archivo(nombreArchivo);
    
    if (!archivo) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return estados;
    }
    
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        Estado estado;
        string sectorStr;

        getline(ss, estado.nombre, ',');
        ss >> estado.numeroEntidad;
        ss.ignore(); // Ignora la coma
        ss >> estado.produccionEconomica;
        ss.ignore(); // Ignora la coma
        ss >> estado.poblacion;
        ss.ignore(); // Ignora la coma
        getline(ss, sectorStr, ',');
        estado.sector = stoi(sectorStr);
        
        estados.push_back(estado);
    }
    
    archivo.close();
    return estados;
}

// Main
int main() {
    vector<Estado> estados = cargarEstadosDesdeArchivo("estados.txt");

    int opcion; // Opción de ordenamiento
    cout << "Selecciona el criterio para ordenar:\n";
    cout << "1. Producción Económica\n";
    cout << "2. Población\n";
    cout << "3. Sector\n";
    cout << "Elige una opción (1-3): ";
    cin >> opcion;

    // Utilizando la función de QuickSort
    switch (opcion) {
        case 1:
            quickSort(estados, 0, estados.size() - 1, PE);
            break;
        case 2:
            quickSort(estados, 0, estados.size() - 1, Poblacion);
            break;
        case 3:
            quickSort(estados, 0, estados.size() - 1, Sector);
            break;
        default:
            cout << "Opción inválida." << endl;
            return 1;
    }

    // Mostrar los estados ordenados
    cout << "\nEstados ordenados:\n";
    for (const Estado& estado : estados) {
        estado.imprimir();
    }

    return 0;
}

#endif // ESTADOSQUICKSORT_H_INCLUDED

