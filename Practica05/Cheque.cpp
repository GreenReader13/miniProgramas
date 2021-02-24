#include "Cheque.hpp"

namespace dfb
{
    Cheque::Cheque(dfb::Empleado & e): empleado{e}
    {
        dfb::Fecha fechEm(1, 1, 2021);
        this->emision = fechEm;
    }

    double Cheque::calcularSueldo()
    {
        int dias = this->empleado.GetDias();
        int penalizacion = this->empleado.GetPen();

        return this->empleado.GetSueldo()*(dias-penalizacion);
    }

    void Cheque::imprimir()
    {   
        std::cout << std::endl;
        std::cout << "Fecha:  " << this->emision.GetFecha() << std::endl;
        std::cout << "Nombre: " << this->empleado.GetNombre() << std::endl;
        std::cout << "Monto:  $" << this->calcularSueldo() << std::endl;
    }

    bool Cheque::SetFecha(dfb::Fecha & f)
    {
        dfb::Fecha nuevaFecha(f);
        this->emision = nuevaFecha;
        return true;
    }
}