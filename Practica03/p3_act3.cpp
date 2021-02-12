/**
 * @file p3_act3.cpp
 * @brief Ejemplo de String
 */

#include<iostream>
#include<string>

int main(){
	
	unsigned int val;

	std::string nombre;
	std::string apellido;
	std::string nombreCompleto;
	std::string nombre2;    /**< Nombre en mayúsculas*/
	
	//Ingresando nombre y apellido
	std::cout<<"Ingresa tu nombre: \n";
	std::cin>>nombre;
	
	std::cout<<"Ingresa tu apellido: \n";
	std::cin>>apellido;
	
	//Concatenando para el nombre completo
	nombreCompleto=nombre + " " + apellido;
	
	//Imprimiendo datos
	std::cout<<"\nNombre: "<<nombre<<std::endl;
	std::cout<<"Apellido: "<<apellido<<std::endl;
	std::cout<<"Nombre Completo: "<<nombreCompleto<<std::endl;

	//Pidiendo dirección
	std::string direccion;
	std::cout<<"\nIngrese su dirección\n";
	std::cin.get();
	std::getline(std::cin, direccion);
	
	//Imprimiendo por caracter
	std::cout<<"Dirección: 	";
	for(char x: direccion){
		std::cout<<x;
	}
	std::cout<<std::endl;
	
	//Nueva variable con nombre en mayusculas
	nombre2=nombre;

	for(char &x: nombre2){
		x=std::toupper(x);
	}
	
	std::cout<<"\nNombre en mayusculas\n";
	std::cout<<nombre2<<std::endl;

	//Analizando tamaño de la direccion en caracteres
	std::cout<<"\nTamaño en caracteres de la direccion\n";
	std::cout<<direccion.size()<<std::endl;

	//Recuperando el caracter en la posición val
	std::cout<<"Ingrese un número entre 0 y "<<direccion.size()-1<<std::endl;
	std::cin>>val;

	if(val>=0 and val<direccion.size()){
		std::cout<<"La letra en la posición: "<<val<<" es: "<<direccion[val];
	}
	
	//borrando
	direccion.clear();
	std::cout<<direccion<<std::endl;

	/*Comparando nombre con apellido*/
	std::cout<<"\n¿nombre < apellido?\n";
	if(nombre<apellido){
		std::cout<<"True\n";
	}else{ std::cout<<"False\n";}

	//Buscando nombre en nombreCompleto
	auto var= nombreCompleto.find(nombre);
	std::cout<<"\nBuscando "<<nombre<<" en: "<<nombreCompleto<<std::endl;
	
	if(var==std::string::npos){
		std::cout<<"No se encontró: "<< nombre<<" en: "<<nombreCompleto<<std::endl;
	}else{
		std::cout<<nombre<<" se encuentra en la dirección: "<< var<<std::endl;
	}
}