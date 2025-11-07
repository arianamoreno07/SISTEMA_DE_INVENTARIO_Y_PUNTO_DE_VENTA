/**
 * @file main.cpp
 * @brief Sistema de Inventario y Ventas.
 *
 * Este programa implementa un sistema básico de inventario con funcionalidades
 * para listar productos, vender, reponer stock y guardar los datos en formato JSON.
 *
 * Se utilizan los patrones de diseño:
 *  - Factory: para crear objetos de tipo Producto.
 *  - Observer: para notificar alertas de stock bajo.
 *
 * Los datos se guardan en el archivo "Productos.json".
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "Prerequisites.h"
#include "ProgrammingPatterns/modelos/Inventario.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "ProgrammingPatterns/observer/AlertaStockBajo.h"
#include <limits>

 /**
  * @brief Limpia la entrada estándar para evitar errores de lectura.
  *
  * Esta función elimina cualquier carácter restante en el buffer de entrada
  * (como saltos de línea o datos no válidos) después de leer desde `std::cin`.
  */
static void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Función principal del sistema de inventario y ventas.
 *
 * Carga los productos desde un archivo JSON, permite listar, vender,
 * comprar y guardar productos mediante un menú interactivo en consola.
 *
 * @return int Devuelve 0 al finalizar correctamente.
 */
int 
main() {
    Inventario inventario;
    AlertaStockBajo alerta;

    // Se registra el observador en el inventario
    inventario.agregarObservador(&alerta);

    // Carga inicial del inventario desde el archivo JSON
    inventario.cargarDesdeJson("Productos.json");

    // Muestra lista inicial de productos
    inventario.listarProductos();

    bool activo = true;

    // Bucle principal del sistema
    while (activo) {
        std::cout << "\nSISTEMA DE INVENTARIO Y VENTAS\n";
        std::cout << "1. Lista Productos\n";
        std::cout << "2. Vender Producto\n";
        std::cout << "3. Comprar para reponer\n";
        std::cout << "4. Guardar inventario\n";
        std::cout << "5. Salir\n";
        std::cout << "Selecciona una opcion: ";

        int opcion;
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida.\n";
            limpiarEntrada();
            continue;
        }

        limpiarEntrada(); // limpia el salto de línea pendiente

        switch (opcion) {

       /**
       * @brief Lista todos los productos disponibles en el inventario.
       */
        case 1:
            inventario.listarProductos();
            break;

        /**
            * @brief Permite vender un producto existente.
            *
            * Solicita el código del producto y la cantidad a vender.
            * Si el stock es bajo, el observador `AlertaStockBajo` mostrará una advertencia.
            */
        case 2: {
            std::string codigo;
            int cantidad;
            std::cout << "Codigo del producto: ";
            std::getline(std::cin, codigo);
            std::cout << "Cantidad a vender: ";
            std::cin >> cantidad;
            limpiarEntrada();
            inventario.venderProducto(codigo, cantidad);
            break;
        }

              /**
                  * @brief Permite reponer el stock de un producto.
                  *
                  * Solicita el código y la cantidad a comprar para aumentar el inventario.
                  */

        case 3: {
            std::string codigo;
            int cantidad;
            std::cout << "Codigo del producto: ";
            std::getline(std::cin, codigo);
            std::cout << "Cantidad a comprar: ";
            std::cin >> cantidad;
            limpiarEntrada();
            inventario.comprarProducto(codigo, cantidad);
            break;
        }

              /**
         * @brief Guarda los datos actuales del inventario en el archivo JSON.
         */

        case 4:
            inventario.guardarAJson("Productos.json");
            break;

            /**
         * @brief Sale del sistema guardando los datos antes de cerrar.
         */
        case 5:
            inventario.guardarAJson("Productos.json");
            std::cout << "Saliendo del sistema...\n";
            activo = false;
            break;


            /**
         * @brief Muestra un mensaje si la opción ingresada no es válida.
         */
        default:
            std::cout << "Opción invalida, intenta otra vez.\n";
            break;
        }
    }

    return 0;
}
