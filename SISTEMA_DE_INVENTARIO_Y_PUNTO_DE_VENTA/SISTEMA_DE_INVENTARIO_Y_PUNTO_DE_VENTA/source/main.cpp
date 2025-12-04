/**
 * @file main.cpp
 * @brief Sistema de Inventario y Ventas.
 */

#include "Prerequisites.h"
#include "programmingPatterns/modelos/Inventario.h"
#include "programmingPatterns/factory/ProductoFactory.h"
#include "programmingPatterns/observer/AlertaStockBajo.h"
#include "programmingPatterns/strategy/PagoCredito.h"
#include "programmingPatterns/strategy/PagoDebito.h"
#include "programmingPatterns/strategy/PagoEfectivo.h"
#include "programmingPatterns/gasolinera/Gasolinera.h"
#include "programmingPatterns/facade/SistemaFacade.h"
#include "programmingPatterns/facade/SistemaGasolineraFacade.h"
#include <limits>

static void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {

    // Inventario + Alerta
    Inventario inventario;
    AlertaStockBajo alerta;
    inventario.agregarObservador(&alerta);

    // Gasolinera + Facade
    Gasolinera gasolinera;
    SistemaGasolineraFacade gasFacade;
    gasolinera.cargarHistorialJson("HistorialGas.json");

    // Cargar inventario
    inventario.cargarDesdeJson("Productos.json");
    inventario.listarProductos();

    bool activo = true;

    while (activo) {
        std::cout << "\nSISTEMA DE INVENTARIO Y VENTAS\n";
        std::cout << "1. Lista Productos\n";
        std::cout << "2. Vender Producto\n";
        std::cout << "3. Comprar para reponer\n";
        std::cout << "4. Guardar inventario\n";
        std::cout << "5. Vender con ticket y factura\n";
        std::cout << "6. Gasolinera (Registrar carga)\n";
        std::cout << "7. Ver historial de gasolinera\n";
        std::cout << "8. Salir\n";
        std::cout << "Selecciona una opcion: ";

        int opcion;
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida.\n";
            limpiarEntrada();
            continue;
        }
        limpiarEntrada();

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
            std::cout << "Inventario guardado.\n";
            break;

        case 5: {
            std::string codigo;
            int cantidad;

            std::cout << "Codigo del producto: ";
            std::getline(std::cin, codigo);

            std::cout << "Cantidad a vender: ";
            std::cin >> cantidad;
            limpiarEntrada();

            std::cout << "Metodo de pago: 1-Efectivo 2-Debito 3-Credito: ";
            int mp;
            std::cin >> mp;
            limpiarEntrada();

            MetodoPago* metodo = nullptr;
            if (mp == 1) metodo = new PagoEfectivo();
            else if (mp == 2) metodo = new PagoDebito();
            else metodo = new PagoCredito();

            SistemaFacade facade;
            facade.procesarVenta(inventario, codigo, cantidad, metodo);

            delete metodo;
            break;
        }

        case 6: {  // GASOLINERA
            double litros;
            std::string tipo;
            double precio;

            std::cout << "Litros a cargar: ";
            std::cin >> litros;
            limpiarEntrada();

            std::cout << "Tipo de gasolina (Magna/Premium/Diesel): ";
            std::getline(std::cin, tipo);

            std::cout << "Precio por litro: ";
            std::cin >> precio;

            std::cout << "Metodo de pago: 1-Efectivo 2-Debito 3-Credito: ";
            int mp;
            std::cin >> mp;
            limpiarEntrada();

            MetodoPago* metodo = nullptr;
            if (mp == 1) metodo = new PagoEfectivo();
            else if (mp == 2) metodo = new PagoDebito();
            else metodo = new PagoCredito();

            gasFacade.procesarCarga(gasolinera, litros, tipo, precio, metodo);

            delete metodo;
            break;
        }

        case 7: // Mostrar historial
            gasolinera.mostrarHistorial();
            break;

        case 8: // Salida
            inventario.guardarAJson("Productos.json");
            gasolinera.guardarHistorialJson("HistorialGas.json");
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
