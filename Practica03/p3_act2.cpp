/**
 * @file p3_act2.cpp
 * @brief Ejercicio implementación de vectores
 */

#include<iostream>
#include<vector>

void Print(std::vector<double> & vex);
void Push(std::vector<double> & vex, int u);
void Info(const std::vector<double> & vex);

/**
 * @brief implementación de las funciones
 */
int main(){
    int ag;
    std::vector<double> vex;

    std::cout << "Tamaño del vector " << vex.size() << std::endl;

    std::cout << "Ingrese los elementos a agregar \n";
    std::cin >> ag;

    Push(vex, ag);

    Print(vex);
    Info(vex);

    std::cout << "\nEliminando 2 elementos utilizando pop_back\n";
    vex.pop_back();
    vex.pop_back();

    Print(vex);
    Info(vex);
    
    std::cout << "\nIntercambiando los valores 1 y 3 \n";
    std::swap(vex[0], vex[2]);

    Print(vex);

    std::cout << "\nInsertando un valor al inicio\n";
    vex.insert(vex.begin(), 2.5);

    Print(vex);

    return 0;
}

/**
 * @brief Funcion que imprime el contenido de un vector de tipo double
 * 
 * La función imprime el contenido del vector utilizando .at y el operador[]
 * @param vex Vector a imprimir
 */
void Print(std::vector<double> & vex){
    unsigned int i = 0;
    std::cout << "\nImprimiendo el vector \n\n";
    std::cout << "Utilizando .at \n";

    for(i=0;i<vex.size();i++){
        std::cout << vex.at(i) << std::endl;
    }

    std::cout << "\nUtilizando [] operador: \n";
    for(i=0;i<vex.size();i++){
        std::cout << vex[i] << std::endl;
    }
}

/**
 * @brief Función que agrega u elementos al vector de tipo double
 * @param vex Vector en el que se agregarán los elementos
 * @param u número de elementos a agregar
 */
void Push(std::vector<double> & vex, int u){
    int i;
    double v;

    for(i=1;i<=u;i++){
        std::cout << "Ingrese el dato "<< i << std::endl;
        std::cin >> v;
        vex.push_back(v);
    }
}

/**
 * @brief Función que muestra la información de un vector de tipo double
 * @param vex Vector del que se mostrará la información
 */
void Info(const std::vector<double> & vex){
    std::cout << "\nTamaño del vector" << vex.size() << std::endl;
    std::cout << "Capacidad " << vex.capacity() << std::endl;
}