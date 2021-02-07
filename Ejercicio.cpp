#include <iostream>
#include <iomanip>
#include <vector>

/**
 * @file Ejercicio.cpp
 * @brief Produccion de fábricas
 * Programa que lee una lista de fábricas y muestra cual tuvo mayor producción
 * XD ejercicio sacado de una tarea de programación xD
 */

int main()
{
    int i = 1;
    int j = 0;
    int clave = 0;
    double mayPro = 0;
    int n;
    char * fabrica; /**< Máximo 9 caracteres*/
    std::vector<char *> fabricas;
    double totAnu = 0;
    double mes = 0;

    std::cout << "Numero de fábricas: " << std::endl;
    std::cin >> n;

    if (n > 1000){
        std::cout << "Error en número de fabricas" << std::endl;
        return 0;
    }

    while (i <= n){
        fabrica = (char*)malloc(10*sizeof(char)); 
        std::cout << "Ingrese clave de fábrica:" << std::endl;
        std::cin >> fabrica;
        fabricas.push_back(fabrica);
        
        j = 1;
        while (j <= 12)
        {
            std::cout << "Ingrese Total del mes:" << std::endl;
            std::cin >> mes;
            totAnu += mes;
            if(j == 7 && mes > 300000){
                std::cout << fabricas[i - 1] << std::endl;
            }
            j+=1;

        }
        if(totAnu>mayPro){
            mayPro = totAnu;
            clave = i - 1;
        }
        std::cout << "Produccion anual fabrica:" << fabricas[i - 1] << std::endl;
        std::cout << std::setprecision(17) << "$" << totAnu << std::endl;

        totAnu = 0;
        i++;
    }

    if (i > n){
        std::cout << "Fabrica que mas produjo en el año: " << fabricas[clave] << std::endl;
        std::cout << std::setprecision(17) << "Producción: $" << mayPro << std::endl;
    }

    return 0;
}