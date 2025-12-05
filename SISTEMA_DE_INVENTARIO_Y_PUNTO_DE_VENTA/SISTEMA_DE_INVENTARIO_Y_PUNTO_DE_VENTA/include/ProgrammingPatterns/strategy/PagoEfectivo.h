#pragma once
#include "ProgrammingPatterns/strategy/MetodoPago.h"
#include <string>

/**
 * @file PagoEfectivo.h
 * @brief Estrategia de pago en efectivo.
 *
 * Implementación del patrón Strategy para pagos en efectivo.
 * No aplica comisiones adicionales; el cliente paga exactamente el monto total.
 *  * @date 2025-12-04
 * @version 1.0
 * @author Ari
 */
class PagoEfectivo : public MetodoPago {
public:

    /**
     * @brief Procesa el pago sin modificar el monto.
     *
     * El pago en efectivo no incluye comisiones ni recargos.
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
    * Este mensaje indica que se efectuó un pago en efectivo.
    *
    * @param monto Monto cobrado.
    * @return std::string Mensaje del proceso de pago.
    */
    std::string pagar(double monto) override {
        return "Pago en efectivo por $" + std::to_string(monto);
    }
};
