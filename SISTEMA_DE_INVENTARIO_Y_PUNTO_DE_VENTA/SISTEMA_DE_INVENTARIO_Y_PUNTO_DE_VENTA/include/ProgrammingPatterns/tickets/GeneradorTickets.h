#pragma once
#include <string>
#include <fstream>
#include <ctime>
#include <iostream>
#include <iomanip>

class GeneradorTickets {
public:
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

        archivo << "*************** TIENDA XYZ ****************\n";
        archivo << "               RECIBO DE COMPRA\n";
        archivo << "-------------------------------------------\n\n";

        archivo << "Ticket No: 001283\n";
        archivo << "Fecha: "
            << std::put_time(t, "%d/%m/%Y")
            << "   Hora: "
            << std::put_time(t, "%H:%M:%S") << "\n\n";

        archivo << "Descripción                         Precio\n";
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
