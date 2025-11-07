#pragma once
#include "ProgrammingPatterns/modelos/Producto.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "ProgrammingPatterns/observer/Sujeto.h"
#include "nlohmann/json.hpp"

class Inventario : public Sujeto {
private:
    std::vector<std::unique_ptr<Producto>> productos;

public:
    void cargarDesdeJson(const std::string& archivo);
    void listarProductos();
    void venderProducto(const std::string& codigo, int cantidadVendida);
    void comprarProducto(const std::string& codigo, int cantidadComprada);
    void guardarAJson(const std::string& archivo);
};
