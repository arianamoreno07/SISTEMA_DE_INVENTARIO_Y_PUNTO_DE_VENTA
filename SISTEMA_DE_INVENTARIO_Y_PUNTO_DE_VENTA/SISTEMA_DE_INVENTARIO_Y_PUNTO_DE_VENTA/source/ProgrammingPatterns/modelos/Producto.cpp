/**
 * @file Producto.cpp
 * @brief Implementación de la clase Producto.
 *
 * Esta clase representa un producto dentro del inventario. Contiene información
 * básica como código, nombre, precio y cantidad disponible, además de métodos
 * para consultar y modificar dichos atributos.
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/modelos/Producto.h"

 /**
  * @brief Constructor de la clase Producto.
  *
  * Inicializa un nuevo producto con los valores proporcionados.
  *
  * @param c Código único del producto.
  * @param n Nombre del producto.
  * @param p Precio unitario del producto.
  * @param q Cantidad disponible en inventario.
  */
Producto::Producto(std::string c, std::string n, double p, int q) : codigo(c), nombre(n), precio(p), cantidad(q) {}

/**
 * @brief Obtiene el código del producto.
 * @return Código del producto como una cadena de texto.
 */
std::string Producto::getCodigo() const { return codigo;}

/**
 * @brief Obtiene el nombre del producto.
 * @return Nombre del producto como una cadena de texto.
 */
std::string Producto::getNombre() const { return nombre;}
/**
 * @brief Obtiene el precio unitario del producto.
 * @return Precio como valor de tipo double.
 */
double 
Producto::getPrecio() const { return precio;}
/**
 * @brief Obtiene la cantidad disponible del producto.
 * @return Cantidad en inventario como un entero.
 */
int 
Producto::getCantidad() const { return cantidad;}

/**
 * @brief Actualiza la cantidad disponible del producto.
 * @param nuevaCantidad Nuevo valor de cantidad.
 */
void 
Producto::setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad;}
/**
 * @brief Actualiza el precio del producto.
 * @param nuevoPrecio Nuevo valor del precio.
 */
void 
Producto::setPrecio(double nuevoPrecio) { precio = nuevoPrecio;}