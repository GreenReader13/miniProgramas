#ifndef CUENTA_HPP
#define CUENTA_HPP

#include<string>
class Cuenta
{
private:

    double saldo{0.0};          /**< Representa el saldo inicial */
    double montoMinimo{0.0};    /**< Monto mínimo que puede tener la cuenta */   
    std::string cuenta;         /**< Número de cuenta */
    std::string password;       /**< Contraseña de la cuenta */

    std::string Desencriptar(std::string pass, std::string llave);
    std::string Encriptar(std::string pass, std::string llave);

public:

    /**
     * @brief Constructor por defecto
     */
    Cuenta() = default;

    /**
     * @brief Destructor
     */
    ~Cuenta();

    /**
     * @brief Constructor explícito, previene asignación implícita
     * @param saldo Saldo inicial de la cuenta
     * @param minimo Monto mínimo de la cuenta
     * @param cuenta Número de cuenta
     * @param password Contraseña de la cuenta
     */
    explicit Cuenta(double saldo, double minimo, std::string cuenta,
                    std::string password);
    
    /**
     * @brief Constructor copia
     * @param rhs Objeto de referencia
     */
    Cuenta(const Cuenta & rhs);

    /**
     * @brief Abona una cantidad al saldo de la cuenta
     * @param cantidad Cantidad que se abonará
     * @return true si la operación fue exitosa
     */
    bool Abonar(double cantidad);

    /**
     * @brief Carga una cantidad a la cuenta
     * @param cantidad monto que se cargará a la cuenta
     * @return true Si el cargo se realizó correctamente
     */
    bool Cargar(double cantidad);

    /**
     * @brief Devuelve el saldo actual de la cuenta
     * @return Saldo actual
     */
    double GetSaldo();

    /**
     * @brief Actualiza el saldo de la cuenta
     * @param saldo Nuevo saldo de la cuenta
     * @return true si la operación se realizó correctamente
     */
    bool SetSaldo(double saldo);

    /**
     * @brief Obtiene el saldo mínimo que puede tener la cuenta
     * @return Monto mínimo
     */
    double GetMontoMin();

    /**
     * @brief Establece el monto mínimo de la cuenta
     * @return true si el monto mínimo se estableció correctamente
     */
    bool SetMontoMin(double monto);

    /**
     * @brief Modifica el número de cuenta
     * @param cuenta Número de cuenta
     * @return true si el número de cuenta es válido
     */
    bool SetCuenta(std::string cuenta);

    /**
     * @brief Establece la contraseña de la cuenta
     * @param password Contraseña asociada a la cuenta
     * @return true si la contraseña cumple con los requerimientos
     */
    bool SetPassword(std::string password);

    /**
     * @brief Verifica si la cuenta y contraseña coinciden
     * @param cuenta Cuenta que debe ser igual a la almacenada
     * @param pass Contraseña que debe coincidir con la almacenada
     * @return true si los parámetros coinciden
     */
    bool Autenticar(std::string cuenta, std::string pass);

    /**
     * @brief Almacena los datos de la cuenta
     */
    void Guardar();

};

#endif