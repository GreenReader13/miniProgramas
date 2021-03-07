#include<iostream>
#include"CuentaAhorro.hpp"

CuentaAhorro::CuentaAhorro(double saldo, double minimo, std::string cuenta,
                    std::string password, double interes):
                    Cuenta(saldo, minimo, cuenta, password), interes{interes}
{
    if(interes < 0)
    {
        this->interes = 0;
        std::cout << "Error al crear la cuenta, verificar el interés\n";
    }
}

CuentaAhorro::CuentaAhorro(const CuentaAhorro & rhs): 
    Cuenta(rhs), 
    interes{rhs.interes}
{
    if(rhs.interes < 0)
    {
        this->interes = 0;
        std::cout << "Error al crear la cuenta, verificar el interés\n";
    }

}

double CuentaAhorro::CalcularInteres()
{
    return this->interes * GetSaldo();
}

CuentaAhorro::~CuentaAhorro()
{
    
}