/**
 * @file Inventario.cpp
 * @brief Implementación del sistema de inventario con carga/guardado JSON,
 * búsqueda de productos, venta, compra y generación de datos para tickets.
 *
 * Este módulo administra un conjunto de productos usando unique_ptr,
 * aplica el patrón Factory para crear productos desde JSON
 * y utiliza el patrón Observer para alertar cuando el stock es bajo.
 * 
 * *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/modelos/Inventario.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

/**
 * @brief Carga los productos desde un archivo JSON.
 *
 * Cada entrada del archivo se utiliza para crear productos
 * a través de la fábrica ProductoFactory.
 *
 * @param archivo Nombre del archivo JSON a leer.
 */
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

/**
 * @brief Muestra todos los productos en el inventario por consola.
 */
void Inventario::listarProductos() {
    for (auto& p : productos) {
        std::cout << p->getCodigo() << " - " << p->getNombre()
            << " | $" << p->getPrecio()
            << " | Stock: " << p->getCantidad() << "\n";
    }
}

/**
 * @brief Realiza la venta de un producto y actualiza su stock.
 *
 * Si el stock restante es menor que 5 unidades, notifica a los observadores.
 *
 * @param codigo Código del producto a vender.
 * @param cantidadVendida Cantidad solicitada por el cliente.
 * @return Total de la venta. Devuelve 0 si falla la operación.
 */
double Inventario::venderProducto(const std::string& codigo, int cantidadVendida) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            if (p->getCantidad() < cantidadVendida) {
                std::cout << "No hay suficiente stock.\n";
                return 0;
            }

            p->setCantidad(p->getCantidad() - cantidadVendida);
            double total = p->getPrecio() * cantidadVendida;

            // Notificación por stock bajo
            if (p->getCantidad() < 5) {
                notificar("Stock bajo de " + p->getNombre());
            }

            return total;
        }
    }
    std::cout << "Producto no encontrado.\n";
    return 0;
}

/**
 * @brief Aumenta el stock de un producto ya existente.
 *
 * @param codigo Código del producto.
 * @param cantidad Cantidad a agregar al inventario.
 */
void Inventario::comprarProducto(const std::string& codigo, int cantidad) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            p->setCantidad(p->getCantidad() + cantidad);
            return;
        }
    }
}

/**
 * @brief Guarda el inventario completo en formato JSON.
 *
 * @param archivo Ruta del archivo donde se guardará el inventario.
 */
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


/**
 * @brief Obtiene el nombre de un producto según su código.
 *
 * @param codigo Código del producto.
 * @return Nombre del producto, o "Desconocido" si no existe.
 */
std::string Inventario::obtenerNombreProducto(const std::string& codigo) const {
    for (const auto& p : productos)
        if (p->getCodigo() == codigo)
            return p->getNombre();
    return "Desconocido";
}

/**
 * @brief Obtiene el precio unitario del producto según su código.
 *
 * @param codigo Código del producto.
 * @return Precio del producto o 0.0 si no existe.
 */
double Inventario::obtenerPrecioProducto(const std::string& codigo) const {
    for (const auto& p : productos)
        if (p->getCodigo() == codigo)
            return p->getPrecio();
    return 0.0;
}
