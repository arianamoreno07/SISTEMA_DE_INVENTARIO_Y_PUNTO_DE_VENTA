#pragma once

/**
 * @file ProductoFactory.h
 * @brief Declara la clase ProductoFactory, encargada de crear instancias de productos.
 *
 * Esta clase implementa el patrón de diseño **Factory Method**, permitiendo
 * centralizar la creación de objetos `Producto` de forma controlada.
 *
 * Su propósito es abstraer la lógica de construcción y facilitar la extensión
 * futura (por ejemplo, si se agregan diferentes tipos de productos especializados).
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/modelos/Producto.h"

 /**
  * @class ProductoFactory
  * @brief Clase responsable de crear objetos `Producto`.
  *
  * La clase `ProductoFactory` proporciona un método estático que genera y retorna
  * instancias únicas (`std::unique_ptr`) de la clase `Producto`, evitando la necesidad
  * de crear productos directamente con `new` en el resto del código.
  *
  * @see Producto
  */
class 
ProductoFactory {

public:
    /**
     * @brief Crea un nuevo objeto `Producto`.
     *
     * Este método encapsula la creación de un producto, asignando dinámicamente
     * memoria y devolviendo un `std::unique_ptr` para asegurar una correcta gestión
     * de recursos.
     *
     * @param codigo Identificador único del producto.
     * @param nombre Nombre descriptivo del producto.
     * @param precio Precio unitario del producto.
     * @param cantidad Cantidad inicial disponible en el inventario.
     * @return std::unique_ptr<Producto> Puntero único al producto recién creado.
     */
	static std::unique_ptr<Producto> crearProducto(const std::string& codigo, const std::string& nombre, double precio, int cantidad);



};