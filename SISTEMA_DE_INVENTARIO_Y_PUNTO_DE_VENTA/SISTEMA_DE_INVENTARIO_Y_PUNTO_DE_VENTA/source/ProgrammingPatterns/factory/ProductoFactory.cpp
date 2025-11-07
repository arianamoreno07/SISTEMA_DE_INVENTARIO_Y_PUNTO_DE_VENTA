#include "ProgrammingPatterns/factory/ProductoFactory.h"

std::unique_ptr<Producto> ProductoFactory::crearProducto(const std::string& codigo, const std::string& nombre, double precio, int cantidad) {
	return std::make_unique<Producto>(codigo, nombre, precio, cantidad);
}