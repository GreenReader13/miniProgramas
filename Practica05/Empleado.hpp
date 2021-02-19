/**
 * @file    Empleado.hpp
 * @class   Empleado
 * @brief   Clase que representa un empleado
 * @author  David Fuentes
 * @version 1.0.0
 * @date    2021
 * @copyright GNU Public License.
 */

#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include<iostream>
#include<string>
#include"Fecha.hpp"
#include"Reloj.hpp"
#include"Puestos.hpp"

namespace dfb{

	class Empleado{

		private:
		
			std::string nombre;
			std::string direccion;
			
            dfb::Fecha contratacion;
			dfb::Puesto puesto;
			dfb::Reloj entrada=dfb::Reloj(8,0,0);
			dfb::Reloj salida=dfb::Reloj(17,0,0);

			double sueldoBase;
			int diasTrabajados;
			int penalizacion;
		
		public:
			
            /**
             * @brief Constructor por defecto
             */
			Empleado()=default;

            /**
             * @brief Constructor con parámetros
             * @details Crea un empleado con los parámetros proporcionados
             * @param nom Nombre del empleado
             * @param dir Dirección del empleado
             * @param con Fecha de contratación
             * @param pue Puesto del empleado
             */
			Empleado(std::string nom, std::string dir, dfb::Fecha cont, dfb::Puesto pue);

            /**
             * @brief Registra la entrada del empleado
             * @details Se penalizan retrasos mayores a una hora
             * @param entrada Hora de entrada
             */
			void checkIn(dfb::Reloj entrada);
			
            /**
             * @brief Muestra los datos del empleado
             */
			void imprimir();

            /**
             * @brief Devuelve el puesto ocupado por el empleado
             * @return Puesto ocupado
             */
			std::string puestoOcupado();

            /**
             * @brief Devuelve el nombre del empleado
             * @return Nombre del empleado
             */
			std::string GetNombre();

            /**
             * @brief Devuelve los días trabajados
             * @return número de días trabajados
             */
			int GetDias();

            /**
             * @brief Devuelve el número de penalizaciones
             * @return numero de penalizaciones
             */
			int GetPen();

            /**
             * @brief Devuelve el sueldo base del empleado
             * @return Sueldo base
             */
			double GetSueldo();

            /**
             * @brief Devuelve la hora de salida
             * @return objeto Reloj con la ora de salida
             */
            dfb::Reloj GetEntrada();
			
            /**
             * @brief Devuelve la hora de salida
             * @return objeto Reloj con la hora de salida
             */
            dfb::Reloj GetSalida();
	};

}

#endif