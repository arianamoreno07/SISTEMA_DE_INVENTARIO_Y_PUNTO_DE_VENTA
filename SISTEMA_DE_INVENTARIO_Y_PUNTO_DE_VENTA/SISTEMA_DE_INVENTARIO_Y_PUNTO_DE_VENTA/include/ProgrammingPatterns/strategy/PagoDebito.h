#pragma once
#include "ProgrammingPatterns/strategy/MetodoPago.h"
#include <string>

/**
 * @file PagoDebito.h
 */

class PagoDebito : public MetodoPago {
public:
    double procesarPago(double monto) override {
        return monto; // paga exactamente el total
    }

    std::string pagar(double monto) override {
        return "Pago con tarjeta de débito por $" + std::to_string(monto);
    }
};
