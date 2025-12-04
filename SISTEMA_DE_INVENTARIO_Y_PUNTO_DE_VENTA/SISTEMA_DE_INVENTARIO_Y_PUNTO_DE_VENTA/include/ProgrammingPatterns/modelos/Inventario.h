#pragma once
#include "ProgrammingPatterns/modelos/Producto.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "ProgrammingPatterns/observer/Sujeto.h"
#include "ProgrammingPatterns/observer/observador.h"
#include <memory>
#include <vector>

class Inventario : public Sujeto {
private:
    std::vector<std::unique_ptr<Producto>> productos;
    std::vector<Observador*> observadores; // AHORA SÍ DEBE ESTAR AQUÍ

public:
    void cargarDesdeJson(const std::string& archivo);
    void listarProductos();
    double venderProducto(const std::string& codigo, int cantidadVendida);
    void comprarProducto(const std::string& codigo, int cantidadComprada);
    void guardarAJson(const std::string& archivo);

    std::string obtenerNombreProducto(const std::string& codigo) const;
    double obtenerPrecioProducto(const std::string& codigo) const;

    // ---- MÉTODOS OBLIGATORIOS DE SUJETO ----
    void agregarObservador(Observador* obs) override {
        observadores.push_back(obs);
    }

    void eliminarObservador(Observador* obs) override {
        observadores.erase(
            std::remove(observadores.begin(), observadores.end(), obs),
            observadores.end()
        );
    }

    void notificar(const std::string& mensaje) override {
        for (auto& obs : observadores) {
            obs->actualizar(mensaje);
        }
    }
};
