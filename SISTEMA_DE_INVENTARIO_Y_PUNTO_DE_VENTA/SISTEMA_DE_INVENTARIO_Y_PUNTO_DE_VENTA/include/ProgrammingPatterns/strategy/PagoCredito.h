#pragma once
#include "ProgrammingPatterns/strategy/MetodoPago.h"
#include <string>

/**
 * @file PagoCredito.h
 * @brief Estrategia de pago con tarjeta de crédito.
 *
 * Esta implementación del patrón Strategy aplica una comisión del 5% al
 * monto original. Se utiliza cuando el cliente selecciona pagar con
 * tarjeta de crédito.
 */
class PagoCredito : public MetodoPago {
public:

    /**
     * @brief Procesa el pago aplicando una comisión del 5%.
     *
     * Esta función toma el monto base y le incrementa un 5%, simulando
     * la comisión típica de pagos con tarjeta.
     *
     * @param monto Monto base a cobrar.
     * @return double Monto final con comisión incluida.
     */
    double procesarPago(double monto) override {
        return monto * 1.05; // ejemplo: añade 5% de comisión
    }

    /**
    * @brief Genera un mensaje informativo del pago realizado.
    *
    * Este mensaje puede mostrarse en la interfaz o utilizarse en logs
    * del sistema para indicar cómo se procesó el pago.
    *
    * @param monto Monto final cobrado al cliente.
    * @return std::string Mensaje del proceso de pago.
    */
    std::string pagar(double monto) override {
        return "Pago con tarjeta de credito por $" + std::to_string(monto);
    }
};
