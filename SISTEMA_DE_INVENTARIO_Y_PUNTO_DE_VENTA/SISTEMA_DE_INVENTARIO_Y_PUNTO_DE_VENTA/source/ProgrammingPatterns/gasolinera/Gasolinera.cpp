#include "ProgrammingPatterns/gasolinera/Gasolinera.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

bool Gasolinera::validarPago(double litros, double precioLitro, double montoPagado) const {
    double total = litros * precioLitro;
    return montoPagado >= total;
}

void Gasolinera::registrarCarga(double litros, const std::string& tipo, double precioLitro, MetodoPago* metodo) {
    if (metodo == nullptr) {
        std::cout << "ERROR: metodo de pago nulo.\n";
        return;
    }

    double total = litros * precioLitro;
    std::cout << "Total a pagar: $" << total << "\n";

    // procesarPago devuelve el monto que efectivamente se cobrará (puede incluir comisión)
    double pagoCliente = metodo->procesarPago(total);

    // Mostrar mensaje informativo (opcional)
    std::cout << metodo->pagar(total) << " -> Monto efectivo: $" << pagoCliente << "\n";

    if (!validarPago(litros, precioLitro, pagoCliente)) {
        std::cout << "⚠ Pago insuficiente. No se puede registrar la carga.\n";
        return;
    }

    historial.push_back({ litros, tipo, precioLitro, pagoCliente });
    std::cout << "✔ Carga registrada correctamente.\n";
}

void Gasolinera::mostrarHistorial() const {
    std::cout << "\n📄 HISTORIAL DE CARGAS:\n";
    if (historial.empty()) {
        std::cout << "(vacío)\n";
        return;
    }
    for (const auto& c : historial) {
        std::cout << c.litros << " L | " << c.tipo
            << " | $" << c.precioLitro
            << " | Pagó: $" << c.totalPagado << "\n";
    }
}

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
    std::cout << "✔ Historial guardado en " << archivo << "\n";
}

void Gasolinera::cargarHistorialJson(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cout << "⚠ No se encontró " << archivo << ", se iniciará vacío.\n";
        return;
    }

    json data;
    try {
        file >> data;
    }
    catch (...) {
        std::cout << "⚠ Error leyendo JSON de " << archivo << ". Se iniciará vacío.\n";
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

    std::cout << "✔ Historial cargado desde " << archivo << "\n";
}
