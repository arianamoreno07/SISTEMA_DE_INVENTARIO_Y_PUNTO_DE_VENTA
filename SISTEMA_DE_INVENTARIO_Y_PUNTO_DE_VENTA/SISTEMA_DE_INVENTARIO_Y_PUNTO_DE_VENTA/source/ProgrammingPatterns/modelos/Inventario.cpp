#include "ProgrammingPatterns/modelos/Inventario.h"
#include "nlohmann/json.hpp"
#include <fstream>          

using json = nlohmann::json;

// Cargar productos desde JSON
void Inventario::cargarDesdeJson(const std::string& archivo) {
    std::ifstream file(archivo);
    if (!file.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << archivo << std::endl;
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

    std::cout << "Productos cargados desde " << archivo << std::endl;
}
// Listar productos
void Inventario::listarProductos() {
    if (productos.empty()) {
        std::cout << " No hay productos cargados.\n";
        return;
    }

    std::cout << "\nINVENTARIO:\n";
    for (auto& p : productos) {
        std::cout << p->getCodigo() << " - "
            << p->getNombre()
            << " | $" << p->getPrecio()
            << " | Stock: " << p->getCantidad() << "\n";
    }
}

// Vender producto
void Inventario::venderProducto(const std::string& codigo, int cantidadVendida) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            int nuevaCantidad = p->getCantidad() - cantidadVendida;
            p->setCantidad(nuevaCantidad);
            if (nuevaCantidad < 5) {
                notificar("Stock bajo de " + p->getNombre());
            }
            std::cout << "Venta realizada: " << cantidadVendida << " de " << p->getNombre() << std::endl;
            return;
        }
    }
    std::cout << "Producto con código " << codigo << " no encontrado.\n";
}

// Comprar producto
void Inventario::comprarProducto(const std::string& codigo, int cantidadComprada) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            p->setCantidad(p->getCantidad() + cantidadComprada);
            std::cout << "Se compraron " << cantidadComprada << " unidades de " << p->getNombre() << std::endl;
            return;
        }
    }
    std::cout << "Producto con código " << codigo << " no encontrado.\n";
}

// Guardar cambios al JSON
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
    if (!file.is_open()) {
        std::cout << "No se pudo abrir el archivo para guardar: " << archivo << std::endl;
        return;
    }

    file << data.dump(2);
    std::cout << "Inventario guardado correctamente en " << archivo << std::endl;
}
