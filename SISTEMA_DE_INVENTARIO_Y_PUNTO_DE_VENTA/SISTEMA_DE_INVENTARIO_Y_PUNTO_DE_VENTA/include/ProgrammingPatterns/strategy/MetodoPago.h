#pragma once
#include <string>

/**
 * @file MetodoPago.h
 * @brief Interfaz base para el patrón Strategy que define métodos de pago.
 *
 * Esta clase establece la estructura que deben seguir todas las estrategias
 * de pago dentro del sistema. Cada método de pago puede aplicar comisiones,
 * descuentos u otras reglas internas, pero todos deben implementar las mismas
 * funciones para permitir su uso intercambiable.
 */
class MetodoPago {
public:

    /**
    * @brief Destructor virtual por defecto.
    *
    * Se deja virtual para asegurar que las clases derivadas destruyan
    * correctamente sus propios recursos.
    */
    virtual ~MetodoPago() = default;

    /**
     * @brief Procesa el pago y devuelve el monto final que debe pagar el cliente.
     *
     * Esta función permite que cada método de pago aplique comisiones,
     * recargos, descuentos o cualquier cálculo adicional necesario.
     *
     * @param monto Monto base sin comisiones.
     * @return double Monto final que se cobrará al cliente.
     */
    virtual double procesarPago(double monto) = 0;

    /**
     * @brief Genera un mensaje informativo sobre el pago realizado.
     *
     * Esta función es útil para mostrar en la interfaz o en logs un mensaje
     * descriptivo indicando cómo se procesó el pago (por ejemplo, comisiones
     * aplicadas o método utilizado).
     *
     * @param monto Monto final cobrado.
     * @return std::string Mensaje con la información del proceso del pago.
     */
    virtual std::string pagar(double monto) = 0;
};
