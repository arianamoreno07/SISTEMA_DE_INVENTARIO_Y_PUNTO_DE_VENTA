#pragma once
#include "ProgrammingPatterns/modelos/Inventario.h"
#include "ProgrammingPatterns/strategy/PagoEfectivo.h"
#include "ProgrammingPatterns/strategy/PagoDebito.h"
#include "ProgrammingPatterns/strategy/PagoCredito.h"
#include "ProgrammingPatterns/tickets/GeneradorTickets.h"
#include <sstream>

class SistemaFacade {

public:
    void procesarVenta(Inventario& inv, const std::string& codigo, int cantidad, MetodoPago* metodo) {

        double total = inv.venderProducto(codigo, cantidad);

        if (total <= 0) {
            std::cout << "No se puede procesar la venta.\n";
            return;
        }

        // ➤ Obtener información real del producto
        std::string nombre = inv.obtenerNombreProducto(codigo);
        double precioUnitario = inv.obtenerPrecioProducto(codigo);

        // ➤ Detectar el método de pago usando dynamic_cast
        std::string tipoPago;
        if (dynamic_cast<PagoEfectivo*>(metodo)) tipoPago = "Efectivo";
        else if (dynamic_cast<PagoDebito*>(metodo)) tipoPago = "Debito";
        else if (dynamic_cast<PagoCredito*>(metodo)) tipoPago = "Credito";

        // ➤ Generar ticket profesional con IVA
        GeneradorTickets::generarTicket(
            nombre,
            cantidad,
            precioUnitario,
            total,
            tipoPago
        );

        // ➤ Ejecutar estrategia de pago
        std::cout << metodo->pagar(total) << "\n";

        std::cout << "[Simulando envio de correo] ticket enviado a: arimj000@hotmail.com\n";
    }
};
