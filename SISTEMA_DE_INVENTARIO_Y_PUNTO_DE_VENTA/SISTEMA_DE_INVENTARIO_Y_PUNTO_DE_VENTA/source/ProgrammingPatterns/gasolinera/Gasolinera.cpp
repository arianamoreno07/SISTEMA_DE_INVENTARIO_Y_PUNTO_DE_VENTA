/**
 * @file Gasolinera.cpp
 * @brief Implementación del módulo de gasolinera con historial, validación de pago y soporte JSON.
 *
 * Este módulo administra el registro de cargas de combustible utilizando el
 * patrón Strategy para métodos de pago. Permite validar montos, registrar
 * operaciones, mostrar historial y guardar/cargar información en formato JSON.
 * *
 * @date 2025-12-04
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/gasolinera/Gasolinera.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

/**
 * @brief Verifica si el cliente pagó suficiente para cubrir la carga.
 *
 * @param litros Cantidad de litros cargados.
 * @param precioLitro Precio por litro del combustible.
 * @param montoPagado Monto que el cliente efectivamente cubrió.
 * @return true si el pago cubre el total requerido, false de lo contrario.
 */
bool Gasolinera::validarPago(double litros, double precioLitro, double montoPagado) const {
    double total = litros * precioLitro;
    return montoPagado >= total;
}

/**
 * @brief Registra una carga de gasolina usando el método de pago Strategy.
 *
 * Valida el pago, procesa la comisión (si la hay) y guarda la operación en el historial.
 *
 * @param litros Litros cargados.
 * @param tipo Tipo de combustible (Magna, Premium, Diesel, etc.).
 * @param precioLitro Precio de venta por litro.
 * @param metodo Estrategia de pago elegida (efectivo, crédito, débito).
 */
void Gasolinera::registrarCarga(double litros, const std::string& tipo, double precioLitro, MetodoPago* metodo) {
    if (metodo == nullptr) {
        std::cout << "ERROR: metodo de pago nulo.\n";
        return;
    }

    double total = litros * precioLitro;
    std::cout << "Total a pagar: $" << total << "\n";

    // Se procesa el pago usando el Strategy (puede incluir comisión)
    double pagoCliente = metodo->procesarPago(total);

    
    std::cout << metodo->pagar(total) << " -> Monto efectivo: $" << pagoCliente << "\n";

    if (!validarPago(litros, precioLitro, pagoCliente)) {
        std::cout << "Pago insuficiente. No se puede registrar la carga.\n";
        return;
    }

    historial.push_back({ litros, tipo, precioLitro, pagoCliente });
    std::cout << "Carga registrada correctamente.\n";
}

/**
 * @brief Muestra por consola todas las cargas registradas.
 */
void Gasolinera::mostrarHistorial() const {
    std::cout << "\n HISTORIAL DE CARGAS:\n";
    if (historial.empty()) {
        std::cout << "(vacío)\n";
        return;
    }
    for (const auto& c : historial) {
        std::cout << c.litros << " L | " << c.tipo
            << " | $" << c.precioLitro
            << " | Pago: $" << c.totalPagado << "\n";
    }
}


/**
 * @brief Guarda el historial completo de cargas en un archivo JSON.
 *
 * @param archivo Ruta del archivo JSON donde se guardará.
 */
void Gasolinera::guardarHistorialJson(const std::string& archivo) const {
    json data = json::array();
    for (const auto& c : historial) {
        data.push_back({
            {"litros", c.litros},
            {"tipo", c.tipo},
            {"precioLitro", c.precioLitro},
            {"totalPagado", c.totalPagado}
            });
    }

    std::ofstream file(archivo);
    if (!file.is_open()) {
        std::cout << "ERROR: no se pudo abrir " << archivo << " para escribir.\n";
        return;
    }
    file << data.dump(2);
    std::cout << " Historial guardado en " << archivo << "\n";
}

/**
 * @brief Carga el historial de cargas desde un archivo JSON.
 *
 * @param archivo Ruta del archivo JSON a leer.
 */
void Gasolinera::cargarHistorialJson(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cout << " No se encontró " << archivo << ", se iniciará vacío.\n";
        return;
    }

    json data;
    try {
        file >> data;
    }
    catch (...) {
        std::cout << " Error leyendo JSON de " << archivo << ". Se iniciará vacío.\n";
        return;
    }

    historial.clear();
    for (const auto& item : data) {
        CargaGasolina c;
        c.litros = item.value("litros", 0.0);
        c.tipo = item.value("tipo", std::string("Desconocido"));
        c.precioLitro = item.value("precioLitro", 0.0);
        c.totalPagado = item.value("totalPagado", 0.0);
        historial.push_back(c);
    }

    std::cout << " Historial cargado desde " << archivo << "\n";
}
