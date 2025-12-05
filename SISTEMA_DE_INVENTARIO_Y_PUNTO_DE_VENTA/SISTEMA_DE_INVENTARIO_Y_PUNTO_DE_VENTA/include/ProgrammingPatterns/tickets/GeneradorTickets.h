#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

/**
 * @file GeneradorTickets.h
 * @brief Clase encargada de generar tickets de compra en archivo de texto.
 *
 * Esta clase funciona como un módulo auxiliar que genera un recibo detallado
 * con información del producto, cantidad, precios, impuestos y método de pago.
 * El ticket se guarda localmente como "ticket_compra.txt".
 *  * @date 2025-12-04
 * @version 1.0
 * @author Ari
 */
class 
GeneradorTickets {
public:

    /**
     * @brief Genera un ticket de compra y lo almacena en un archivo de texto.
     *
     * El ticket incluye:
     * - Nombre del producto
     * - Cantidad adquirida
     * - Precio unitario
     * - Subtotal e IVA
     * - Total pagado
     * - Método de pago utilizado
     * - Fecha y hora exacta de la transacción
     *
     * @param producto Nombre del producto comprado.
     * @param cantidad Cantidad adquirida.
     * @param precioUnitario Precio por unidad del producto.
     * @param total Monto total pagado por el cliente.
     * @param metodoPago Descripción del método de pago utilizado.
     */
    static void generarTicket(const std::string& producto, int cantidad, double precioUnitario, double total, const std::string& metodoPago) {

        std::ofstream archivo("ticket_compra.txt");

        if (!archivo.is_open()) {
            std::cout << "No se pudo crear el ticket.\n";
            return;
        }

        // Fecha y hora
        time_t now = time(nullptr);
        tm* t = localtime(&now);

        // Cálculo de IVA
        double subtotal = total / 1.16;
        double iva = subtotal * 0.16;

        archivo << "*************** TIENDA DE LA ESQUINA ****************\n";
        archivo << "               RECIBO DE COMPRA\n";
        archivo << "-------------------------------------------\n\n";

        archivo << "Ticket No: 001283\n";
        archivo << "Fecha: "
            << std::put_time(t, "%d/%m/%Y")
            << "   Hora: "
            << std::put_time(t, "%H:%M:%S") << "\n\n";

        archivo << "Descripción                          Precio \n";
        archivo << "-------------------------------------------\n";

        archivo << producto
            << std::setw(35 - producto.length())
            << "$" << precioUnitario << "\n";

        archivo << "Cantidad: " << cantidad << "\n";
        archivo << "-------------------------------------------\n\n";

        archivo << std::fixed << std::setprecision(2);
        archivo << "Subtotal:                           $" << subtotal << "\n";
        archivo << "IVA (16%):                          $" << iva << "\n";
        archivo << "TOTAL:                              $" << total << "\n\n";

        archivo << "Método de pago: " << metodoPago << "\n";
        archivo << "-------------------------------------------\n";
        archivo << "   Gracias por su compra. Vuelva pronto :)\n";
        archivo << "*******************************************\n";

        archivo.close();
    }
};
