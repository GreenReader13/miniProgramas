
#include<iostream>
#include<string>
#include"Empleado.hpp"
#include"Cheque.hpp"
#include"Reloj.hpp"
#include"Fecha.hpp"

/**
 * @brief Ejemplo de implementación de objetos
 */
int main(){
	
	std::cout<<"Empleado 1\n";

	std::string nombre;
	std::cout<<"\nIngrese Nombre\n";
	std::getline(std::cin, nombre);

	std::string direccion;
	std::cout<<"\nIngrese dirección\n";
	std::getline(std::cin, direccion);
	
	dfb::Fecha contratacion=dfb::Fecha(26,9,2016);
	
	dfb::Puesto puesto=dfb::Puesto(2);

	dfb::Empleado empleado1(nombre, direccion, contratacion, puesto);

	std::cout<<"\nEmpleado 2\n";

	std::string nombre2;
	std::cout<<"\nIngrese Nombre\n";
	std::getline(std::cin, nombre2);

	std::string direccion2;
	std::cout<<"\nIngrese dirección\n";
	std::getline(std::cin, direccion2);
	
	
	dfb::Puesto puesto2=dfb::Puesto(3);

	dfb::Empleado empleado2(nombre2, direccion2, contratacion, puesto2);

	dfb::Reloj horaEntrada=dfb::Reloj(8,59,47);
	
	int i;
	
	for (i=0;i<20;i++){
		horaEntrada.Avanzar();
		
		empleado1.checkIn(horaEntrada);
		empleado2.checkIn(horaEntrada);
	}
	std::cout << "Dias:" << empleado1.GetDias() << std::endl;
	dfb::Cheque cheque1(empleado1);
	dfb::Cheque cheque2(empleado2);
	
	cheque1.imprimir();
	cheque2.imprimir();
}