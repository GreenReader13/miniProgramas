#include<iostream>
#include"Cuenta.hpp"

Cuenta::Cuenta(double s, double m, std::string c, std::string p): 
        saldo{s}, montoMinimo{m}
{

    if(this->saldo < this->montoMinimo)
    {
        this->saldo = 0;
        std::cout << "Error al crear la cuenta\n";
        std::cout << "El saldo debe ser igual o mayor al monto mínimo\n";
    }
    if(this->saldo < 0 || this->montoMinimo <0)
    {
        this->saldo = 0;
        std::cout << "Error al crear la cuenta\n";
        std::cout << "El saldo y monto mínimo no pueden ser negativos\n";
    }
    if(this->SetCuenta(c) && this->SetPassword(p))
    {
        std::cout << "La cuenta se ha creado correctamente\n";
    }
}

Cuenta::Cuenta(const Cuenta & rhs):
saldo{rhs.saldo}, montoMinimo{rhs.montoMinimo},
cuenta{rhs.cuenta}, password{rhs.password}
{
    //Copia del objeto cuenta
}

bool Cuenta::Abonar(double cantidad)
{
    if(cantidad <= 0) return false;

    const double cantidadAct = this->saldo;
    const double cantidadTot = cantidadAct + cantidad;

    try
    {
        if(this->SetSaldo(cantidadTot) && cantidadAct < this->saldo)
        return true;

        this->saldo = cantidadAct;
        return false;
    }
    catch(const std::exception& e)
    {
        this->saldo = cantidadAct;
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool Cuenta::Cargar(double cantidad)
{
    if(cantidad <= 0 || this->saldo < cantidad) return false;

    const double cantidadAct = this->saldo;
    const double cantidadTot = cantidadAct - cantidad;

    try
    {
        if(this->SetSaldo(cantidadTot) && cantidadAct > this->saldo)
        return true;

        this->saldo = cantidadAct;
        return false;
    }
    catch(const std::exception& e)
    {
        this->saldo = cantidadAct;
        std::cerr << e.what() << '\n';
        return false;
    }
}

double Cuenta::GetSaldo()
{
    return this->saldo;
}

bool Cuenta::SetSaldo(double saldo)
{
    if (saldo < this->montoMinimo) return false;
    this->saldo = saldo;
    return true;
}

double Cuenta::GetMontoMin()
{
    return this->montoMinimo;
}

bool Cuenta::SetMontoMin(double monto)
{
    if(monto < 0) return false;
    this->montoMinimo = monto;
    return true;
}

bool Cuenta::SetCuenta(std::string cuenta)
{
    //Implementar verificación de cuenta única
    bool unica = true;
    if(unica){
        //Implementar verificar estructura
        //if(verificarEstructura(cuenta))...
        this->cuenta =cuenta;
        return true;
    }
    return false;
}

bool Cuenta::SetPassword(std::string pass)
{
    //Implementar verificación
    //if(verificarPass(pass))...
    //Implementar cifrado
    const std::string passCifrada = pass;
    this->password = passCifrada;
}

bool Cuenta::Autenticar(std::string cuenta, std::string pass)
{
    if(this->cuenta.compare(cuenta) == 0)
    {
        //Desencriptar contraseña almacenada
        std::string passDes = this->password;
        return pass.compare(passDes) == 0;
    }
}

void Cuenta::Guardar()
{
    //Implementar
}

std::string Cuenta::Desencriptar(std::string pass, std::string llave)
{
    //Implementar
}

std::string Cuenta::Encriptar(std::string pass, std::string llave)
{
    //implementar
}