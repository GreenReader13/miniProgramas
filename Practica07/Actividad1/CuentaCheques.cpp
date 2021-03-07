#include<iostream>
#include"CuentaCheques.hpp"

CuentaCheques::CuentaCheques(double saldo, double minimo, std::string cuenta,
                    std::string password, double cuota):
                    Cuenta(saldo, minimo, cuenta, password), cuota{cuota}
{
    if(cuota < 0)
    {
        this->cuota = 0;
        std::cout << "Error al crear la cuenta, verificar la cuota\n";
    }
}

CuentaCheques::CuentaCheques(const CuentaCheques & rhs): 
    Cuenta(rhs), 
    cuota{rhs.cuota}
{
    if(rhs.cuota < 0)
    {
        this->cuota = 0;
        std::cout << "Error al crear la cuenta, verificar la cuota\n";
    }

}


bool CuentaCheques::Abonar(double cantidad)
{
    if(cantidad <= this->cuota) return false;

    const double cantidadAct = this->GetSaldo();
    const double cantidadTot = cantidadAct + cantidad - this->cuota;

    try
    {
        if(this->SetSaldo(cantidadTot) && cantidadAct < this->GetSaldo())
        return true;

        this->SetSaldo(cantidadAct);
        return false;
    }
    catch(const std::exception& e)
    {
        this->SetSaldo(cantidadAct);
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool CuentaCheques::Cargar(double cantidad)
{
    if(cantidad <= 0 || this->GetSaldo() < (cantidad + this ->GetMontoMin() + cuota)) return false;

    const double cantidadAct = this->GetSaldo();
    const double cantidadTot = cantidadAct - (cantidad + this->cuota);

    try
    {
        if(this->SetSaldo(cantidadTot) && cantidadAct > this->GetSaldo())
        return true;

        this->SetSaldo(cantidadAct);
        return false;
    }
    catch(const std::exception& e)
    {
        this->SetSaldo(cantidadAct);
        std::cerr << e.what() << '\n';
        return false;
    }
}

CuentaCheques::~CuentaCheques()
{
    
}