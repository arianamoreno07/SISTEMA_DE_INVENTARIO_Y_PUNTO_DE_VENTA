/**
 * @file Inventario.cpp
 * @brief Implementación de la clase Inventario.
 *
 * Este archivo contiene las definiciones de los métodos de la clase `Inventario`,
 * que permiten administrar los productos en el sistema mediante operaciones de carga,
 * listado, venta, compra y guardado en formato JSON.
 *
 * Utiliza el patrón de diseño **Observer** (para alertas de stock bajo)
 * y **Factory** (para crear productos desde JSON).
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/modelos/Inventario.h"
#include "nlohmann/json.hpp"
#include <fstream>          

using json = nlohmann::json;

/**
 * @brief Carga los productos desde un archivo JSON.
 *
 * Abre el archivo especificado, lee su contenido JSON y crea instancias de `Producto`
 * utilizando la `ProductoFactory`. Cada producto se agrega al vector `productos`.
 *
 * @param archivo Ruta del archivo JSON a cargar (por ejemplo `"Productos.json"`).
 *
 * Si el archivo no puede abrirse, muestra un mensaje de error.
 */
void 
Inventario::cargarDesdeJson(const std::string& archivo) {
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
/**
 * @brief Muestra todos los productos del inventario en consola.
 *
 * Si no hay productos cargados, muestra un mensaje de advertencia.
 * Imprime el código, nombre, precio y cantidad disponible de cada producto.
 */
void 
Inventario::listarProductos() {
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

/**
 * @brief Vende una cantidad de un producto identificado por su código.
 *
 * Busca el producto en el inventario y descuenta la cantidad vendida.
 * Si el nuevo stock es menor a 5, se notifica a los observadores (patrón Observer).
 *
 * @param codigo Código del producto que se desea vender.
 * @param cantidadVendida Número de unidades a reducir del stock.
 *
 * Si el producto no se encuentra, muestra un mensaje de error.
 */
void 
Inventario::venderProducto(const std::string& codigo, int cantidadVendida) {
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

/**
 * @brief Aumenta la cantidad de un producto en el inventario.
 *
 * Busca el producto por su código y suma la cantidad comprada al stock actual.
 *
 * @param codigo Código del producto que se desea reponer.
 * @param cantidadComprada Número de unidades a agregar al stock.
 *
 * Si el producto no se encuentra, muestra un mensaje de error.
 */
void 
Inventario::comprarProducto(const std::string& codigo, int cantidadComprada) {
    for (auto& p : productos) {
        if (p->getCodigo() == codigo) {
            p->setCantidad(p->getCantidad() + cantidadComprada);
            std::cout << "Se compraron " << cantidadComprada << " unidades de " << p->getNombre() << std::endl;
            return;
        }
    }
    std::cout << "Producto con código " << codigo << " no encontrado.\n";
}

/**
 * @brief Guarda todos los productos del inventario en un archivo JSON.
 *
 * Recorre el vector de productos y genera un arreglo JSON con sus datos.
 * Luego sobrescribe el archivo especificado con la información actualizada.
 *
 * @param archivo Ruta del archivo JSON donde se guardará la información.
 *
 * Si el archivo no puede abrirse para escritura, muestra un mensaje de error.
 */
void 
Inventario::guardarAJson(const std::string& archivo) {
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
