#include <iostream>
#include <iomanip>
#include <vector>

/**
 * @file Ejercicio.cpp
 * @brief Produccion de fábricas
 * Programa que lee una lista de fábricas y muestra cual tuvo mayor producción
 * 
 * XD ejercicio sacado de una tarea de programación xD
 * 
 */

int main()
{
    //Region para expandir o contraer en Visual Studio Code
    #pragma region Variables
    int i = 1;                      /**< Variable que para el número de fabricas*/
    int j = 1;                      /**< Variable que para el número de meses */
    int n;                          /**< Número de fábricas */
    int clave = 0;                  /**< Almacena el índice del vector */
    int longClv = 10;               /**< Caracteres para la clave de fábrica */

    double mayPro = 0;              /**< Almacena la mayor producción anual */
    double totAnu = 0;              /**< Producción total anual */
    double mes = 0;                 /**< Producción total mensual */

    char * fabrica;                 /**< Clave de fabrica Máximo 9 caracteres*/

    std::vector<char *> fabricas;   /**< Vector claves de fabricas */
    #pragma endregion

    //Se ingresa el número de fábricas
    std::cout << "Numero de fábricas: " << std::endl;
    std::cin >> n;

    //No se permiten más de 1000 fábricas
    if (n > 1000){
        std::cout << "Error en número de fabricas" << std::endl;
        return 0;
    }

    //Se capturan los datos por fábrica
    while (i <= n){
        fabrica = (char*)malloc(longClv*sizeof(char)); 
        std::cout << "Ingrese clave de fábrica:" << std::endl;
        std::cin >> fabrica;
        fabricas.push_back(fabrica);
        
        j = 1;
        //Produccion mensual
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

        //Se verifica si el total anual es el mayor de las fábricas
        if(totAnu>mayPro){
            mayPro = totAnu;
            clave = i - 1;
        }

        std::cout << "Produccion anual fabrica:" << fabricas[i - 1] << std::endl;
        std::cout << std::setprecision(17) << "$" << totAnu << std::endl;

        totAnu = 0;
        i++;
    }

    //Se muestra la fábrica con mayor producción anual y el monto
    std::cout << "Fabrica que mas produjo en el año: " << fabricas[clave] << std::endl;
    std::cout << std::setprecision(17) << "Producción: $" << mayPro << std::endl;
    
    return 0;
}