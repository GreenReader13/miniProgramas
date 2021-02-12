/**
 * @file p4_acti1.cpp
 * @brief Clase que suma y resta números complejos
 * 
 * Se incluye main() mostrando un ejemplo de uso
 */

#include<iostream>

class Complex
{
private:
    double real;
    double imaginario;
public:
    Complex();
    Complex(double rel, double img);
    Complex(double img);

    Complex Suma(Complex otro);
    Complex Resta(Complex otro);
    void Imprimir();
    void setReal(double real);
    void setImaginario(double img);
};

/**
 * @brief Constructor por defecto
 * 
 * Constructor que nicializa los valores en cero
 */
Complex::Complex():real(0.0), imaginario(0.0)
{
}

/**
 * @brief Constructor numero complejo
 * @param rel Parte real del número complejo
 * @param img Parte imaginaria del número complejo
 */
Complex::Complex(double rel, double img):real(rel), imaginario(img)
{
}

/**
 * @brief Constructor numero imaginario
 * @param img Parte imaginaria del número complejo
 */
Complex::Complex(double img):real(0.0), imaginario(img)
{
}

/**
 * @brief Setter parte real
 * Asigna el valor de la parte real
 * @param real Parte real del numero complejo a actualizar
 */
void Complex::setReal(double real){
    this->real = real;
}

/**
 * @brief Setter parte imaginaria
 * Asigna el valor de la parte imaginaria
 * @param img Parte imaginaria del numero complejo a actualizar
 */
void Complex::setImaginario(double img){
    this->imaginario = img;
}

/**
 * @brief Suma de números complejos
 * @param otro Segundo número complejo a sumar
 * @return resultado de sumar el número actual con otro
 */
Complex Complex::Suma(Complex otro){
    Complex resultado;
    resultado.real = this->real + otro.real;
    resultado.imaginario = this->imaginario + otro.imaginario;
    return resultado;
}

/**
 * @brief Resta de números complejos
 * @param otro Segundo número complejo a restar
 * @return resultado de restar otro al número actual
 */
Complex Complex::Resta(Complex otro){
    Complex resultado;
    resultado.real = this->real - otro.real;
    resultado.imaginario = this->imaginario - otro.imaginario;
    return resultado;
}

/**
 * @brief Función que imprime el número complejo
 */
void Complex::Imprimir(){
    std::cout << "Complex: (" << this->real << ", " << this->imaginario << "i)";
    std::cout << std::endl;
}

/**
 * @brief implementación de clase Complex
 */
int main(){
    double realA, realB, imgA, imgB;

    //Se inicializan dos números A y B
    std::cout << "Ingresa el primer número complejo\n";
    std::cout << "Parte real: ";
    std::cin >> realA;
    std::cout << "Parte compleja: ";
    std::cin >> imgA;

    std::cout << "Ingresa el segundo número complejo\n";
    std::cout << "Parte real: ";
    std::cin >> realB;
    std::cout << "Parte compleja: ";
    std::cin >> imgB;

    //Constructor con parametros rel, img
    Complex A(realA, imgA);
    Complex B(realB, imgB);

    //Método imprimir
    std::cout << "Primer número complejo A: ";
    A.Imprimir();
    std::cout << std::endl;

    std::cout << "Segundo número complejo B: ";
    B.Imprimir();
    std::cout << std::endl;

    //Suma complejos
    Complex C = A.Suma(B);
    std::cout << "Suma A + B: ";
    // Se imprime creando un nuevo número
    C.Imprimir();
    std::cout << std::endl;

    //Resta de complejos
    std::cout << "Resta A - B: ";
    //Se pueden llamar a los métodos directamente 
    //si la función devuelve un objeto Complex
    A.Resta(B).Imprimir();
    std::cout << std::endl;
}