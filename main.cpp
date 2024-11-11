#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//estructura datos estado
struct Estado {
    string nombre;               //Nombre
    int indice;                  //indice
    double produccionEconomica;  //produccion economica en millones de US
    int poblacion;               //poblacion
    int sector;                  //sectore economico

    //imprimir info estado en archivo
    void imprimir(ofstream& outputFile) const {
        outputFile << nombre << " - Producción Económica: " << produccionEconomica << " millones de US\n";
    }

    //imprimir infor estado en consola
    void imprimir(ostream& os) const {
        os << nombre << " - Producción Económica: " << produccionEconomica << " millones de US\n";
    }
};

//leer datos desde archivo de texto
bool leerDatosDesdeArchivo(const string& archivo, vector<Estado>& estados) {
    ifstream inputFile(archivo);  //abrimosarchivo en modo lectura
    if (!inputFile) {  //si no se pudo abrir el archivo, mostramos error
        cout << "No se pudo abrir el archivo " << archivo << endl;
        return false;
    }

    string linea;
    while (getline(inputFile, linea)) {  //leemos linea por linea
        stringstream ss(linea);  //creamos un stringstream para separar cada línea por comas
        Estado estado;
        string campo;

        //leemos cada campo y los asignamos a las variables del struct
        getline(ss, estado.nombre, ',');
        getline(ss, campo, ',');
        estado.indice = stoi(campo);  //convertimos el campo a entero
        getline(ss, campo, ',');
        estado.produccionEconomica = stod(campo);  //convertimos a double
        getline(ss, campo, ',');
        estado.poblacion = stoi(campo);  //convertimos a entero
        getline(ss, campo, ',');
        estado.sector = stoi(campo);  //convertimos a entero

        estados.push_back(estado);  //agregamos el estado al vector
    }

    inputFile.close();  //cerramos el archivo
    return true;
}

//guardar resultados en un archivo
void guardarResultados(const string& archivo, const vector<Estado>& estados, int opcion, double resultado) {
    ofstream outputFile(archivo, ios::app);  //abrimos el archivo en modo append

    if (!outputFile) {  //si no se pudo abrir el archivo, mostramos error
        cout << "No se pudo abrir el archivo " << archivo << endl;
        return;
    }

    //dependiendo de eleccion guardamos el resultado
    switch (opcion) {
        case 4:
            outputFile << "Media: " << resultado << "\n\n";
            break;
        case 5:
            outputFile << "Mediana: " << resultado << "\n\n";
            break;
        case 6:
            outputFile << "Moda: " << resultado << "\n\n";
            break;
        case 7:
            outputFile << "Rango de Variación: " << resultado << "\n\n";
            break;
        case 8:
            outputFile << "Varianza: " << resultado << "\n\n";
            break;
        case 9:
            outputFile << "Desviación Estándar: " << resultado << "\n\n";
            break;
        case 10:
            outputFile << "Coeficiente de Variación: " << resultado << "%\n\n";
            break;
        default:
            break;
    }

    //si se ha ordenado guardamos los resultados
    if (opcion >= 1 && opcion <= 3) {
        outputFile << "\nDatos ordenados:\n";
        for (const auto& estado : estados) {
            estado.imprimir(outputFile);
        }
        outputFile << "\n";  //linea en blanco al final
    }

    outputFile.close();
}

//media
double calcularMedia(const vector<Estado>& estados) {
    double suma = 0;
    for (const auto& estado : estados) {
        suma += estado.produccionEconomica;
    }
    return suma / estados.size();
}

//mediana
double calcularMediana(vector<Estado>& estados) {
    //ordenamos produccion economica
    sort(estados.begin(), estados.end(), [](const Estado& a, const Estado& b) {
        return a.produccionEconomica < b.produccionEconomica;
    });

    int n = estados.size();
    if (n % 2 == 0) {  //si num de elementos es par
        return (estados[n / 2 - 1].produccionEconomica + estados[n / 2].produccionEconomica) / 2.0;
    } else {  //si impar
        return estados[n / 2].produccionEconomica;
    }
}

//moda
double calcularModa(const vector<Estado>& estados) {
    map<double, int> frecuencias;
    //contamos veces roduccion economica
    for (const auto& estado : estados) {
        frecuencias[estado.produccionEconomica]++;
    }

    double moda = 0;
    int maxFrecuencia = 0;
    //buscamos num con mayor frecuencia
    for (const auto& [valor, frecuencia] : frecuencias) {
        if (frecuencia > maxFrecuencia) {
            maxFrecuencia = frecuencia;
            moda = valor;
        }
    }
    return moda;
}

//rango de variacion
double calcularRango(const vector<Estado>& estados) {
    double minValor = estados[0].produccionEconomica;
    double maxValor = estados[0].produccionEconomica;
    for (const auto& estado : estados) {
        if (estado.produccionEconomica < minValor) minValor = estado.produccionEconomica;
        if (estado.produccionEconomica > maxValor) maxValor = estado.produccionEconomica;
    }
    return maxValor - minValor;
}

//varianza
double calcularVarianza(const vector<Estado>& estados) {
    double media = calcularMedia(estados);
    double suma = 0;
    for (const auto& estado : estados) {
        suma += pow(estado.produccionEconomica - media, 2);
    }
    return suma / estados.size();
}

//desviacion estandar
double calcularDesviacionEstandar(const vector<Estado>& estados) {
    return sqrt(calcularVarianza(estados));
}

//coeficiente de variacion
double calcularCoeficienteVariacion(const vector<Estado>& estados) {
    double media = calcularMedia(estados);
    double desviacion = calcularDesviacionEstandar(estados);
    return (desviacion / media) * 100;
}

//produccion economica
bool compararPorProduccionEconomica(const Estado& a, const Estado& b) {
    return a.produccionEconomica < b.produccionEconomica;
}

//ordenar por poblacion
bool compararPorPoblacion(const Estado& a, const Estado& b) {
    return a.poblacion < b.poblacion;
}

//ordenar por sector
bool compararPorSector(const Estado& a, const Estado& b) {
    return a.sector < b.sector;
}

//MAIN//

int main() {
    vector<Estado> estados;
    string archivoEntrada = "estados.txt";  //nombre archivo de texto datos de enttrada
    string archivoSalida = "resultados.txt"; //archivo donde se guardaran los resultados

    //Leemos los datos desde el archivo
    if (!leerDatosDesdeArchivo(archivoEntrada, estados)) {
        return 1;  //Si no se pudo leer el archivo de entrada se slae
    }

    int opcion;
    //menu opciones
    cout << "Selecciona una opción:\n";
    cout << "1. Ordenar por Producción Económica\n";
    cout << "2. Ordenar por Población\n";
    cout << "3. Ordenar por Sector\n";
    cout << "4. Calcular la Media\n";
    cout << "5. Calcular la Mediana\n";
    cout << "6. Calcular la Moda\n";
    cout << "7. Calcular el Rango de Variación\n";
    cout << "8. Calcular la Varianza\n";
    cout << "9. Calcular la Desviación Estándar\n";
    cout << "10. Calcular el Coeficiente de Variación\n";
    cout << "Elige una opción (1-10): ";
    cin >> opcion;

    double resultado = 0;
    //ejecutamos seleccion con swicth (por faiclidad)
    switch (opcion) {
        case 1:
            sort(estados.begin(), estados.end(), compararPorProduccionEconomica);
            break;
        case 2:
            sort(estados.begin(), estados.end(), compararPorPoblacion);
            break;
        case 3:
            sort(estados.begin(), estados.end(), compararPorSector);
            break;
        case 4:
            resultado = calcularMedia(estados);
            break;
        case 5:
            resultado = calcularMediana(estados);
            break;
        case 6:
            resultado = calcularModa(estados);
            break;
        case 7:
            resultado = calcularRango(estados);
            break;
        case 8:
            resultado = calcularVarianza(estados);
            break;
        case 9:
            resultado = calcularDesviacionEstandar(estados);
            break;
        case 10:
            resultado = calcularCoeficienteVariacion(estados);
            break;
        default:
            cout << "Opción no válida." << endl;
            return 1;
    }

    //Guardamos resultados en archivo
    guardarResultados(archivoSalida, estados, opcion, resultado);

    //mostrar datos ordenados (si fue una opcion deordenamiento)
    cout << "\nDatos ordenados:\n";
    for (const auto& estado : estados) {
        estado.imprimir(cout);  // Imprimimos en consola (solo para comprobar)
    }

    return 0;
}


