/**
 * @file    CuentaCheques.hpp
 * @class   CuentaCheques
 * @brief   Clase que representa una cuenta de chquees
 * @author  David Fuentes
 * @version 1.0.0
 * @date    2021
 * @copyright GNU Public License.
 */

#ifndef CUENTA_CHEQUES_HPP
#define CUENTA_CHEQUES_HPP

#include"Cuenta.hpp"

class CuentaCheques : public Cuenta
{
private:
    double cuota{0.0}; /**< Cuota cargada por movimiento */
public:
    /**
     * @brief Constructor explícito, previene asignación implícita
     * @param saldo Saldo inicial de la cuenta
     * @param minimo Monto mínimo de la cuenta
     * @param cuenta Número de cuenta
     * @param password Contraseña de la cuenta
     * @param cuota Cuota cargada a la cuenta por movimiento
     */
    CuentaCheques(double saldo, double minimo, std::string cuenta,
                    std::string password, double cuota);

    /**
     * @brief Constructor copia
     * @param rhs Objeto de referencia
     */
    CuentaCheques(const CuentaCheques & rhs);

    /**
     * @brief Abona una cantidad al saldo de la cuenta
     * Se redefine la función para aplicar el cargo por movimiento
     * @param cantidad Cantidad que se abonará
     * @return true si la operación fue exitosa
     */
    bool Abonar(double cantidad);

    /**
     * @brief Carga una cantidad a la cuenta
     * Se redefine la función para aplicar el cargo por movimiento
     * @param cantidad monto que se cargará a la cuenta
     * @return true Si el cargo se realizó correctamente
     */
    bool Cargar(double cantidad);
    
    ~CuentaCheques();
};
#endif