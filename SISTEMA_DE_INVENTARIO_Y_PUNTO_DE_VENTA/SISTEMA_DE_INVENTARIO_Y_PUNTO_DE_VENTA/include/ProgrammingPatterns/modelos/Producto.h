#pragma once
/**
 * @file Producto.h
 * @brief Declaración de la clase Producto que representa un artículo del inventario.
 *
 * La clase `Producto` almacena la información básica de un artículo, incluyendo su código,
 * nombre, precio y cantidad disponible. Es utilizada por la clase `Inventario` para
 * gestionar el stock de productos.
 *
 * @date 2025-11-07
 * @version 1.0
 * @autor Ari
 */
#include "Prerequisites.h"

 /**
  * @class Producto
  * @brief Representa un producto dentro del sistema de inventario.
  *
  * Esta clase contiene los datos esenciales de un producto y proporciona
  * métodos para consultar y modificar su información.
  */
class 
Producto {

public:
	/**
	* @brief Constructor de la clase Producto.
	*
	* @param c Código único del producto (por ejemplo, "A001").
	* @param n Nombre del producto.
	* @param p Precio unitario del producto.
	* @param q Cantidad inicial disponible en el inventario.
	*/
	Producto(std::string c, std::string n, double p, int q);
	/**
	* @brief Obtiene el código del producto.
	* @return std::string Código del producto.
	*/
	std::string getCodigo() const;
	/**
	 * @brief Obtiene el nombre del producto.
	 * @return std::string Nombre del producto.
	 */
	std::string getNombre() const; 
	/**
	 * @brief Obtiene el precio unitario del producto.
	 * @return double Precio actual.
	 */
	double 
	getPrecio() const;
	/**
	* @brief Obtiene la cantidad disponible del producto.
	* @return int Cantidad actual en stock.
	*/
	int 
	getCantidad() const;
	/**
	 * @brief Establece una nueva cantidad de producto disponible.
	 * @param nuevaCantidad Valor entero con la nueva cantidad.
	 */
	void 
	setCantidad(int nuevaCantidad);
	/**
	* @brief Establece un nuevo precio para el producto.
	* @param nuevoPrecio Nuevo precio unitario.
	*/
	void 
	setPrecio(double nuevoPrecio);

private:
	/**
	 * @brief Código único que identifica al producto.
	 */
	std::string codigo;
	/**
	 * @brief Nombre descriptivo del producto.
	 */
	std::string nombre;
	/**
	* @brief Precio unitario del producto.
	*/
	double precio;
	/**
	* @brief Cantidad disponible en el inventario.
	*/
	int cantidad;
};