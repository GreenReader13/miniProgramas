/**
 * @file p4_act2.cpp
 * @brief Uso de constructores, setters y getters
 * 
 * Ejemplo de clase rectangulo
 */
#include<iostream>

class Rectangulo{
    private:
        double ancho;
        double largo;

    public:

        Rectangulo();
        Rectangulo(Rectangulo & r);
        Rectangulo(double a);
        Rectangulo(double a, double l);

        double area();
        double perimetro();

        void setAncho(double ancho);
        void setLargo(double largo);

        double getAncho();
        double getLargo();

        ~Rectangulo();
};

/**
 * @brief Constructor por defecto
 * 
 * Crea un nuevo rectangulo con ancho y largo = 1.0
 * 
 */
Rectangulo::Rectangulo():ancho(1.0), largo(1.0)
{

}

/**
 * @brief Constructor por copia
 * 
 * Crea un nuevo rectángulo a partir de otro existente
 * @param r Rectángulo a partir del cual se creará uno nuevo
 */
Rectangulo::Rectangulo(Rectangulo & r)
{
    this->ancho = r.ancho;
    this->largo = r.largo;
}

/**
 * @brief Constructor por parámetros
 * @param a ancho del rectángulo
 * @param l largo del rectángulo
 */
Rectangulo::Rectangulo(double a, double l):ancho(a), largo(l)
{
}

/**
 * @brief Constructor con un parámetro
 * @param a ancho y largo (Cuadrado)
 */
Rectangulo::Rectangulo(double a):ancho(a), largo(a)
{
}

/**
 * @brief Desctructor por defecto
 */
Rectangulo::~Rectangulo()
{
}

/**
 * @brief Función que establece el ancho del rectángulo
 * @param ancho Ancho del rectángulo
 */
void Rectangulo::setAncho(double ancho)
{
    this->ancho = ancho;
}

/**
 * @brief Función que establece el largo del rectángulo
 * @param largo Largo del rectángulo
 */
void Rectangulo::setLargo(double largo)
{
    this->largo = largo;
}

/**
 * @brief Función que obtiene el ancho del rectángulo
 * @return Ancho del rectángulo
 */
double Rectangulo::getAncho()
{
    return this->ancho;
}

/**
 * @brief Función que obtiene el largo del rectángulo
 * @return Largo del rectángulo
 */
double Rectangulo::getLargo()
{
    return this->largo;
}

/**
 * @brief Función que devuelve el área del rectángulo
 * @return Area del rectángulo
 */
double Rectangulo::area()
{
    return this->ancho * this->largo;
}

/**
 * @brief Función que calcula el perímetro del rectángulo
 * @return Perímetro del rectángulo
 */
double Rectangulo::perimetro()
{
    return 2 * (this->ancho + this->largo);
}

/**
 * @brief implementación de la clase Rectangulo
 */
int main(){

    double largo, ancho;/**< Ancho y largo del rectángulo*/

	std::cout<<"Ingrese el largo del rectángulo\n";
	std::cin>>largo;

	std::cout<<"Ingrese el ancho del rectángulo\n";
	std::cin>>ancho;

    //Se crea el rectángulo con los valores proporcionados
	Rectangulo nuevo(ancho, largo);
	std::cout << "El área es: " << nuevo.area() << std::endl;
	std::cout << "El perímetro es: " << nuevo.perimetro() << std::endl;
    
    std::cout<<"Ingrese el nuevo largo del rectángulo\n";
	std::cin>>largo;

	std::cout<<"Ingrese el nuevo ancho del rectángulo\n";
	std::cin>>ancho;

    //Setters para modificar variables privadas
    nuevo.setAncho(ancho);
    nuevo.setLargo(largo);

	std::cout << "El área es: " << nuevo.area() << std::endl;
	std::cout << "El perímetro es: " << nuevo.perimetro() << std::endl;
    std::cout << std::endl;

    //Distintos constructores
    Rectangulo r1(nuevo);
    Rectangulo r2(5.0);
    Rectangulo r3(6.0, 8.0);

    //Implementación de varias funciones
    //Uso de getters para leer variables privadas
    std::cout << "El ancho del r1 es: " << r1.getAncho() << std::endl;
    std::cout << "El largo del r1 es: " << r1.getLargo() << std::endl;
    std::cout << "El área del r1 es: " << r1.area() << std::endl;
    std::cout << "El perímetro del r1 es: " << r1.perimetro() << std::endl;
    std::cout << std::endl;

    std::cout << "El ancho del r2 es: " << r2.getAncho() << std::endl;
    std::cout << "El largo del r2 es: " << r2.getLargo() << std::endl;
    std::cout << "El área del r2 es: " << r2.area() << std::endl;
    std::cout << "El perímetro del r2 es: " << r2.perimetro() << std::endl;
    std::cout << std::endl;

    std::cout << "El ancho del r3 es: " << r3.getAncho() << std::endl;
    std::cout << "El largo del r3 es: " << r3.getLargo() << std::endl;
    std::cout << "El área del r3 es: " << r3.area() << std::endl;
    std::cout << "El perímetro del r3 es: " << r3.perimetro() << std::endl;
    std::cout << std::endl;

	return 0;
}