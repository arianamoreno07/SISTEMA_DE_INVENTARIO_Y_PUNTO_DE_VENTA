
/**
 * @file main.cpp
 * @brief Sistema de Inventario, Ventas y Gasolinera usando varios patrones de diseño.
 *
 * Este programa combina múltiples patrones de diseño:
 * - Factory: creación de productos.
 * - Observer: alerta cuando el stock es bajo.
 * - Strategy: selección de métodos de pago.
 * - Facade: simplificación de procesos de venta y cargas en gasolinera.
 *
 * También incluye funciones para manejo de inventario, venta de productos,
 * generación de ticket/factura, registro de cargas de gasolina y persistencia en JSON.
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

 /**
  * @brief Limpia la entrada estándar para evitar problemas al mezclar `cin >>` con `getline`.
  */
static void limpiarEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Función principal del sistema.
 *
 * Permite:
 *  - Listar productos
 *  - Vender y reponer inventario
 *  - Guardar cambios en JSON
 *  - Realizar ventas con ticket/factura
 *  - Registrar cargas de gasolina
 *  - Mostrar historial de la gasolinera
 *
 * @return int Código de salida.
 */
int main() {

    // Inicialización del inventario y el observador de stock bajo
    Inventario inventario;
    AlertaStockBajo alerta;
    inventario.agregarObservador(&alerta);

    // Inicialización de la gasolinera + fachada
    Gasolinera gasolinera;
    SistemaGasolineraFacade gasFacade;
    gasolinera.cargarHistorialJson("HistorialGas.json");
	gasolinera.mostrarHistorial();

    // Cargar inventario desde archivo
    inventario.cargarDesdeJson("Productos.json");
    inventario.listarProductos();

    bool activo = true;

    // ----------------- MENÚ PRINCIPAL ------------------
    while (activo) {
		std::cout << "\n-----------------------------------\n";
        std::cout << "\nSISTEMA DE INVENTARIO Y VENTAS\n";
        std::cout << "1. Lista Productos\n";
        std::cout << "2. Vender Producto\n";
        std::cout << "3. Comprar para reponer\n";
        std::cout << "4. Guardar inventario\n";
        std::cout << "5. Vender con ticket y factura\n";
        std::cout << "6. Gasolinera (Registrar carga)\n";
        std::cout << "7. Ver historial de gasolinera\n";
        std::cout << "8. Salir\n";
        std::cout << "\n-----------------------------------\n";
        std::cout << "Selecciona una opcion: ";
		

        int opcion;
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida.\n";
            limpiarEntrada();
            continue;
        }
        limpiarEntrada();

        switch (opcion) {

            // -------- Opción 1: Mostrar productos --------
        case 1:
            inventario.listarProductos();
            break;

            // -------- Opción 2: Venta simple --------
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

              // -------- Opción 3: Reponer stock --------
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

              // -------- Opción 4: Guardar inventario --------
        case 4:
            inventario.guardarAJson("Productos.json");
            std::cout << "Inventario guardado.\n";
            break;

            // -------- Opción 5: Venta con ticket y método de pago (Strategy + Facade) --------
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

              // -------- Opción 6: Registrar carga en gasolinera (Facade + Strategy) --------

        case 6: {  
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

              // -------- Opción 7: Mostrar historial --------
        case 7: 
            gasolinera.mostrarHistorial();
            break;

            // -------- Opción 8: Salir del sistema --------
        case 8: 
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
