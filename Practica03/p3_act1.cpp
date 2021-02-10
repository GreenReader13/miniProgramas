/**
 * @file p3_act1.cpp
 * @brief Ejemplo de uso de arreglos y ciclos For
 */

#include<iostream>
#include<array>
#include<algorithm>

constexpr int SIZE = 10;

void Info(const std::array<int, SIZE> & arr);
void Imprimir(const std::array<int, SIZE> & arr);
void Comparar(const std::array<int, SIZE> & n, const std::array<int, SIZE> & m);

/**
 * @brief implementación de las funciones
 */
int main(){
    int i = 0;

    std::array<int, SIZE>n{-1, 5, -9, 5, -7, 45, -6, -4, 13, 8};
    Imprimir(n);

    std::cout << "Tamaño del arreglo N: " << n.size() << std::endl;
    std::cout << "Primer elemento: " << n.front() << std::endl;
    std::cout << "Ultimo elemento: " << n.back() << std::endl;

    std::sort(n.begin(), n.end());

    std::cout << "N ordenado" << std::endl;
    Imprimir(n);

    std::array<int, SIZE>m;
    for(int x:m){
        i+=1;
        std::cout << "Ingrese el valor: " << i;
        std::cout << " Para el arreglo M" << std::endl;
        std::cin >> x;
        m[i-1] = x;
    }

    Imprimir(m);

    m.swap(n);

    std::cout << "Arreglo N: " << std::endl;
    Imprimir(n);
    std::cout << "Arreglo M: " << std::endl;
    Imprimir(m);
    Comparar(n, m);

    return 0;
}

/**
 * @brief Información de arreglo
 * 
 * Función que muestra el contenido y tamaño de un arreglo de enteros
 * @param arr arreglo de enteros del que se mostrará la información
 */
void Info(const std::array<int, SIZE> & arr){
    std::cout << "Contenido: " << arr.at(SIZE -1) << std::endl;
    std::cout << "Tamaño: " << arr.size() << std::endl;
}

/**
 * @brief Imprime el contenido de un arreglo
 * @param arr Arreglo de enteros del que se imprimirá el contenido
 */
void Imprimir(const std::array<int, SIZE> & arr){
    std::cout << "Arreglo: " << std::endl;
    for(int x:arr){
        std::cout << x << std::endl;
    }
    std::cout << std::endl;
}

/**
 * @brief Función que compara el contenido de dos arreglos
 * 
 * La comparación se realiza con elementos del mismo índice
 * Los dos arreglos deben tener el mismo tamaño SIZE
 */
void Comparar(const std::array<int, SIZE> & n, const std::array<int, SIZE> & m){
    int i;
    for(i=0;i<SIZE;i++){
        if(m[i]==n[i]){
            std::cout << "Los elementos " << i+1 << "Son iguales" << std::endl;
        }
        else{
            if(m[i]>n[i]){
                std::cout << "Los elementos " << i+1 << "Son distintos";
                std::cout << std::endl;
                std::cout << "El elemento M["<< i+1 << "] es mayor";
                std::cout << std::endl;
            }
            else{
                std::cout << "Los elementos " << i+1 << "Son distintos";
                std::cout << std::endl;
                std::cout << "El elemento N["<< i+1 << "] es mayor";
                std::cout << std::endl;
            }
        }   
    }
}