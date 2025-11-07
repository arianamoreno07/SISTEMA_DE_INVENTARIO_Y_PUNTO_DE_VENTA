#pragma once

/**
 * @file Inventario.h
 * @brief Declaración de la clase Inventario que administra los productos del sistema.
 *
 * La clase `Inventario` gestiona una colección de productos, permitiendo operaciones
 * como cargar desde archivo JSON, listar, vender, comprar y guardar nuevamente los datos.
 *
 * También hereda de la clase `Sujeto` (patrón Observer) para notificar a los observadores
 * cuando el stock de un producto es bajo o ha cambiado.
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/modelos/Producto.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "ProgrammingPatterns/observer/Sujeto.h"
#include "nlohmann/json.hpp"

 /**
  * @class Inventario
  * @brief Clase que administra el conjunto de productos en el sistema de inventario.
  *
  * La clase permite manejar los productos mediante operaciones CRUD básicas y mantiene
  * una lista de observadores para notificarles sobre cambios relevantes, como el stock bajo.
  *
  * Utiliza el patrón **Observer** (heredando de `Sujeto`) y el patrón **Factory** para la
  * creación dinámica de productos.
  */
class 
Inventario : public Sujeto {
private:
    /**
     * @brief Contenedor de productos administrados en el inventario.
     *
     * Cada producto se almacena como un `std::unique_ptr<Producto>` para asegurar
     * una gestión de memoria segura y evitar fugas.
     */
    std::vector<std::unique_ptr<Producto>> productos;

public:
    /**
     * @brief Carga los productos desde un archivo JSON.
     *
     * @param archivo Ruta del archivo JSON (por ejemplo, `"Productos.json"`).
     *
     * Esta función lee los datos del archivo y crea objetos `Producto` utilizando
     * la `ProductoFactory`. Si el archivo no existe o hay un error de formato,
     * debe manejarse apropiadamente.
     */
    void 
    cargarDesdeJson(const std::string& archivo);
    /**
     * @brief Muestra la lista de productos en consola.
     *
     * Esta función imprime los detalles de cada producto, incluyendo su código,
     * nombre, precio y cantidad disponible.
     */
    void 
    listarProductos();
    /**
     * @brief Vende una cantidad de un producto existente.
     *
     * @param codigo Código único del producto a vender.
     * @param cantidadVendida Cantidad a reducir del stock.
     *
     * Si la cantidad vendida es mayor al stock disponible, se muestra un mensaje de error.
     * Si el stock baja de cierto umbral, se notifica a los observadores registrados.
     */
    void 
    venderProducto(const std::string& codigo, int cantidadVendida);
    /**
    * @brief Aumenta el stock de un producto al comprar o reponer.
    *
    * @param codigo Código del producto.
    * @param cantidadComprada Cantidad a agregar al stock.
    *
    * Si el producto no existe, se muestra un mensaje de error.
    */
    void 
    comprarProducto(const std::string& codigo, int cantidadComprada);
    /**
    * @brief Guarda los productos actuales en un archivo JSON.
    *
    * @param archivo Ruta del archivo destino (por ejemplo, `"Productos.json"`).
    *
    * Esta función sobrescribe el archivo con la información actualizada del inventario.
    */
    void 
    guardarAJson(const std::string& archivo);
};
