#include "ProgrammingPatterns/modelos/Producto.h"


Producto::Producto(std::string c, std::string n, double p, int q) : codigo(c), nombre(n), precio(p), cantidad(q) {}

std::string Producto::getCodigo() const { return codigo;}
std::string Producto::getNombre() const { return nombre;}
double Producto::getPrecio() const { return precio;}
int Producto::getCantidad() const { return cantidad;}

void Producto::setCantidad(int nuevaCantidad) { cantidad = nuevaCantidad;}
void Producto::setPrecio(double nuevoPrecio) { precio = nuevoPrecio;}