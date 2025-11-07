#pragma once
#include "Prerequisites.h"
class Producto {

public:
	Producto(std::string c, std::string n, double p, int q);
	std::string getCodigo() const;
	std::string getNombre() const; 
	double getPrecio() const;
	int getCantidad() const;
	void setCantidad(int nuevaCantidad);
	void setPrecio(double nuevoPrecio);

private:
	std::string codigo;
	std::string nombre;
	double precio;
	int cantidad;
};