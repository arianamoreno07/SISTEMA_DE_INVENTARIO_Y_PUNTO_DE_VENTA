#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ProgrammingPatterns/strategy/MetodoPago.h"

/**
 * @file Gasolinera.h
 */

struct CargaGasolina {
    double litros;
    std::string tipo;
    double precioLitro;
    double totalPagado;
};

class Gasolinera {
private:
    std::vector<CargaGasolina> historial;

public:
    Gasolinera() = default;
    ~Gasolinera() = default;

    // Valida si el monto pagado cubre (o excede) el total a pagar.
    bool validarPago(double litros, double precioLitro, double montoPagado) const;

    // Registra una carga usando un objeto MetodoPago (Strategy).
    void registrarCarga(double litros, const std::string& tipo, double precioLitro, MetodoPago* metodo);

    // Muestra el historial por consola.
    void mostrarHistorial() const;

    // Guardar / cargar historial a JSON
    void guardarHistorialJson(const std::string& archivo) const;
    void cargarHistorialJson(const std::string& archivo);
};
