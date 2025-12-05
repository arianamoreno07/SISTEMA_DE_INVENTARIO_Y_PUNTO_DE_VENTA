#pragma once
#include "ProgrammingPatterns/modelos/Producto.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "ProgrammingPatterns/observer/Sujeto.h"
#include "ProgrammingPatterns/observer/observador.h"
#include <memory>
#include <vector>

/**
 * @file Inventario.h
 * @brief Declaración de la clase Inventario, que gestiona los productos del sistema.
 *
 * Esta clase administra un conjunto de productos, permitiendo:
 *  - Cargar productos desde un archivo JSON.
 *  - Registrar compras y ventas.
 *  - Notificar automáticamente cuando algún producto tiene poco stock (Observer).
 *  - Consultar información del inventario.
 *
 * Utiliza los patrones:
 *  - **Factory** para crear productos.
 *  - **Observer** para notificar eventos como "stock bajo".
 *  - **Strategy** indirectamente a través del sistema de ventas.
 */

 /**
  * @class Inventario
  * @brief Gestiona productos mediante operaciones de compra, venta y persistencia.
  *
  * El inventario almacena productos dinámicamente mediante `std::unique_ptr`.
  * Además, actúa como sujeto en el patrón **Observer**, permitiendo registrar
  * observadores que serán notificados de cambios importantes (como stock insuficiente).
  */
class Inventario : public Sujeto {
private:

    /// Lista de productos administrados por el sistema.
    std::vector<std::unique_ptr<Producto>> productos;

    /// Observadores registrados (patrón Observer).
    std::vector<Observador*> observadores; 

public:

    /**
    * @brief Carga productos desde un archivo JSON.
    *
    * Usa la clase `ProductoFactory` para crear instancias concretas de productos.
    *
    * @param archivo Ruta del archivo JSON con la información de productos.
    */
    void cargarDesdeJson(const std::string& archivo);

    /**
    * @brief Muestra todos los productos del inventario por consola.
    */
    void listarProductos();

    /**
     * @brief Vende una cantidad específica de un producto.
     *
     * Si el producto tiene menos stock que la cantidad solicitada, la venta se rechaza.
     * Si después de la venta el stock baja de 5 unidades, se notifica a los observadores.
     *
     * @param codigo Código único del producto.
     * @param cantidadVendida Cantidad que se desea vender.
     * @return Total de la venta o 0 si la operación falla.
     */
    double venderProducto(const std::string& codigo, int cantidadVendida);

    /**
     * @brief Aumenta la cantidad de un producto existente.
     *
     * @param codigo Código del producto a actualizar.
     * @param cantidadComprada Cantidad que se agregó al inventario.
     */
    void comprarProducto(const std::string& codigo, int cantidadComprada);

    /**
    * @brief Guarda todos los productos actuales en un archivo JSON.
    *
    * @param archivo Ruta del archivo donde se guardará la información.
    */
    void guardarAJson(const std::string& archivo);

    /**
    * @brief Obtiene el nombre de un producto según su código.
    *
    * @param codigo Código único del producto.
    * @return Nombre del producto o `"Desconocido"` si no existe.
    */
    std::string obtenerNombreProducto(const std::string& codigo) const;

    /**
     * @brief Obtiene el precio unitario de un producto según su código.
     *
     * @param codigo Código único del producto.
     * @return Precio del producto o 0.0 si no existe.
     */
    double obtenerPrecioProducto(const std::string& codigo) const;

   
    //  MÉTODOS OBLIGATORIOS DEL PATRÓN OBSERVER
    /**
     * @brief Registra un observador para recibir notificaciones.
     *
     * @param obs Puntero al observador a agregar.
     */
    void agregarObservador(Observador* obs) override {
        observadores.push_back(obs);
    }

    /**
     * @brief Elimina un observador previamente registrado.
     *
     * @param obs Observador que se desea eliminar.
     */
    void eliminarObservador(Observador* obs) override {
        observadores.erase(
            std::remove(observadores.begin(), observadores.end(), obs),
            observadores.end()
        );
    }

    /**
     * @brief Notifica un mensaje a todos los observadores registrados.
     *
     * @param mensaje Contenido de la notificación.
     */
    void notificar(const std::string& mensaje) override {
        for (auto& obs : observadores) {
            obs->actualizar(mensaje);
        }
    }
};
