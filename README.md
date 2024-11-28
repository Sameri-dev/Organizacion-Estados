# Proyecto: Organizacion-Estados

Este proyecto en C++ se encarga de gestionar, organizar y analizar datos económicos de los estados de la Republica Mexicana. El programa permite consultar y ordenar información sobre la producción económica, sectores productivos, número de entidad y población. 

El usuario puede interactuar con el programa seleccionando qué datos desea visualizar. Los resultados se presentan de manera ordenada (de menor a mayor), según la opción elegida, facilitando asi la comparación y el análisis de la información. 

## Descripción del Avance 1
Para este primer avance, utilicé la función sort para ordanarlos datos en los archivos Ordenamiento.h y el main.cpp. Lo hice para experimentar con la función, pero también implementé el algoritmo QuickSort en el archivo EstadosQuickSort.h para mejorar el rendimiento de grandes conjuntos de datos.

Utilice un vector que tiene todos los estados de la republica con sus datos (necesito revisar y confirmar parte de la informacion que encontre en linea especialmente la parte de los sectores a los que se encarga cada estado por lo que no lo aplique ente avance), tiene el algoritmo de ordenamiento (Quick sort debido a que es eficiente para grandes conjuntos de datos y su rendimiento promedio es de O(nlogn)), y las opciones de las que se puede elegir (planeo agregarle mas opciones). Otra modificacion que quiero hacer es solo mostrar el estado y el dato solicitado en vez de toda la linea de datos.

## Descripción del avance 2
Para este segundo avance se eliminó el programa de ordenamiento Quick Sort y se utilizó un programa de Sort para acomodar los estados con su respectivo main. A su vez se agregó la función de leer mediante un archivo de texto (estados.txt) los datos que se desean analizar en el programa por lo que se eliminó el vector que contenía la información.

### Cambios sobre el primer avance
##### Cambio 1: Implementación de QuickSort
Razón: El algoritmo QuickSort fue implementado en el archivo EstadosQuickSort.h debido a su eficiencia para manejar grandes conjuntos de datos, con un rendimiento promedio de O(n log n).
##### Cambio 2: Adición de opciones estadísticas
Razón: Se incluyeron opciones para calcular estadísticas como la media, mediana, moda, etc., lo cual permite un análisis más profundo de los datos económicos de los estados.

## Descripción del avance 3
Para este último avance se agregaron las opciones de operaciones de análisis de datos con sus respectivas funciones y se modifico el codigo para que este enviará o imprimiera los resultados del programa a un archivo txt (resultados.txt), también para facilitar el programa se realizó todo dentro de un mismo archivo. 

### Cambios sobre el segundo avance
##### Cambio 1: Mejora en la presentación de resultados
Razón: Se planea mostrar solo los datos solicitados, evitando sobrecargar la salida con información innecesaria.
##### Cambio 2: Optimización de la visualización de los datos
Razón: Se agregará una opción para exportar los resultados a un archivo de texto, lo que permitirá guardar los resultados para su posterior análisis.

## Entrega final
La entrega final incluirá una versión optimizada del programa con las opciones de ordenamiento y estadísticas completamente implementadas. Además, se mejorará la interacción con el usuario y la presentación de los resultados tanto en la consola como en el archivo de salida. Además se implementará el READ ME de manera apropiada.

### Cambios sobre el tercer avance
#### Cambio 1: Mejora en el manejo de archivos
Razón: Se optimizará el manejo de archivos de entrada y salida para garantizar que los datos se carguen y se guarden de manera eficiente.

## Uso
En cualquiera de las dos opciones del programa que se escoga solo se selecciona el numero de la opcion en la que se quiere ordenar los datos y el programa los ordena con la funcion o con el algoritmo (dependiendo del archivo) y se muestran ya ordenados.

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:
g++ main.cpp -o Organizacion-Estados

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:
./Organizacion-Estados

## Descripción de las entradas del proyecto
El proyecto recibe un archivo de texto estados.txt que contiene los datos económicos de los estados de la República Mexicana. Los datos están organizados en líneas con los siguientes campos: nombre del estado, índice, producción económica (en millones de US), población y sector económico, separados por comas.
#### Ejemplo de archivo de entrada:
Estado A,1,5000000,5000000,1
Estado B,2,4000000,4000000,2

## Descripción de las salidas del proyecto
Los resultados de la ejecución del programa se guardan en el archivo resultados.txt. Dependiendo de la opción seleccionada por el usuario, los resultados pueden incluir datos ordenados por producción económica, población o sector, así como estadísticas como media, mediana, moda, rango de variación, varianza, desviación estándar y coeficiente de variación.


Desarrollo de competencias
SICT0301: Evalúa los componentes
Análisis de complejidad de los algoritmos de ordenamiento: El uso de QuickSort mejora el rendimiento en comparación con otros algoritmos, especialmente en grandes conjuntos de datos. Este análisis está reflejado en el rendimiento de O(n log n) para el algoritmo de ordenamiento.


Análisis de las estructuras de datos: Se utiliza un vector de estructuras para almacenar los datos de los estados, lo cual permite un acceso eficiente a los datos al ser ordenados o manipulados.


## SICT0302: Toma decisiones
#### Selección del algoritmo de ordenamiento: 
Se ha seleccionado el algoritmo QuickSort debido a su eficiencia en el manejo de grandes conjuntos de datos.

#### Selección de estructura de datos: 
El vector de estructuras es adecuado para almacenar y organizar los datos de los estados de manera eficiente.


## SICT0303: Implementa acciones científicas
#### Mecanismos para consultar información: 
El programa permite consultar información específica de los estados, como la producción económica, población y otros datos relevantes.

#### Mecanismos de lectura y escritura de archivos: 
El programa utiliza mecanismos eficientes para leer y escribir datos en archivos, lo cual permite cargar los datos de los estados y guardar los resultados de manera correcta.

## Analisis de complejidad

### 1. Análisis de Complejidad de los Algoritmos de Ordenamiento
El programa emplea varias funciones de ordenamiento utilizando la función sort de C++ y el algoritmo QuickSort. Los algoritmos de ordenamiento en el programa se aplican sobre el vector estados, que contiene los datos de cada estado.

#### sort(estados.begin(), estados.end(), comparador): 
El algoritmo de ordenamiento utilizado en este caso es la versión optimizada de QuickSort implementada por la función std::sort en C++. La complejidad temporal promedio de QuickSort es O(n log n), siendo n el número de elementos en el vector de estados. En el peor de los casos, la complejidad es O(n²), aunque esto es poco probable debido a las optimizaciones en la implementación de QuickSort (por ejemplo, el uso de una selección de pivote más inteligente).
##### Complejidad promedio: 
O(n log n)
##### Complejidad en el peor de los casos: 
O(n²)
Este algoritmo se utiliza en las opciones del programa que ordenan los estados según diferentes criterios: producción económica, población y sector económico.

### 2. Análisis de Complejidad de las Estructuras de Datos
El programa usa diversas estructuras de datos, principalmente el vector y el map:

#### Vector (std::vector):
##### Acceso por índice: 
El acceso a un elemento específico del vector es O(1), ya que se usa un índice para acceder directamente a cualquier elemento.
##### Inserción de elementos: 
Al insertar un nuevo elemento en un vector (usando push_back), la complejidad promedio es O(1). Sin embargo, si el vector necesita redimensionarse debido a que se excede su capacidad, la complejidad de esta operación puede ser O(n) en el peor de los casos.
##### Ordenamiento: 
Como se explicó antes, la función sort tiene una complejidad de O(n log n).

#### Map (std::map):
El programa utiliza un map<double, int> para contar la frecuencia de las producciones económicas (en la función calcularModa). La inserción y la búsqueda en un map son operaciones de O(log n), ya que los elementos del mapa están organizados internamente en un árbol binario balanceado.
##### Inserción y búsqueda en el map: 
O(log n).

### 3. Análisis de Complejidad de Otros Conponentes del Programa
El programa realiza diversas operaciones sobre los datos de los estados, tales como calcular estadísticas (media, mediana, moda, etc.). A continuación se detalla el análisis de complejidad de cada uno de los componentes relevantes:

#### Calcular la Media:
La complejidad para calcular la media de las producciones económicas de todos los estados es O(n), ya que requiere recorrer todo el vector estados y acumular los valores de produccionEconomica.
#### Calcular la Mediana:
Para calcular la mediana, primero se debe ordenar el vector estados por la producción económica, lo que tiene una complejidad de O(n log n) debido al uso de std::sort. Después, el acceso a la mediana es O(1), ya que se trata de acceder al elemento central del vector.
#### Calcular la Moda:
El cálculo de la moda implica recorrer el vector estados y registrar las frecuencias de las producciones económicas en un map, lo cual tiene una complejidad de O(n log n) debido a las operaciones de inserción y búsqueda en el map.
#### Calcular el Rango de Variación:
Para calcular el rango de variación, se debe recorrer todo el vector estados para encontrar los valores mínimo y máximo de la producción económica. Esto tiene una complejidad de O(n).
#### Calcular la Varianza y Desviación Estándar:
Ambos cálculos requieren recorrer todo el vector estados dos veces: una para calcular la media y otra para calcular la suma de las diferencias al cuadrado con respecto a la media. Esto da una complejidad de O(n) para cada uno.
#### Calcular el Coeficiente de Variación:
El coeficiente de variación también depende de la media y la desviación estándar, por lo que tiene una complejidad de O(n).

### 4. Complejidad Final del Programa
La complejidad total del programa depende principalmente de las operaciones de ordenamiento, que son las que dominan la complejidad temporal:
Si el usuario selecciona una opción que involucra ordenamiento (opciones 1 a 3), la complejidad de la operación de ordenamiento será O(n log n), donde n es el número de estados.
Las operaciones estadísticas (media, mediana, moda, etc.) tienen una complejidad adicional que depende de si se requiere ordenar los datos o de las búsquedas en mapas:
Calcular la mediana tiene una complejidad de O(n log n) debido al ordenamiento.
Las otras operaciones estadísticas tienen una complejidad de O(n).
Por lo tanto, la complejidad final del programa es dominada por las operaciones de ordenamiento y será O(n log n) en el caso general.



# Videos
## Estrucutra lineal
### Drive: 
https://drive.google.com/drive/folders/1n9n4ZLc3LdTFop5N4oa_GZv2Wu46EZLa?usp=sharing
### YouTube
https://youtu.be/5hHCugw0-xg

## Estructura no lineal
### Drive: 
https://drive.google.com/drive/folders/1FEyCXakscVu-bkTf8iVI3awJOy_ad5nu?usp=sharing
### YouTube
https://youtu.be/jdwTLRktQ9w

## Algoritmo de ordenamiento
### Drive: 
https://drive.google.com/drive/folders/1MRtbpOepUUJH4xgmMbyiTFJfpz8FGXy6?usp=sharing
### YouTube
https://youtu.be/QivnbOciiGk


## Referencias:

Aguascalientes: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/aguascalientes-ag?redirect=true

Baja California: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/baja-california-bc

Baja California Sur: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/baja-california-sur-bs

Campeche: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/campeche-cm

ChatGPT. (n.d.). https://chatgpt.com/

Chiapas: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/chiapas-cs

Chihuahua: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/chihuahua-ch

Ciudad de México: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/ciudad-de-mexico-cx

Coahuila de Zaragoza: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/coahuila-de-zaragoza-co

Colima: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/colima-cl

De Los Mexicanos En El Exterior, I. (n.d.). Estados de la República Mexicana 2018. gob.mx. https://www.gob.mx/ime/acciones-y-programas/estado-de-la-republica-mexicana

Durango: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/durango-dg

Estado de México: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/mexico-em

Guanajuato: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/guanajuato-gt

Guerrero: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/guerrero-gr

Hidalgo: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/hidalgo-hg

Jalisco: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/jalisco-jc

Michoacán de Ocampo: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/michoacan-de-ocampo-mi

Morelos: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/morelos-mo

Nayarit: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/nayarit-na

Nuevo León: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/nuevo-leon-nl

Oaxaca: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/oaxaca-oa

Puebla: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/puebla-pu

Querétaro: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/queretaro-qt

Quintana Roo: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/quintana-roo-qr

San Luis Potosí: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/san-luis-potosi-sl

Sinaloa: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/sinaloa-si

Sonora: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/sonora-so

Tabasco: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/tabasco-tb

Tamaulipas: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/tamaulipas-tm

Tamaulipas: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/tamaulipas-tm

Tlaxcala: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/tlaxcala-tl

Veracruz de Ignacio de la Llave: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/veracruz-de-ignacio-de-la-llave-ve

Yucatán: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/yucatan-yu

Zacatecas: Economía, empleo, equidad, calidad de vida, educación, salud y seguridad pública | Data México. (n.d.). Data México. https://www.economia.gob.mx/datamexico/es/profile/geo/zacatecas-za
