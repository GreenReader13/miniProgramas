/**
 * @file    CuentaAhorros.hpp
 * @class   CuentaAhorros
 * @brief   Clase que representa una cuenta de ahorros
 * @author  David Fuentes
 * @version 1.0.0
 * @date    2021
 * @copyright GNU Public License.
 */
#ifndef CUENTA_AHORRO_HPP
#define CUENTA_AHORRO_HPP

#include"Cuenta.hpp"

class CuentaAhorro : public Cuenta
{
private:
    double interes{0.0}; /**< Interés de la cuenta */

public:
    /**
     * @brief Constructor explícito, previene asignación implícita
     * @param saldo Saldo inicial de la cuenta
     * @param minimo Monto mínimo de la cuenta
     * @param cuenta Número de cuenta
     * @param password Contraseña de la cuenta
     * @param interes Interés aplicado al saldo de la cuenta
     */
    CuentaAhorro(double saldo, double minimo, std::string cuenta,
                    std::string password, double interes);

    /**
     * @brief Constructor copia
     * @param rhs Objeto de referencia
     */
    CuentaAhorro(const CuentaAhorro & rhs);

    /**
     * @brief Calcula el interés generado
     * @return Cantidad generada por el interés como double
     */
    double CalcularInteres();


    ~CuentaAhorro();
};

#endif