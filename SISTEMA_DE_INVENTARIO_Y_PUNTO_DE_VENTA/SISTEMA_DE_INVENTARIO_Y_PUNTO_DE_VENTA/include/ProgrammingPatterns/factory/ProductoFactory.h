#pragma once
#include "ProgrammingPatterns/modelos/Producto.h"

class 
ProductoFactory {

public:
	static std::unique_ptr<Producto> crearProducto(const std::string& codigo, const std::string& nombre, double precio, int cantidad);



};