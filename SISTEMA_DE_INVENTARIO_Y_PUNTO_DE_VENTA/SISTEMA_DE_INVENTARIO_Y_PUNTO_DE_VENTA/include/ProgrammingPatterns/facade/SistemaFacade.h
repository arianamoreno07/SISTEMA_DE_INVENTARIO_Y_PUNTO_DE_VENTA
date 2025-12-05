#pragma once
#include "ProgrammingPatterns/modelos/Inventario.h"
#include "ProgrammingPatterns/strategy/PagoEfectivo.h"
#include "ProgrammingPatterns/strategy/PagoDebito.h"
#include "ProgrammingPatterns/strategy/PagoCredito.h"
#include "ProgrammingPatterns/tickets/GeneradorTickets.h"
#include <sstream>

/**
 * @class SistemaFacade
 * @brief Fachada principal que simplifica el proceso de ventas dentro del sistema.
 *
 * Esta clase implementa el patrón **Facade**, proporcionando un único punto de acceso
 * para realizar una venta completa:
 *  - Validación del inventario
 *  - Obtención de información del producto
 *  - Procesamiento del método de pago (Strategy)
 *  - Generación del ticket
 *  - Notificación simulada por correo
 *
 * El objetivo es ocultar toda la complejidad interna de los subsistemas
 * (Inventario, Métodos de pago, Generador de tickets) mediante una interfaz simple.
 */
class 
SistemaFacade {

public:

    /**
     * @brief Procesa una venta completa dentro del sistema usando el patrón Facade.
     *
     * Esta función coordina todos los pasos necesarios para realizar una venta:
     *  1. Descontar cantidad en inventario.
     *  2. Recuperar información del producto.
     *  3. Identificar el tipo de método de pago mediante dynamic_cast.
     *  4. Generar un ticket con información detallada.
     *  5. Ejecutar la estrategia de pago correspondiente.
     *
     * @param inv Referencia al inventario del sistema.
     * @param codigo Código único del producto a vender.
     * @param cantidad Cantidad de unidades que se desean vender.
     * @param metodo Estrategia de pago seleccionada por el cliente (Strategy).
     */
    void procesarVenta(Inventario& inv, const std::string& codigo, int cantidad, MetodoPago* metodo) {

        double total = inv.venderProducto(codigo, cantidad);

        if (total <= 0) {
            std::cout << "No se puede procesar la venta.\n";
            return;
        }

        // Obtener información real del producto
        std::string nombre = inv.obtenerNombreProducto(codigo);
        double precioUnitario = inv.obtenerPrecioProducto(codigo);

        // Detectar el método de pago usando dynamic_cast
        std::string tipoPago;
        if (dynamic_cast<PagoEfectivo*>(metodo)) tipoPago = "Efectivo";
        else if (dynamic_cast<PagoDebito*>(metodo)) tipoPago = "Debito";
        else if (dynamic_cast<PagoCredito*>(metodo)) tipoPago = "Credito";

        //  Generar ticket profesional con IVA
        GeneradorTickets::generarTicket(
            nombre,
            cantidad,
            precioUnitario,
            total,
            tipoPago
        );

        //  Ejecutar estrategia de pago
        std::cout << metodo->pagar(total) << "\n";

        std::cout << "[Simulando envio de correo] ticket enviado a: arimj000@hotmail.com\n";
    }
};
