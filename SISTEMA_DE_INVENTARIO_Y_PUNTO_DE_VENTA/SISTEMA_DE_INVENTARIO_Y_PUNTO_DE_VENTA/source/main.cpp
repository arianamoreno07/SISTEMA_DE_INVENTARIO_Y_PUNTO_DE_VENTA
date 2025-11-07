#include "Prerequisites.h"
#include "ProgrammingPatterns/modelos/Inventario.h"
#include "ProgrammingPatterns/factory/ProductoFactory.h"
#include "ProgrammingPatterns/observer/AlertaStockBajo.h"
#include <limits>

static void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Inventario inventario;
    AlertaStockBajo alerta;

    inventario.agregarObservador(&alerta);
    inventario.cargarDesdeJson("Productos.json");

    inventario.listarProductos();

    bool activo = true;

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
        case 1:
            inventario.listarProductos();
            break;

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

        case 4:
            inventario.guardarAJson("Productos.json");
            break;

        case 5:
            inventario.guardarAJson("Productos.json");
            std::cout << "Saliendo del sistema...\n";
            activo = false;
            break;

        default:
            std::cout << "Opción invalida, intenta otra vez.\n";
            break;
        }
    }

    return 0;
}
