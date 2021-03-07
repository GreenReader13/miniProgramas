#include <iostream>
#include "CuentaAhorro.hpp"
#include "CuentaCheques.hpp"

int main(void)
{
    /*---------------Cuenta de Ahorros---------------*/
    std::cout <<"/*---------------Cuenta de Ahorros---------------*/\n";
    CuentaAhorro david(1500, 50, "12345", "pass", 0.12);
    std::cout << "Saldo: " << david.GetSaldo() << std::endl;
    
    david.Abonar(500.0);
    std::cout << "Saldo: " << david.GetSaldo() << std::endl;
    
    if(david.Cargar(700.0))
    {
        std::cout << "Transacción realizada con éxito\n";
    }
    else
    {
        std::cout << "Error Saldo insuficiente\n";
    }
    
    std::cout << "Interes: " << david.CalcularInteres() << std::endl;
    std::cout << "Saldo: " << david.GetSaldo() << std::endl;
    
    /*---------------Cuenta de Cheques---------------*/
    std::cout << "/*---------------Cuenta de Cheques---------------*/\n";
    
    CuentaCheques davidEjecutivo(1200.0, 500, "12341", "pass", 30);
    
    std::cout << "Saldo: " << davidEjecutivo.GetSaldo() << std::endl;
    
    davidEjecutivo.Abonar(500.0);
    std::cout << "Saldo: " << davidEjecutivo.GetSaldo() << std::endl;
    
    if(davidEjecutivo.Cargar(700.0))
    {
        std::cout << "Transacción realizada con éxito\n";
    }
    else
    {
        std::cout << "Error Saldo insuficiente\n";
    }
    std::cout << "Saldo: " << davidEjecutivo.GetSaldo() << std::endl;
}
