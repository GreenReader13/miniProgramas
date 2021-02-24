/**
 * @file    Cheque.hpp
 * @brief   Clase que representa un cheque
 * @author  David Fuentes
 * @version 1.0.0
 * @date    2021
 * @copyright GNU Public License.
 */

#ifndef CHEQUE_HPP
#define CHEQUE_HPP

#include<iostream>
#include"Fecha.hpp"
#include"Empleado.hpp"

namespace dfb
{
    class Cheque
    {
        private:
            dfb::Fecha emision;
            dfb::Empleado empleado;

        public:
            /**
             * @brief Constructor
             * @param e Empleado al que se hará el cheque
             */
            Cheque(dfb::Empleado & e);
            
            /**
             * @brief Establese la fecha del cheque
             * @param f Fecha de emisión del cheque
             */
            bool SetFecha(dfb::Fecha & f);
            
            /**
             * @brief Imprime los datos del cheque
             */
            void imprimir();

            /**
             * @brief Calcula el sueldo del cheque
             * 
             * El monto se calcula con los días trabajados
             * @return Sueldo del empleado
             */
            double calcularSueldo();
    };
}

#endif