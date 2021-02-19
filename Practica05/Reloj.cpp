#include<iostream>
#include"Reloj.hpp"

namespace dfb
{
    Reloj::Reloj():hora(0), min(0), seg(0)
    {

    }

    Reloj::Reloj(int h, int m, int s)
    {
        this->Establecer(h, m, s);
    }

    Reloj::Reloj(const Reloj & r)
    {
        this->hora = r.hora;
        this->min = r.min;
        this->seg = r.seg;
    }

    void Reloj::Establecer(int h, int m, int s)
    {
        this->hora = (h >= 0 || h <= 24)? h : 0;
        this->min = (m >= 0 && m < 60)? m : 0;
        this->seg = (s >= 0 && s < 60)? s : 0;
    }

    void Reloj::Imprimir()
    {
        std::cout << this->hora << ":";
        std::cout << this->min << ":";
        std::cout << this->seg << std::endl;
    }

    void Reloj::Avanzar()
    {
        if (this->seg < 59)
        {
            this->seg += 1;
            return;
        }
        this->seg = 0;
        if (this->min < 59)
        {
            this->min += 1;
            return;
        }
        this->min = 0;
        if(this->hora < 23)
        {
            this->hora += 1;
            return;
        }
        this->hora = 0;
    }

    bool Reloj::Mayor(const Reloj & r)
    {
        if(this->hora > r.hora) return true;
        if(this->hora < r.hora) return false;
        if(this->min > r.min) return true;
        if(this->min < r.min) return false;
        return this->seg > r.seg;
    }

    bool Reloj::Igual(const Reloj & r)
    {
        return  this->hora == r.hora &&
                this->min == r.min &&
                this->seg == r.seg;
    }

    bool Reloj::operator>(const Reloj & r)
    {
        return this->Mayor(r);
    }

    bool Reloj::operator>=(const Reloj & r)
    {
        return  this->hora >= r.hora &&
                this->min >= r.min &&
                this->seg >= r.seg;
    }

    bool Reloj::operator<(const Reloj & r)
    {
        if(this->hora < r.hora) return true;
        if(this->hora > r.hora) return false;
        if(this->min < r.min) return true;
        if(this->min > r.min) return false;
        return this->seg < r.seg;
    }

    bool Reloj::operator<=(const Reloj & r)
    {
        return !this->Mayor(r);
    }

    bool Reloj::operator==(const Reloj & r)
    {
        return this->Igual(r);
    }

    bool Reloj::operator!=(const Reloj & r)
    {
        return !this->Igual(r);
    }

    int Reloj::GetHora()
    {
        return this->hora;
    }

    int Reloj::GetMin()
    {
        return this->min;
    }

    int Reloj::GetSeg()
    {
        return this->seg;
    }
}