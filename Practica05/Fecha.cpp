#include<iostream>
#include "Fecha.hpp"

namespace dfb
{
    Fecha::Fecha(int d, int m, int a):
    dia(d), mes(dfb::Meses(m)), anio(a)
    {
    }

    Fecha::Fecha(const Fecha & f)
    {
        this->dia = f.dia;
        this->mes = f.mes;
        this->anio = f.anio;
    }

    bool Fecha::setDia(int d)
    {
        if(d < 1) return false;
        
        switch (this->mes)
        {
            //Meses de 30 días
            case Meses(4):
            case Meses(6):
            case Meses(9):
            case Meses(11):
                if (d > 30) return false;
                break;

            //Febrero
            case Meses(2):
                if (!this->Bisiesto() && d > 28) return false;
                if (d > 29) return false;

            //Meses 31 días
            default:
                if (d > 31) return false;
                break;
        }
        this->dia = d;
        return true;
    }
    
    bool Fecha::setMes(int m)
    {
        if(m > 0 && m <=12)
        {
            this->mes = Meses(m -1);
        }
    }

    bool Fecha::setA(int a)
    {
        this->anio = a;
    }

	void Fecha::getDia(){
		std::cout << this->dia << std::endl;
	}
	
	void Fecha::getMes(){
		int i = static_cast<int>(this->mes);
		std::cout << i+1 << std::endl;
	}
	
	void Fecha::getA(){
		std::cout << this->anio << std::endl;
	}

    std::string Fecha::GetFecha() const
    {
        std::string fech;
        fech = std::to_string (this->dia) + "/";
        fech += std::to_string(static_cast<int>(this->mes) + 1) + "/";
        fech += std::to_string(this->anio);
        return fech;
    }

    bool Fecha::Igual(const Fecha & f)
    {
        return  f.anio == this->anio && 
                f.mes == this->mes && 
                f.dia == this->dia;
    }

    bool Fecha::Mayor(const Fecha & f)
    {
        int mes, mesf;

        mes = static_cast<int>(this->mes);
        mesf = static_cast<int>(f.mes);

        if(f.anio > this->anio) return true;
        if(f.anio < this->anio) return false;
        if(mesf > mes) return true;
        if(mesf < mes) return false;
        return f.dia > this->dia;
    }

    bool Fecha::Menor(const Fecha & f)
    {
        return !(this->Igual(f) || this->Mayor(f));
    }

    bool Fecha::Bisiesto()
    {
        int a = this->anio;
        return (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
    }

    bool Fecha::operator>(const Fecha & f)
    {
        return this->Mayor(f);
    }

    bool Fecha::operator<(const Fecha & f)
    {
        return this->Menor(f);
    }

    bool Fecha::operator>=(const Fecha & f)
    {
        return (this->Mayor(f) || this->Igual(f));
    }

    bool Fecha::operator<=(const Fecha & f)
    {
        return !this->Mayor(f);
    }

    bool Fecha::operator==(const Fecha & f)
    {
        return this->Igual(f);
    }

    bool Fecha::operator!=(const Fecha & f)
    {
        return !this->Igual(f);
    }

}