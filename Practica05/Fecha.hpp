/**
 * @file    Fecha.hpp
 * @class   Fecha
 * @brief   Clase que representa la fecha
 * 
 * @details Esta clase almacena el día, mes y año
 *          Contiene funciones básicas para manejar estos parametos
 * @author  David Fuentes
 * @version 1.0.0
 * @date    2021
 * @copyright GNU Public License.
 */

#ifndef FECHA_HPP
#define FECHA_HPP

#include "Meses.hpp"
namespace dfb
{
    class Fecha
    {
    private:
        int dia;        /**< Dia del año */
        dfb::Meses mes; /**< Mes del año */
        int anio;       /**< Año */

    public:
        /**
         * @brief Constructor por defecto
         */
        Fecha() = default;

        /**
         * @brief Constructor por parametros
         * @param d día del año
         * @param m mes del año
         * @param a año
         */
        Fecha(int d, int m, int a);

        /**
         * @brief Constructor copia
         * @param f Objeto fecha referencia
         */
        Fecha(const Fecha & f);

        /**
         * @brief Establece el día
         * 
         * El día debe ser válido deacuerdo al mes
         * @param d día, número entero entre 1 y 31
         */
        bool setDia(int d);

        /**
         * @brief Establece el mes
         * @param m mes, número entero entre 1 y 12
         */
        bool setMes(int m);

        /**
         * @brief Establece el año
         * @param a año, número entero
         */
        bool setA(int a);

        /**
         * @brief Imprime el día
         */
        void getDia();

        /**
         * @brief Imprime el mes
         */
        void getMes();

        /**
         * @brief Imprime el año
         */
        void getA();

        /**
         * @brief Función que da formato a la fecha
         * @return fecha, string con formato día/mes/año
         */
        std::string GetFecha() const;

        /**
         * @brief Compara si la fecha es mayor que la proporcionada
         * @param f Fecha a comparar
         * @return true si la fecha es mayor que f, false otro caso
         */
        bool Mayor(const Fecha & f);

        /**
         * @brief Compara si la fecha es menor que la proporcionada
         * @param f Fecha a comparar
         * @return true si la fecha es menor que f, false otro caso
         */
        bool Menor(const Fecha & f);

        /**
         * @brief Compara si la fecha es igual que la proporcionada
         * @param f Fecha a comparar
         * @return true si las fechas son iguales, false otro caso
         */
        bool Igual(const Fecha & f);

        /**
         * @brief Función para saber si el año es bisiesto
         * @return true si el año es bisiesto, false otro caso
         */
        bool Bisiesto();

        bool operator >  (const Fecha & f);
        bool operator >= (const Fecha & f);
        bool operator == (const Fecha & f);
        bool operator <= (const Fecha & f);
        bool operator <  (const Fecha & f);
        bool operator != (const Fecha & f);
    };
} // namespace dfb

#endif