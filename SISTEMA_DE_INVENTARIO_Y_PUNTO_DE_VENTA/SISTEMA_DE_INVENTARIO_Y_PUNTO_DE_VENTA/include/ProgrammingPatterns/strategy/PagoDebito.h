#pragma once
#include "ProgrammingPatterns/strategy/MetodoPago.h"
#include <string>

/**
 * @file PagoDebito.h
 * @brief Estrategia de pago con tarjeta de débito.
 *
 * Esta implementación del patrón Strategy procesa el pago sin aplicar
 * comisiones adicionales; el cliente paga exactamente el monto total.
 */
class PagoDebito : public MetodoPago {
public:

    /**
     * @brief Procesa el pago sin modificar el monto.
     *
     * A diferencia del pago con crédito, aquí no se agregan comisiones.
     *
     * @param monto Monto base a cobrar.
     * @return double Monto final cobrado (igual al original).
     */
    double procesarPago(double monto) override {
        return monto; // paga exactamente el total
    }

    /**
    * @brief Genera un mensaje informativo del pago realizado.
    *
    * Este mensaje se usa para indicar que el pago fue procesado con
    * tarjeta de débito.
    *
    * @param monto Monto cobrado.
    * @return std::string Mensaje del proceso de pago.
    */
    std::string pagar(double monto) override {
        return "Pago con tarjeta de debito por $" + std::to_string(monto);
    }
};
