/**
 * @file ProductoFactory.cpp
 * @brief Implementación de la clase ProductoFactory.
 *
 * Esta clase implementa el método de fábrica responsable de crear objetos
 * `Producto` de manera dinámica, utilizando punteros inteligentes para una
 * gestión segura de memoria.
 *
 * Forma parte del patrón de diseño **Factory Method**, utilizado para
 * centralizar y estandarizar la creación de instancias de productos.
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/factory/ProductoFactory.h"

 /**
  * @brief Crea una nueva instancia de la clase `Producto`.
  *
  * Este método construye un producto con los valores especificados y devuelve
  * un puntero inteligente (`std::unique_ptr`) que garantiza la liberación
  * automática de memoria cuando el objeto ya no es necesario.
  *
  * @param codigo Identificador único del producto.
  * @param nombre Nombre del producto.
  * @param precio Precio unitario del producto.
  * @param cantidad Cantidad inicial disponible en inventario.
  * @return std::unique_ptr<Producto> Puntero único al producto creado.
  */
std::unique_ptr<Producto> ProductoFactory::crearProducto(const std::string& codigo, const std::string& nombre, double precio, int cantidad) {
	return std::make_unique<Producto>(codigo, nombre, precio, cantidad);
}