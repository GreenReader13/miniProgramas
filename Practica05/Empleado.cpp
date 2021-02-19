#include<iostream>
#include"Empleado.hpp"

namespace dfb
{
    Empleado::Empleado( std::string, std::string, dfb::Fecha, dfb::Puesto):
	                    nombre{nombre}, direccion{direccion},
                        contratacion{contratacion}, puesto{puesto},
                        diasTrabajados{0},penalizacion{0}
	{
		if(puesto==dfb::Puesto(1)) this->sueldoBase = 7000.0;
		if(puesto==dfb::Puesto(2)) this->sueldoBase = 3000.0;
		if(puesto==dfb::Puesto(3)) this->sueldoBase = 1800.0;
	}

	void Empleado::checkIn(dfb::Reloj entrada){
		
        int horasRetraso;
		this->diasTrabajados+=1;
        horasRetraso = entrada.GetHora() - this->entrada.GetHora();
		if(horasRetraso > 1) this->penalizacion+=1;
	}

	void Empleado::imprimir()
    {	
		std::cout << "Nombre: " << this->nombre << std::endl;
		std::cout << "Direccion: " << this->direccion << std::endl;
		std::cout << "Fecha de contratacion: ";
        std::cout << this->contratacion.GetFecha() << std::endl;
		std::cout << "Puesto" << this->puestoOcupado() << std::endl;
		std::cout << "Dias hábiles" << this->diasTrabajados << std::endl;
		std::cout << "Retardos" << this->penalizacion << std::endl;	
	}

    std::string Empleado::puestoOcupado()
    {
		int i = static_cast<int>(this->puesto);

		switch(i){
			case 1:
				return "Jefe";
				break;

			case 2:
				return "Gerente";
				break;

			case 3:
				return "Recepcion";
				break;

            default:
				return "Error";
				break;
		}
	}

	std::string Empleado::GetNombre()
    {
		return this->nombre;
	}
	
	int Empleado::GetDias()
    {
		return this->diasTrabajados;
	}

	int Empleado::GetPen()
    {
		return this->penalizacion;
	}

	double Empleado::GetSueldo()
    {
		return this->sueldoBase;
	}
	
	dfb::Reloj Empleado::GetEntrada()
    {
        return this->entrada;
    }

	dfb::Reloj Empleado::GetSalida()
    {
        return this->salida;
    }
}