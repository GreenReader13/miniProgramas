/**
 * @file    Reloj.hpp
 * @class   Reloj
 * @brief   Clase que representa la hora
 * 
 * @details Esta clase almacena hora, minutos y segundos
 *          Contiene funciones básicas para manejar estos parametos
 * @author  David Fuentes
 * @version 1.0.0
 * @date    2021
 * @copyright GNU Public License.
 */

#ifndef RELOJ_HPP
#define RELOJ_HPP

namespace dfb
{
    class Reloj
    {
    private:
        /* data */
        int hora;
        int min;
        int seg;

    public:
        /**
         * @brief Constructor por defecto
         */
        Reloj() = default;

        /**
         * @brief Constructor por parámetros
         * @details Si algún parámetro se encuentra fuera del rango
         *          se almacena por defecto como 0
         * @param h hora, entero entre 0 y 23
         * @param m minutos, entero entre 0 y 59
         * @param s segundos, entero entre 0 y 59
         */
        Reloj(int h, int m, int s);

        /**
         * @brief Constructor por copia
         * @param r Reloj de referencia
         */
        Reloj(const Reloj & r);

        /**
         * @brief Establece la hora del reloj
         * @details Si algún parámetro se encuentra fuera del rango
         *          se almacena por defecto como 0
         * @param h hora, entero entre 0 y 23
         * @param m minutos, entero entre 0 y 59
         * @param s segundos, entero entre 0 y 59
         */
        void Establecer(int h, int m, int s);

        /**
         * @brief Imprime la hora en formato 24 horas
         */
        void Imprimir();

        /**
         * @brief Avanza un segundo el reloj
         */
        void Avanzar();

        /**
         * @brief Compara si la hora es mayor que la del reloj proporcionado
         * @param r Reloj de referencia
         * @return true si la hora es mayor que la de r, false en otro caso
         */
        bool Mayor(const Reloj & r);

        /**
         * @brief Compara si la hora es igual que la del reloj proporcionado
         * @param r Reloj de referencia
         * @return true si la hora es igual
         */
        bool Igual(const Reloj & r);

        /**
         * @brief Devuelve la hora del reloj
         * @return hora, entero entre 0 y 23 que representa la hora
         */
        int GetHora();

        /**
         * @brief Devuelve los minutos del reloj
         * @return minutos, entero entre 0 y 59 que representa los minutos
         */
        int GetMin();

        /**
         * @brief Devuelve los segundos del reloj
         * @return segundos, entero entre 0 y 59 que representa los segundos
         */
        int GetSeg();

        bool operator > (const Reloj & r);
        bool operator >= (const Reloj & r);
        bool operator == (const Reloj & r);
        bool operator <= (const Reloj & r);
        bool operator < (const Reloj & r);
        bool operator != (const Reloj & r);

    };
}
#endif