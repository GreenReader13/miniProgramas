#ifndef FECHA_HPP
#define FECHA_HPP

#include "Meses.hpp"
namespace dfb
{
    class Fecha
    {
    private:
        int dia; /**< Dia del año */
        dfb::Meses mes; /**< Mes del año */
        int anio;  /**< Año */

    public:
        Fecha() = default;
        Fecha(int d, int m, int a);
        Fecha(const Fecha & f);

        bool setDia(int d);
        bool setMes(int m);
        bool setA(int a);

        void getDia();
        void getMes();
        void getA();
        std::string GetFecha() const;

        bool Mayor(const Fecha & f);
        bool Menor(const Fecha & f);
        bool Igual(const Fecha & f);
        bool Bisiesto();

        bool operator >  (const Fecha & f);
        bool operator >= (const Fecha & f);
        bool operator == (const Fecha & f);
        bool operator <= (const Fecha & f);
        bool operator <  (const Fecha & f);
        bool operator != (const Fecha & f);
    };
} // namespace dfb

#endif