#include "ProgrammingPatterns/modelos/Inventario.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

void Inventario::cargarDesdeJson(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cout << "No se pudo abrir " << archivo << "\n";
        return;
    }

    json data;
    file >> data;

    for (auto& item : data) {
        auto producto = ProductoFactory::crearProducto(
            item["id"].get<std::string>(),
            item["nombre"].get<std::string>(),
            item["precio"].get<double>(),
            item["cantidad"].get<int>()
        );
        productos.push_back(std::move(producto));
    }
}

void Inventario::listarProductos() {
    for (auto& p : productos) {
        std::cout << p->getCodigo() << " - " << p->getNombre()
            << " | $" << p->getPrecio()
            << " | Stock: " << p->getCantidad() << "\n";
    }
}

double Inventario::venderProducto(const std::string& codigo, int cantidadVendida) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            if (p->getCantidad() < cantidadVendida) {
                std::cout << "No hay suficiente stock.\n";
                return 0;
            }

            p->setCantidad(p->getCantidad() - cantidadVendida);
            double total = p->getPrecio() * cantidadVendida;

            if (p->getCantidad() < 5) {
                notificar("Stock bajo de " + p->getNombre());
            }

            return total;
        }
    }
    std::cout << "Producto no encontrado.\n";
    return 0;
}

void Inventario::comprarProducto(const std::string& codigo, int cantidad) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            p->setCantidad(p->getCantidad() + cantidad);
            return;
        }
    }
}

void Inventario::guardarAJson(const std::string& archivo) {
    json data = json::array();

    for (auto& p : productos) {
        data.push_back({
            {"id", p->getCodigo()},
            {"nombre", p->getNombre()},
            {"precio", p->getPrecio()},
            {"cantidad", p->getCantidad()}
            });
    }

    std::ofstream file(archivo);
    file << data.dump(2);
}

// Nuevas funciones para ticket
std::string Inventario::obtenerNombreProducto(const std::string& codigo) const {
    for (const auto& p : productos)
        if (p->getCodigo() == codigo)
            return p->getNombre();
    return "Desconocido";
}

double Inventario::obtenerPrecioProducto(const std::string& codigo) const {
    for (const auto& p : productos)
        if (p->getCodigo() == codigo)
            return p->getPrecio();
    return 0.0;
}
