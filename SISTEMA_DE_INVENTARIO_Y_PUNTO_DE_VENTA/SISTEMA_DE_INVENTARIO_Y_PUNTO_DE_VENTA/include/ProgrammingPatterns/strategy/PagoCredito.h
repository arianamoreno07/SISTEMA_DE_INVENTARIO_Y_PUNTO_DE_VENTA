#pragma once
#include "ProgrammingPatterns/strategy/MetodoPago.h"
#include <string>

/**
 * @file PagoCredito.h
 *
 * Ejemplo: añade una comisión del 5% al monto.
 */

class PagoCredito : public MetodoPago {
public:
    double procesarPago(double monto) override {
        return monto * 1.05; // ejemplo: añade 5% de comisión
    }

    std::string pagar(double monto) override {
        return "Pago con tarjeta de crédito por $" + std::to_string(monto);
    }
};
