#pragma once
#include <string>

/**
 * @file MetodoPago.h
 * @brief Interfaz para el patrón Strategy de métodos de pago.
 */

class MetodoPago {
public:
    virtual ~MetodoPago() = default;

    // Regresa el monto que efectivamente paga el cliente (puede incluir comisiones).
    virtual double procesarPago(double monto) = 0;

    // Mensaje informativo (opcional).
    virtual std::string pagar(double monto) = 0;
};
